//
//  Projection.h
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/19/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Projection_h
#define Projection_h
#include "Angel.h"

typedef Angel::vec4  point4;
class Projection {
public:
    mat4 matrix;
    Projection() {
        matrix = Frustum( LEFT, RIGHT, BOTTOM, TOP, NEAR, FAR );
    }
private:
    float const LEFT = -1.0;
    float const RIGHT = 1.0;
    float const BOTTOM = -1.0;
    float const TOP = 1.0;
    float const NEAR = 1.0;
    float const FAR = 100000.0;
};


#endif /* Projection_h */
