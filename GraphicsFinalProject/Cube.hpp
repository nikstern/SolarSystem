//
//  Cube.hpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp
#include "Angel.h"

#include <stdio.h>

typedef Angel::vec4  point4;
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
#endif /* Cube_hpp */
