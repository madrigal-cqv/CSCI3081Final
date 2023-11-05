#include "HelicopterObserver.h"

HelicopterObserver::HelicopterObserver(Helicopter* helicopter) {
  this->helicopter = helicopter;
  name = (std::string) helicopter->GetDetails()["name"];
}

std::string HelicopterObserver::Update(double dt) {
  Vector3 dest = helicopter->GetDestination();
  Vector3 pos = helicopter->GetPosition();
  if (dest.Distance(pos) < 4.0) {
    return name + " has arrived at its destination\n";
  }
  return "";
}
