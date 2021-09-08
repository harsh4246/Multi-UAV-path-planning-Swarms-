#include "VehicleData.h"

VehicleData::VehicleData(double weight, double maxForce, double maxVel, double tolerance, vector<double> position,
                    vector<double> velocity, vector<double> direction)
{
    this->weight=weight;
    this->maxForce=maxForce;
    this->maxVel=maxVel;
    this->tolerance=tolerance;
    this->position=position;
    this->velocity=velocity;
    this->direction=direction;
}

VehicleData::~VehicleData()
{
    //dtor
}
