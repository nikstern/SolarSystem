//
//  Display.cpp
//  GraphicsFinalProject
//
//  Created by Nick Stern on 11/18/15.
//  Copyright © 2015 Dolan-Stern, Nicholas. All rights reserved.
//

#include "Display.hpp"
#include "Planet.h"
#include "Texture.hpp"
int PROGRAM;
int POSITION;
int NORMAL;
int MATERIAL_A;
int MATERIAL_D;
int MATERIAL_S;
int MATERIAL_SHINY;
int LIGHT_P;
int LIGHT_A;
int LIGHT_D;
int LIGHT_S;
int LIGHT_INVERSE;
int MODEL;
int TEX;
Cube CUBE = Cube();
const size_t CUBE_POINTS_OFFSET = 0;
const size_t CUBE_NORMALS_OFFSET = Cube::SIZE_POINTS;
const size_t CYLINDER_POINTS_OFFSET = Cube::SIZE;
const size_t CYLINDER_NORMALS_OFFSET = CYLINDER_POINTS_OFFSET + Cylinder::SIZE_POINTS;
const size_t SPHERE_POINTS_OFFSET = CYLINDER_NORMALS_OFFSET+Cylinder::SIZE_NORMALS;
const size_t SPHERE_NORMALS_OFFSET = SPHERE_POINTS_OFFSET+Sphere::SIZE_POINTS;
const size_t SPHERE_TEXTURE_OFFSET = SPHERE_NORMALS_OFFSET+Sphere::SIZE_NORMALS;
const size_t TOTAL_SIZE = SPHERE_NORMALS_OFFSET + Sphere::SIZE_NORMALS + Sphere::SIZE_TEXTURE;
void DrawCube(DrawShape shape);
void DrawCylinder(DrawShape shape);
void DrawSphere(DrawShape shape);
int day;
Sphere SPHERE;
Cylinder CYLINDER;
void SetMaterial(Material material);
void SetLight(Light light);
void drawShape(DrawShape shape, int numPoints,size_t points, size_t normals);
void drawing();
enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
int      Axis = Zaxis;
GLfloat  Theta1[NumAxes] = { 0.0, 0.0, 0.0 };
float r = 4.0;
View view = View();
Projection proj = Projection();
mat4 matrix;
vec4 lpos = vec4( 0.0, 0.0, 0.0, 0.0 );
vec4 sla(1,1,1,1);
vec4 sld(0.0, 0.0,0.0, 1.0);
vec4 sls(0.5, 0.5, 0.5, 1.0);
Light sunlight = Light(lpos,sla,sld,sls,false);
vec4 la = vec4(0.1,0.1,0.1,0.0);
vec4 ld = vec4(0.5, 0.5, 0.5, 1.0);
vec4 ls = vec4(0.5, 0.5, 0.5, 1.0);
Light planetlight = Light(vec4(0,0,0,0), la, ld, ls, false);
float EARTH_SIZE = 1.0;
float EARTH_DISTANCE = 10;
float EARTH_THETA = 1;
int PLANETS = 6;
Planet planets[] = {
    Planet(1,0,0,0),
    Planet(EARTH_SIZE*0.3,EARTH_DISTANCE*0.387,EARTH_THETA/0.241,0.01),
    Planet(EARTH_SIZE*0.98,EARTH_DISTANCE*0.716,EARTH_THETA/0.615,177.4),
    Planet(EARTH_SIZE*1.0, EARTH_DISTANCE*1.0,EARTH_THETA*1.0,23.4),
    Planet(EARTH_SIZE*0.532,EARTH_DISTANCE*1.52,EARTH_THETA/1.88,6.7),
    Planet(EARTH_SIZE*11.21, EARTH_DISTANCE*5.2,EARTH_THETA/11.9,25.2),
    };
