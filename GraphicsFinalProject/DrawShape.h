//
//  DrawShape.h
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/19/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef DrawShape_h
#define DrawShape_h
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
#endif /* DrawShape_h */
