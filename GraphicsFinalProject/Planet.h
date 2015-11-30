//
//  Planet.h
//  GraphicsFinalProject
//
//  Created by Dolan-Stern, Nicholas on 11/18/15.
//  Copyright (c) 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#ifndef __GraphicsFinalProject__Planet__
#define __GraphicsFinalProject__Planet__

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <GLUT/glut.h>
using namespace std;

class Satellite
{
public:
    GLfloat radius;
    GLfloat orbitRadius;
    GLfloat orbitDuration;
    GLfloat rotationDuration;
    GLfloat inclination;
    GLint num;
    Satellite()
    {
        
    }
    Satellite(GLfloat r, GLfloat oR, GLfloat oD, GLfloat i, GLint n)
    {
        radius = r;
        orbitRadius = oR;
        orbitDuration = oD;
        inclination = i;
        num = n;
    }
};
class Ring {
public:
    GLdouble inner;
    GLdouble outer;
    GLint slices;
    GLint loops;
    GLuint texture_num;
    Ring()
    {
        inner = 0;
        outer = 0;
        slices = 0;
        loops = 0;
        texture_num = 0;
    }
    Ring(GLdouble i, GLdouble radius, GLint s, GLint l, GLuint t)
    {
        inner = i;
        outer = i+radius;
        slices = s;
        loops = l;
        texture_num = t;
    }
};
class Planet {
public:
    GLfloat radius;
    GLfloat orbitRadius;
    GLfloat orbitDuration;
    GLfloat rotationDuration;
    GLfloat inclination;
    GLint num;
    int numChildren;
    Planet(GLfloat r, GLfloat oR, GLfloat oD, GLfloat rD, GLfloat i, GLint n)
    {
        radius = r;
        orbitRadius = oR;
        orbitDuration = oD;
        rotationDuration = rD;
        inclination = i;
        num = n;
        numChildren = 0;
    }
    Planet(GLfloat r, GLfloat oR, GLfloat oD, GLfloat rD, GLfloat i, GLint n, int numChilds)
    {
        radius = r;
        orbitRadius = oR;
        orbitDuration = oD;
        rotationDuration = rD;
        inclination = i;
        num = n;
        numChildren = numChilds;
    }

};

const Ring SATURN_RING1 = Ring(10,1,48,48,1);
const Ring SATURN_RING2 = Ring(11.3,1,48,48,2);
const Ring SATURN_RING3 = Ring(12.5,1,48,48,3);
const Ring SATURN_RING4 = Ring(13.7,1,48,48,4);
const Ring SATURN_RING5 = Ring(14.9,1,48,48,5);
const Ring JUPITER_RING1 = Ring(13.5,2.5,48,48,1);
const Ring JUPITER_RING2 = Ring(17.05,4.0,48,48,2);
const Ring URANUS_RING1 = Ring(5,1.0,48,48,1);
const Ring URANUS_RING2 = Ring(6.3,2.0,48,48,2);
const Satellite MOON = Satellite(0.27,0.257,30.0,0,0);
const Planet SUN = Planet(1.0, 0,1,1,0,0);
const Planet MERCURY = Planet(0.383,  0.387, 88,   59,    7, 1);
const Planet VENUS = Planet(  0.949, 0.723, 225, -243,   3, 2);
const Planet EARTH = Planet(  1.0, 1, 365,    1,   7, 3, 1);
const Planet MARS = Planet(   0.532,  1.52, 686,    1,   2, 4);
const Planet JUPITER = Planet(11.21,  5.2, 4333,   0.4, 1, 5);
const Planet SATURN = Planet( 9.45,  9.58, 10759,  0.4, 2, 6);
const Planet URANUS = Planet( 4.01,  19.20, 30685, -0.7, 1, 7);
const Planet NEPTUNE = Planet(3.88,  30.05, 60190,  0.7, 2, 8);
const GLfloat SUNLIGHT_MODEL_AMBIENT[] = { 0.2, 0.2, 0.2, 0.0};
Planet PLANETS[9] =
{
    SUN,MERCURY,VENUS,EARTH,MARS,JUPITER,SATURN,URANUS,NEPTUNE
};
Satellite PLANET_SATELLITES[9][30]=
{
    {},{},{},{MOON},{},{},{},{},{},
};
Ring PLANET_RINGS[9][10] =
{
    {},{},{},{},{},{JUPITER_RING1,JUPITER_RING2},{SATURN_RING1,SATURN_RING2,SATURN_RING3,SATURN_RING4,SATURN_RING5},{URANUS_RING1,URANUS_RING1},{}
};
GLfloat theta = 0.00;
GLfloat days  = 0.00;
GLfloat increment    =10;
const GLfloat SUNLIGHT_POSITION[]    = { 0.0, 0.0, 0.0, 1.0};
const GLfloat SUNLIGHT_AMBIENT[]       = { 0, 0, 0, 1.0};
const GLfloat SUNLIGHT_DIFFUSE[]       = { 1, 1, 1, 1.0};
const GLfloat SUNLIGHT_SPECULAR[]      = { 1, 1, 1, 1.0};
const GLfloat SUN_LIGHT_AMB[] = {1,1,1,1};
const GLfloat SUNLIGHT_SPOT_DIRECTION[] = {0.0,0,1};
GLuint textures[9];

