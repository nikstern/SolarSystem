//
//  Display.cpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All r````ights reserved.
//

#include "Display.hpp"

int main(int argc, char** arv)
{
    glutInit (&argc, arv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL | GLUT_DEPTH );
    glutInitWindowPosition( 150, 150 );
    glutInitWindowSize( 800, 800 );
    glutCreateWindow( "Solar System" );
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClearColor(0, 0, 0, 0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures( 9, textures );
    unsigned char* pic1 = NULL;
    int w,h;
    setTextures(9);
    glutDisplayFunc(drawing);
    glutTimerFunc( 20, timer, 1 );
    glutKeyboardFunc( key );
    glutMainLoop();
    return 0;
}

void drawing()
{
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,SUNLIGHT_MODEL_AMBIENT);
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 1.5, 1.5, 10000.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT| GL_STENCIL_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE1,
              EYE2,
              EYE3,
              0, 0, 0,
              0.0, 1.0, 0.020);
    drawAllPlanets();
    glDisable(GL_LIGHTING);
    glutSwapBuffers();
    glFlush();
    
}

void key(unsigned char pressedKey, int mouseXPosition, int mouseYPosition)
{
    switch(pressedKey)
    {
        case 'a':
            increment *= 1.1;
            if (increment > 100.0)
                increment = 100.0;
            break;
        case 'd':
            increment *= 0.9;
            if (increment < 0.001)
                increment = 0.001;
            break;
            
        case '1':
            if (EYE2 > 0.01)
                EYE2 -= 0.1;
            break;
            
        case '2':
            if (EYE2 < 100)
                EYE2 += 0.1;
            break;
        case '`':
            exit(0);
            
    }
}

void timer(int value)
{
    theta += increment;
    days += increment;
    glutPostRedisplay();
    glutTimerFunc(20, timer, 1);
}

void setTextures(int num)
{
    RGBpixmap pix;
    for (int i = 0; i < num; i++)
    {
        pix.readBMPFile(to_string(i)+".bmp", false);
        pix.setTexture(textures[i]);
    }
}

