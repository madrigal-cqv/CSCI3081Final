#ifndef DRONE_OBSERVER_H_
#define DRONE_OBSERVER_H_

#include <vector>

#include "IObserver.h"
#include "Drone.h"


/**
 * @brief Observer class used for Drone entities
 */
class DroneObserver : public IObserver {
 public:
  /**
   * @brief DroneObserver constructor
   * @param drone reference to drone entity that will be tracked
   */
  DroneObserver(Drone* drone);
  /**
   * @brief DroneObserver destructor
   */
  ~DroneObserver() {}
  /**
   * @brief update function called to update notifications.
   * @param dt time since last call to update()
   * @return brief update of Drone as string
   */
  std::string Update(double dt);
  /**
   * @brief getter function for the ID of the observed drone.
   * @return ID of the observed drone.
   */
  int GetId() { return drone->GetId(); }

 private:
  Drone* drone;
  std::string name;
  bool gettingToEntity;
  bool pickedUp;
  bool deliveringEntity;
  bool arrived;
  double time;
  Vector3 pos;
  std::string carried;
};

#endif
