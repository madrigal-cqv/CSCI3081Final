#ifndef HUMAN_OBSERVER_H_
#define HUMAN_OBSERVER_H_

#include <vector>

#include "IObserver.h"
#include "Human.h"


/**
 * @brief Observer class used for Human entities
 */
class HumanObserver : public IObserver {
 public:
  /**
   * @brief HumanObserver constructor
   * @param human reference to Human entity that will be tracked
   */
  HumanObserver(Human* human);
  /**
   * @brief HumanObserver destructor
   */
  ~HumanObserver() {}
  /**
   * @brief update function called to update notifications.
   * @param dt time since last call to update()
   * @return brief update of human as string
   */
  std::string Update(double dt);
  /**
   * @brief getter function for the ID of the observed human.
   * @return ID of the observed human.
   */
  int GetId() { return human->GetId(); }

 private:
  Human* human;
  std::string name;
  Vector3 dest;
  float prev_dist;
};

#endif
