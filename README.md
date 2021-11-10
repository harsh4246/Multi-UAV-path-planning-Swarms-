![Shape4](RackMultipart20211110-4-12do4zp_html_c76f580fe67ee3bd.gif)

# MACHINE-LEARNING

# MODELSFORMULTI-UAVPATHPLANNING

# (phase III)

![Shape5](RackMultipart20211110-4-12do4zp_html_c76f580fe67ee3bd.gif)

##### V HARSHVARDHAN180103095

GOLLA VIJAYA RAGHAVA180103099

##### SUPERVISOR

Dr. SachinSinghGautam

![](RackMultipart20211110-4-12do4zp_html_28a0bd0a4a35b8be.png)

### CERTIFICATE

_It __is__ certified __that__ the work __contained__ in __the__ entitled __&quot;Machine__ learning__models_

_for __multi-UAV__ path __planning&quot;,__ by __&quot;Mr.__ V __HARSHVARDHAN&quot;__ and__&quot;Mr._

_GOLLA VIJAYA RAGHAVA NARENDRA CHOWDARY&quot; has been carried out under __my supervision and that this work has not been submitted elsewhere for a__ degree._

Dr.SachinSingh Gautam

NOV,2021. DepartmentofMechanicalEngineering,

I.I.T. Guwahati

### **Declaration**

_We declare that the submission contains ideas of our own and wherever __any idea is borrowed it has been properly cited and referenced the source. We understand that any violation of academic principles will be__ cause for disciplinary action by the institute and sources which have not __been__ properly__cited._

_V __HARSHVARDHAN GOLLA VIJAYA RAGHAVA__ NARENDRA__CHOWDARY_

**Abstract****  **

Swarm Intelligence has played a vital role in controlling a group of vehicles.

We have made a swarm of UAVs to map a group of moving targets avoiding obstacles scattered in the space that were stationary and react according to their genetic string. To have better candidate solutions for moving targets we tweaked the cost function. We have also collected data on time taken and convergence to the minima of a sample. The parallelization of code has reduced the time taken by code significantly.

###SEE 100 drones Simulation in the repo.

### Tableofcontents

1. Introduction (1)
2. Literaryreview(2)2.1. Path planningforswarms(2)2.2. Geneticalgorithms(3)
3. Objectives(4)
4. Methodology(5)4.1.Code Framework(5)

    1. Assumptions(5)
    2. Gene (5)
    3. Frame time (5)
    4. Duration(5)
    5. Vehicle(6)
    6. Obstacle(6)
    7. Target(6)
    8. Generation(6)
    9. Epoch(6)

4.2.Interactions (7)

    1. Unit vector directed from UAV to an X entity(7)
    2. Effective weight to hit Single Entity (8)
    3. Average Effective weight to hit one type of Entities (8)
    4. Effective weight to hit all types of Entities……………………………….(8)

4.3.A Genetic Algorithm (9)

4.4. Cost function (11)

4.4.1. Cost function for Stationary targets (11)

4.4.2. Cost function for moving targets (11)

4.5. Observations (12)

4.6. Parallelization of code (15)

4.6.1. Threads (15)

4.6.2. Parallel life of Genes (15)

4.7. A sample to observe the change in fitness vs generation (16)

4.4.1. Parameters (16)

4.4.1. Simulation of Best gene (17)

5. Conclusion…………………………………………………………………………..……………...(21)

1. Workplannedforupcomingsemesters (22)

References(23)

## Chapter1

### INTRODUCTION

The advances in automation in our age have the potential to disrupt our daily lives. Furthermore, these advancements are helping us develop robust and interacting systems that can tirelessly work for long chunks of time without any human intervention. This technology is leading towards generating some complex models which have sheer coordination that they can outperform humans in many of today&#39;s jobs.

A key field evolving out of automation is the development of Unmanned Aerial vehicles (UAVs) which can think for themselves and make decisions. Machine learning (ML) has come a long way in being able to give this intelligence to non-biological entities by emulating the evolutionary model.

In the twentieth-century research in UAVs was primarily done for military enhancements but due to the eventual decrease in cost per unit of drones, these machines are widely used in civilian applications. Rwanda, a country that is surrounded by a lot of hills has a working drone delivery system that supplies blood and saves many lives. Recent developments suggest the use of drones in places where a man cannot operate such as monitoring volcanos, disaster management, mapping of terrains, real estate, etc.