DrawShape planetShapes[] =
{
    DrawShape(sunlight,
    Material(
              vec4(1.0, 1.0, 1.0, 1.0),
              vec4(1.0, 1.0, 1.0, 1.0),
              vec4(1.0, 1.0, 1.0, 1.0),
              5.0
             ),planets[0].getSize(), vec4(1.0,1.0,0.0,1.0)),
    DrawShape(planetlight, // MERCURY
    Material(
            vec4(0.0, 0.0, 0.0, 1.0),
            vec4(1.0, 0.0, 0.0, 1.0),
            vec4(0.3, 0.3, 0.3, 1.0),
            5
            ),matrix, vec4(0.0,0.0,0.0,1.0)),
    DrawShape(planetlight, // VENUS
    Material(
            vec4(0.0, 0.0, 0.0, 1.0),
            vec4(1.0, 0.0, 0.0, 1.0),
            vec4(0.5, 1.0, 0.5, 1.0),
            5
            ),matrix, vec4(0.0,1.0,0.5,1.0)),
    DrawShape(planetlight, // EARTH
    Material(
            vec4(0.0, 0.0, 0.0, 1.0),
            vec4(1.0, 0.0, 0.0, 1.0),
            vec4(0.0, 0.0, 1.0, 1.0),
             5
            ),matrix, vec4(0.0,0.0,1.0,1.0)),
    DrawShape(planetlight, // MARS
    Material(
             vec4(0.0, 0.0, 0.0, 1.0),
             vec4(1.0, 0.0, 0.0, 1.0),
             vec4(1.0, 0.0, 0.0, 1.0),
             5
            ),matrix, vec4(1.0,0.0,0.0,1.0)),
    DrawShape(planetlight, // JUPITER
    Material(
            vec4(0.0, 0.0, 0.0, 1.0),
            vec4(1.0, 0.0, 0.0, 1.0),
            vec4(1.0, 0.0, 0.0, 1.0),
            5
            ),matrix, vec4(1.0,0.5,0.0,1.0)),
    
};
GLuint textures[2];
void drawing()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    GLuint PROJ = glGetUniformLocation( PROGRAM, "projection" );
    glUniformMatrix4fv( PROJ, 1, GL_TRUE, proj.matrix);
    GLuint VIEW = glGetUniformLocation( PROGRAM, "view" );
glUniform1i( glGetUniformLocation(PROGRAM, "texture_on"), true );
     glUniform1f( glGetUniformLocation(PROGRAM, "st_factor"), 10.0 );
    glUniformMatrix4fv( VIEW, 1, GL_TRUE, view.matrix );
 //   glVertexAttribPointer( TEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(SPHERE_TEXTURE_OFFSET) );
        for (int i = 0; i < PLANETS; i++)
    {
        
        glBindTexture( GL_TEXTURE_2D, textures[1] );
        Planet planet = planets[i];
        DrawShape shape = planetShapes[i];
        shape.setModel(Translate(planet.getX(day), 0, planet.getY(day))*Scale(planet.getSize()));
        DrawSphere(shape);
    }
    
    glutSwapBuffers();

}
void idle()
{
    day++;
    glutPostRedisplay();
}


