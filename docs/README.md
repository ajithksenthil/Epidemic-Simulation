# Documentation for my final project

This is the documentation for my final project
# [Infection Prediction]

Author: [Ajith Senthil]

---


   This is an epidemic simulator that models the different ways different types of diseases can spread given different 
factors and conditions and model a reasonably accurate SIR model from the simulated data. SIR models of diseases are
 compartmental models as they group people into having consistent behavior as a whole. Humans are complex but SIR 
 models can predict to a degree the outcome of an epidemic by generalizing their behavior and movement.
    SIR models calculate three main values S the number of susceptible individuals in a population, 
I the number of infected individuals, and R the number of recovered or deceased individuals in 
a population who can no longer infect. To make an SIR model the transition rates need to be 
calculated and this tells us the change in time of the three variables of SIR. 
    Due to current events of the year 2020, pandemics and epidemiology have become 
mainstream issues and a population that understands how diseases spread are better 
equipped for the future. To produce the graphs in this model I will use the 
[CairoBasic](https://github.com/cinder/Cinder/tree/master/samples/CairoBasic), [matplotlb](https://github.com/lava/matplotlib-cpp) and [VboMesh](https://github.com/cinder/Cinder/tree/master/samples/_opengl/VboMesh)
    Here is a timeline for this project. By the end of Week 1, I will have finished a simple SIR model based on a 
simulation of person objects that move randomly but have the transition rates for the transmission of a disease. 
By the end of Week 2, a graph will be produced from the data based on the variables as well for 
any disease that is to be modeled, I will still be working on adding external variables along with the 
real time simulation. Week 3, I will have made the ability to take external variables which can be modified 
or assigned by an end user. For example, vaccines or any situation that has a measurable effect on the transition 
rates of the SIR model can be included. Stretch goals include a GUI for the real time simulation which shows each 
person object interacting with each other and how modifications to the environment would look like, being able to 
change the environment of the real time simulation and fetching data from external sources to have relevant models 
continually updated. 

## Notes
