#include "HumanObserver.h"

HumanObserver::HumanObserver(Human* human) {
  this->human = human;
  name = (std::string) human->GetDetails()["name"];
  prev_dist = human->GetDestination().Distance(human->GetPosition());
}

// not sure why the logic for humanObserver needs to be different from
// helicopterObserver, but it just wouldn't work if implemented that way.
std::string HumanObserver::Update(double dt) {
  Vector3 dest = human->GetDestination();
  Vector3 pos = human->GetPosition();
  if (dest.Distance(pos) - prev_dist > 10.0) {
    prev_dist = dest.Distance(pos);
    return name + " has arrived at its destination\n";
  }
  prev_dist = dest.Distance(pos);
  return "";
}
