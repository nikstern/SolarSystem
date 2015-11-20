//
//  Cylinder.cpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#include "Cylinder.hpp"
void
Cylinder::quad()
{
    points[index] = vertices[CORNER_ONE];
    normals[index] = vec3(vertices[CORNER_ONE].x, 0.0, vertices[CORNER_ONE].z); index++;
    points[index] = vertices[CORNER_TWO];
    normals[index] = vec3(vertices[CORNER_TWO].x, 0.0, vertices[CORNER_TWO].z); index++;
    points[index] = vertices[CORNER_THREE];
    normals[index] = vec3(vertices[CORNER_THREE].x, 0.0, vertices[CORNER_THREE].z); index++;
    points[index] = vertices[CORNER_ONE];
    normals[index] = vec3(vertices[CORNER_ONE].x, 0.0, vertices[CORNER_ONE].z); index++;
    points[index] = vertices[CORNER_THREE];
    normals[index] = vec3(vertices[CORNER_THREE].x, 0.0, vertices[CORNER_THREE].z); index++;
    points[index] = vertices[CORNER_FOUR];
    normals[index] = vec3(vertices[CORNER_FOUR].x, 0.0, vertices[CORNER_FOUR].z); index++;
}
Cylinder::Cylinder()
{
    index = 0;
    for ( int n = 0; n < SEGMENTS; n++ )
    {
        GLfloat const t0 = COEFF * n;
        GLfloat const t1 = COEFF * (n+1);
        
        points[index].x = 0.0;
        points[index].y = TOP;
        points[index].z = 0.0;
        points[index].w = 1.0;
        normals[index] = vec3(0.0, 1.0, 0.0);
        index++;
        points[index].x = cos(t0) * RADIUS;
        points[index].y = TOP;
        points[index].z = sin(t0) * RADIUS;
        points[index].w = 1.0;
        normals[index] = vec3(0.0, 1.0, 0.0);
        index++;
        points[index].x = cos(t1) * RADIUS;
        points[index].y = TOP;
        points[index].z = sin(t1) * RADIUS;
        points[index].w = 1.0;
        normals[index] = vec3(0.0, 1.0, 0.0);
        index++;
    }
    int num;
    for ( int n = 0; n < SEGMENTS; n++ )
    {
        num = 0;
        
        
        GLfloat const t0 = COEFF * n;
        GLfloat const t1 = COEFF * (n+1);
        
        //quad vertex 0
        vertices[num].x = cos(t0) * RADIUS;
        vertices[num].y = BOTTOM;
        vertices[num].z = sin(t0) * RADIUS;
        vertices[num++].w = 1.0;
        //quad vertex 1
        vertices[num].x = cos(t1) * RADIUS;
        vertices[num].y = BOTTOM;
        vertices[num].z = sin(t1) * RADIUS;
        vertices[num++].w = 1.0;
        //quad vertex 2
        vertices[num].x = cos(t1) * RADIUS;
        vertices[num].y = TOP;
        vertices[num].z = sin(t1) * RADIUS;
        vertices[num++].w = 1.0;
        //quad vertex 3
        vertices[num].x = cos(t0) * RADIUS;
        vertices[num].y = TOP;
        vertices[num].z = sin(t0) * RADIUS;
        vertices[num++].w = 1.0;
        
        quad();
    }
    
    for ( int n = 0; n < SEGMENTS; n++ )
    {
        
        GLfloat const t0 = COEFF * n;
        GLfloat const t1 = COEFF * (n+1);

        points[index].x = 0.0;
        points[index].y = BOTTOM;
        points[index].z = 0.0;
        points[index].w = 1.0;
        normals[index] = vec3(0.0, -1.0, 0.0);
        index++;
        points[index].x = cos(t1) * RADIUS;
        points[index].y = BOTTOM;
        points[index].z = sin(t1) * RADIUS;
        points[index].w = 1.0;
        normals[index] = vec3(0.0, -1.0, 0.0);
        index++;
        points[index].x = cos(t0) * RADIUS;
        points[index].y = BOTTOM;
        points[index].z = sin(t0) * RADIUS;
        points[index].w = 1.0;
        normals[index] = vec3(0.0, -1.0, 0.0);
        index++;
    }
}

