#ifndef TARGET_H
#define TARGET_H




class target
{
    public:
        double position[3];
        friend class vehicle;
        target( double* position, double tolerance);
        double * getPosition();
        void action(double frametime){
            apply_force(frametime);
        }
        void apply_force(double frametime);

        double* Getvelocity() { return velocity; }
        double GetmaxForce() { return maxForce; }
        double Getweight() { return weight; }
        double* Getdirection() { return direction; }
        double magnitudeOfVector(double * Vector);

    protected:

    private:

        double weight=50.0;
        double maxForce=100000.0;
        double maxVel=100;
        double velocity[3];
        double direction[3]={1,0,0};
        double tolerance;

};

#endif // TARGET_H
