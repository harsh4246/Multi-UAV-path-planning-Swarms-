#include <iostream>
#include "vehicle.h"
#include <vector>
#include <fstream>




using namespace std;

int main()
{
    // the problem definition is taken, i.e., the parameters on which our code runs


    int numDrones;
    int numObstacles;
    int numTargets;


    vector <vehicle> swarm;
    vector <target> targets;
    vector <obstacle> obstacles;



    double gene[15];

    cout<<"Enter the gene array of size 15"<<endl;

    for(int i=0;i<15;i++){
        cin>>gene[i];
    }


    cout<<"Enter numDrones numObstacles numTargets "<<endl;
    cin>>numDrones>>numObstacles>>numTargets;



    for (int i=0;i<numDrones;i++){
        double weight;
        cout<<"Enter weight of drone"<<endl;
        cin>>weight;

        int maxForce;
        cout<<"enter the max force drone can apply"<<endl;
        cin>>maxForce;

        double maxVel;
        cout<<"Enter the max velocity drone can sustain"<<endl;
        cin>>maxVel;

        double position[3];
        cout<<"Enter Drone position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];

        double velocity[3];
        cout<<"Enter Drone current velocity in space separated triads"<<endl;
        cin>>velocity[0]>>velocity[1]>>velocity[2];

        double direction[3];
        cout<<"Enter the current direction in which velocity is present"<<endl;
        cin>> direction[0]>>direction[1]>>direction[2];


        swarm.push_back(vehicle(false, weight,maxForce, maxVel, position, velocity, direction ));
    }



    ofstream obstaclefile("obstacles.dat", ios::app);




    for (int i=0;i<numObstacles;i++){
        double position[3];
        cout<<"Enter Obstacle position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];
        obstaclefile<<position[0]<<" "<<position[1]<<" "<<position[2]<<endl;


        double tolerance;
        cout<<"Enter the tolerance that the obstacle has"<<endl;
        cin>>tolerance;

        obstacles.push_back(obstacle(position , tolerance));

    }

    obstaclefile.close();


    ofstream targetfile("targets.dat", ios::app);

    for (int i=0;i<numTargets;i++){
        double position[3];
        cout<<"Enter target position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];
        targetfile<<position[0]<<" "<<position[1]<<" "<<position[2]<<endl;

        double tolerance;
        cout<<"Enter the tolerance that the target has"<<endl;
        cin>>tolerance;

        targets.push_back(target( position, tolerance));
    }

    targetfile.close();


    cout<<"Enter the boundary values simulation"<<endl;
    int boundary[3];
    for (int i=0;i<3;i++){
        cin>>boundary[i];
    }

    double frameTime;
    cout<<"Enter the frame time you want to simulate the drone environment"<<endl;
    cin>>frameTime;

    double currTime=0.0;


    double duration;
    cout<<"Enter the duration you want to simulate"<<endl;
    cin>>duration;

    ofstream myfile("sim.dat", ios::app);
    ofstream movingtargetfile("movingTargets.dat", ios::app);



    while(currTime<duration){
        if(targets.size()==0){
            cout<<"all targets mapped"<<endl;
            break;
        }

        for (int i=0;i<numDrones;i++){
            double * dir = swarm[i].Getposition();
            myfile<<dir[0]<<" "<<dir[1]<<" "<<dir[2]<<endl;
        }
        myfile<<endl<<endl;

        for (int i=0;i<targets.size();i++){
            movingtargetfile<<targets[i].position[0]<<" "<<targets[i].position[1]<<" "<<targets[i].position[2]<<endl;
        }
        movingtargetfile<<endl<<endl;

        for (int i=0;i<numDrones;i++){
            if(swarm[i].hit){
                continue;
            }
            swarm[i].Aim(swarm,targets,obstacles,gene);
        }
        for (int i=0;i<numDrones;i++){
            if(swarm[i].hit){
                continue;
            }
            swarm[i].Action(duration,frameTime,boundary);
        }
        for (int i=0;i<targets.size();i++){
                    targets[i].action(frameTime);
                }
        currTime+=frameTime;
    }



    cout<<currTime/frameTime - 1;


    for (int i=0;i<numDrones;i++){
            double * dir = swarm[i].Getposition();
            myfile<<dir[0]<<" "<<dir[1]<<" "<<dir[2]<<endl;
        }

    myfile.close();





    cout<<"thank you"<<endl;


    return 0;
}