If multiple UAVs are deployed, it hugely caters to us in optimizing the time for a mission and enhancing the overall cognition. Inspired by the fascinating coordination observed in flocking of birds, schooling of fish, and humans in traffic we try to inject this behavior into our UAVs. A dense group of UAVs share sensory data among

themselves and act as a unit to form &quot;Swarms&quot;. The key objective out of many others for a swarm is to get autonomy in planning the path of every single member of the swarm to avoid obstacles and map targets.

The project which we are doing aims to generate paths for swarms of interacting UAVs that can map the moving targets in an environment filled with moving obstacles given the information of the position of all member UAVs, obstacles, and targets. We further optimize the time taken to map the targets using parallelized genetic algorithms.

## Chapter2

### LITERARYREVIEW

  1.
#### Pathplanning forswarms

####

Swarm, a phenomenon that is widely observed in biological groups, bringing thisphenomenon in the computer models was intensively studied in the late twentiethcentury. The qualitative research done by Braitenberg [1] presented us with how avehicle with a few sensors can perform as a living entity. He perceived vehicles to behaving a plethora of emotions such as aggression, fear, love, hate, etc., His studymadeusrealizethatifwewantourmodelstobehaveascloselyasbiologicalswarms,weneedtoemulatetheir emotions also.

The breakthrough to mimic the flock of birds was provided by Craig Reynold [2] withhis &quot;Boids algorithm&quot;. The algorithm controlled each bird with simple rules named&quot;separation&quot; to keep a safe distance with other members of the swarm, &quot;alignment&quot;to keep the bird moving in the direction same as its immediate neighbors do, and&quot;cohesion&quot; to position the bird at an average of its neighbors. However, by thesesimple rules in a local environment, a much more complicated system emerged when observedasawhole[3].

Improving the Boids algorithms, lattice architecture-based concrete formations ofswarms and their simulations were made[4]. The relatively fixed position of swarmmembers within the swarm&#39;s frame of reference made the group stable andpredictable, which in turn gave us much easier control over emergent swarmingbehavior.

Recently many node-based algorithms are being developed which are not bio-inspiredbutsampletheenvironmentintonodesanddevelopthemostoptimaland collision-free path [5-9]. The biggest point to notice here is that they guaranteethe solution to be the most optimal one but if we are using a bio-inspired approachthenwe cannot.

It is believed that a series of forces of interactions between entities develop a swarm.Thisreportisinspiredbythe worksofT.I.Zohdiinpathplanning[10].Theauthor wisely exploits the use of decaying exponential function to make decisions of UAVwhether it wants to hit or retreat. He then optimizes the time taken for the swarm to mapalltargetsby a geneticalgorithm.

Unmanned aerial vehicle (UAV) is flexible, safe, which makes it used in many different tasks such as exploration, rescue, inspection, and target tracking. A dynamic environment was simulated by Shuang Li. Xi. Fang [11]. It incorporates the formation decision function into the UAV and puts forward a hierarchical early warning mechanism. While simulating UAVs can make their formation according to the environment, and avoid collisions between UAVs and various obstacles which are dynamic.

An attempt was done by T.I.Zohdi in his review where he described how we can tweak cost function to evaluate candidate solutions for mapping moving targets and get the best among them considering the closeness of entities as a parameter[12].

  1.
#### Geneticalgorithms

####

These are the algorithms that are used to optimize a function in a similar way in which we as living beings got optimized over millions of years. Inroads into these concepts were first made by Turing who proposed a &quot;Learning machine&quot; that would mimic evolution [13]. Population-based methods which undergo selection, mutation, and recombination were seen in the early works of Bremermann[14]. The might of genetic algorithms to optimize complex engineering problems was getting noticed after the work proposed by Rechenberg and Schwefe[15-16].

The series of initial genetic algorithm variants aimed to solve a single objective function but the most general problems which we tackle do not always have the best-optimized solution but many with trade-offs among them. Works of Kalyanmoy Deb in the latter part of the twentieth century made the breakthrough into this complex problem and lead to the generation of &quot;Non-Dominated Sorting Genetic Algorithm&quot; which are gradually improved to solve problems that have many objectives of the range of more than ten [17-18]. These algorithms gave us whatever number of Pareto optimal solutions we want but were primarily aimed at selecting the solutions as sparse and distanced as possible for diversity.

