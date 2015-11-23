//
//  Display.hpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef Display_hpp
#define Display_hpp

#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GLUT/glut.h>
#include "Shapes.hpp"
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
    float const R = 10.5;
    float const DEFAULT_EYE_X = R * (cos(Y)*cos(Z));
    float const DEFAULT_EYE_Y = R * sin(Z);
    float const DEFAULT_EYE_Z = R * (cos(Z)*sin(Y));
    vec4 const DEFAULT_EYE = vec4(DEFAULT_EYE_X,DEFAULT_EYE_Y,DEFAULT_EYE_Z);
    vec4 const DEFAULT_AT = vec4(0,0,0,1);
    vec4 const DEFAULT_UP = vec4(0,cos(Z),0,0);
    mat4 const DEFAULT_VIEW = LookAt(DEFAULT_EYE,DEFAULT_AT,DEFAULT_UP);
    
};



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





class DrawShape
{
public:
    Light light;
    Material material;
    mat4 model;
    vec4 color;
    DrawShape(Light l, Material mat, mat4 mod, vec4 col)
    {
        light = l;
        material = mat;
        model = mod;
        color = col;
    }
    void setLight(Light l)
    {
        light = l;
    }
    void setMaterial(Material mat)
    {
        material = mat;
    }
    void setModel(mat4 mod)
    {
        model = mod;
    }
    void setColor(vec4 col)
    {
        color = col;
    }
};


    void Display(int argc, char** arv);
    

#endif /* Display_hpp */
