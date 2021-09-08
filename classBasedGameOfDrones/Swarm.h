#ifndef SWARM_H
#define SWARM_H

#include "Vehicle.h"
#include "VehicleData.h"
#include "Drone.h"
#include <vector>

class Swarm
{
    public:
        Swarm(vector <double> gene,vector <VehicleData*> dronesData);
        virtual ~Swarm();
        vector <Vehicle*> drones; // seriously want to change its name to mambers
        vector<vector<double>> membersPosition;

        //actions
        void updateSwarm(double frameTime);
        void senseArena(vector<vector<double>> membersPosition,vector<vector<double>> obstaclesPosition,vector<vector<double>> targetsPosition);

        //utility
        void updatePositions();
        void initMembers(vector <VehicleData*> dronesData,vector <double> gene);

    protected:

    private:
};

#endif // SWARM_H
