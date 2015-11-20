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


class Planet {
public:
    
    double getSize();
    double getDistance();
    double getTheta();
    double getTilt(int day);
    
    double getX(int day);
    double getY(int day);
    Planet(double size, double distance, double theta,double til);
private:
    double size;
    double distance;
    double theta;
    double tilt;
    double coeff;
    void setSize(double s);
    void setDistance(double d);
    void setTheta(double t);
    void setTilt(double til);
};
#endif /* defined(__GraphicsFinalProject__Planet__) */