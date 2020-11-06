/**
 * Filename: PriorityQueueExample.cpp
 * Author: Douglas Schmidt
 * Author: Julie A. Adams
 * Description: A test program to demonstrate STL Queue Container Adopter
 */

#include <iostream>
#include <queue>
#include <string>

struct Place {
  std::size_t dist;
  std::string dest;
  Place (const std::string dt, std::size_t ds): dist(ds), dest(dt) {}
  bool operator< (const Place &right) const { return dist < right.dist; }
};

std::ostream &operator<<(std::ostream &os, const Place &p) {
  return os << p.dest << " " << p.dist << std::endl;
}

int main (int argc, char *argv[])
{
  std::priority_queue<Place> pque;
  
  pque.push(Place("Kyoto", 12000));
  pque.push(Place("Amsterdam", 6500));
  pque.push(Place("Anchorage", 5500));
  pque.push(Place("Istanbul", 11350));
  pque.push(Place("Mt. Kilimanjaro", 16000));
  pque.push(Place("Brussels", 6300));
  
  for (; !pque.empty(); pque.pop()){
    std::cout << pque.top() << std::endl;
  }
  return 0;
}

/************* OUTPUT *********************
Mt. Kilimanjaro 16000

Kyoto 12000

Instanbul 11350

Amsterdam 6500

Brussels 6300

Anchorage 5500
*/
