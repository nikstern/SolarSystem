//
//  Sphere.hpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include "Angel.h"


typedef Angel::vec4  color4;
typedef Angel::vec4  point4;
class Sphere {
public:
    static int const VERTICES = 4;
    static int const SEGMENTS = 64;
    static int const POINTS = SEGMENTS * 6 * (SEGMENTS - 2) + SEGMENTS * 6;
    point4 points[POINTS];
    vec3 normals[POINTS];
    point4 vertices[VERTICES];
    static size_t const SIZE = sizeof(points) + sizeof(normals);
    static size_t const SIZE_POINTS = sizeof(points);
    static size_t const SIZE_NORMALS = sizeof(normals);
    vec2 texCoords[4];
    Sphere();
private:
    float const BOTTOM = -0.5;
    float const TOP    = 0.5;
    float const PH_TOP_PRIME = 1.0 - (2/SEGMENTS);
    float const PH_BOTTOM_PRIME = -PH_TOP_PRIME;
    float const PH_TOP = PH_TOP_PRIME * 2 * M_PI;
    float const PH_BOTTOM = -PH_TOP;
    int quad(float t0, float t1, float p0, float p1,int index);
};
#endif /* Sphere_hpp */
