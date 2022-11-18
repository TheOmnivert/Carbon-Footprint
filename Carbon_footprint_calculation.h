#ifndef CARBON_FOOTPRINT_CALCULATION_H_INCLUDED
#define CARBON_FOOTPRINT_CALCULATION_H_INCLUDED

#include<string>
#include<iostream>
using namespace std;

const double lpg_factor = 1.25;
const double electricity_factor = 2.07;
const double trash_factor = 0.63;
const double privateVehicle_factor = 0.14;
const double bus_factor = 0.013;
const double train_factor = 0.03;
const double plane_factor = 0.17;
const double hotel_factor = 29.53;

double lpg(int consumed)
{
    double co2;
    co2 = double(12*1000*consumed)*lpg_factor;
    return co2;
}
//write info logs too if possible
double electricity(int consumed)
{
    double co2;
    co2 = double(12*consumed)*electricity_factor;
    return co2;
}
double trash(int thrown)
{
    double co2;
    co2 = double(365*thrown)*trash_factor;
    return co2;
}
double privateVehicle(int travelled)
{
    double co2;
    co2 = double(12*travelled)*privateVehicle_factor;
    return co2;
}
double bus(int travelled)
{
    double co2;
    co2 = double(12*travelled)*bus_factor;
    return co2;
}
double train(int travelled)
{
    double co2;
    co2 = double(12*travelled)*train_factor;
    return co2;
}
double plane(int travelled)
{
    double co2;
    co2 = double(travelled)*plane_factor;
    return co2;
}
double hotel(int days)
{
    double co2;
    co2 = double(days)*hotel_factor;
    return co2;
}

#endif // CARBON_FOOTPRINT_CALCULATION_H_INCLUDED
