#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include "Vehicle.h"

using namespace std;

class Generation
{
    public:
        Generation(vector<vector<double>> droneGenes,vector<vector<double>> obstacleGenes,vector<vector<double>> targetsGenes,
                    vector <Vehicle*> drones, vector <Vehicle*> obstacles,
                    vector<Vehicle*> targets, double frameTime, double duration);
        virtual ~Generation();

        vector<vector<double>> droneGenes;
        vector<vector<double>> obstacleGenes;
        vector<vector<double>> targetsGenes;

        vector <Vehicle*> drones;
        vector <Vehicle*> obstacles;
        vector<Vehicle*> targets;
        double frameTime;
        double duration;

        void simulateGeneration();

    protected:

    private:
};

#endif // GENERATION_H
