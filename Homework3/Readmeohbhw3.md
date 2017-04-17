# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)
by Oddny H Brun

### Part2 - Simulating a simple pedestrian flow

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

I coipied a maze from www.mazegenerator.net and traced it. The pedestrians are entering at a rate of 1,000 per minute and exiting without showing any area that forms a build up (queue). The belonging density map is shown in the below figure,
![Maze, density, 1,000 arrivals per minute](part2_b_1.png)

When increasing the entrance rate to 5,000 per minute, the density plot indicates queues start to build up in areas with narrow passages, ref fig below.

![Maze, density 5,000 arrivals per minute](part2_b_2.png)

So far, all pedestrians are choosing the same route, the one that leads to the exit as they pass through the maze.

### (c) Modeling and analysis of the PIII building

One floor of the IST PIII building is modelled using the first floor floor plan. (Dr Wiegand and several of the labs are according to my model on forst floor for the time being.)

![IST PIII Floor plan](part2_c_2.png)

And Dr. Wegand is, according to the density map, close to teh hottest spot (printer or coffe machine?).

![Entrance to PIII of 100 people per min, density map ](part2_c_1.png)



