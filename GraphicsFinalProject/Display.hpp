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
#include "Planet.h"
#include "RGBpixmap.hpp"

int EYE1 = 10;
int EYE2 = 20;
int EYE3 = 0;
void drawing();
void timer(int value);
void key(unsigned char pressedKey, int mouseXPosition, int mouseYPosition);
void setTextures(int num);


#endif /* Display_hpp */
