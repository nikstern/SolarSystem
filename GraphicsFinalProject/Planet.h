//
//  Planet.h
//  GraphicsFinalProject
//
//  Created by Dolan-Stern, Nicholas on 11/18/15.
//  Copyright (c) 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef __GraphicsFinalProject__Planet__
#define __GraphicsFinalProject__Planet__

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
class Planet {
public:
    
    double getSize()
    {
        return size;
    }
    double getDistance()
    {
        return distance;
    }
    double getTheta()
    {
        return theta;
    }
    double getTilt(int day)
    {
        double temp = day * tilt * M_PI/180.00;
        return temp;
    }
    
    double getX(int day)
    {
        double temp = day * theta * M_PI/180.00;
        
        return distance * cos(temp);
    }
    double getY(int day)
    {
        double temp = day * theta * M_PI/180.00;
        return distance * sin(temp);
    }
    Planet(double size, double distance, double theta,double til)
    {
        cout << "Planet is being created" << endl;
        setSize(size);
        setDistance(distance);
        setTheta(theta);
        setTilt(tilt);
    }
private:
    double size;
    double distance;
    double theta;
    double tilt;
    double coeff;
    void setSize(double s)
    {
        size = s;
    }
    void setDistance(double d)
    {
        distance = d;
    }
    void setTheta(double t)
    {
        theta = t;
    }
    void setTilt(double til)
    {
        tilt = til;
    }

};
#endif /* defined(__GraphicsFinalProject__Planet__) */