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
#include "Cube.hpp"
#include "Cylinder.hpp"
#include "Sphere.hpp"
#include "Angel.h"
#include "View.hpp"
#include "Light.h"
#include "Material.h"
#include "DrawShape.h"
#include "Projection.h"
typedef Angel::vec4  point4;



    void Display(int argc, char** arv);
    

#endif /* Display_hpp */
