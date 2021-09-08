#include "Swarm.h"

#include <iostream>

Swarm::Swarm(vector <double> gene,vector <VehicleData*> dronesData)
{
    initMembers(dronesData,gene);
}

Swarm::~Swarm()
{
    //dtor
}

void Swarm:: initMembers(vector <VehicleData*> dronesData,vector <double> gene){
    for (int i=0;i<dronesData.size();i++){
        this->drones.push_back(new Vehicle(dronesData[i],gene));
    }
}



void Swarm::updateSwarm(double frameTime){

    for (int i=0;i<this->drones.size();i++){

        this->drones[i]->makeDecision();
        this->drones[i]->updateState(frameTime);
    }

    updatePositions();
}

void Swarm::updatePositions(){
    for (int i=0;i<this->drones.size();i++){

        this->membersPosition[i]=this->drones[i]->position;
    }
}

void Swarm::senseArena(vector<vector<double>> membersPosition,vector<vector<double>> obstaclesPosition,vector<vector<double>> targetsPosition){
    for (int i=0;i<this->drones.size();i++){
        this->drones[i]->senseSurroundings(membersPosition,obstaclesPosition,targetsPosition);
    }

    this->membersPosition=membersPosition;//doubtful step may lea to cycle
}

