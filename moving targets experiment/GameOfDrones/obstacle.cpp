#include "obstacle.h"

obstacle::obstacle( double* position, double tolerance)
{
    for (int i=0;i<3;i++){
        this->position[0]=position[0];
        this->position[1]=position[1];
        this->position[2]=position[2];
    }

    this->tolerance=tolerance;
}