void sunLight();
void updateSunLight();
void drawAllPlanets();
void drawPlanet(Planet planet);
void drawRing(Ring ring, Planet planet);
void drawSatellite(Satellite satellite, Planet planet);

void sunLight()
{
    glEnable( GL_LIGHT0 );
    glDisable(GL_LIGHT1);
    glLightfv( GL_LIGHT0, GL_AMBIENT, SUNLIGHT_AMBIENT );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, SUNLIGHT_DIFFUSE );
    glLightfv( GL_LIGHT0, GL_SPECULAR, SUNLIGHT_SPECULAR);
    glLightfv( GL_LIGHT0, GL_POSITION, SUNLIGHT_POSITION );
    glLightfv( GL_LIGHT0, GL_SPOT_DIRECTION, SUNLIGHT_SPOT_DIRECTION);
    glLightf( GL_LIGHT0, GL_SPOT_EXPONENT, 0.0 );
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f );
    glLightf( GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0 );
    glLightf( GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0 );
    glLightf( GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0 );
}

void updateSunLight()
{
    glPushMatrix();
        glLightfv(GL_LIGHT1, GL_POSITION, SUNLIGHT_POSITION);
        glLightfv(GL_LIGHT1, GL_AMBIENT,  SUN_LIGHT_AMB);
        glPopMatrix();
    glEnable(GL_LIGHT1);
}
void drawAllPlanets()
{
    updateSunLight();
    drawPlanet(SUN);
    sunLight();
    drawPlanet(MERCURY);
    drawPlanet(VENUS);
    drawPlanet(EARTH);
    drawPlanet(MARS);
    drawPlanet(JUPITER);
    drawPlanet(SATURN);
    drawPlanet(URANUS);
    drawPlanet(NEPTUNE);
}

void drawRing(Ring ring,Planet planet)
{
    GLUquadricObj* quadro = gluNewQuadric();
    gluQuadricNormals(quadro, GLU_SMOOTH);
    gluQuadricTexture(quadro, GL_TRUE);
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(planet.num/36.0*(ring.texture_num), planet.num/36.0 *(ring.texture_num),planet.num/36.0*(ring.texture_num) );
    glPushMatrix();
        glRotatef(planet.inclination, 0.0, 0.0, 1.0);
        glRotatef( 360.0 * (days/planet.orbitDuration), 0.0, 1.0, 0.0);
        glTranslatef(planet.orbitRadius, 0.0, 0.0 );
        glRotatef(-180/planet.num, 1.0, 0.0, 0.0 );
        gluDisk(quadro, ring.inner/10, ring.outer/10, ring.slices,ring.loops );
    glPopMatrix();
    glColor3f(1, 1, 1);
    glDisable(GL_COLOR_MATERIAL);
    gluDeleteQuadric(quadro);
    
}
void drawSatellite(Satellite satellite,Planet planet)
{
    GLUquadricObj* quadro = gluNewQuadric();
    gluQuadricNormals(quadro, GLU_SMOOTH);
    gluQuadricTexture(quadro, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glPushMatrix();
            glRotatef(planet.inclination, 0.0, 0.0, 1.0);
            glRotatef( 360.0 * (days/planet.orbitDuration), 0.0, 1.0, 0.0);
            glTranslatef(planet.orbitRadius, 0.0, 0.0 );
            glRotatef( 360.0 * days/satellite.orbitDuration , 0.0, 1.0, 0.0 );
            glTranslatef( satellite.orbitRadius, 0.0, 0.0 );
            glBindTexture(GL_TEXTURE_2D, textures[satellite.num]);
            gluSphere(quadro, satellite.radius/10, 48, 48);
        glPopMatrix();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(quadro);
}
void drawPlanet(Planet planet)
{
    if (planet.num !=0)
    {
        
        for (int i = 0; i < 10;i++)
        {
            Ring ring = PLANET_RINGS[planet.num][i];
            drawRing(ring,planet);
        }
        for (int i = 0; i < planet.numChildren; i++)
        {
            Satellite satellite = PLANET_SATELLITES[planet.num][i];
            drawSatellite(satellite, planet);
        }
    }
    GLUquadricObj* quadro = gluNewQuadric();
    gluQuadricNormals(quadro, GLU_SMOOTH);
    gluQuadricTexture(quadro, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glPushMatrix();
				glRotatef( planet.inclination, 0.0, 0.0, 1.0);
				glRotatef( 360.0 * (days/ planet.orbitDuration), 0.0, 1.0, 0.0);
				glTranslatef( planet.orbitRadius, 0.0, 0.0 );
				glRotatef( 360.0 * (theta/ planet.rotationDuration), 0.0, 1.0, 0.0 );
                glRotatef( -90.0, 1.0, 0.0, 0.0 );
				glBindTexture(GL_TEXTURE_2D, textures[planet.num]);
				gluSphere(quadro, planet.radius/10, 48, 48);
        glPopMatrix();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(quadro);
}


#endif /* defined(__GraphicsFinalProject__Planet__) */