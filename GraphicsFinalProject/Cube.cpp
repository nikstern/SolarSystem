//
//  Cube.cpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#include "Cube.hpp"
int Cube::quad( int a, int b, int c, int d,int i)
{
    // Initialize temporary vectors along the quad's edge to compute its face normal
    vec4 u = vertices[b] - vertices[a];
    vec4 v = vertices[c] - vertices[b];
    
    vec3 normal = normalize( cross(u, v) );
    
    normals[i] = normal; points[i] = vertices[a]; i++;
    normals[i] = normal; points[i] = vertices[b]; i++;
    normals[i] = normal; points[i] = vertices[c]; i++;
    normals[i] = normal; points[i] = vertices[a]; i++;
    normals[i] = normal; points[i] = vertices[c]; i++;
    normals[i] = normal; points[i] = vertices[d]; i++;
    return i;
}
Cube::Cube()
{
    int i = 0;
    i=quad( 1, 0, 3, 2,i);
    i=quad( 2, 3, 7, 6,i );
    i=quad( 3, 0, 4, 7,i );
    i=quad( 6, 5, 1, 2,i );
    i=quad( 4, 5, 6, 7,i );
    i=quad( 5, 4, 0, 1,i);
}

