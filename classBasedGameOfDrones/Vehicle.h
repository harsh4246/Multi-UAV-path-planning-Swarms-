#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include "VehicleData.h"
using namespace std;

class Vehicle
{
    public:
        Vehicle(VehicleData* data, vector<double> gene);
        bool isAlive;
        double tolerance;
        double weight;
        double maxForce;
        double maxVel;
        vector<double> Nmt;
        vector<double> Nmo;
        vector<double> Nmm;
        vector<double> gene;
        vector<double> position;
        vector<double> velocity;
        vector<double> direction;
        vector<vector<double>> membersSensed;
        vector<vector<double>> obstaclesSensed;
        vector<vector<double>> targetsSensed;




        //actions
        virtual void senseSurroundings(vector<vector<double>> membersSensed,
                               vector<vector<double>> obstaclesSensed,
                               vector<vector<double>> targetsSensed); // update the  sensed variables

        virtual void makeDecision(); // update the direction from all interactions
        virtual void updateState(double frameTime); //change the position velocity



        //utility
        double magnitudeOfVector(vector<double> Vector);
        void refresh();
            //the interactions
        virtual void T_interaction();
        virtual void O_interaction();
        virtual void M_interaction();
};

#endif // VEHICLE_H
