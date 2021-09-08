#ifndef VEHICLEDATA_H
#define VEHICLEDATA_H

#include <vector>
using namespace std;
class VehicleData
{
    public:
        VehicleData(double weight, double maxForce, double maxVel, double tolerance, vector<double> position,
                    vector<double> velocity, vector<double> direction);
        virtual ~VehicleData();

        double tolerance;
        double weight;
        double maxForce;
        double maxVel;

        vector<double> gene; //note this is not present in constructor
        vector<double> position;
        vector<double> velocity;
        vector<double> direction;

    protected:

    private:
};

#endif // VEHICLEDATA_H
