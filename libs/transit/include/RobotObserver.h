#ifndef ROBOT_OBSERVER_H_
#define ROBOT_OBSERVER_H_

#include <vector>

#include "IObserver.h"
#include "Robot.h"


/**
 * @brief Observer class used for Robot entities
 */
class RobotObserver : public IObserver {
 public:
  /**
   * @brief RobotObserver constructor
   * @param robot reference to robot entity that will be tracked
   */
  RobotObserver(Robot* robot);
  /**
   * @brief RobotObserver destructor
   */
  ~RobotObserver() {}
  /**
   * @brief update function called to update notifications.
   * @param dt time since last call to update()
   * @return brief update of Robot as string
   */
  std::string Update(double dt);
  /**
   * @brief getter function for the ID of the observed robot.
   * @return ID of the observed robot.
   */
  int GetId() { return robot->GetId(); }

 private:
  Robot* robot;
  std::string name;
  Vector3 init_pos;
  Vector3 prev_pos;
  bool waiting;
  bool pickedUp;
  bool delivering;
  bool arrived;
  float time;
};

#endif