Kennedy and Eberhart discovered particle swarm optimization which makes birds flock inside the search space[19]. The Simulated Annealing algorithm is one of the most preferred heuristic methods for solving optimization problems. Kirkpatrick et al. introduced this by inspiring from the annealing procedure of the metal working[20]. Differential evolution is a type of evolutionary algorithm developed by Rainer Storn and Kenneth Price [21] for optimization problems over a continuous domain.

##

##

##

##

##

##

##

##

## Chapter3

### OBJECTIVES

- Optimize the code by parallelizing the execution
- Plot and observe how the fitness of candidates is changing with generation
- Extend the ability of UAVs to map moving targets while avoiding obstacles

## Chapter4

### METHODOLOGY

  1.
##### **Code**  **Framework for Dynamic obstacles and targets**

#####

**_4.1.1 Assumptions_**

- All entities are point masses with a tolerance (radius of the presence of entity)
- Stationary obstacles
- Targets have a path defined by the randomized curve as follows
- A fixed 3D cartesian coordinate system referenced to the ground is used.

_ **4.1.2 Gene** _

A Gene is a set of 15 non-negative fractional constants that define a candidate solution (Eq 1). It is used in all the collective decision-making processes of UAVs in the simulation and defines the behavior of swarm.

![](RackMultipart20211110-4-12do4zp_html_2700fbcdd22685a0.png)

Where x = m/o/t

**Eq 1:** Representation of a 15 member gene candidate used in genetic algorithm

**_4.1.3 Frame time_**

The frame time is the smallest moment where we consider velocity to be constant and no force to be acting. This small unit is used for updating positions of moving UAVs and Targets.

**_4.1.4 Duration_**

Duration is the maximum time for which we simulate all the entities after which the simulation is stopped and the candidate is scored.

    1. _ **Vehicle** _

A vehicle is a representation of a UAV that can sense positions in its surroundings and make a decision to move in a direction accordingly.

    1. **_Obstacle_**

An obstacle is an opaque entity that has its presence to a fixed radius termed tolerance. When it is hit by a UAV then the UAV is switched off.

    1. **_Target_**

Target is a transparent entity that has its presence to a fixed radius termed tolerance. When hit by a UAV the target is set mapped and removed from the further decision-making process of the UAV. Target also has a fixed path that is updated on each frame time (Eq 2).

![](RackMultipart20211110-4-12do4zp_html_ba5271ac632453e6.png)

Here ai bi ci are random positive values less than 1

**Eq 2.** Equations of the path of a target in the space

    1. **_Generation_**

A generation is a group of Genes that simulate simultaneously and get a score. They are then put through mating, Selection, and population regeneration

    1. **_Epoch_**

Epoch is resetting of Generation after the generation has evolved through a fixed number of evolutions in genetic algorithm to diversify the search space for an optimal solution. The evolution through genetic algorithms mostly improves the initial candidate by taking it to a local minima hence a new initial point in the search space ensures we are exploring other local minima and increases our chances of finding the global minima (Fig 1).

![](RackMultipart20211110-4-12do4zp_html_c6f11416fa004f81.png)

**Fig 1.** A representation of a random graph for visualizing search space in 3d coordinates

  1.
##### **Interaction and finding direction**

A UAV or Vehicle can calculate the interaction forces from other entities in space and return an effective direction based on its gene. Member is considered as a UAV in a swarm. Theinteractions between Member and every other entity are classified into threedifferenttypesandcorrespondingconstantsarerepresentedasfollows

NMM(Member–Memberinteractions)

NMT(Member–Targetinteractions)

NMO(Member–Obstacleinteractions)

Note: from here on x = m/o/t to remove redundancy as it is calculated for all three types similarly.

**_4.2.1 Unit vector directed from UAV to an X entity_**

The direction of presence felt by ith UAV from the jth entity is given by calculating the unit vector using Eq 3.

![](RackMultipart20211110-4-12do4zp_html_2c8291d17183db14.png)

![](RackMultipart20211110-4-12do4zp_html_8a49a2b2666d3ec3.png)

