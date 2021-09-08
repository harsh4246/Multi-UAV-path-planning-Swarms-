#include "Generation.h"

Generation::Generation(vector<vector<double>> droneGenes,vector<vector<double>> obstacleGenes,vector<vector<double>> targetsGenes,
                    vector <Vehicle*> drones, vector <Vehicle*> obstacles,
                    vector<Vehicle*> targets, double frameTime, double duration)
{
    this->droneGenes=droneGenes;
    this->obstacleGenes=obstacleGenes;
    this->targetsGenes=targetsGenes;

    this->duration=duration;
    this->frameTime=frameTime;

    this->drones=drones;
    this->obstacles=obstacles;//assuming obstacles and targets have already built gene in genetic algorithm
    this->targets=targets;//assuming obstacles and targets have already built gene in genetic algorithm

}

Generation::~Generation()
{
    //dtor
}

void Generation::simulateGeneration(){

}
