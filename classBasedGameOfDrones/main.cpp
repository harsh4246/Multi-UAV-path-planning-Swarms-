#include <iostream>
#include "Vehicle.h"
#include "Drone.h"
#include "Obstacle.h"
#include "Target.h"
#include <cstdlib>
#include <ctime>

#include "Arena.h"
using namespace std;

void takeManualInput(vector<VehicleData*> &dronesData,vector<VehicleData*> &obstaclesData,vector<VehicleData*> &targetsData){
    int numDrones;
    int numObstacles;
    int numTargets;
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

        vector<double> position(3,0);
        cout<<"Enter Drone position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];

        vector<double> velocity(3,0);
        cout<<"Enter Drone current velocity in space separated triads"<<endl;
        cin>>velocity[0]>>velocity[1]>>velocity[2];

        vector<double> direction(3,0);
        cout<<"Enter the current direction in which velocity is present"<<endl;
        cin>> direction[0]>>direction[1]>>direction[2];

        double tolerance;
        cout<<"Enter the tolerance that the drone has"<<endl;
        cin>>tolerance;

        dronesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }


    for (int i=0;i<numObstacles;i++){
        double weight;
        cout<<"Enter weight of obstacle"<<endl;
        cin>>weight;

        int maxForce;
        cout<<"enter the max force obstacle can apply"<<endl;
        cin>>maxForce;

        double maxVel;
        cout<<"Enter the max velocity obstacle can sustain"<<endl;
        cin>>maxVel;

        vector<double> position(3,0);
        cout<<"Enter obstacle position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];

        vector<double> velocity(3,0);
        cout<<"Enter obstacle current velocity in space separated triads"<<endl;
        cin>>velocity[0]>>velocity[1]>>velocity[2];

        vector<double> direction(3,0);
        cout<<"Enter the current direction in which velocity is present"<<endl;
        cin>> direction[0]>>direction[1]>>direction[2];

        double tolerance;
        cout<<"Enter the tolerance that the obstacle has"<<endl;
        cin>>tolerance;

        obstaclesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }

    for (int i=0;i<numTargets;i++){
        double weight;
        cout<<"Enter weight of target"<<endl;
        cin>>weight;

        int maxForce;
        cout<<"enter the max force target can apply"<<endl;
        cin>>maxForce;

        double maxVel;
        cout<<"Enter the max velocity target can sustain"<<endl;
        cin>>maxVel;

        vector<double> position(3,0);
        cout<<"Enter target position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];

        vector<double> velocity(3,0);
        cout<<"Enter target current velocity in space separated triads"<<endl;
        cin>>velocity[0]>>velocity[1]>>velocity[2];

        vector<double> direction(3,0);
        cout<<"Enter the current direction in which velocity is present"<<endl;
        cin>> direction[0]>>direction[1]>>direction[2];

        double tolerance;
        cout<<"Enter the tolerance that the target has"<<endl;
        cin>>tolerance;

        targetsData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }
}

void takeAutoInput(vector<VehicleData*> &dronesData,vector<VehicleData*> &obstaclesData,vector<VehicleData*> &targetsData){
    int numDrones;
    int numObstacles;
    int numTargets;
    cout<<"Enter numDrones numObstacles numTargets "<<endl;
    cin>>numDrones>>numObstacles>>numTargets;

    for (int i=0;i<numDrones;i++){
        double weight=rand()%100;
        int maxForce=rand()%100000 +100000;
        double maxVel=rand()%1000 +500;

        vector<double> position(3,0);
        for (int i=0;i<3;i++){
            position[i]=((double)rand()/(double)RAND_MAX)*5;
        }

        vector<double> velocity(3,0);
        for (int i=0;i<3;i++){
            velocity[i]=0;
        }
        vector<double> direction(3,0);
        for (int i=0;i<3;i++){
            direction[i]=0;
        }
        double tolerance=((double)rand()/(double)RAND_MAX)*2;
        dronesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }

    cout<<"please provide a max values of coordinates"<<endl;
    vector<double> boundary(3,0);
    for (int i=0;i<3;i++){
        cin>>boundary[i];
    }


    for (int i=0;i<numObstacles;i++){
        double weight=0;
        int maxForce=0;
        double maxVel=0;

        vector<double> position(3,0);
        for (int i=0;i<3;i++){
            position[i]=((double)rand()/(double)RAND_MAX)*boundary[i];
        }

        vector<double> velocity(3,0);
        for (int i=0;i<3;i++){
            velocity[i]=0;
        }
        vector<double> direction(3,0);
        for (int i=0;i<3;i++){
            direction[i]=0;
        }
        double tolerance=((double)rand()/(double)RAND_MAX)*2;
        obstaclesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));
    }

    for (int i=0;i<numTargets;i++){
        double weight=0;
        int maxForce=0;
        double maxVel=0;

        vector<double> position(3,0);
        for (int i=0;i<3;i++){
            position[i]=((double)rand()/(double)RAND_MAX)*boundary[i];
        }

        vector<double> velocity(3,0);
        for (int i=0;i<3;i++){
            velocity[i]=0;
        }
        vector<double> direction(3,0);
        for (int i=0;i<3;i++){
            direction[i]=0;
        }
        double tolerance=((double)rand()/(double)RAND_MAX)*2;
        targetsData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));
    }
}

int main()
{
    vector<VehicleData*> dronesData;
    vector<VehicleData*> obstaclesData;
    vector<VehicleData*> targetsData;
    cout<<"press 'y' and enter if you want to give manual input"<<endl;
    cout<<"press 'n' and enter if you want to allow automatic input"<<endl;
    char x;
    cin>>x;
    if(x=='y'||x=='Y'){
        takeManualInput(dronesData,obstaclesData,targetsData);
    }
    else takeAutoInput(dronesData,obstaclesData,targetsData);

    vector <double> dronegene= {
4.86588,
3.63601,
8.04724,
0.900244,
0.184334,
0.526715,
0.468357,
0.9577382,
0.225181,
0.0246987,
0.0876617,
0.649437,
0.362262,
0.716265,
0.330391};

vector <double> obstacleGene(15,0);
vector <double> targetGene(15,0);

    double frameTime;
    cout<<"please enter the frame time"<<endl;
    cin>>frameTime;

    double duration;
    cout<<"please enter the maxTime/durattion"<<endl;
    cin>>duration;

cout<<targetsData.size()<<endl;
    Arena arena(dronegene,obstacleGene,targetGene,dronesData,obstaclesData,targetsData,frameTime,duration);
    cout<<arena.score<<endl;
    arena.simulateArena();
    cout<<arena.score<<endl;

    return 0;
}
