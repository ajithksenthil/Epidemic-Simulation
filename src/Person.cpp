//
// Created by Ajith Senthil on 4/23/20.
//

#include <stdlib.h>
#include "mylibrary/Person.h"

namespace person {

Person::Person() {
  is_susceptible = true;
  is_infected = false;
  is_removed = false;
  grid_size = 100;
}
Person::Person(int num_people, int soc_dist) {
  x_loc = rand() % (soc_dist * num_people);
  y_loc = rand() % (soc_dist * num_people);
  is_susceptible = true;
  is_infected = false;
  is_removed = false;
  grid_size = num_people * soc_dist;
}
Person::Person(bool isPatientZero, int num_people, int soc_dist) {
  x_loc = rand() % (soc_dist * num_people);
  y_loc = rand() % (soc_dist * num_people);
  is_susceptible = false;
  is_infected = true;
  is_removed = false;
  infected_time = 0;
  grid_size = num_people * soc_dist;
}
Person::Person(bool isPatientZero, int num_people, int soc_dist, int area_size) {
  x_loc = rand() % (soc_dist * area_size);
  y_loc = rand() % (soc_dist * area_size);
  is_susceptible = false;
  is_infected = true;
  is_removed = false;
  infected_time = 0;
  grid_size = num_people * soc_dist;
}
Person::Person(int num_people, int soc_dist, int area_size) {
  x_loc = rand() % (soc_dist * area_size);
  y_loc = rand() % (soc_dist * area_size);
  is_susceptible = true;
  is_infected = false;
  is_removed = false;
  grid_size = area_size * soc_dist;
}

int Person::getXLoc() {
  return x_loc;
}

int Person::getYLoc() {
  return y_loc;
}

void Person::move(){
  if (rand()%1 - 0.5 > 0 && x_loc < grid_size - 10) {
    x_loc = x_loc + 10;
  } else  if (rand()%1 - 0.5 < 0 && x_loc > 10){
    x_loc = x_loc - 10;
  }
  if (rand()%1 - 0.5 > 0 && y_loc < grid_size - 10) {
    y_loc = y_loc + 10;
  } else if (rand()%1 - 0.5 < 0 && y_loc > 10){
    y_loc = y_loc - 10;
  }
};

void Person::getSick(int time_elapsed){
  is_infected = true;
  is_susceptible = false;
  infected_time = time_elapsed;
}

int Person::getInfectedTime() {
  return infected_time;
}

void Person::now_removed(){
  is_infected = false;
  is_susceptible = false;
  is_removed = true;
}

bool Person::isInfected() {
  return is_infected;
}

bool Person::isSusceptible() {
  return is_susceptible;
}



bool Person::isRemoved() {
  return is_removed;
}
};