#pragma once
#include <maths.h>
#include <aircraft_data.h>


class Aircraft
{
private:
    BodyElement body_elements[8];
    double mass;
    double thrust_setting;
    Vector position;
    Vector velocity;
    Vector angular_velocity;
    Vector body_velocity;
    Vector moment;
    Vector Forces;
    // orientation needed

    void fill_aircraft_properties(AircraftModel model_enum);

public:
    Aircraft(AircraftModel model);
    ~Aircraft();
    void custom_print();
};
