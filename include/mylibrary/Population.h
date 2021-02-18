//
// Created by Ajith Senthil on 4/23/20.
//
//#pragma once

#ifndef FINALPROJECT_POPULATION_H
#define FINALPROJECT_POPULATION_H
#include "Person.h"
#include "stdio.h"
#include "vector"

namespace population {

class Population {
 private:
  int num_total_population, num_infected_people, num_susceptible_people;
  int num_removed_people, time_elapsed, threshold_time, threshold_distance;
  int date;
  int area_size;
  double infection_probability;
  double vaccination_rate;
  std::vector<person::Person> my_population;
  std::vector<person::Person> daily_infected;
  std::vector<std::vector<int>> SIRModelVector;

  /**
   * Infects the population for each day.
   */
  void infect_pop();
//  void get_SIR();
  /**
   * Removes the population for each day.
   */
  void remove_pop();
  /**
   * Gets the time elapsed.
   * @return
   */
  int getTimeElapsed();
  /**
   * Gets the number of people removed.
   * @return
   */
  int getNumRemoved();
  /**
   * Gets the number of susceptible.
   * @return
   */
  int getNumSusceptible();
  /**
   * Gets the number infected.
   * @return
   */
  int getNumInfected();
  /**
   * Gets the distance between two people.
   * @param b the first person object.
   * @param a the second person object.
   * @return
   */
  double getDistance(person::Person b, person::Person a);


 public:
  /**
   * Population constructor.
   * @param num_people the number of people in the population.
   * @param threshold_time the time it takes to become recovered after infection.
   * @param threshold_distance the distance between people to infect them.
   * @param num_sick the number sick initially.
   * @param soc_dist the factor of interactions in the population.
   * @param infection_probability the probability of infection after exposure.
   * @param area_size the size of container carrying the population.
   */
  Population(int num_people, int threshold_time, int threshold_distance,
             int num_sick, int soc_dist, double infection_probability, int area_size);

  /**
   * Returns the SIR data for a given population object.
   * @param date the date to add a vaccination.
   * @param addVaccination the rate of adding vaccinations.
   * @return
   */
  std::vector<std::vector<int>> getSIRModelVector(int date, double addVaccination);
  /**
   * Adds a vaccination at a given date.
   * @param vaccination_rate the rate people are vaccinated.
   */
  void addVaccination(double vaccination_rate);
};
}


#endif  // FINALPROJECT_POPULATION_H
