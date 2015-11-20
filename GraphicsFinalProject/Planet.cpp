//
//  Planet.cpp
//  GraphicsFinalProject
//
//  Created by Dolan-Stern, Nicholas on 11/18/15.
//  Copyright (c) 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#include "Planet.h"
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

Planet::Planet(double size, double distance, double theta,double tilt)
{
    cout << "Planet is being created" << endl;
    setSize(size);
    setDistance(distance);
    setTheta(theta);
    setTilt(tilt);
}
void Planet::setSize(double s)
{
    size = s;
}

void Planet::setDistance(double d)
{
    distance = d;
}
void Planet::setTheta(double t)
{
    theta = t;
}
void Planet::setTilt(double til)
{
    tilt = til;
}
double Planet::getDistance()
{
    return distance;
}
double Planet::getSize()
{
    return size;
}
double Planet::getTheta()
{
    return theta;
}
double Planet::getTilt(int day)
{
     double temp = day * tilt * M_PI/180.00;
    return temp;
}

double Planet::getX(int day){
    double temp = day * theta * M_PI/180.00;
    
    return distance * cos(temp);
}
double Planet::getY(int day)
{
    double temp = day * theta * M_PI/180.00;
    return distance * sin(temp);
}
