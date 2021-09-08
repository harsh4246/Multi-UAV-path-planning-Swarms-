#include "Vehicle.h"
#include <cstdlib>
#include <cmath>
#include <climits>
#include <iostream>

Vehicle::Vehicle(VehicleData* data, vector<double> gene)
{
    this->isAlive=true;
    this->gene=gene;
    this->tolerance=data->tolerance;
    this->weight=data->weight;
    this->maxForce=data->maxForce;
    this->maxVel=data->maxVel;
    this->position=data->position;
    this->direction=data->direction;
    this->velocity=data->velocity;

    for (int i=0;i<3;i++){
        this->Nmm.push_back(0.0);
        this->Nmo.push_back(0.0);
        this->Nmt.push_back(0.0);
    }
}

void Vehicle:: refresh(){
    for (int i=0;i<3;i++){
        this->Nmm[i]=0.0;
        this->Nmo[i]=0.0;
        this->Nmt[i]=0.0;
    }
}


double Vehicle:: magnitudeOfVector(vector<double> Vector){
            double sum=0;
            for (int i=0;i<3;i++){
                sum+=Vector[i]*Vector[i];
            }
            return sqrt(sum);
        }



void Vehicle :: T_interaction()
        {
            for(int j=0;j<this->targetsSensed.size();j++){
                //if(this->targetsSensed[j]->isAlive==false)continue;
                vector<double> distanceVector(3,0);
                double distance;
                for (int i=0;i<3;i++){
                    distanceVector[i]=this->targetsSensed[j][i]-this->position[i];
                }
                distance=this->magnitudeOfVector(distanceVector);
                for (int i=0;i<3;i++){
                    distanceVector[i]=distanceVector[i]/distance;
                }

                double Desire=this->gene[3]*exp(-1*this->gene[9]*distance)-this->gene[4]*exp(-1*this->gene[10]*distance);
                for(int i=0;i<3;i++){
                    this->Nmt[i]+=Desire*distanceVector[i];
                }
            }
        }

void Vehicle:: O_interaction()
        {
            for(int j=0;j<this->obstaclesSensed.size();j++){
                vector<double> distanceVector(3,0);
                double distance;
                for (int i=0;i<3;i++){
                    distanceVector[i]=this->obstaclesSensed[j][i]-this->position[i];
                }
                distance=this->magnitudeOfVector(distanceVector);
                for (int i=0;i<3;i++){
                    distanceVector[i]=distanceVector[i]/distance;
                }

                double Desire=this->gene[5]*exp(-1*this->gene[11]*distance)-this->gene[6]*exp(-1*this->gene[12]*distance);
                for(int i=0;i<3;i++){
                    this->Nmo[i]+=Desire*distanceVector[i];
                }
            }
        }

void Vehicle:: M_interaction()
        {
            for(int j=0;j<this->membersSensed.size();j++){
                //if(this->membersSensed[j]->isAlive==false)continue;
                vector<double> distanceVector(3,0);
                double distance;
                for (int i=0;i<3;i++){
                    distanceVector[i]=this->membersSensed[j][i]-this->position[i];
                }
                distance=this->magnitudeOfVector(distanceVector);
                if(distance==0.0){
                    continue;
                }
                for (int i=0;i<3;i++){
                    distanceVector[i]=distanceVector[i]/distance;
                }
                double Desire=this->gene[7]*exp(-1*this->gene[13]*distance)-this->gene[8]*exp(-1*this->gene[14]*distance);
                for(int i=0;i<3;i++){
                    this->Nmm[i]+=Desire*distanceVector[i];
                }
            }
        }

//doubtful implementation to be checked
void Vehicle::senseSurroundings(vector<vector<double>> membersSensed,
                               vector<vector<double>> obstaclesSensed,
                               vector<vector<double>> targetsSensed)  //consider this as radar from arena
{
    this->membersSensed=membersSensed;
    this->obstaclesSensed=obstaclesSensed;
    this->targetsSensed=targetsSensed;
}


void Vehicle::makeDecision(){//update direction
    refresh();
    M_interaction();
    O_interaction();
    T_interaction();
    vector<double> Ntot(3,0);
    for (int i=0;i<3;i++){
        Ntot[i] = this->gene[0]*this->Nmt[i] + this->gene[1]*this->Nmo[i] + this->gene[2]*this->Nmm[i];
    }

    double magnitude=magnitudeOfVector(Ntot);
    for (int i=0;i<3;i++){
        this->direction[i]=Ntot[i]/magnitude;
    }

}

void Vehicle:: updateState(double frameTime){
    double accMultiplier=this->maxForce/this->weight;
    for (int i=0;i<3;i++){
        this->velocity[i]=this->velocity[i]+accMultiplier*this->direction[i]*frameTime;
        this->position[i]=this->position[i]+this->velocity[i]*frameTime;
    }

    //checking velocity out of bounds
    double magnitude=magnitudeOfVector(this->velocity);
    if(magnitude>this->maxVel){
        for (int i=0;i<3;i++){
            this->velocity[i]=this->maxVel*this->velocity[i]/magnitude;
        }
    }
}



