#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <math.h>
#include <vector>
#include "target.h"
#include "obstacle.h"

using namespace std;

class vehicle
{
    private:

        double weight;
        double maxForce;
        double maxVel;
        double position[3];
        double velocity[3];
        double direction[3];

        double* T_interaction( vector <target> &targets, double* design, double* Nmt);
        double* O_interaction( vector <obstacle> &obstacles, double* design, double* Nmo);
        double* M_interaction(vector <vehicle> &swarm, double* design, double* Nmm);


        double Getweight() { return weight; }
        void Setweight(double val) { weight = val; }

        double GetmaxVel() { return maxVel; }
        void SetmaxVel(double val) { maxVel = val; }

        double GetmaxForce() { return maxForce; }
        void SetmaxForce(double val) { maxForce = val; }

        void Setposition(double* val)
        {
             this->position[0] = val[0];
             this->position[1] = val[1];
             this->position[2] = val[2];
        }
        double* Getvelocity() { return velocity; }
        void Setvelocity(double* val)
        {
             this->velocity[0] = val[0];
             this->velocity[1] = val[1];
             this->velocity[2] = val[2];
        }

        void Setdirection(double* val)
        {
             this->direction[0] = val[0];
             this->direction[1] = val[1];
             this->direction[2] = val[2];
        }
        void apply_force(double frameTime);

        double magnitudeOfVector(double * Vector);


    public:
        bool hit;

        double* Getdirection() { return direction; }

        vehicle(bool isHit, double weight, double maxForce, double maxVel, double* position, double* velocity, double* direction);

        void Action( double timeout, double frameTime, int* boundary ){
                     apply_force(frameTime);
                    }

        void Aim(  vector <vehicle> &swarm, vector <target> &targets , vector <obstacle> &obstacles, double* gene);

        double* Getposition() { return position; }
};

#endif // VEHICLE_H
