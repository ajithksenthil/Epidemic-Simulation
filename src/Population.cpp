//
// Created by Ajith Senthil on 4/23/20.
//

#include "mylibrary/Population.h"
#include <math.h>

namespace population {

Population::Population(int num_people, int time_threshold, int my_distance,
                       int num_sick, int soc_dist, double infection_stat, int area_size) {

  num_infected_people = num_sick;
  num_susceptible_people = 0;
  num_removed_people = 0;
  num_total_population = num_people;
  time_elapsed = 0;
  int time_remaining = 0;
  threshold_time = time_threshold;
  threshold_distance = my_distance;
  infection_probability = infection_stat;

  //Initial population set up.
  if (area_size > 0) {
    for (int i = 0; i < num_infected_people; i++) {
      my_population.push_back(person::Person(true, num_people, soc_dist, area_size));
    }
    for (int i = 0; i < num_people - num_infected_people; i++) {
      my_population.push_back(person::Person(num_people, soc_dist, area_size));
    }
  }
  else {
    for (int i = 0; i < num_infected_people; i++) {
//      my_population.push_back(new Person(true, num_people, soc_dist));
      my_population.push_back(person::Person(true, num_people, soc_dist));
    }
    for (int i = 0; i < num_people - num_infected_people; i++) {
      my_population.push_back(person::Person(num_people, soc_dist));
    }
  }

}

void Population:: infect_pop() {
  //Pushing back all the infected people in the population to daily infected,
  // a separate vector.
  for (int i = 0; i < num_total_population; i++) {
    if (my_population.at(i).is_infected) {
      daily_infected.push_back(my_population.at(i));
    }
  }

  //Going through the infected population
  for (int j = 0; j < daily_infected.size(); j++) {
    for (int k = 0; k < num_total_population; k++) {
      if (getDistance(daily_infected.at(j), my_population.at(k)) <
          threshold_distance &&
          my_population.at(k).isSusceptible()) {
        if ((infection_probability * 10) >= (rand()%10)) {
          my_population.at(k).getSick(time_elapsed);
        }
      }
    }
  }

  for (int i = 0; i < num_total_population; i++) {
    my_population.at(i).move();
  }
  daily_infected.clear();
}

double Population::getDistance(person::Person a, person::Person b) {
  return sqrt(((a.getXLoc() - b.getXLoc())*(a.getXLoc() - b.getXLoc()))
              + ((a.getYLoc() - b.getYLoc())*(a.getYLoc() - b.getYLoc())));
}

void Population::remove_pop() {
  for (int i = 0; i < num_total_population; i++) {
    if (my_population.at(i).isInfected() &&
        (time_elapsed - my_population.at(i).getInfectedTime()) >
        threshold_time) {
      my_population.at(i).now_removed();
    }
  }
}

int Population::getNumInfected() {
  int count = 0;
  for (int i = 0; i < my_population.size(); i++) {
    if (my_population.at(i).isInfected()) {
      count++;
    }
  }
  return count;
}

int Population::getNumSusceptible() {
  int count = 0;
  for (int i = 0; i < my_population.size(); i++) {
    if (my_population.at(i).isSusceptible()) {
      count++;
    }
  }
  return count;
}

int Population::getNumRemoved() {
  int count = 0;
  for (int i = 0; i < my_population.size(); i++) {
    if (my_population.at(i).isRemoved()) {
      count++;
    }
  }
  return count;
}


void Population::addVaccination(double vaccination_rate) {
  if (vaccination_rate > 0) {
    for (int i = 0; i < num_total_population; i++) {
      if (my_population.at(i).is_susceptible) {
        if ((vaccination_rate * 10) >= (rand() % 10)) {
          my_population.at(i).now_removed();
        }
      }
    }
  }
}

int Population::getTimeElapsed() {
  return time_elapsed;
}

std::vector<std::vector<int>> Population::getSIRModelVector(int date, double vaccination_rate) {

  while (getNumInfected() > 0) {
    infect_pop();
    remove_pop();
    if (date <= time_elapsed) {
      addVaccination(vaccination_rate);
    }
    std::vector<int> day_vector = {getNumInfected() * 100 / num_total_population,
                                   getNumSusceptible() * 100 / num_total_population,
                                   getNumRemoved() * 100 / num_total_population};
    SIRModelVector.push_back(day_vector);
    time_elapsed++;
  }

  return SIRModelVector;
}
}
