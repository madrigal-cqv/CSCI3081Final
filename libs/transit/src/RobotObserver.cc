#include "RobotObserver.h"
#include "IEntity.h"

RobotObserver::RobotObserver(Robot* robot) {
  this->robot = robot;
  name = (std::string) robot->GetDetails()["name"];
  init_pos = robot->GetPosition();
  waiting = false;
  pickedUp = false;
  delivering = false;
  arrived = false;
  time = 0;
}

std::string RobotObserver::Update(double dt) {
  if (!waiting) {
    if (robot->GetPosition().Distance(init_pos) < 4.0) {
      waiting = true;
      return name + " is waiting to be picked up.\n";
    }
  }

  if (!pickedUp) {
    if (robot->GetPosition().Distance(init_pos) > 4.0) {
      pickedUp = true;
      return name + " has been picked up.\n";
    }
  } else {
    if (!delivering) {
      delivering = true;
      return name + " is being delivered.\n";
    } else {
      time += dt;
      if (time > 60 && !arrived) {
        delivering = false;
        time = 0;
      }
    }
  }

  if (!arrived && pickedUp) {
    if (robot->GetPosition().Distance(prev_pos) == 0) {
      delivering = true;
      arrived = true;
      return name + " has arrived at the destination.\n";
    }
  }
  prev_pos = robot->GetPosition();
  return "";
}
