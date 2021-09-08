#ifndef ARENA_H
#define ARENA_H

#include "Swarm.h"
#include "VehicleData.h"



class Arena
{
    public:
        Arena( vector<double> droneGene,vector<double> obstacleGene,vector<double> targetGene,vector <VehicleData*> dronesData,
                vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData, double frameTime, double duration);
        virtual ~Arena();

        int targetsRemaining;
        int timeRemaining;

        int totalTargets;
        double frameTime;
        double duration;
        double score=1.001;

        //genes
        vector<double> droneGene;
        vector<double> obstacleGene;
        vector<double> targetGene;


        //the tri-services
        Swarm* droneSwarm;
        Swarm* obstacleSwarm;
        Swarm* targetSwarm;

        //positions
        vector<vector<double>> dronesPosition;
        vector<vector<double>> obstaclesPosition;
        vector<vector<double>> targetsPosition;


        void simulateArena();
        void updateScore(double currTime);


        //utility
        void checkCollisions();
        void initPositions(vector <VehicleData*> dronesData, vector <VehicleData*> obstaclesData,vector <VehicleData*> targetsData);
        double magnitudeOfVector(vector<double> Vector);

    protected:

    private:
};

#endif // ARENA_H
