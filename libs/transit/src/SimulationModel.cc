#include "SimulationModel.h"

#include "DroneFactory.h"
#include "RobotFactory.h"
#include "HumanFactory.h"
#include "HelicopterFactory.h"

#include "HumanObserver.h"
#include "DroneObserver.h"
#include "RobotObserver.h"
#include "HelicopterObserver.h"

SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  compFactory = new CompositeFactory();
  AddFactory(new DroneFactory());
  AddFactory(new RobotFactory());
  AddFactory(new HumanFactory());
  AddFactory(new HelicopterFactory());

  publisher = new Publisher();
}

SimulationModel::~SimulationModel() {
  // Delete dynamically allocated variables
  for (int i = 0; i < entities.size(); i++) {
    delete entities[i];
  }
  for (int i = 0; i < scheduler.size(); i++) {
    delete scheduler[i];
  }
  delete graph;
  delete compFactory;
  delete publisher;
}

void SimulationModel::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  std::string name = entity["name"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;

  IEntity* myNewEntity = compFactory->CreateEntity(entity);
  myNewEntity->SetGraph(graph);

  // Call AddEntity to add it to the view
  controller.AddEntity(*myNewEntity);
  entities.push_back(myNewEntity);

  // set up observer for entity
  IObserver* observer = nullptr;

  if (type.compare("robot") == 0) {
    observer = new RobotObserver(reinterpret_cast<Robot*>(myNewEntity));
  } else if (type.compare("drone") == 0) {
    observer = new DroneObserver(reinterpret_cast<Drone*>(myNewEntity));
  } else if (type.compare("human") == 0) {
    observer = new HumanObserver(reinterpret_cast<Human*>(myNewEntity));
  } else if (type.compare("helicopter") == 0) {
    observer = new HelicopterObserver(
               reinterpret_cast<Helicopter*>(myNewEntity));
  }

  if (observer) {
    publisher->AddObserver(observer);
  }
}

/// Schedules a trip for an object in the scene
void SimulationModel::ScheduleTrip(JsonObject& details) {
  std::string name = details["name"];
  JsonArray start = details["start"];
  JsonArray end = details["end"];
  std::cout << name << ": " << start << " --> " << end << std::endl;

  for (auto entity : entities) {  // Add the entity to the scheduler
    JsonObject detailsTemp = entity->GetDetails();
    std::string nameTemp = detailsTemp["name"];
    std::string typeTemp = detailsTemp["type"];
    if (name.compare(nameTemp) == 0 && typeTemp.compare("robot") == 0 &&
        entity->GetAvailability()) {
      std::string strategyName = details["search"];
      entity->SetDestination(Vector3(end[0], end[1], end[2]));
      entity->SetStrategyName(strategyName);
      scheduler.push_back(entity);
      break;
    }
  }
  controller.SendEventToView("TripScheduled", details);
}

/// Updates the simulation
void SimulationModel::Update(double dt) {
  for (int i = 0; i < entities.size(); i++) {
    entities[i]->Update(dt, scheduler);
    controller.UpdateEntity(*entities[i]);
  }
  std::string full = "";
  std::vector<std::string> notis = publisher->notify(dt);
  for (int i = 0; i < notis.size(); i++) {
    if (notis[i] != "") {
      full += notis[i];
    }
  }
  if (full != "") {
    JsonObject details;
    details["info"] = full;
    controller.SendEventToView("observe", details);
  }
}

void SimulationModel::AddFactory(IEntityFactory* factory) {
  compFactory->AddFactory(factory);
}

void SimulationModel::Focus(int id) {
  publisher->focus(id);
}

void SimulationModel::Unfocus() {
  publisher->unfocus();
}
