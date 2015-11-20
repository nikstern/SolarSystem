//
//  View.hpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/19/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include "Angel.h"

typedef Angel::vec4  point4;
class View {
public:
    mat4 matrix;
    View() {
        matrix = DEFAULT_VIEW;
    }
    View(mat4 view) {
        matrix = view;
    }
    View(vec4 eye, vec4 at, vec4 up)
    {
        matrix = LookAt(eye,at,up);
    };
    View(float thetaY,float thetaZ)
    {
        float y = thetaY * M_PI/180.0;
        float z = thetaZ * M_PI/180.0;
        vec4 eye = vec4(R * (cos(z)) * cos(y),R * sin(z),R * (cos(z)) * sin(y));
        vec4 up = vec4(0,cos(z),0,0);
        matrix = LookAt(eye, DEFAULT_AT, up);
    };
    
private:
    float const Y = 1;
    float const Z = 1.0;
    float const R = 2000.5;
    float const DEFAULT_EYE_X = R * (cos(Y)*cos(Z));
    float const DEFAULT_EYE_Y = R * sin(Z);
    float const DEFAULT_EYE_Z = R * (cos(Z)*sin(Y));
    vec4 const DEFAULT_EYE = vec4(DEFAULT_EYE_X,DEFAULT_EYE_Y,DEFAULT_EYE_Z);
    vec4 const DEFAULT_AT = vec4(0,0,0,1);
    vec4 const DEFAULT_UP = vec4(0,cos(Z),0,0);
    mat4 const DEFAULT_VIEW = LookAt(DEFAULT_EYE,DEFAULT_AT,DEFAULT_UP);
    
};
#endif /* View_hpp */
