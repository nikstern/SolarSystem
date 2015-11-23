//
//  Shapes.hpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/19/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Shapes_hpp
#define Shapes_hpp

#include <stdio.h>

 /* Shapes_hpp */
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





class Cube {
public:
    static int const POINTS=36;
    static int const VERTICES = 8;
    point4 points[36];
    vec3 normals[36];
    static size_t const SIZE = sizeof(points) + sizeof(normals);
    static size_t const SIZE_POINTS = sizeof(points);
    static size_t const SIZE_NORMALS = sizeof(normals);
    Cube();
private:
    point4 vertices[VERTICES] = {
        point4( -0.5, -0.5,  0.5, 1.0 ),
        point4( -0.5,  0.5,  0.5, 1.0 ),
        point4(  0.5,  0.5,  0.5, 1.0 ),
        point4(  0.5, -0.5,  0.5, 1.0 ),
        point4( -0.5, -0.5, -0.5, 1.0 ),
        point4( -0.5,  0.5, -0.5, 1.0 ),
        point4(  0.5,  0.5, -0.5, 1.0 ),
        point4(  0.5, -0.5, -0.5, 1.0 )
    };
    int quad(int a, int b, int c, int d,int index);
};




class Sphere {
public:
    static int const VERTICES = 4;
    static int const SEGMENTS = 512;
    static int const POINTS = SEGMENTS * 6 * (SEGMENTS - 2) + SEGMENTS * 6;
    point4 points[POINTS];
    vec3 normals[POINTS];
    vec2 texture[POINTS];
    point4 vertices[VERTICES];
    static size_t const SIZE = sizeof(points) + sizeof(normals)+sizeof(texture);
    static size_t const SIZE_POINTS = sizeof(points);
    static size_t const SIZE_NORMALS = sizeof(normals);
    static size_t const SIZE_TEXTURE = sizeof(texture);
    Sphere();
private:
    float const BOTTOM = -0.5;
    float const TOP    = 0.5;
    float const PH_TOP_PRIME = 1.0 - (2/SEGMENTS);
    float const PH_BOTTOM_PRIME = -PH_TOP_PRIME;
    float const PH_TOP =(float)((SEGMENTS/2)-1)/(float)(64/2) * M_PI/2.0;
    float const PH_BOTTOM = -PH_TOP;
    int quad(float t0, float t1, float p0, float p1,int index);
};
#endif /* Cylinder_hpp */
