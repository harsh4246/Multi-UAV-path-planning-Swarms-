#include "vehicle.h"
#include <vector>
#include <math.h>


using namespace std;

vehicle::vehicle(bool isHit, double weight, double maxForce, double maxVel, double* position, double* velocity, double* direction){
            this->position[0]=position[0];
            this->position[1]=position[1];
            this->position[2]=position[2];

            this->velocity[0]=velocity[0];
            this->velocity[1]=velocity[1];
            this->velocity[2]=velocity[2];

            this->weight=weight;

            this->direction[0]=direction[0];
            this->direction[1]=direction[1];
            this->direction[2]=direction[2];

            this->maxForce=maxForce;
            this->maxVel=maxVel;
            this->hit=isHit;
        }

double* vehicle :: T_interaction( vector <target> &targets, double* gene, double* Nmt)
        {

            for(int j=0;j<targets.size();j++){



                double DistanceVector_j[3];
                double Distance_j;
                for (int i=0;i<3;i++){
                    DistanceVector_j[i]=targets[j].position[i] - this->position[i];
                }

                Distance_j = magnitudeOfVector(DistanceVector_j);


                if (Distance_j<targets[j].tolerance){
                    targets.erase(targets.begin()+j);
                    cout<<"target "<<j<<" is mapped distance "<<Distance_j<<" and tolerance "<<targets[j].tolerance<<" and target array size"<<targets.size()<<endl;
                    continue;
                }

                double unitVector[3];

                for (int i=0;i<3;i++){
                    unitVector[i]=DistanceVector_j[i]/Distance_j;
                }

                double Desire=gene[3]*exp(-1*gene[9]*Distance_j)-gene[4]*exp(-1*gene[10]*Distance_j);


                for(int i=0;i<3;i++){
                    Nmt[i]+=Desire*unitVector[i];
                }

                if(Desire <0){
                        cout<<"The vector in direction"<<DistanceVector_j[0]<<" "<<DistanceVector_j[1]<<" "<<DistanceVector_j[2]<<endl;
                        cout<<"desire "<<Desire<<" "<<j<<endl;
                }

            }



            return Nmt;

        }

double* vehicle:: O_interaction( vector <obstacle> &obstacles, double* gene, double* Nmo)
        {


            for(int j=0;j<obstacles.size();j++){
                double DistanceVector_j[3];
                double Distance_j;
                for (int i=0;i<3;i++){
                    DistanceVector_j[i]=obstacles[j].position[i]-this->position[i];
                }

                Distance_j = magnitudeOfVector(DistanceVector_j);

                if (Distance_j<obstacles[j].tolerance){
                    this->hit=true;
                    cout<<"Obstacle "<<j<<" is hit distance "<<Distance_j<<" and tolerance "<<obstacles[j].tolerance<<endl;
                    continue;
                }

                double unitVector[3];

                for (int i=0;i<3;i++){
                    unitVector[i]=DistanceVector_j[i]/Distance_j;
                }

                double Desire=gene[5]*exp(-1*gene[11]*Distance_j)-gene[6]*exp(-1*gene[12]*Distance_j);

                for(int i=0;i<3;i++){
                    Nmo[i]+=Desire*unitVector[i];
                }

            }



            return Nmo;
        }

double* vehicle:: M_interaction( vector<vehicle> &swarm, double* gene, double* Nmm)
        {


            for(int j=0;j<swarm.size();j++){
                double DistanceVector_j[3];
                double Distance_j;
                for (int i=0;i<3;i++){
                    DistanceVector_j[i]=swarm[j].position[i]-this->position[i];
                }

                Distance_j = magnitudeOfVector(DistanceVector_j);
                if(Distance_j==0.0){
                    continue;
                }

                double unitVector[3];

                for (int i=0;i<3;i++){
                    unitVector[i]=DistanceVector_j[i]/Distance_j;
                }

                double Desire=gene[7]*exp(-1*gene[13]*Distance_j)-gene[8]*exp(-1*gene[14]*Distance_j);

                for(int i=0;i<3;i++){
                    Nmm[i]+=Desire*unitVector[i];
                }

            }



            return Nmm;
        }



void vehicle:: apply_force(double frameTime){
            double weight=Getweight();
            double* direction=Getdirection();
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


 double vehicle:: magnitudeOfVector(double * Vector){
            double sum=0;
            for (int i=0;i<3;i++){
                sum+=Vector[i]*Vector[i];
            }
            //cout<<"Magnitude caculated "<<sqrt(sum)<<endl;
            return sqrt(sum);

        }


void vehicle:: Aim(  vector <vehicle> &swarm, vector <target> &targets , vector <obstacle> &obstacles, double* gene ){

                    double tNmt[3]={0.0,0.0,0.0};
                    double tNmo[3]={0.0,0.0,0.0};
                    double tNmm[3]={0.0,0.0,0.0};

                    double* Nmt;
                    double* Nmo;
                    double* Nmm;

                    double newDirection[3];
                     Nmt = T_interaction( targets, gene, tNmt );
                     Nmo = O_interaction( obstacles, gene, tNmo );
                     Nmm = M_interaction( swarm, gene, tNmm );

                     //cout<<magnitudeOfVector(Nmt)<<endl;

                    //cout<<"NewDir Nmt "<<Nmt[0]<<endl;

                    //find directions from weight
                    double Ntot[3];

                    for (int i=0;i<3;i++){
                        Ntot[i] = gene[0]*Nmt[i] + gene[1]*Nmo[i] + gene[2]*Nmm[i];
                    }

                    //cout<<"Nmt calculated "<<Nmt[0]<<" "<<Nmt[1]<<" "<<Nmt[2]<<endl;


                    double magnitude=magnitudeOfVector(Ntot);

                    for (int i=0;i<3;i++){
                        newDirection[i]=Ntot[i]/magnitude;
                    }

                    //cout<<"Direction calculated "<<newDirection[0]<<" "<<newDirection[1]<<" "<<newDirection[2]<<endl;

                    Setdirection(newDirection);

                  }

