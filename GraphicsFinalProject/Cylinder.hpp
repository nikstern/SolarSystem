//
//  Cylinder.hpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Cylinder_hpp
#define Cylinder_hpp

#include <stdio.h>
#include "Angel.h"
typedef Angel::vec4  point4;
class Cylinder {
public:
    static int const SEGMENTS = 64;
    static int const POINTS = SEGMENTS * 12;
    static int const VERTICES = 4;
    point4 points[64*12];
    vec3 normals[64*12];
    static size_t const SIZE = sizeof(points) + sizeof(normals);
    static size_t const SIZE_POINTS = sizeof(points);
    static size_t const SIZE_NORMALS = sizeof(normals);
    Cylinder();
private:
    int index=0;
    point4 vertices[VERTICES];
    float const TOP = 0.5;
    float const BOTTOM = -1 * TOP;
    float const RADIUS = 0.5;
    int const CORNER_ONE = 0;
    int const CORNER_TWO = 1;
    int const CORNER_THREE = 2;
    int const CORNER_FOUR = 3;
    float const COEFF = 2 * M_PI / SEGMENTS;
    void quad();
};

#endif /* Cylinder_hpp */
