#include "Arena.h"
#include <cmath>
#include <iostream>
using namespace std;


Arena::Arena(vector<double> droneGene,vector<double> obstacleGene,vector<double> targetGene,vector <VehicleData*> dronesData,
                vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData, double frameTime, double duration)
{
    this->droneSwarm=new Swarm(droneGene,dronesData);
    this->obstacleSwarm=new Swarm(obstacleGene,obstaclesData);
    this->targetSwarm=new Swarm(targetGene,targetsData);

    this->duration=duration;
    this->frameTime=frameTime;
    this->totalTargets=targetsData.size();
    initPositions(dronesData,obstaclesData,targetsData);

}

Arena::~Arena()
{
    //dtor
}

double Arena:: magnitudeOfVector(vector<double> Vector){
            double sum=0;
            for (int i=0;i<3;i++){
                sum+=Vector[i]*Vector[i];
            }
            return sqrt(sum);
        }


void Arena:: simulateArena(){
    double currTime=0.0;


    while(currTime<duration){

            //sense surroundings
        this->droneSwarm->senseArena(this->dronesPosition,this->obstaclesPosition,this->targetsPosition);
        //this->obstacleSwarm->updateArena();  // not required as these are not moving
        //this->targetSwarm->updateArena();

        //get in action
        this->droneSwarm->updateSwarm(this->frameTime);

        //this->obstacleSwarm->updateSwarm();
        //this->targetSwarm->updateSwarm();
        this->dronesPosition=this->droneSwarm->membersPosition;//updating the positions for sensing
        for (int i=0;i<3;i++){
            cout<<this->dronesPosition[0][i]<<" ";
        }
        cout<<endl;

        checkCollisions();

        //increase time diration
        currTime+=this->frameTime;

        if(this->targetsPosition.size()==0)break;


    }
        updateScore(currTime);
}

void Arena:: updateScore(double currTime){
    //note we have considered the parameters to be already decided hence hard coded
    this->score = 1*(this->targetsPosition.size()/this->totalTargets) + 0.001;
    this->score*=currTime/this->duration;
}

void Arena:: checkCollisions(){
    //the drones will switch off themselves if they are hit obstacles
    for(int i=0;i<this->dronesPosition.size();i++){
        for (int j=0;j<this->obstaclesPosition.size();j++){
            vector<double> distanceVector(3,0);
            for (int m=0;m<3;m++){
                distanceVector[m]=this->dronesPosition[i][m]-this->obstaclesPosition[j][m];
            }
            double distance=magnitudeOfVector(distanceVector);
            if(distance< this->droneSwarm->drones[i]->tolerance+this->obstacleSwarm->drones[j]->tolerance){
                this->droneSwarm->drones[i]->isAlive=false;
                this->dronesPosition.erase(dronesPosition.begin()+i);
                i--;
                break;
            }
        }
    }

    //the targets will switch off themselves if they are hit drones
    for(int i=0;i<this->dronesPosition.size();i++){
        for (int j=0;j<this->targetsPosition.size();j++){
            vector<double> distanceVector(3,0);
            for (int m=0;m<3;m++){
                distanceVector[m]=this->dronesPosition[i][m]-this->targetsPosition[j][m];
            }
            double distance=magnitudeOfVector(distanceVector);
            if(distance< this->droneSwarm->drones[i]->tolerance+this->targetSwarm->drones[j]->tolerance){
                this->targetSwarm->drones[j]->isAlive=false;
                this->targetsPosition.erase(targetsPosition.begin()+j);
                j--;
            }
        }
    }
}



void Arena:: initPositions(vector <VehicleData*> dronesData, vector <VehicleData*> obstaclesData,vector <VehicleData*> targetsData){
    for (int i=0;i<dronesData.size();i++){
        this->dronesPosition.push_back(dronesData[i]->position);
    }
    for (int i=0;i<obstaclesData.size();i++){
        this->obstaclesPosition.push_back(obstaclesData[i]->position);
    }
    for (int i=0;i<targetsData.size();i++){
        this->targetsPosition.push_back(targetsData[i]->position);
    }
}
