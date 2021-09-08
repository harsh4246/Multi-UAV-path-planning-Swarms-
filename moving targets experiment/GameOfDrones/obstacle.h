#ifndef OBSTACLE_H
#define OBSTACLE_H


class obstacle
{
    public:
        friend class vehicle;
        obstacle(double* position, double tolerance);

    protected:

    private:
        double position[3];
        double tolerance;
};

#endif // OBSTACLE_H
