//
//  Material.h
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/19/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Material_h
#define Material_h
#include "Angel.h"

typedef Angel::vec4  point4;
class Material {
public:
    vec4 atmos;
    vec4 diffuse;
    vec4 specular;
    float shiny;
    Material()
    {
        atmos = DEFAULT_ATMOS;
        diffuse = DEFAULT_DIFFUSE;
        specular = DEFAULT_SPECULAR;
        shiny = 5.0;
    };
    Material(vec4 a,vec4 d, vec4 s, float shine)
    {
        atmos = a;
        diffuse = d;
        specular = s;
        shiny = shine;
    };
private:
    float  DEFAULT_SHINY = 5.0;
    vec4  DEFAULT_ATMOS = {0,0,0,1};
    vec4  DEFAULT_DIFFUSE = {1,0,0,1};
    vec4  DEFAULT_SPECULAR = {1.0,0.4,0.4,1.0};
};

#endif /* Material_h */