void Display(int argc, char** arv)
{
    day = 0;
    glutInit(&argc,arv);
    //glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 800, 800 );
    glutCreateWindow( "Color Cube" );
    PROGRAM = InitShader( "vshader31.glsl", "fshader31.glsl" );
    glUseProgram(PROGRAM);
    POSITION = glGetAttribLocation( PROGRAM, "vPosition" );
    NORMAL  = glGetAttribLocation( PROGRAM, "vNormal" );
    MATERIAL_A = glGetUniformLocation(PROGRAM, "ka");
    MATERIAL_D = glGetUniformLocation(PROGRAM, "kd");
    MATERIAL_S = glGetUniformLocation(PROGRAM, "ks");
    MATERIAL_SHINY = glGetUniformLocation(PROGRAM, "Shininess");
    LIGHT_P = glGetUniformLocation(PROGRAM, "LightPosition");
    LIGHT_A = glGetUniformLocation(PROGRAM, "AmbientLight");
    LIGHT_D = glGetUniformLocation(PROGRAM, "DiffuseLight");
    LIGHT_S = glGetUniformLocation(PROGRAM, "SpecularLight");
    LIGHT_INVERSE = glGetUniformLocation(PROGRAM, "light_out");
    MODEL = glGetUniformLocation(PROGRAM,"model");
    TEX = glGetUniformLocation(PROGRAM,"vTexCoord");
    const int  TextureSize  = 512;
    GLubyte checker_tex[TextureSize][TextureSize][3];
    
    for ( int i = 0; i < TextureSize; i++ )
    {
        for ( int j = 0; j < TextureSize; j++ )
        {
            //GLubyte c = (((i & 0x4) == 0) ^ ((j & 0x1)  == 0)) * 255;
            GLubyte c = (((j & 0x10)  == 0)) * 255;
            checker_tex[i][j][0]  = c;
            checker_tex[i][j][1]  = c;
            checker_tex[i][j][2]  = c;
        }
    }
    glGenTextures( 2, textures );
    
    glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, textures[0] );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, TextureSize, TextureSize, 0, GL_BGR, GL_UNSIGNED_BYTE, checker_tex );
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    unsigned char* pic1 = NULL;
    int w,h;
    loadBMP_custom(&pic1, &w, &h, "earth_physical.bmp");
    glBindTexture( GL_TEXTURE_2D, textures[1] );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, pic1 );
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    
    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData(GL_ARRAY_BUFFER, TOTAL_SIZE, NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, CUBE_POINTS_OFFSET, CUBE.SIZE_POINTS, CUBE.points);
    glBufferSubData(GL_ARRAY_BUFFER, CUBE_NORMALS_OFFSET, CUBE.SIZE_NORMALS, CUBE.normals);
    glBufferSubData(GL_ARRAY_BUFFER, CYLINDER_POINTS_OFFSET, CYLINDER.SIZE_POINTS, CYLINDER.points);
    glBufferSubData(GL_ARRAY_BUFFER, CYLINDER_NORMALS_OFFSET, CYLINDER.SIZE_NORMALS, CYLINDER.normals);
    glBufferSubData(GL_ARRAY_BUFFER, SPHERE_POINTS_OFFSET, SPHERE.SIZE_POINTS, SPHERE.points);
    glBufferSubData(GL_ARRAY_BUFFER, SPHERE_NORMALS_OFFSET, SPHERE.SIZE_NORMALS, SPHERE.normals);
     glBufferSubData(GL_ARRAY_BUFFER, SPHERE_TEXTURE_OFFSET, SPHERE.SIZE_TEXTURE, SPHERE.texture);
    glEnableVertexAttribArray( POSITION );
    glVertexAttribPointer( POSITION, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(CUBE_POINTS_OFFSET) );
    glEnableVertexAttribArray( NORMAL );
    glVertexAttribPointer( NORMAL, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(CUBE_NORMALS_OFFSET) );
    glEnable( GL_DEPTH_TEST );
    glEnableVertexAttribArray( TEX );
    glVertexAttribPointer( TEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(SPHERE_TEXTURE_OFFSET) );
    glUniform1i( glGetUniformLocation(PROGRAM, "myTextureSampler"), 0 );
    glUniform1i( glGetUniformLocation(PROGRAM, "texture_on"), true );

    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    GLuint VIEW = glGetUniformLocation( PROGRAM, "view" );
    glUniformMatrix4fv( VIEW, 1, GL_TRUE, view.matrix);
    glutDisplayFunc(drawing);
    glutIdleFunc(idle);
    glutMainLoop();
}


void SetMaterial(Material material)
{
    glUniform4fv( MATERIAL_A, 1, material.atmos );
    glUniform4fv( MATERIAL_D, 1, material.diffuse);
    glUniform4fv( MATERIAL_S, 1, material.specular );
    glUniform1f( MATERIAL_SHINY, material.shiny );
}
void SetLight(Light light)
{
    glUniform4fv( LIGHT_P, 1, light.pos );
    glUniform4fv( LIGHT_A, 1, light.atmos );
    glUniform4fv( LIGHT_D, 1, light.diffuse);
    glUniform4fv( LIGHT_S, 1, light.specular );
    glUniform1f( LIGHT_INVERSE, light.inverse );
}
void drawShape(DrawShape shape, int numPoints, size_t points, size_t normals)
{
    SetLight(shape.light);
    SetMaterial(shape.material);
    glUniformMatrix4fv( MODEL, 1, GL_TRUE, shape.model);
    glUniform4fv( glGetUniformLocation(PROGRAM, "obj_color"), 1,  shape.color);
    glVertexAttribPointer( POSITION, 4, GL_FLOAT, GL_FALSE, 0,  BUFFER_OFFSET(points));
    glVertexAttribPointer( NORMAL, 3, GL_FLOAT, GL_FALSE, 0,  BUFFER_OFFSET(normals));
    glDrawArrays( GL_TRIANGLES, 0, numPoints );
}
void DrawCube(DrawShape shape)
{
    drawShape(shape, CUBE.POINTS,CUBE_POINTS_OFFSET, CUBE_NORMALS_OFFSET);
}
void DrawCylinder(DrawShape shape)
{
//    drawShape(shape, CYLINDER.POINTS,CYLINDER_POINTS_OFFSET, CYLINDER_NORMALS_OFFSET);
}
void DrawSphere(DrawShape shape)
{
   drawShape(shape,SPHERE.POINTS,SPHERE_POINTS_OFFSET, SPHERE_NORMALS_OFFSET);
}


