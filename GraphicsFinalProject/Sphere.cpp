//
//  Sphere.cpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#include "Sphere.hpp"
Sphere::Sphere()
{
    float r = 0.5;
    int index = 0;
    for ( int n = 0; n < SEGMENTS; n++ )
    {
        float t0Prime;
        float t1Prime;
        GLfloat const t0 = 2 * M_PI * (t0Prime=((float)n / SEGMENTS));
        GLfloat const t1 = 2 * M_PI * (t0Prime=((float)(n+1) / SEGMENTS));
        
        points[index].x = 0.0;
        points[index].y = TOP;
        points[index].z = 0.0;
        points[index].w = 1.0;
        normals[index] = vec3(points[index].x, points[index].y, points[index].z);

        index++;
        points[index].x = cos(PH_TOP) * cos(t0) * r;
        points[index].y = sin(PH_TOP) * r;
        points[index].z = cos(PH_TOP) * sin(t0) * r;
        points[index].w = 1.0;
        normals[index] = vec3(points[index].x, points[index].y, points[index].z);
        
        index++;
        points[index].x = cos(PH_TOP) * cos(t1) * r;
        points[index].y = sin(PH_TOP) * r;
        points[index].z = cos(PH_TOP) * sin(t1) * r;
        points[index].w = 1.0;
        normals[index] = vec3(points[index].x, points[index].y, points[index].z);
        index++;
    }
    
    for( int m = 1; m < SEGMENTS-1; m++ )
    {
    
        float p0Prime,p0 = M_PI/2.0 - M_PI*(p0Prime=(m/(float)SEGMENTS));
        float p1Prime,p1 = M_PI/2.0 - M_PI*(p1Prime=((m+1)/(float)SEGMENTS));
        
        int num;
        for ( int n = 0; n < SEGMENTS; n++ )
        {
            num = 0;
            
            float t0Prime,t0 = 2 * M_PI * (t0Prime=(float)n / SEGMENTS);
            float t1Prime,t1 = 2 * M_PI * (t1Prime=(float)(n+1) / SEGMENTS);
            
            //quad vertex 0
            vertices[num].x = cos(p1)*cos(t0) * r;
            vertices[num].y = sin(p1) * r;
            vertices[num].z = cos(p1)*sin(t0) * r;
            vertices[num++].w = 1.0;
            //quad vertex 1
            vertices[num].x = cos(p1)*cos(t1) * r;
            vertices[num].y = sin(p1) * r;
            vertices[num].z = cos(p1)*sin(t1) * r;
            vertices[num++].w = 1.0;
            //quad vertex 2
            vertices[num].x = cos(p0)*cos(t1) * r;
            vertices[num].y = sin(p0) * r;
            vertices[num].z = cos(p0)*sin(t1) * r;
            vertices[num++].w = 1.0;
            //quad vertex 3
            vertices[num].x = cos(p0)*cos(t0) * r;
            vertices[num].y = sin(p0) * r;
            vertices[num].z = cos(p0)*sin(t0) * r;
            vertices[num++].w = 1.0;
            
            index = quad(t0Prime, t1Prime, p0Prime, p1Prime, index);
        }
    }
    
    for ( int n = 0; n < SEGMENTS; n++ )
    {
        
        float t0Prime,t0 = 2 * M_PI * (t0Prime=(float)n / SEGMENTS);
        float t1Prime,t1 = 2 * M_PI * (t1Prime=(float)(n+1) / SEGMENTS);
        points[index].x = 0.0;
        points[index].y = BOTTOM;
        points[index].z = 0.0;
        points[index].w = 1.0;
        normals[index] = vec3(points[index].x, points[index].y, points[index].z);
        
        index++;
        points[index].x = cos(PH_BOTTOM) * cos(t0) * r;
        points[index].y = sin(PH_BOTTOM) * r;
        points[index].z = cos(PH_BOTTOM) * sin(t0) * r;
        points[index].w = 1.0;
        normals[index] = vec3(points[index].x, points[index].y, points[index].z);
        
        index++;
        points[index].x = cos(PH_BOTTOM) * cos(t1) * r;
        points[index].y = sin(PH_BOTTOM) * r;
        points[index].z = cos(PH_BOTTOM) * sin(t1) * r;
        points[index].w = 1.0;
        normals[index] = vec3(points[index].x, points[index].y, points[index].z);
       
        index++;
    }
    
}

int Sphere::quad(float t0, float t1, float p0, float p1, int index)
{
    int CORNER_ONE = 0;
    int CORNER_TWO = 1;
    int CORNER_THREE = 2;
    int CORNER_FOUR = 3;
    points[index] = vertices[CORNER_ONE];
    normals[index] = vec3(vertices[CORNER_ONE].x, vertices[CORNER_ONE].y, vertices[CORNER_ONE].z);
    index++;
    points[index] = vertices[CORNER_TWO];
    normals[index] = vec3(vertices[CORNER_TWO].x, vertices[CORNER_TWO].y, vertices[CORNER_TWO].z);
    index++;
    points[index] = vertices[CORNER_THREE];
    normals[index] = vec3(vertices[CORNER_THREE].x, vertices[CORNER_THREE].y, vertices[CORNER_THREE].z);
    index++;
    points[index] = vertices[CORNER_ONE];
    normals[index] = vec3(vertices[CORNER_ONE].x, vertices[CORNER_ONE].y, vertices[CORNER_ONE].z);
    index++;
    points[index] = vertices[CORNER_THREE];
    normals[index] = vec3(vertices[CORNER_THREE].x, vertices[CORNER_THREE].y, vertices[CORNER_THREE].z);
    index++;
    points[index] = vertices[CORNER_FOUR];
    normals[index] = vec3(vertices[CORNER_FOUR].x, vertices[CORNER_FOUR].y, vertices[CORNER_FOUR].z);
    index++;
    return index;
}
