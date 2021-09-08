#include "target.h"
#include <math.h>

target::target( double* position, double tolerance)
{
    for (int i=0;i<3;i++){
        this->position[0]=position[0];
        this->position[1]=position[1];
        this->position[2]=position[2];

    }

    this->tolerance=tolerance;

}


double * target:: getPosition() {
    return this->position;
}

void target::apply_force(double frameTime){
            double weight=this->Getweight();
            double* direction=this->Getdirection();
            double force=GetmaxForce();
            double accMultiplier=force/weight;
            double acceleration[3];

            for (int i=0;i<3;i++){
                acceleration[i]=this->direction[i]*accMultiplier;
                this->velocity[i]=this->velocity[i]+acceleration[i]*frameTime;
            }

            double magOfVel= magnitudeOfVector(this->Getvelocity());
            if(magOfVel>this->maxVel){
                for(int i=0;i<3;i++){
                    this->velocity[i]=((this->velocity[i])/magOfVel)*this->maxVel;
                }
            }

            for (int i=0;i<3;i++){
                this->position[i]=this->position[i]+this->velocity[i]*frameTime;
            }

        }

double target:: magnitudeOfVector(double * Vector){
            double sum=0;
            for (int i=0;i<3;i++){
                sum+=Vector[i]*Vector[i];
            }
            //cout<<"Magnitude caculated "<<sqrt(sum)<<endl;
            return sqrt(sum);

        }
