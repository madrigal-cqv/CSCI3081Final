# Team-010-33-homework4

Team 33, Section 010 - Chi Vu (vu000153) and Elijah Carlson (carl5411)

### What is this?
This is a drone simulation system set on the University of Minnesota Twin Cities campus. It is run through a web browser, and you can schedule trips from point A to point B where a drone carries a robot across campus (kind of like Uber). There are other entities besides the drone and robot(s), including at least one human, and a helicopter. These don't really affect the simulation though, they just make it feel more alive. Each entity in the simulation can be tracked by notifications relating to that entity's actions. 

### How do I use this?
First you will need to download the source code, then navigate to the `Team-010-33-homework4` directory in a terminal. Run the command `make -j`, and after that is finished, run `./build/bin/transit_service <port> apps/transit_service/web/` (replace <port> with whatever port you wish to use, 8081 for example). Next, navigate to `http://127.0.0.1:<port>` on your browser to launch the simulation. To schedule trips or add more humans, navigate to `http://127.0.0.1:<port>/schedule.html` in a separate tab. On this page, give your trip a name, choose a pathing algorithm, click on the map for a start and end location of the trip, and finally click the "Schedule Trip" button at the bottom. This will spawn a robot, and cause the drone to start moving.

### Features of the simulation
There are four movement algorithms used in this simulation - A*, Dijkstra's, Beeline, and Depth-First Search. The human entites (one spawns on launching of the simulation but more can be added through the scheduling page) use A* pathing to move from one random destination to the next. The helicopter that is spawned in on launch will use Beeline pathing to travel from one random point to another. The drone can use any of the algorithms besides Beeline to carry the robot to it's destination. When a drone finishes carrying the robot to its destination, both the robot and the drone will do a little celebration by spinning and/or jumping depending on the pathing algortihm used. You can also make the camera follow one specific entity, which can be selcected from the drop-down box on the simulation page (and you can zoom in and out by scrolling up or down respectively).

### New feature (notifications)
Our added feature introduces notifications to the simulation. It is interesting because it allows the user to watch specific entities and gain a better understanding of how the simulation works. By getting real-time updates, notifications can potentially clear up any confusion on what is happening in the system, and will allow for the user to understand a little of what is going on under the hood. We used the Observer pattern to implement this, as it allows the user to subscribe to the entity that they want to track. This seemed to be the easiest and most logical way to implement notifications into the system. Using the notification system is very easy: when launched, the simulation will automatically give notifications for every entity on the left side of the simulation screen. If the user only wants updates from one specific entity, they can choose the entity in the drop-down box labeled "Change observed entity", in which case only the selected entity's notifications will appear.

### Sprint Retrospective
Initially, the sprint was doing well but both of us did not seem to care about the artificial deadline set by the sprint, and so it was (for the most part) ignored. The Jira software really helped us keep track of what we still needed to do and what the other person was currently working on. The issues that we had created to be solved worked out pretty well, and covered nearly everything we needed to do except create a publisher class. We also had an extra issue (connect front-end to back-end) which ended up just being encompassed by other issues that we had created, making it more or less pointless. There were supposed to be two seperate sprints, one for the code and one for the documentation, but it really just ended up being one extended sprint with no time in-between. 

Here is the Youtube link: https://youtu.be/rPE6D-iHGU8

Here is the Docker link: https://hub.docker.com/repository/docker/vuqchi/team-010-33-homework4/general

And finally, here is the UML diagram:
![3081 010-33 Project Extension](https://media.github.umn.edu/user/24568/files/1fc21f47-6242-4a29-9d6c-0360e6c62e79)
