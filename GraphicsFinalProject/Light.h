//
//  Light.h
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/19/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Light_h
#define Light_h
#include "Angel.h"

typedef Angel::vec4  point4;
class Light {
public:
    vec4 pos;
    vec4 atmos;
    vec4 diffuse;
    vec4 specular;
    bool inverse;
    float shiny;
    Light() {
        pos = DEFAULT_POS;
        atmos = DEFAULT_ATMOS;
        diffuse = DEFAULT_DIFFUSE;
        specular = DEFAULT_SPECULAR;
        inverse = DEFAULT_INVERSE;
    }
    Light(vec4 p, vec4 a,vec4 d, vec4 s, bool inv)
    {
        pos = p;
        atmos = a;
        diffuse = d;
        specular = s;
        inverse = inv;
    };
private:
    vec4  DEFAULT_POS = vec4(0,0,0,0);
    vec4  DEFAULT_ATMOS = vec4(0.4,0.4,0.4,1);
    vec4  DEFAULT_DIFFUSE = vec4(0.7,0.7,0.7,1);
    vec4  DEFAULT_SPECULAR = vec4(0.7,0.7,0.7,1);
    bool  DEFAULT_INVERSE = false;
};

#endif /* Light_h */