**Eq 3.** Formula to find the unit vector from UAV to an X entity

**_4.2.2 Effective weight to hit single entity_**

The numerical value that decides for the UAV to hit the jth entity is multiplied with the direction calculated from Eq(3) as shown in Eq(4).

![](RackMultipart20211110-4-12do4zp_html_bd0ec7dca783a7ca.png)

W𝑥1, 𝑎1, W𝑥2, 𝑎2 – These are constants which are gathered from the gene of the candidate

**Eq 4.** Formula to find the weighted vector from UAV to an X entity

_ **4.2.3 Average effective weight to hit one type of entity** _

All the values obtained from Eq(4) is accumulated as in Eq(5) to form the net value considering all x type of entities

![](RackMultipart20211110-4-12do4zp_html_f86e8604a8817d0e.png)

**Eq 5.** Formula to find Average effective weight to hit all one type of entities

_ **4.2.4 Effective weight to hit all types of entities** _

The weighted sum of all types of interactions is done to get the cumulative interaction for ith member (Eq 6).

![](RackMultipart20211110-4-12do4zp_html_b74f0dcdc197cb9b.png)

𝑊𝑚𝑚, 𝑊𝑚𝑡, 𝑊𝑚𝑜 These are constants that are gathered from the gene of candidate

**Eq 6.** Formula to find Effective weight to hit all entities types

    1. **_Net Direction_**

At the end, the net direction in which UAV decided to move is calculated as in Eq (7)

![](RackMultipart20211110-4-12do4zp_html_2f847a681201ce3f.png)

**Eq 7.** Formula to find net direction

#####

#####

##### **4.3 A Genetic Algorithm**

Thefollowingarethestepsfollowedforimplementing a geneticalgorithm [10].

1. Initialize the positions of targets, obstacles, and swarm members and all theirpropertiestodefinethe problemstatement
2. GenerateNrandomgenesandconsiderthemparents
3. Iterateforallparent genesandgeneratethescore
4. Sortthegenesintheorderoftheirscore
5. Generateoffspringbythefollowingmethod

Goff i=∅1Gpari+(1-∅1)Gpar i+1 (0\&lt;∅1\&lt;1)

Goffi=∅2Gpari+(1-∅2)Gpari+1 (0\&lt;∅2 \&lt;1)

1. Shortlist K genes from Parents and K from offspring and generate N-2Krandomgenes
2. Repeatsteps3-7forQnumberofgenerationsyouwant
3. CollectthebestgeneoutofQgenerations
4. Repeat step 2-9 for E number of resets (i.e., assume all species wiped outeveryQgeneration)
5. Sortcollectionofbestgenesandselectthefirstonetoobtainthemostoptimalspecie

![](RackMultipart20211110-4-12do4zp_html_1af8936765d4038e.jpg)

**Fig 2** : An overview of the framework of algorithm

##### **4.4 Cost Function**

**_4.4.1 Cost Function for Stationary targets_**

The tweaking of gene values can produce infinite species and we apply genetic algorithms which makes these species compete among themselves to hit the minimum of the cost function defined (Eq 8).

![](RackMultipart20211110-4-12do4zp_html_827ab485a17c2fe.png)

A is the fraction of targets not mapped

Tm is the fraction of time utilized

W1, W2are constants

**Eq 8.** Formula to find Cost Function for Stationary targets

Physical meaning

- W1 dictates the importance of targets mapped, if all the targets were mapped the score is significantly reduced hence giving priority to all mapped targets
- W2 differentiates the candidates that map the same number of targets based on the time taken.

**_4.4.2 Cost function for moving targets_**

The previous cost function (Eq 8) considered mapped targets and the time needed to map them. But since here the targets are moving we could potentially lose candidates that were close behind the target. Therefore a cost function that takes into account the closeness of UAVs to targets is defined by T.I.Zohdi (Eq 9).

![](RackMultipart20211110-4-12do4zp_html_90c134d99a5c9c34.png)

- is maximum duration we have set

- is the position of a target

![Shape14](RackMultipart20211110-4-12do4zp_html_343a70f7ca5a21e3.gif) is the position of UAV

**Eq 9.** Formula to find Cost Function for moving targets

Physical meaning

