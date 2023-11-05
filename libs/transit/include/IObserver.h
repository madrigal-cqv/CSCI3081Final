#ifndef I_OBSERVER_H_
#define I_OBSERVER_H_

// #include "IEntity.h"
#include <string>

/**
 * @brief Observer interface
 *
 */
class IObserver {
 public:
  /**
   * @brief update function called to update notifications.
   * @param dt time since last call to update()
   * @return brief update of object as a string
   */
  virtual std::string Update(double dt) = 0;
  /**
   * @brief getter function for the name of the observed entity.
   * @return name of the observed entity.
   */
  virtual int GetId() = 0;
};

#endif
