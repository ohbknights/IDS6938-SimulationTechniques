# Homework 3 : Agent based Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)
by Oddny H Brun

### Part 1 Behaviors

#### (a) Derivative

The derivatives are implemented using Eulers method. The first two, deriv[0] and deriv[1] represent the change in velocity per time step dv/dt = force/mass = acceleration for linear and angular movement of the agent, respecitvely. The other two, deriv[1] and deriv[2] are the change in length traveled by the agent per time step, dx/dt = v. The Euler method seems to give reasonable results in terms of linear movement. I suspect thet a higher order method like the midpoint method or the Runge-Kutta 4 method might have given more narrow turns whenever an agent changes direction. This has not been checked or attmpted quantified in this work.

The derivative were defined as:

		deriv[0] = input[0] / Mass;
		deriv[1] = input[1] / Inertia;
		deriv[2] = state[2] - vd;
		deriv[3] = input[1] / Inertia; //Assuming time is one as velocity*time equals distance.

In order to achieve smooth movements, the agents' mass and inertia were adjusted along with force and torque. Too much torque resulted in the agent turning back and forth around its own axix as it walked in the commanded direction. Too high inertia related to torque resulted in wider turns as it was circling around target in a seek as wellas when changing directions due to changing behaviors. I settled at torque per inertia of 40/30, and a force per mass of 8/100.

#### (b) Individual behaviors

Seek

Seek was implemented

Obstacles

Approach:
- find number of obstales (obstacleNum)
- find obstacle location and diameter (env->obstacles[0][0], env->obstacles[0][1]) and (env->obstacles[0][2]) and check if "cylinder corridor" along the direction of movement is clear
- take corrective action when "cylinder corridor" is not clear.

Cylinder corridor (that is, it is a rectangle bc. this agent moves in 2D, not 3D) is found by calculating the straight line between agent's location, GPos, and its goal, goal. A radius of length "radius" is added to both sides in x and y direction (that is the actual radius, the hypotenus, is a liitle bigger than the radius) of the straight line to define the corridor. The for each obstacle we check if any area of the corridor is within the obstacle's footprint described by its radius. I check in both x and y direction along the direction of travel, and if obstacle is within corridor, I decrease or increase the angel thetad, respectively.

Status: Used obstacle no 1 and found it to be within the agent's corridor, but have issues with my "if statement" and get aborted during execution. Also, the thetad angle adjustment is currently set to +/_ .5 just to test the effect (as oppostite to a proper calculation based on degree of obstacle blockage.



#### (c) Agent Group Behavior

Avoid.

Step one: Identify other agents within radius of "RNeighborhood" of our agent

In order to understand where to find info about other agents' location an how to refer to it, I created 2 agents and find their info in "SIMAgent::agents", ref. screenshot below, where the frame nr, color, etc. are given. Need to find their locations, GPos.

I pick agents[0] to be my agent and usees its location to check for the other within a radius of RNeighborhood. 

![Agents Information](agents_2.png)


### Part 2 - Simulating a simple pedestrian flow

#### (a) Subway Enterance

The subway enterance example was created with boundaries, walls, entrance and exit, including faregates before exit to train as shown in the figures below for entrance rate of 1000 per min.

![Subway Hall](part2_a_1.png)

Adding 3d,

![Subway Hall 3d](part2_a_2.png)

And adding faregates, displayed with density map,

![Faregates, density map](part2_a_3.png)

The entrance frequency was increased to 14,000 per minute and the back up and lines were visible as demonstrated in the below two figures:

![Density for 14,000](part2_a_4.png)

![3d of 14,000 entrances per minute](part2_a_5.png)

#### (b) Maze

I coipied a maze from www.mazegenerator.net and traced it. The pedestrians are entering at a rate of 1,000 per minute and exiting without showing any area of congestion (queue). The belonging density map is shown in the below figure,
![Maze, density, 1,000 arrivals per hour](part2_b_1.PNG)

When increasing the entrance rate to 5,000 per minute, the density plot indicates queues start to build up in areas with narrow passages, ref map fig with density below. The most congested area, not taking the entrance area into consideration is in the 3rd quadrant where the passage is rather narrow due to poor tracing of the maze. Similar effect was observed with lower entrance rate and larger size people so the hall ways became relatively more narrow. 

![Maze, density 5,000 arrivals per hour](part2_b_2.png)

So far, all pedestrians are choosing the same route, the one that leads to the exit as they pass through the maze. In order to diverge pedestrians to some of the dead ends, three pedestrian service areas were placed at three different locations. Pedestrians were directed uniformly distributed to these areas at a rate of .2 each, while the reminding 40% of the pedestrians were routed straight to the exit. This created little changes to the density map except for the expected population of these service areas, ref fig below. The service areas provided service at a uniformly distributed rare.

![Maze density, 8,000 arrivals per hour, three service areas](part2_b_5.png). The locations of the service areas are easier recognized in the following figure:

![Maze service areas locations](part2_b_6.png)

The three service areas were changed to provide service at a Poisson distribution, still receiving the same amount of pedestrians. This resulted in the service areas to start accumulating queues as seen in the density map below:

![Poisson distributed service times](part2_b_7.png)


#### (c) Modeling and analysis of the PIII building

One floor of the IST PIII building is modelled using the first floor floor plan. (Dr Wiegand and several of the labs are according to my model on forst floor for the time being.)

![IST PIII Floor plan](part2_c_2.png)

And Dr. Wegand is, according to the density map, close to the hottest spot (printer or coffe machine?). The floor plan is further detailed with six labs located on my version of this floor, L1 - L5 and the 3d Print lab. Lab 1 leas to lab 2 and lab 2 leads to lab 3. Lab 4 and 5 are only accessible through lab 5. The 3D lab is acceccible from the corridor. With 100 people entering the floor per hour uniformly distributed, there are two hot spots identified, one in the narrower part of the hallway outside lab1 enterance, not too far from Dr. Wiegand's office, and the other is closer to the exit, ref. figure below. Looking closer at the floor plan, the hallway is ratehr narrow in that first hot spot area and pedestrians get "tricked into the small office next to the hallway. After improving the wall recreatin which expanded the hallway, the first hotspot was resolved, ref the 3D image below.

![Pedestrian flow, 100 pedestriands per hour](part2_c_5.png)



![Entrance to PIII of 100 people per min, density map ](part2_c_4.png)