- The numerator follows the closeness of UAVs to the target at every instance of the frame time. It prioritizes candidates that are continuously chasing the targets
- Denominator normalizes the score

##### **4.5 Observations**

At the core of decision-making sits the Gene of a candidate and also the Eq(4) that decides to hit. We observed the following patterns which can be used as modes in further simulations

Case 1: Black Hole

In Eq(4) 𝑤𝑥1 \&gt;𝑤𝑥2 and𝑎1\&gt; 𝑎2

![](RackMultipart20211110-4-12do4zp_html_7d4c72b74c358187.png)

**Fig 3** : A graph representing outputs of Eq (4) of the curve y=0.845\*exp(-0.214\*x)-0.348\*exp(-0.020\*x)

Characteristics:

If the distance is large mild repulsion takes place but as it nears closer Attraction increases exponentially with a decrease in distance

Case 2 : Repulsion

In Eq(4) 𝑤𝑥1 \&lt;𝑤𝑥2 and𝑎1\&gt; 𝑎2 ![](RackMultipart20211110-4-12do4zp_html_dd8dde2fe5288d36.png)

**Fig 4** :A graph representing outputs of Eq (4) of the curve y=0.245\*exp(-0.214\*x)-0.348\*exp(-0.020\*x)

Characteristics:

If the distance is low (near 0) mild repulsion takes place but as it goes further away repulsion increases considerably to a saturation point

Case 3: Equilibrium

In Eq(4) 𝑤𝑥1 \&lt;𝑤𝑥2 and𝑎1\&lt; 𝑎2

![](RackMultipart20211110-4-12do4zp_html_3c8bb9c763b614ec.png)

**Fig 5** :A graph representing outputs of Eq (4) of the curve y=0.355\*exp(-0.014\*x)-0.848\*exp(-0.220\*x)

Characteristics:

If the distance is low (near 0) mild repulsion takes place but if its far Attraction increases considerably to a saturation point. It finally attains an equilibrium point.

Case 4: Attraction

In Eq(4) 𝑤𝑥1 \&gt;𝑤𝑥2 and𝑎1\&lt;𝑎2

![](RackMultipart20211110-4-12do4zp_html_4321e93a9e3167ba.png)

**Fig 6** :A graph representing outputs of Eq (4) of the curve y=0.845\*exp(-0.014\*x)-0.348\*exp(-0.220\*x)

Characteristics:

If the distance is low (near 0) mild attraction takes place but if it&#39;s far Attraction increases considerably to a saturation point.

  1.
##### **Parallelization of Code**

**_4.6.1 Threads_**

In computer science, a thread of execution is the smallest sequence of programmed instructions that can be managed independently by a scheduler, which is typically a part of the operating system [22]. The implementation of threads and processes differs between operating systems, but in most cases, a thread is a component of a process. Multiple threads can exist within one process, executing concurrently and sharing resources such as memory, while different processes do not share these resources. In particular, the threads of a process share its executable code and the values of its dynamically allocated variables and non-thread-local global variables at any given time. [22]

**_4.6.2 Parallel life of genes_**

Two parallelization points can execute in parallel without requiring synchronization (required sequence of execution). One is parallel execution of Epochs and the other is parallel execution of Genes in a generation. It is observed that if the number of threads is more than the number of cores the execution may start to get slower. Therefore to use the threshold number of threads we have decided for parallel execution of genes. (refer Fig 7)

![](RackMultipart20211110-4-12do4zp_html_a7cc3bff04d89439.jpg)

**Fig 7:** A schematic depicting parallel execution of a gene

_Results_

A simulation of 100 UAVs, 200 stationary obstacles, and 80 moving targets took 2 hours 47 minutes to compile for frame time 0.002 and 20 as maximum duration using parallelization but without parallelization, even a simulation of 20 drones, 30 stationary obstacles, and 30 moving targets took 3 hours to compile for frame time 0.002 and 20 as maximum duration.

##### **4.7 A sample to observe the change in fitness vs generation**

**_4.7.1 Parameters taken_**

noOfDrones = 100

noOfObstacles = 200

noOfTargets = 80

frameTime = 0.002

maxDuration = 20

boundary = [500, 500, 500]

toleranceObstacles=0.5

toleranceTargets=1

