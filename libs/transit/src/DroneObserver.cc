#include "DroneObserver.h"

DroneObserver::DroneObserver(Drone* drone) {
  this->drone = drone;
  gettingToEntity = false;
  pickedUp = false;
  deliveringEntity = false;
  name = (std::string) drone->GetDetails()["name"];
  time = 0;
  carried = "";
  arrived = false;
  pos = Vector3();
}

std::string DroneObserver::Update(double dt) {
  if (!drone->GetAvailability()) {
    if (!arrived) {
      pos = drone->GetEntity()->GetDestination();
      arrived = true;
    }
    if (!gettingToEntity) {
      carried = (std::string) drone->GetEntity()->GetDetails()["name"];
      gettingToEntity = true;
      return name + " is getting to " + carried + ".\n";
    }

    if (!pickedUp) {
      if (drone->GetEntity()->GetPosition().
          Distance(drone->GetPosition()) < 4.0) {
        pickedUp = true;
        return name + " has picked up " + carried + ".\n";
      }
    } else {
      if (!deliveringEntity) {
        deliveringEntity = true;
        return name + " is delivering " + carried + ".\n";
      } else {
        time += dt;
        if (time > 120) {
          deliveringEntity = false;
          time = 0;
        }
      }
    }

  } else {
    time = 0;
    arrived = false;
    gettingToEntity = false;
    pickedUp = false;
    deliveringEntity = false;
    if (pos.Distance(Vector3()) > 4.0) {
      pos = Vector3();
      return name + " has delivered "
             + carried + " to the final\ndestination.\n";
    }
    carried = "";
    pos = Vector3();
  }
  return "";
}
