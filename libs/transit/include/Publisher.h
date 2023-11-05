#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include "IObserver.h"
#include <iostream>
#include <vector>

using namespace std;

class Publisher {
 public:
  /**
   * @brief Publisher constructor
   */
  Publisher();
  /**
   * @brief Publisher destructor
   */
  ~Publisher();
  /**
   * @brief Add observers to Publisher
   * @param observer IObserver object to be added to Publisher
   */
  void AddObserver(IObserver* observer);
  /**
   * @brief Remove observers to Publisher
   * @param observer IObserver object to be removed to Publisher
   */
  void RemoveSubscriber(IObserver* observer);
  /**
   * @brief notify function called to update notifications.
   * @param dt time since last call to update()
   * @return all text updates
   */
  vector<string> notify(double dt);
  /**
   * @brief Focus on one entity
   * @param id ID of the entity to focus on
   */
  void focus(int id);
  /**
   * @brief Stop focusing on one observer
   */
  void unfocus();

 private:
  int focus_obs;
  vector<IObserver*> obs_list;
};

#endif
