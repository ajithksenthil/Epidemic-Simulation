//
// Created by Ajith Senthil on 4/23/20.
//

#ifndef FINALPROJECT_PERSON_H
#define FINALPROJECT_PERSON_H

namespace person {
class Person {
 public:
  bool is_infected, is_susceptible, is_removed;
  int x_loc, y_loc, infected_time, grid_size;
  int area_size;
  double infect_rate, susceptible_rate, removed_rate;

  /**
   * Returns the X locations and Y locations.
   * @return
   */
  int getXLoc();
  int getYLoc();

  /**
   * moves a person object.
   */
  void move();
  /**
   * Infects a person object.
   * @param time_elapsed time initially infected.
   */
  void getSick(int time_elapsed);
  /**
   * Removes a person object.
   */
  void now_removed();
  /**
   * Returns if the person is susceptible.
   * @return
   */
  bool isSusceptible();
  /**
   * returns if the person is infected.
   * @return
   */
  bool isInfected();
  /**
   * returns if the person is removed.
   * @return
   */
  bool isRemoved();
  /**
   * returns the infected time or time infected.
   * @return
   */
  int getInfectedTime();


  /**
   * default person constructor.
   */
  Person();
  /**
   * sick person constructor.
   * @param isPatientZero if patient is sick
   * @param num_people number of people
   * @param soc_dist the factor of social distancing
   */
  Person(bool isPatientZero, int num_people, int soc_dist);
  /**
   * Person constructor.
   * @param num_people number of people
   * @param soc_dist social distancing factor
   */
  Person(int num_people, int soc_dist);
  /**
   * sick person constructor
   * @param isPatientZero if person is sick
   * @param num_people number of people
   * @param soc_dist social distancing factor
   * @param area_size size of container
   */
  Person(bool isPatientZero, int num_people, int soc_dist, int area_size);
  /**
   * Person constructor
   * @param num_people number of people
   * @param soc_dist social distancing factor
   * @param area_size size of container for population.
   */
  Person(int num_people, int soc_dist, int area_size);
};
}



#endif  // FINALPROJECT_PERSON_H
