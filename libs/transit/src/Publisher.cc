#include "Publisher.h"

using namespace std;


Publisher::Publisher() {
  focus_obs = -1;
}

Publisher::~Publisher() {
  for (int i = 0; i < obs_list.size(); i++) {
    delete obs_list[i];
  }
}

void Publisher::AddObserver(IObserver* observer) {
  obs_list.push_back(observer);
}

void Publisher::RemoveSubscriber(IObserver* observer) {
  for (int i = 0; i < obs_list.size(); i++) {
    if (observer == obs_list[i]) {
      obs_list.erase(obs_list.begin()+i);
    }
  }
}

vector<string> Publisher::notify(double dt) {
  vector<string> result;
  if (focus_obs == -1) {
    for (int i = 0; i < obs_list.size(); i++) {
      result.push_back(obs_list[i]->Update(dt));
    }
  } else {
    result.clear();
    for (int i = 0; i < obs_list.size(); i++) {
      if (i != focus_obs) {
        obs_list[i]->Update(dt);
      } else {
        result.push_back(obs_list[i]->Update(dt));
      }
    }
  }
  return result;
}

void Publisher::focus(int id) {
  focus_obs = id;
}

void Publisher::unfocus() {
  focus_obs = -1;
}
