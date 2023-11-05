#ifndef HELICOPTER_OBSERVER_H_
#define HELICOPTER_OBSERVER_H_

#include <vector>

#include "IObserver.h"
#include "Helicopter.h"


/**
 * @brief Observer class used for Helicopter entities
 */
class HelicopterObserver : public IObserver {
 public:
  /**
   * @brief HelicopterObserver constructor
   * @param helicopter reference to Helicopter entity that will be tracked
   */
  HelicopterObserver(Helicopter* helicopter);
  /**
   * @brief HelicopterObserver destructor
   */
  ~HelicopterObserver() {}
  /**
   * @brief update function called to update notifications.
   * @param dt time since last call to update()
   * @return brief update of helicopter as string
   */
  std::string Update(double dt);
  /**
   * @brief getter function for the ID of the observed helicopter.
   * @return ID of the observed helicopter.
   */
  int GetId() { return helicopter->GetId(); }

 private:
  Helicopter* helicopter;
  std::string name;
};

#endif