Positions, velocity, the direction of obstacles, targets were randomly assigned inside the

boundary provided. Drones positions were confined to [5, 5, 5] and assigned randomly (Fig 11). We obtain solutions listed (Table 1)

![](RackMultipart20211110-4-12do4zp_html_77c1565f943b03e3.gif)

**Fig 8:** An overall look at how the score is changing/ optimizing with generation

![](RackMultipart20211110-4-12do4zp_html_c5315a1e690503ff.gif)

**Fig 9:** A closer look at the changes through generations.

Candidate solutions obtained are as shown below

![](RackMultipart20211110-4-12do4zp_html_924e6d5dfb794f28.png)

**Table 1:** A list of best gene candidates recorded

**_4.7.2 Simulation Of Best gene_**

![](RackMultipart20211110-4-12do4zp_html_8c565273085274ff.png)

**Fig 10:** Colors and symbols for entities

### ![](RackMultipart20211110-4-12do4zp_html_d1e4a83560c2c869.png)

### ![](RackMultipart20211110-4-12do4zp_html_cce1fdeddcf2c11b.png)

### ![](RackMultipart20211110-4-12do4zp_html_13c30a28657cda95.png)

### ![](RackMultipart20211110-4-12do4zp_html_84cb0daf6df5fad0.png)

### ![](RackMultipart20211110-4-12do4zp_html_7dab179dc2a46853.png)

### ![](RackMultipart20211110-4-12do4zp_html_fa9dcb1b6b8a9c0e.png)

### ![](RackMultipart20211110-4-12do4zp_html_a60465bce5bac9c0.png) ![](RackMultipart20211110-4-12do4zp_html_a1ea89dc182c2615.png)

### ![](RackMultipart20211110-4-12do4zp_html_d46879024be519e1.png)

###

**Fig 11:** A collection of snapshots from the simulation done to depict the mapping of moving targets by a swarm of drones.

## Chapter5

### Conclusion

- The parallelization has significantly improved the performance thereby reducing the time required from ~ 3 hours to 27 minutes.

- The reset after every epoch makes code to start a gene from a different random point on search space and therefore increasing the chance to obtain a global minimum

- The cost function defined for moving targets does not take into account the number of drones wasted in collision with obstacles

- It is important to consider the closeness of UAVs to targets when the targets are moving to get better candidate genes

##

##

##

##

##

##

##

##

##

##

##

##

##

##

##

## Chapter6

### Workplanfor upcomingsemesters

- Information sharing forms the core of emergent swarm intelligence; hence wewant to have an idea on how and in what form that information can be sharedbetweenUAVs andimplementit
- For the model to perform in the physical world, we aim to plan velocity variation of UAV in traversing the path and do apracticalsession

### References

  1. Braitenberg, V. (1986). Vehicles: Experiments in Synthetic Psychology (58042nd ed.).BradfordBooks.
  2. Reynolds, C. W. (1987). Flocks, herds, and schools: A distributed behavioral model. ACMSIGGRAPHComputerGraphics,21(4),25–34.[https://doi.org/10.1145/37402.37406](https://doi.org/10.1145/37402.37406)
  3. Craig W. Reynolds. Boids, Background, and Update.Retrieved October 5, 2020, fromhttps://cs.stanford.edu/people/eroberts/courses/soco/projects/2008-09/modeling-natural- systems/boids.html.
  4. Wang, J., Zhao, H., Bi, Y., Shao, S., Liu, Q., Chen, X., Zeng, R., Wang, Y., &amp; Ha, L. (2014). AnImproved Fast Flocking Algorithm with Obstacle Avoidance for Multiagent DynamicSystems. Journal of Applied Mathematics, 2014, 1–13.[https://doi.org/10.1155/2014/659805](https://doi.org/10.1155/2014/659805)
  5. Karaman, S., &amp; Frazzoli, E. (2011). Sampling-based algorithms for optimal motionplanning. The International Journal of Robotics Research, 30(7), 846–894.https://doi.org/10.1177/0278364911406761
  6. Yang, Kwangjin &amp; Sukkarieh, Salah. (2008). Real-time continuous curvature pathplanning of UAVs in cluttered environments. _5th International Symposium on__Mechatronics and Its Applications 2008,_ 1 - 6.[https://doi.org/10.1109/isma.2008.4648836](https://doi.org/10.1109/isma.2008.4648836).
  7. Yan, F., Liu, YS. &amp; Xiao, JZ. Path Planning in Complex 3D Environments Using aProbabilistic Roadmap Method. Int. J. Autom. Comput. 10, 525–533 (2013).https://doi.org/10.1007/s11633-013-0750-9
  8. Musliman, I. A., Rahman, A. A., Coors V. Implementing 3D network analysis in 3D-GIS[J].InternationalArchivesof ISPRS,2008,37(partB).
  9. De Filippis, L., Guglieri, G., &amp; Quagliotti, F. (2011). Path Planning Strategies for UAVs in3D Environments. Journal of Intelligent &amp; Robotic Systems, 65(1–4), 247–264.[https://doi.org/10.1007/s10846-011-9568-2](https://doi.org/10.1007/s10846-011-9568-2)
  10. Zohdi, T. I. (2019). The Game of Drones: rapid agent-based machine-learning models formulti-UAV path planning. Computational Mechanics, 65(1), 217–228.https://doi.org/10.1007/s00466-019-01761-9
  11. Shuang Li, Xi Fang, A modified adaptive formation of UAV swarm by pigeon flock behavior within local visual field, Aerospace Science and Technology, Volume 114, 2021, 106736, ISSN 1270-9638, [https://doi.org/10.1016/j.ast.2021.106736](https://doi.org/10.1016/j.ast.2021.106736).
  12. Zohdi TI (2018) Multiple UAVs for Mapping: a review of basic modeling, simulation and applications. Ann Rev Environ Resour. https://doi.org/10.1146/annurev-environ-102017-025912
  13. TURING, A. M. (1950). I.—COMPUTING MACHINERY AND INTELLIGENCE. Mind, LIX(236),433–460.https://doi.org/10.1093/mind/lix.236.433
  14. Bremermann,H.J.,1962,OptimizationThroughEvolution andRecombination in SelfOrganizingSystems.Yovits, JacobiandGoldstein,(eds.)SpartanBooks,Washington,D.C.
  15. Rechenberg,&quot;Cyberneticsolutionpathofanexperimentalproblem,&quot;RoyalAircraft

Establishment,LibrarytranslationNo.1122,Farnborough,Hants.,U.K.,Aug.1965.

  1. H.-P. Schwefel, &quot;Projekt MHD-Staustrahlrohr: Experimentelle Optimierung einerZweiphasend¨use, Teil I,&quot; Technischer Bericht 11.034/68,35, AEG Forschungsinstitut,Berlin,Germany, Oct. 1968
  2. Deb, K., Pratap, A., Agarwal, S., &amp; Meyarivan, T. (2002). A fast and elitist multiobjectivegenetic algorithm: NSGA-II. _IEEE Transactions on Evolutionary Computation_, _6_(2), 182–197.https://doi.org/10.1109/4235.996017
  3. Deb, K., &amp; Jain, H. (2014). An Evolutionary Many-Objective Optimization Algorithm UsingReference-Point-Based Nondominated Sorting Approach, Part I: Solving Problems WithBox Constraints. _IEEE Transactions on Evolutionary Computation_, _18_(4), 577–601.https://doi.org/10.1109/tevc.2013.2281535
  4. J. Kennedy and R. Eberhart, &quot;Particle swarm optimization,&quot; _Proceedings of ICNN&#39;95 - International Conference on Neural Networks_, 1995, pp. 1942-1948 vol.4, https://doi.org 10.1109/ICNN.1995.488968.
  5. S. Kirkpatrick, C. Gelatt, Jr., and M. Vecchi, Optimization by simulated annealing, Science, Vol220, No 4598, May 1983, pp. 671-680.
  6. Storn, R., Price, K. Differential Evolution – A Simple and Efficient Heuristic for global Optimization over Continuous Spaces. Journal of Global Optimization 11, 341–359 (1997). https://doi.org/10.1023/A:1008202821328
  7. [https://en.wikipedia.org/wiki/Thread\_(computing](https://en.wikipedia.org/wiki/Thread_(computing)) accessed on 20/04/21 20:12

![Shape7](RackMultipart20211110-4-12do4zp_html_e7420c1e96fd47be.gif)

i | Page
