/**************************************************/
/* Name: Ben Linser                               */
/* Name: Chase Davis                              */
/* Name: Austin Gilbert                           */
/*                                                */
/* HW11                                           */
/*                                                */
/* CSci 446 / Fall 2017                           */
/**************************************************/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include "./raygl.h"
#include "./raygldefs.h"

float xpos, ypos, zpos, xrot, yrot, zrot, angle;
float lastx, lasty;
float cRadius; // our radius distance from our character
int rotating = 0;

bool start = 0;
bool forward = 0;
GLfloat LAngle, RAngle;

GLuint texture[6];

GLfloat xUFO, yUFO, zUFO = 0;
GLfloat xChicken, yChicken, zChicken = 0;
GLfloat xCow, yCow, zCow = 0;



int lastSub = 1;
int lastAdd = 1;

void head(GLuint texture[])
{  
   glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

   glBindTexture( GL_TEXTURE_2D, texture[1]);

   glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 0.25, y +1,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -0.25,y + 1,z + 1.5);

      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + 0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + 0.25,y + .5,z + 1.0);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + 0.25,y + .5,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + 0.25,y + .5,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.0);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.0);
   glEnd();

   glBindTexture( GL_TEXTURE_2D, texture[2]);

   glBegin(GL_QUADS);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + 0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + 0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.5);

   glEnd();

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
}

void backLeftLegTop(GLuint texture[])
{

   glTranslatef(x + 0.9f, y+ -1.4f, z + -1.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-x + -0.9f, -y + 1.4f, -z + 1.9f);

   glBegin(GL_QUADS);

   /*
   1  1.0, -1.0, -2.0
   2  1.0, -1.0, -1.8
   3  0.8, -1.0, -1.8 
   4  0.8, -1.0, -2.0
   5  0.8, -1.8, -2.0
   6  0.8, -1.8, -1.8
   7  1.0, -1.8, -2.0
   8  1.0, -1.8, -1.8
   */

   glVertex3f(x + 0.8,y + -1.0,z + -1.8);
   glVertex3f(x + 0.8,y + -1.0,z + -2.0);
   glVertex3f(x + 0.8,y + -1.4,z + -2.0);
   glVertex3f(x + 0.8,y + -1.4,z + -1.8);

   glVertex3f(x + 0.8,y + -1.0,z + -1.8);
   glVertex3f(x + 1.0,y + -1.0,z + -1.8);
   glVertex3f(x + 1.0,y + -1.4,z + -1.8);
   glVertex3f(x + 0.8,y + -1.4,z + -1.8);

   glVertex3f(x + 1.0,y + -1.0,z + -1.8);
   glVertex3f(x + 1.0,y + -1.0,z + -2.0);
   glVertex3f(x + 1.0,y + -1.4,z + -2.0);
   glVertex3f(x + 1.0,y + -1.4,z + -1.8);

   glVertex3f(x + 0.8,y + -1.0,z + -2.0);
   glVertex3f(x + 1.0,y + -1.0,z + -2.0);
   glVertex3f(x + 1.0,y + -1.4,z + -2.0);
   glVertex3f(x + 0.8,y + -1.4,z + -2.0);

   glEnd();
}

void backRightLegTop(GLuint texture[])
{

   glTranslatef(x + -0.9f, y+-1.4f,z+-1.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-x+0.9f, -y+1.4f, -z+1.9f);

   glBegin(GL_QUADS);

   /*
   1  -1.0, -1.0, -2.0
   2  -1.0, -1.0, -1.8
   3  -0.8, -1.0, -1.8
   4  -0.8, -1.0, -2.0
   5  -0.8, -1.8, -2.0
   6  -0.8, -1.8, -1.8
   7  -1.0, -1.8, -1.8
   8  -1.0, -1.8, -2.0
   */

   glVertex3f(x + -1.0,y + -1.0,z + -1.8);
   glVertex3f(x + -1.0,y + -1.0,z + -2.0);
   glVertex3f(x + -1.0,y + -1.4,z + -2.0);
   glVertex3f(x + -1.0,y + -1.4,z + -1.8);

   glVertex3f(x + -1.0,y + -1.0,z + -1.8);
   glVertex3f(x + -0.8,y + -1.0,z + -1.8);
   glVertex3f(x + -0.8,y + -1.4,z + -1.8);
   glVertex3f(x + -1.0,y + -1.4,z + -1.8);

   glVertex3f(x + -0.8,y + -1.0,z + -1.8);
   glVertex3f(x + -0.8,y + -1.0,z + -2.0);
   glVertex3f(x + -0.8,y + -1.4,z + -1.8);
   glVertex3f(x + -0.8,y + -1.4,z + -2.0);

   glVertex3f(x + -1.0,y + -1.0,z + -1.8);
   glVertex3f(x + -0.8,y + -1.0,z + -2.);
   glVertex3f(x + -1.0,y + -1.4,z + -2.0);
   glVertex3f(x + -0.8,y + -1.4,z + -2.0);

   glEnd();
}

void backLeftLegBot(GLuint texture[])
{

   glBegin(GL_QUADS);
   /*
   1  1.0, -1.0, -2.0
   2  1.0, -1.0, -1.8
   3  0.8, -1.0, -1.8 
   4  0.8, -1.0, -2.0
   5  0.8, -1.8, -2.0
   6  0.8, -1.8, -1.8
   7  1.0, -1.8, -2.0
   8  1.0, -1.8, -1.8
   */

   glVertex3f(x + 0.8,y + -1.4,z + -1.8);
   glVertex3f(x + 0.8,y + -1.4,z + -2.0);
   glVertex3f(x + 0.8,y + -1.8,z + -2.0);
   glVertex3f(x + 0.8,y + -1.8,z + -1.8);

   glVertex3f(x + 0.8,y + -1.4,z + -1.8);
   glVertex3f(x + 1.0,y + -1.4,z + -1.8);
   glVertex3f(x + 1.0,y + -1.8,z + -1.8);
   glVertex3f(x + 0.8,y + -1.8,z + -1.8);

   glVertex3f(x + 1.0,y + -1.4,z + -1.8);
   glVertex3f(x + 1.0,y + -1.4,z + -2.0);
   glVertex3f(x + 1.0,y + -1.8,z + -2.0);
   glVertex3f(x + 1.0,y + -1.8,z + -1.8);

   glVertex3f(x + 0.8,y + -1.4,z + -2.0);
   glVertex3f(x + 1.0,y + -1.4,z + -2.0);
   glVertex3f(x + 1.0,y + -1.8,z + -2.0);
   glVertex3f(x + 0.8,y + -1.8,z + -2.0);

   glEnd();
} 

void backRightLegBot(GLuint texture[])
{

   glBegin(GL_QUADS);
   /*
   1  -1.0, -1.0, -2.0
   2  -1.0, -1.0, -1.8
   3  -0.8, -1.0, -1.8
   4  -0.8, -1.0, -2.0
   5  -0.8, -1.8, -2.0
   6  -0.8, -1.8, -1.8
   7  -1.0, -1.8, -1.8
   8  -1.0, -1.8, -2.0
   */

   glVertex3f(x + -1.0,y + -1.4,z + -1.8);
   glVertex3f(x + -1.0,y + -1.4,z + -2.0);
   glVertex3f(x + -1.0,y + -1.8,z + -2.0);
   glVertex3f(x + -1.0,y + -1.8,z + -1.8);

   glVertex3f(x + -1.0,y + -1.4,z + -1.8);
   glVertex3f(x + -0.8,y + -1.4,z + -1.8);
   glVertex3f(x + -0.8,y + -1.8,z + -1.8);
   glVertex3f(x + -1.0,y + -1.8,z + -1.8);

   glVertex3f(x + -0.8,y + -1.4,z + -1.8);
   glVertex3f(x + -0.8,y + -1.4,z + -2.0);
   glVertex3f(x + -0.8,y + -1.8,z + -1.8);
   glVertex3f(x + -0.8,y + -1.8,z + -2.0);

   glVertex3f(x + -1.0,y + -1.4,z + -1.8);
   glVertex3f(x + -0.8,y + -1.4,z + -2.);
   glVertex3f(x + -1.0,y + -1.8,z + -2.0);
   glVertex3f(x + -0.8,y + -1.8,z + -2.0);

   glEnd();
} 

void frontLeftLegBot(GLuint texture[])
{

   glBegin(GL_QUADS);

   /*
   1  1.0, -1.0, -2.0
   2  1.0, -1.0, -1.8
   3  0.8, -1.0, -1.8 
   4  0.8, -1.0, -2.0
   5  0.8, -1.8, -2.0
   6  0.8, -1.8, -1.8
   7  1.0, -1.8, -2.0
   8  1.0, -1.8, -1.8

   -2 = .8
   -1.8 = 1
   */

   glVertex3f(x + 0.8,y + -1.4,z + 1.0);
   glVertex3f(x + 0.8,y + -1.4,z + 0.8);
   glVertex3f(x + 0.8,y + -1.8,z + 0.8);
   glVertex3f(x + 0.8,y + -1.8,z + 1.0);

   glVertex3f(x + 0.8,y + -1.4,z + 1.0);
   glVertex3f(x + 1.0,y + -1.4,z + 1.0);
   glVertex3f(x + 1.0,y + -1.8,z + 1.0);
   glVertex3f(x + 0.8,y + -1.8,z + 1.0);

   glVertex3f(x + 1.0,y + -1.4,z + 1.0);
   glVertex3f(x + 1.0,y + -1.4,z + 0.8);
   glVertex3f(x + 1.0,y + -1.8,z + 0.8);
   glVertex3f(x + 1.0,y + -1.8,z + 1.0);

   glVertex3f(x + 0.8,y + -1.4,z + 0.8);
   glVertex3f(x + 1.0,y + -1.4,z + 0.8);
   glVertex3f(x + 1.0,y + -1.8,z + 0.8);
   glVertex3f(x + 0.8,y + -1.8,z + 0.8);

   glEnd();
}

void frontRightLegBot(GLuint texture[])
{
   glBegin(GL_QUADS);

   /*
   1  -1.0, -1.0, -2.0
   2  -1.0, -1.0, -1.8
   3  -0.8, -1.0, -1.8
   4  -0.8, -1.0, -2.0
   5  -0.8, -1.8, -2.0
   6  -0.8, -1.8, -1.8
   7  -1.0, -1.8, -1.8
   8  -1.0, -1.8, -2.0

   -2 = .8
   -1.8 = 1
   */

   glVertex3f(x + -1.0,y + -1.4,z + 1.0);
   glVertex3f(x + -1.0,y + -1.4,z + 0.8);
   glVertex3f(x + -1.0,y + -1.8,z + 0.8);
   glVertex3f(x + -1.0,y + -1.8,z + 1.0);

   glVertex3f(x + -1.0,y + -1.4,z + 1.0);
   glVertex3f(x + -0.8,y + -1.4,z + 1.0);
   glVertex3f(x + -0.8,y + -1.8,z + 1.0);
   glVertex3f(x + -1.0,y + -1.8,z + 1.0);

   glVertex3f(x + -0.8,y + -1.4,z + 1.0);
   glVertex3f(x + -0.8,y + -1.4,z + 0.8);
   glVertex3f(x + -0.8,y + -1.8,z + 1.0);
   glVertex3f(x + -0.8,y + -1.8,z + 0.8);

   glVertex3f(x + -1.0,y + -1.4,z + 1.0);
   glVertex3f(x + -0.8,y + -1.4,z + 0.8);
   glVertex3f(x + -1.0,y + -1.8,z + 0.8);
   glVertex3f(x + -0.8,y + -1.8,z + 0.8);

   glEnd();
}

void frontLeftLegTop(GLuint texture[])
{

   glTranslatef(x+0.9f, y+-1.4f, z+0.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-x+-0.9f, -y+1.4f, -z+-0.9f);

      glBegin(GL_QUADS);

   /*
   1  1.0, -1.0, -2.0
   2  1.0, -1.0, -1.8
   3  0.8, -1.0, -1.8 
   4  0.8, -1.0, -2.0
   5  0.8, -1.8, -2.0
   6  0.8, -1.8, -1.8
   7  1.0, -1.8, -2.0
   8  1.0, -1.8, -1.8

   -2 = .8
   -1.8 = 1
   */

   glVertex3f(x + 0.8,y + -1.0,z + 1.0);
   glVertex3f(x + 0.8,y + -1.0,z + 0.8);
   glVertex3f(x + 0.8,y + -1.4,z + 0.8);
   glVertex3f(x + 0.8,y + -1.4,z + 1.0);

   glVertex3f(x + 0.8,y + -1.0,z + 1.0);
   glVertex3f(x + 1.0,y + -1.0,z + 1.0);
   glVertex3f(x + 1.0,y + -1.4,z + 1.0);
   glVertex3f(x + 0.8,y + -1.4,z + 1.0);

   glVertex3f(x + 1.0,y + -1.0,z + 1.0);
   glVertex3f(x + 1.0,y + -1.0,z + 0.8);
   glVertex3f(x + 1.0,y + -1.4,z + 0.8);
   glVertex3f(x + 1.0,y + -1.4,z + 1.0);

   glVertex3f(x + 0.8,y + -1.0,z + 0.8);
   glVertex3f(x + 1.0,y + -1.0,z + 0.8);
   glVertex3f(x + 1.0,y + -1.4,z + 0.8);
   glVertex3f(x + 0.8,y + -1.4,z + 0.8);

   /*
   1  -1.0, -1.0, -2.0
   2  -1.0, -1.0, -1.8
   3  -0.8, -1.0, -1.8
   4  -0.8, -1.0, -2.0
   5  -0.8, -1.8, -2.0
   6  -0.8, -1.8, -1.8
   7  -1.0, -1.8, -1.8
   8  -1.0, -1.8, -2.0

   -2 = .8
   -1.8 = 1
   */

   

   glEnd();
}

void frontRightLegTop(GLuint texture[])
{

   glTranslatef(x+-0.9f, y+-1.4f, z+0.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-x+0.9f, -y+1.4f, -z+-0.9f);

      glBegin(GL_QUADS);

   /*
   1  1.0, -1.0, -2.0
   2  1.0, -1.0, -1.8
   3  0.8, -1.0, -1.8 
   4  0.8, -1.0, -2.0
   5  0.8, -1.8, -2.0
   6  0.8, -1.8, -1.8
   7  1.0, -1.8, -2.0
   8  1.0, -1.8, -1.8

   -2 = .8
   -1.8 = 1
   */

   glVertex3f(x + -1.0,y + -1.0,z + 1.0);
   glVertex3f(x + -1.0,y + -1.0,z + 0.8);
   glVertex3f(x + -1.0,y + -1.4,z + 0.8);
   glVertex3f(x + -1.0,y + -1.4,z + 1.0);

   glVertex3f(x + -1.0,y + -1.0,z + 1.0);
   glVertex3f(x + -0.8,y + -1.0,z + 1.0);
   glVertex3f(x + -0.8,y + -1.4,z + 1.0);
   glVertex3f(x + -1.0,y + -1.4,z + 1.0);

   glVertex3f(x + -0.8,y + -1.0,z + 1.0);
   glVertex3f(x + -0.8,y + -1.0,z + 0.8);
   glVertex3f(x + -0.8,y + -1.4,z + 1.0);
   glVertex3f(x + -0.8,y + -1.4,z + 0.8);

   glVertex3f(x + -1.0,y + -1.0,z + 1.0);
   glVertex3f(x + -0.8,y + -1.0,z + 0.8);
   glVertex3f(x + -1.0,y + -1.4,z + 0.8);
   glVertex3f(x + -0.8,y + -1.4,z + 0.8);
   /*
   1  -1.0, -1.0, -2.0
   2  -1.0, -1.0, -1.8
   3  -0.8, -1.0, -1.8
   4  -0.8, -1.0, -2.0
   5  -0.8, -1.8, -2.0
   6  -0.8, -1.8, -1.8
   7  -1.0, -1.8, -1.8
   8  -1.0, -1.8, -2.0

   -2 = .8
   -1.8 = 1
   */

   

   glEnd();
}

void body(GLuint texture[])
{

   glTranslatef(x+0.9f, y+-1.0f, z+-1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-x+-0.9f, -y+1.0f,-z+1.9f);

   glTranslatef(x+-0.9f, y+-1.0f, z+-1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-x+ 0.9f, -y+1.0f, -z+1.9f);

   glTranslatef(x+ 0.9f, y+-1.0f, z+0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef( -x+-0.9f, -y+1.0f, -z+-0.9f);

   glTranslatef( x+-0.9f, y+-1.0f, z+0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef( -x+0.9f, -y+1.0f, -z+-0.9f);

   glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

   //texture = LoadTexture( "aaa.ppm", 560, 350);

   glBindTexture( GL_TEXTURE_2D, texture[1]);

   glBegin(GL_QUADS);
   /*
   glVertex3f(-1.0, 1.0, 1.0);
   glVertex3f(1.0, 1.0, 1.0);
   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(-1.0, -1.0, 1.0);

   glVertex3f(-1.0, 1.0, -2.0); 
   glVertex3f(1.0, 1.0, -2.0);
   glVertex3f(1.0, -1.0, -2.0);
   glVertex3f(-1.0, -1.0, -2.0);
   */

   glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

   glTexCoord2d(0.0, 0.0); glVertex3f(x + -1.0,y + 1.0,z + 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(x + 1.0,y + 1.0,z + 1.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(x + 1.0,y + -1.0,z + 1.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(x + -1.0,y + -1.0,z + 1.0);

   glTexCoord2d(0.0, 0.0); glVertex3f(x + -1.0,y + 1.0,z + -2.0); 
   glTexCoord2d(1.0, 0.0); glVertex3f(x + 1.0,y + 1.0,z + -2.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(x + 1.0,y + -1.0,z + -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(x + -1.0,y + -1.0,z + -2.0);

   /////////////////////////////////

   glTexCoord2d(0.0, 0.0); glVertex3f(x + -1.0,y + -1.0,z + 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(x + 1.0,y + -1.0,z + 1.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(x + 1.0,y + -1.0,z + -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(x + -1.0,y + -1.0,z + -2.0);

   glTexCoord2d(0.0, 0.0); glVertex3f(x + -1.0,y + 1.0,z + 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(x + 1.0,y + 1.0,z + 1.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(x + 1.0,y + 1.0,z + -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(x + -1.0,y + 1.0,z + -2.0);

   ///////////////////////////

   glTexCoord2d(0.0, 0.0); glVertex3f(x + -1.0,y + 1.0,z + 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(x + -1.0,y + 1.0,z + -2.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(x + -1.0,y + -1.0,z + -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(x + -1.0,y + -1.0,z + 1.0);

   glTexCoord2d(0.0, 0.0); glVertex3f(x + 1.0,y + 1.0,z + 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(x + 1.0,y + 1.0,z + -2.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(x + 1.0,y + -1.0,z + -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(x + 1.0,y + -1.0,z + 1.0);
   glEnd();

   //FreeTexture(texture);

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
   //glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
}

void drawCow(GLuint texture[])
{

   //GLfloat angle = 0; 
   //GLfloat angle2 = 0; 
   //GLfloat angle3 = 0;
   //GLfloat angle4 = 0;
   //GLfloat phase = 1;

   glTranslatef(x + 1.0,y + 1.0,z + 0.0);
   head(texture);
   body(texture);


      frontRightLegTop(texture);

      frontLeftLegTop(texture);
      //angle--;

            frontRightLegBot(texture);

            frontLeftLegBot(texture);
      //angle3++;


      backLeftLegTop(texture);         

      backRightLegTop(texture);

      //angle2--;
            backRightLegBot(texture);

            backLeftLegBot(texture);
      //angle4++;

         glTranslatef(-x + 1.0,-y + 1.0,-z + 0.0);
}

void lWing()
{
  if(LAngle > -90 && lastSub == 1)
  {
    LAngle -= 1.0f;
  }
  else if(LAngle == -90)
  {
    lastSub = 0;
    LAngle += 1.0f;
  }
  else if(LAngle < 0 && lastSub == 0)
  {
    LAngle += 1.0f;
  }
  else if(LAngle == 0)
  {
    lastSub = 1;
    LAngle -= 1.0f;
  }
}

void rWing()
{
  if(RAngle < 90 && lastAdd == 1)
  {
    RAngle += 1.0f;
  }
  else if(RAngle == 90)
  {
    lastAdd = 0;
    RAngle -= 1.0f;
  }
  else if(RAngle > 0 && lastAdd == 0)
  {
    RAngle -= 1.0f;
  }
  else if(RAngle == 0)
  {
    lastAdd = 1;
    RAngle += 1.0f;
  } 
}

void drawChicken(GLuint texture[])
{

  glBindTexture(GL_TEXTURE_2D, texture[0]);
    //The body
    glBegin(GL_QUADS);
      //Top face
      glColor3f(0.8f, 0.5f, 0.25f);
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + 1.0f, z + 1.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + 1.0f, z + 1.0f);

      //Bottom face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + -1.0f);
 
      //Front face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + 1.0f);
 
      //Back face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + 1.0f, z + -1.0f);
      
      //Left face
      glTexCoord2d(0.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + 1.0f);
      
      //Right face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + -1.0f);
    glEnd();
    glDisable (GL_TEXTURE_2D);
    
    //The head  
    glPushMatrix();
  glTranslatef(0.0f, 1.0f, 1.0f);
  glRotatef(LAngle, 0.0f, 1.0f, 0.0f);
  glTranslatef(0.0f, -1.0f, -1.0f);
    glBegin(GL_QUADS);
      //Top face
    glColor3f(1.0f, 0.87f, 0.68f);
        glVertex3f(x + 0.5f, y + 1.5f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.5f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
        glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
        
        //Bottom face
        glVertex3f(x + 0.5f, y + 1.0f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.0f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.0f, z + 1.8f);
        glVertex3f(x + 0.5f, y + 1.0f, z + 1.8f);
        
        //Front face
        glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
        glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
        glVertex3f(x + -0.5f, y + 1.0f, z + 1.8f);
        glVertex3f(x + 0.5f, y + 1.0f, z + 1.8f);
        
        //Back face
        glVertex3f(x + 0.5f, y + 1.0f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.0f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.5f, z + 0.8f);
        glVertex3f(x + 0.5f, y + 1.5f, z + 0.8f);
        
        //Left face
        glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
        glVertex3f(x + -0.5f, y + 1.5f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.0f, z + 0.8f);
        glVertex3f(x + -0.5f, y + 1.0f, z + 1.8f);
        
        //Right face
        glVertex3f(x + 0.5f, y + 1.5f, z + 0.8f);
        glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
        glVertex3f(x + 0.5f, y + 1.0f, z + 1.8f);
        glVertex3f(x + 0.5f, y + 1.0f, z + 0.8f);
  //glEnd();
  
  //The Eyes
  //glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    //Right eye
    glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
    glVertex3f(x + 0.25f, y + 1.5f, z + 1.8f);
    glVertex3f(x + 0.25f, y + 1.25f, z + 1.8f);
    glVertex3f(x + 0.5f, y + 1.25f, z + 1.8f);
    
    //Left eye
    glVertex3f(x + -0.25f, y + 1.5f, z + 1.8f);
    glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
    glVertex3f(x + -0.5f, y + 1.25f, z + 1.8f);
    glVertex3f(x + -0.25f, y + 1.25f, z + 1.8f);
  //glEnd();
  
  //The Beak
  //glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    
    //Top face
    glVertex3f(x + 0.25f, y + 1.25f, z + 1.8f);
    glVertex3f(x + -0.25f, y + 1.25f, z + 1.8f);
    glVertex3f(x + -0.25f, y + 1.25f, z + 2.2f);
    glVertex3f(x + 0.25f, y + 1.25f, z + 2.2f);
    
    //Bottom face
    glVertex3f(x + 0.25f, y + 1.0f, z + 1.8f);
    glVertex3f(x + -0.25f, y + 1.0f, z + 1.8f);
    glVertex3f(x + -0.25f, y + 1.0f, z + 2.2f);
    glVertex3f(x + 0.25f, y + 1.0f, z + 2.2f);
    
    //Front face
    glVertex3f(x + 0.25f, y + 1.25f, z + 2.2f);
    glVertex3f(x + -0.25f, y + 1.25f, z + 2.2f);
    glVertex3f(x + -0.25f, y + 1.0f, z + 2.2f);
    glVertex3f(x + 0.25f, y + 1.0f, z + 2.2f);
    
    //Left face
    glVertex3f(x + -0.25f, y + 1.25f, z + 2.2f);
    glVertex3f(x + -0.25f, y + 1.25f, z + 1.8f);
    glVertex3f(x + -0.25f, y + 1.0f, z + 1.8f);
    glVertex3f(x + -0.25f, y + 1.0f, z + 2.2f);
    
    //Right face
    glVertex3f(x + 0.25f, y + 1.25f, z + 1.8f);
    glVertex3f(x + 0.25f, y + 1.25f, z + 2.2f);
    glVertex3f(x + 0.25f, y + 1.0f, z + 2.2f);
    glVertex3f(x + 0.25f, y + 1.0f, z + 1.8f);    
  //glEnd();
  
  //The Gullet
  //glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    
    //Bottom face
    glVertex3f(x + 0.125f, y + 0.8f, z + 1.0f);
    glVertex3f(x + -0.125f, y + 0.8f, z + 1.0f);
    glVertex3f(x + -0.125f, y + 0.8f, z + 1.8f);
    glVertex3f(x + 0.125f, y + 0.8f, z + 1.8f);
    
    //Front face
    glVertex3f(x + 0.125f, y + 1.0f, z + 1.8f);
    glVertex3f(x + -0.125f, y + 1.0f, z + 1.8f);
    glVertex3f(x + -0.125f, y + 0.8f, z + 1.8f);
    glVertex3f(x + 0.125f, y + 0.8f, z + 1.8f);
    
    //Left face
    glVertex3f(x + -0.125f, y + 1.0f, z + 1.8f);
    glVertex3f(x + -0.125f, y + 1.0f, z + 1.0f);
    glVertex3f(x + -0.125f, y + 0.8f, z + 1.0f);
    glVertex3f(x + -0.125f, y + 0.8f, z + 1.8f);
    
    //Right face
    glVertex3f(x + 0.125f, y + 1.0f, z + 1.0f);
    glVertex3f(x + 0.125f, y + 1.0f, z + 1.8f);
    glVertex3f(x + 0.125f, y + 0.8f, z + 1.8f);
    glVertex3f(x + 0.125f, y + 0.8f, z + 1.0f);
  glEnd();
  glPopMatrix();
  
  //The Legs
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    //Left leg
    //Bottom face
    glVertex3f(x + -0.33f, y + -2.0f, z + -0.33f);
    glVertex3f(x + -0.66f, y + -2.0f, z + -0.33f);
    glVertex3f(x + -0.66f, y + -2.0f, z + 0.33f);
    glVertex3f(x + -0.33f, y + -2.0f, z + 0.33f);
    
    //Front face
    glVertex3f(x + -0.33f, y + -1.0f, z + 0.33f);
    glVertex3f(x + -0.66f, y + -1.0f, z + 0.33f);
    glVertex3f(x + -0.66f, y + -2.0f, z + 0.33f);
    glVertex3f(x + -0.33f, y + -2.0f, z + 0.33f);
    
    //Back face
    glVertex3f(x + -0.33f, y + -1.0f, z + -0.33f);
    glVertex3f(x + -0.66f, y + -1.0f, z + -0.33f);
    glVertex3f(x + -0.66f, y + -2.0f, z + -0.33f);
    glVertex3f(x + -0.33f, y + -2.0f, z + -0.33f);
    
    //Left face
    glVertex3f(x + -0.66f, y + -1.0f, z + 0.33f);
    glVertex3f(x + -0.66f, y + -1.0f, z + -0.33f);
    glVertex3f(x + -0.66f, y + -2.0f, z + -0.33f);
    glVertex3f(x + -0.66f, y + -2.0f, z + 0.33f);
    
    //Right face
    glVertex3f(x + -0.33f, y + -1.0f, z + -0.33f);
    glVertex3f(x + -0.33f, y + -1.0f, z + 0.33f);
    glVertex3f(x + -0.33f, y + -2.0f, z + 0.33f);
    glVertex3f(x + -0.33f, y + -2.0f, z + -0.33f);
  glEnd();
  
  //Right leg
  //Bottom face
  glBegin(GL_QUADS);
    glVertex3f(x + 0.66f, y + -2.0f, z + -0.33f);
    glVertex3f(x + 0.33f, y + -2.0f, z + -0.33f);
    glVertex3f(x + 0.33f, y + -2.0f, z + 0.33f);
    glVertex3f(x + 0.66f, y + -2.0f, z + 0.33f);
    
    //Front face
    glVertex3f(x + 0.66f, y + -1.0f, z + 0.33f);
    glVertex3f(x + 0.33f, y + -1.0f, z + 0.33f);
    glVertex3f(x + 0.33f, y + -2.0f, z + 0.33f);
    glVertex3f(x + 0.66f, y + -2.0f, z + 0.33f);
    
    //Back face
    glVertex3f(x + 0.66f, y + -1.0f, z + -0.33f);
    glVertex3f(x + 0.33f, y + -1.0f, z + -0.33f);
    glVertex3f(x + 0.33f, y + -2.0f, z + -0.33f);
    glVertex3f(x + 0.66f, y + -2.0f, z + -0.33f);
    
    //Left face
    glVertex3f(x + 0.33f, y + -1.0f, z + 0.33f);
    glVertex3f(x + 0.33f, y + -1.0f, z + -0.33f);
    glVertex3f(x + 0.33f, y + -2.0f, z + -0.33f);
    glVertex3f(x + 0.33f, y + -2.0f, z + 0.33f);
    
    //Right face
    glVertex3f(x + 0.66f, y + -1.0f, z + -0.33f);
    glVertex3f(x + 0.66f, y + -1.0f, z + 0.33f);
    glVertex3f(x + 0.66f, y + -2.0f, z + 0.33f);
    glVertex3f(x + 0.66f, y + -2.0f, z + -0.33f);
  glEnd();

    glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture[0]);
  //The wings
  //Left Wing
  glPushMatrix();
  glTranslatef(-1.0f, 1.0f, 0.0f);
  glRotatef(LAngle, 0.0f, 0.0f, 1.0f);
  glTranslatef(1.0f, -1.0f, 0.0f);
  glBegin(GL_QUADS);
      glColor3f(0.8f, 0.5f, 0.25f);
    glTexCoord2d(0.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + 0.75f);
    glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + -0.75f);
    glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -0.33f, z + -0.75f);
    glTexCoord2d(0.0,1.0); glVertex3f(x + -1.0f, y + -0.33f, z + 0.75f);
  glEnd();
  glPopMatrix();
  
  glBindTexture(GL_TEXTURE_2D, texture[0]);
  //Right wing
  glPushMatrix();
  glTranslatef(1.0f, 1.0f, 0.0f);
  glRotatef(RAngle, 0.0f, 0.0f, 1.0f);
  glTranslatef(-1.0f, -1.0f, 0.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + -0.75f);
    glTexCoord2d(1.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + 0.75f);
    glTexCoord2d(1.0,1.0); glVertex3f(x + 1.0f, y + -0.33f, z + 0.75f);
    glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -0.33f, z + -0.75f);
  glEnd();
  glPopMatrix();
  
  //lWing();
  //rWing();
}


void drawUFO()
{
  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x+0, y+2, z+0);
    for (int angle2 = 0; angle2 < 360; angle2++)
    {
      glColor3f(0.0f, angle2/100, 0.0f);
      glVertex3f(x+sin(angle2) * 10, y+0, z+cos(angle2) * 10);
    }
  glEnd();

  glColor3f(1.0f, 0.0f, 0.0f);
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x+0, y+-2, z+0);
    for (int angle2 = 0; angle2 < 360; angle2++)
    {
      glColor3f(angle2/100, 0.0f, 0.0f);
      glVertex3f(x+sin(angle2) * 10, y+0, z+cos(angle2) * 10);
    }
  glEnd();

  glTranslatef(x+0.0f, y+1.5f, z+0.0f);
  glColor3f(0.0f, 0.0f, 1.0f);
  glutSolidSphere(1.0f, 50.0f, 50.0f);
  glTranslatef(-x+0.0f, -y+1.5f, -z+0.0f);
}

void drawPost() 
{
  for(double j = 0; j < 51; j += 50)
  {
    for(double i = 0.00; i < 52; i += 2)
    {
      //begin vertical
        glColor3f(0.59f, 0.41f, 0.31f);

        glBegin(GL_QUADS);
          glVertex3f(j + 0.5f, 2.0f, i + 0.5f);
          glVertex3f(j + 1.0f, 2.0f, i + 0.5f);
          glVertex3f(j + 1.0f, 2.0f, i + 1.0f);
          glVertex3f(j + 0.5f, 2.0f, i + 1.0f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.5f, 0.1f, i + 0.5f);
          glVertex3f(j + 1.0f, 0.1f, i + 0.5f);
          glVertex3f(j + 1.0f, 2.0f, i + 0.5f);
          glVertex3f(j + 0.5f, 2.0f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.5f, 0.1f, i + 1.0f);
          glVertex3f(j + 1.0f, 0.1f, i + 1.0f);
          glVertex3f(j + 1.0f, 2.0f, i + 1.0f);
          glVertex3f(j + 0.5f, 2.0f, i + 1.0f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 1.0f, 0.1f, i + 0.5f);
          glVertex3f(j + 1.0f, 0.1f, i + 1.0f);
          glVertex3f(j + 1.0f, 2.0f, i + 1.0f);
          glVertex3f(j + 1.0f, 2.0f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.5f, 0.1f, i + 0.5f);
          glVertex3f(j + 0.5f, 0.1f, i + 1.0f);
          glVertex3f(j + 0.5f, 2.0f, i + 1.0f);
          glVertex3f(j + 0.5f, 2.0f, i + 0.5f);
        glEnd();

        if(i != 50)
        {
        //begin horizontal
        glColor3f(0.59f, 0.41f, 0.31f);
        glBegin(GL_QUADS);
          glVertex3f(j + 0.6f, 0.3f, i + 0.5f);
          glVertex3f(j + 0.6f, 0.3f, i + 3.0f);
          glVertex3f(j + 0.9f, 0.3f, i + 3.0f);
          glVertex3f(j + 0.9f, 0.3f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.6f, 0.7f, i + 0.5f);
          glVertex3f(j + 0.6f, 0.7f, i + 3.0f);
          glVertex3f(j + 0.9f, 0.7f, i + 3.0f);
          glVertex3f(j + 0.9f, 0.7f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.6f, 1.3f, i + 0.5f);
          glVertex3f(j + 0.6f, 1.3f, i + 3.0f);
          glVertex3f(j + 0.9f, 1.3f, i + 3.0f);
          glVertex3f(j + 0.9f, 1.3f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.6f, 1.7f, i + 0.5f);
          glVertex3f(j + 0.6f, 1.7f, i + 3.0f);
          glVertex3f(j + 0.9f, 1.7f, i + 3.0f);
          glVertex3f(j + 0.9f, 1.7f, i + 0.5f);
        glEnd();
        //
        glBegin(GL_QUADS);
          glVertex3f(j + 0.6f, 0.3f, i + 0.5f);
          glVertex3f(j + 0.6f, 0.3f, i + 3.0f);
          glVertex3f(j + 0.6f, 0.7f, i + 3.0f);
          glVertex3f(j + 0.6f, 0.7f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.9f, 0.3f, i + 0.5f);
          glVertex3f(j + 0.9f, 0.3f, i + 3.0f);
          glVertex3f(j + 0.9f, 0.7f, i + 3.0f);
          glVertex3f(j + 0.9f, 0.7f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.6f, 1.3f, i + 0.5f);
          glVertex3f(j + 0.6f, 1.3f, i + 3.0f);
          glVertex3f(j + 0.6f, 1.7f, i + 3.0f);
          glVertex3f(j + 0.6f, 1.7f, i + 0.5f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(j + 0.9f, 1.3f, i + 0.5f);
          glVertex3f(j + 0.9f, 1.3f, i + 3.0f);
          glVertex3f(j + 0.9f, 1.7f, i + 3.0f);
          glVertex3f(j + 0.9f, 1.7f, i + 0.5f);
        glEnd();
        }
      }
    }
    for(double j = 0; j < 51; j += 50)
    {
      for(double i = 0.00; i < 52; i += 2)
      {
      //begin vertical
      glColor3f(0.59f, 0.41f, 0.31f);

      glBegin(GL_QUADS);
      glVertex3f(i + 0.5f, 2.0f, j + 0.5f);
      glVertex3f(i + 1.0f, 2.0f, j + 0.5f);
      glVertex3f(i + 1.0f, 2.0f, j + 1.0f);
      glVertex3f(i + 0.5f, 2.0f, j + 1.0f);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(i + 0.5f, 0.1f, j + 0.5f);
      glVertex3f(i + 1.0f, 0.1f, j + 0.5f);
      glVertex3f(i + 1.0f, 2.0f, j + 0.5f);
      glVertex3f(i + 0.5f, 2.0f, j + 0.5f);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(i + 0.5f, 0.1f, j + 1.0f);
      glVertex3f(i + 1.0f, 0.1f, j + 1.0f);
      glVertex3f(i + 1.0f, 2.0f, j + 1.0f);
      glVertex3f(i + 0.5f, 2.0f, j + 1.0f);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(i + 1.0f, 0.1f, j + 0.5f);
      glVertex3f(i + 1.0f, 0.1f, j + 1.0f);
      glVertex3f(i + 1.0f, 2.0f, j + 1.0f);
      glVertex3f(i + 1.0f, 2.0f, j + 0.5f);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(i + 0.5f, 0.1f, j + 0.5f);
      glVertex3f(i + 0.5f, 0.1f, j + 1.0f);
      glVertex3f(i + 0.5f, 2.0f, j + 1.0f);
      glVertex3f(i + 0.5f, 2.0f, j + 0.5f);
      glEnd();

      if(i != 50)
      {
        //begin horizontal
        glColor3f(0.59f, 0.41f, 0.31f);
        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 0.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 0.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 0.3f, j + 0.9f);
          glVertex3f(i + 0.5f, 0.3f, j + 0.9f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 0.7f, j + 0.6f);
          glVertex3f(i + 3.0f, 0.7f, j + 0.6f);
          glVertex3f(i + 3.0f, 0.7f, j + 0.9f);
          glVertex3f(i + 0.5f, 0.7f, j + 0.9f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 1.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 1.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 1.3f, j + 0.9f);
          glVertex3f(i + 0.5f, 1.3f, j + 0.9f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 1.7f, j + 0.6f);
          glVertex3f(i + 3.0f, 1.7f, j + 0.6f);
          glVertex3f(i + 3.0f, 1.7f, j + 0.9f);
          glVertex3f(i + 0.5f, 1.7f, j + 0.9f);
        glEnd();
        //
        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 0.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 0.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 0.7f, j + 0.6f);
          glVertex3f(i + 0.5f, 0.7f, j + 0.6f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 0.3f, j + 0.9f);
          glVertex3f(i + 3.0f, 0.3f, j + 0.9f);
          glVertex3f(i + 3.0f, 0.7f, j + 0.9f);
          glVertex3f(i + 0.5f, 0.7f, j + 0.9f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 1.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 1.3f, j + 0.6f);
          glVertex3f(i + 3.0f, 1.7f, j + 0.6f);
          glVertex3f(i + 0.5f, 1.7f, j + 0.6f);
        glEnd();

        glBegin(GL_QUADS);
          glVertex3f(i + 0.5f, 1.3f, j + 0.9f);
          glVertex3f(i + 3.0f, 1.3f, j + 0.9f);
          glVertex3f(i + 3.0f, 1.7f, j + 0.9f);
          glVertex3f(i + 0.5f, 1.7f, j + 0.9f);
        glEnd();
      }
    }
  }
}

void drawFarm(GLuint texture[])
{
  glLineWidth(2);
  glColor3f(0.0f, 0.0f, 0.0f);
  glBegin(GL_LINES);
    glVertex3f(48.0f, 0.11f, 48.0f);
    glVertex3f(48.0f, 0.11f, 30.0f);

    glVertex3f(48.0f, 0.11f, 30.0f);
    glVertex3f(35.0f, 0.11f, 30.0f);

    glVertex3f(35.0f, 0.11f, 48.0f);
    glVertex3f(35.0f, 0.11f, 30.0f);

    glVertex3f(48.0f, 0.11f, 48.0f);
    glVertex3f(35.0f, 0.11f, 48.0f);
  glEnd();
  glLineWidth(1);

  glBindTexture(GL_TEXTURE_2D, texture[4]);
  glColor3f(0.80f, 0.0f, 0.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 30.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 0.1f, 48.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 30.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(48.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(48.0f, 5.0f, 48.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 30.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 5.0f, 30.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 48.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 5.0f, 48.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 48.0f);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, texture[5]);
  glColor3f(0.80f, 1.0f, 0.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 5.0f, 48.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(42.0f, 9.0f, 48.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(42.0f, 9.0f, 30.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(35.0f, 5.0f, 48.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(42.0f, 9.0f, 48.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(42.0f, 9.0f, 30.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(35.0f, 5.0f, 30.0f);
  glEnd();

  glColor3f(0.80f, 1.0f, 1.0f);
  glBegin(GL_TRIANGLES);
    glVertex3f(35.0f, 5.0f, 30.0f);
    glVertex3f(42.0f, 9.0f, 30.0f);
    glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_TRIANGLES);
    glVertex3f(35.0f, 5.0f, 48.0f);
    glVertex3f(42.0f, 9.0f, 48.0f);
    glVertex3f(48.0f, 5.0f, 48.0f);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, texture[4]);
  glColor3f(0.80f, 0.0f, 1.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(35.0f, 5.0f, 48.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 0.1f, 35.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(35.0f, 5.0f, 35.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(35.0f, 5.0f, 35.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 35.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(35.0f, 5.0f, 30.0f);
  glEnd();

  glColor3f(0.0f, 0.0f, 0.0f);

  glBegin(GL_LINES);
    glVertex3f(34.9f, 5.0f, 39.0f);
    glVertex3f(34.9f, 0.1f, 39.0f);
  glEnd();
}

void drawTrough()
{
  glColor3f(0.90f, 0.91f, 0.98f);
  glBegin(GL_QUADS);
    glVertex3f(39.0f, 1.0f, 23.0f);
    glVertex3f(39.0f, 2.0f, 23.0f);
    glVertex3f(43.0f, 2.0f, 23.0f);
    glVertex3f(43.0f, 1.0f, 23.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(39.0f, 1.0f, 16.0f);
    glVertex3f(39.0f, 2.0f, 16.0f);
    glVertex3f(43.0f, 2.0f, 16.0f);
    glVertex3f(43.0f, 1.0f, 16.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(39.0f, 1.0f, 23.0f);
    glVertex3f(39.0f, 2.0f, 23.0f);
    glVertex3f(39.0f, 2.0f, 16.0f);
    glVertex3f(39.0f, 1.0f, 16.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(43.0f, 1.0f, 23.0f);
    glVertex3f(43.0f, 2.0f, 23.0f);
    glVertex3f(43.0f, 2.0f, 16.0f);
    glVertex3f(43.0f, 1.0f, 16.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(39.0f, 1.0f, 23.0f);
    glVertex3f(43.0f, 1.0f, 23.0f);
    glVertex3f(43.0f, 1.0f, 16.0f);
    glVertex3f(39.0f, 1.0f, 16.0f);
  glEnd();

  glLineWidth(2); 
  glBegin(GL_LINES);
    glVertex3f(43.0f, 1.0f, 23.0f);
    glVertex3f(43.0f, 0.1f, 23.0f);

    glVertex3f(39.0f, 1.0f, 23.0f);
    glVertex3f(39.0f, 0.1f, 23.0f);

    glVertex3f(43.0f, 1.0f, 16.0f);
    glVertex3f(43.0f, 0.1f, 16.0f);

    glVertex3f(39.0f, 1.0f, 16.0f);
    glVertex3f(39.0f, 0.1f, 16.0f);
  glEnd();
  glLineWidth(1);

  glColor3f(1.0f, 1.0f, 0.0f);
  glBegin(GL_QUADS);
    glVertex3f(39.0f, 1.5f, 23.0f);
    glVertex3f(43.0f, 1.5f, 23.0f);
    glVertex3f(43.0f, 1.5f, 16.0f);
    glVertex3f(39.0f, 1.5f, 16.0f);
  glEnd();
}

void drawEnvironment(GLuint texture[])
{
  glBindTexture(GL_TEXTURE_2D, texture[3]);
  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2d(0.0,1.0); glVertex3f(0.0f, 0.0f, 52.0f);
    glTexCoord2d(1.0,1.0); glVertex3f(52.0f, 0.0f, 52.0f);
    glTexCoord2d(1.0,0.0); glVertex3f(52.f, 0.0f, 0.0f);
  glEnd();
  glDisable (GL_TEXTURE_2D);

  drawPost();
  drawFarm(texture);
  drawTrough();
}

void loadTextures(void)
{
  int c;
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  
  Image *image[6];
  for(c = 0; c < 6; c++)
  {
    image[c] = (Image *) malloc(sizeof(Image));
    if(image[c] == NULL) exit(0);
  }
  
  if(!imageLoad("./25-brown-black-bird-nice-feather-texture.ppm", image[0])) exit(0);
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image[0]->sizeX, image[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);

  if(!imageLoad("./aaa.ppm", image[1])) exit(0);
    glGenTextures(1, &texture[1]);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image[1]->sizeX, image[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[1]->data); 

  if(!imageLoad("./minecraft_cow.ppm", image[2])) exit(0);
    glGenTextures(1, &texture[2]);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image[2]->sizeX, image[2]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[2]->data);

  if(!imageLoad("./grass.ppm", image[3])) exit(0);
    glGenTextures(1, &texture[3]);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image[3]->sizeX, image[3]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[3]->data); 

  if(!imageLoad("./index.ppm", image[4])) exit(0);
    glGenTextures(1, &texture[4]);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image[4]->sizeX, image[4]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[4]->data); 

  if(!imageLoad("./roof.ppm", image[5])) exit(0);
    glGenTextures(1, &texture[5]);
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image[5]->sizeX, image[5]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[5]->data);     
}   

void lightc()
{
      GLfloat position[] = {5, 1.5, 15, 10.0};

       glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SINGLE_COLOR); 
 //  glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPERATE_SPECULAR_COLOR); 
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);

    glLightfv(GL_LIGHT0, GL_POSITION, position);

          // Ambient "light source".
      GLfloat ambient[] = {0.4f, 1.0f, 1.0f, 1.0f};
      GLfloat ambient_intensity[] = {0.4f, 0.4f, 0.4f, 1.0f};
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

 GLfloat diffuse[]  = {1.0, 1.0, 1.0, 1.0};
     glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);

     // Spectular light source.
 GLfloat specular[] = {1.0, 1.0, 1.0, 1.0}; 
    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);


    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_FLAT);
}

void myDisplay()
{

   glClearColor (0.0,0.0,0.0, 1.0); //clear the screen to black
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
   glLoadIdentity();

   glColor3f(1.0f, 1.0f, 1.0f);
   glTranslatef(0.0f, 0.0f, -50);
   glRotatef(35,1.0,0.0,0.0);

   if(start == 1 && forward == 1)
   {
      glRotatef(yrot,1.0,0.0,0.0);
      glRotatef(yrot,0.0,1.0,0.0);
      yrot++;
   }
   if(start == 1 && forward == 0)
   {
      glRotatef(yrot,1.0,0.0,0.0);
      glRotatef(yrot,0.0,1.0,0.0);
      yrot--;
   }

   //glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
   glTranslated(-19, 0.0f,-25); //translate the screen to the position of our camera
   glColor3f(1.0f, 1.0f, 1.0f);
   //cube(); //call the cube drawing function


   rayglFrameBegin("movie");

   drawEnvironment(texture);
   x = 0; y = 10; z = 0;
   drawUFO();
   x = 10; y = 0.01; z = 15;
   drawChicken(texture);
   x = 15; y = 0.01; z = 15;
   drawCow(texture);

   //uf.x++;


   //start 2d
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   glOrtho(0.0, 1000, 800, 0.0, -1.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   //glPushMatrix();        ----Not sure if I need this
   glLoadIdentity();
   glDisable(GL_CULL_FACE);

   glClear(GL_DEPTH_BUFFER_BIT);

   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0);
      glVertex2f(50.0, 50.0);
      glVertex2f(50.0, 100.0);
      glVertex2f(100.0, 100.0);
      glVertex2f(100.0, 50.0);
   glEnd();

   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0);
      glVertex2f(150.0, 150.0);
      glVertex2f(150.0, 200.0);
      glVertex2f(200.0, 200.0);
      glVertex2f(200.0, 150.0);
   glEnd();

   // Making sure we can render 3d again
   glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
   //glPopMatrix();        ----and this?


   glutSwapBuffers(); //swap the buffers

   rayglFrameEnd();

   angle++;
}

void myInit(void)
{
   
   rayglTextureType(0);
   rayglTranslateTexture(0, 0, 0);
   rayglScaleTexture(1, 1, 1);
   setFadeDistance(1000);
   setFadePower(1.4);
   glEnable (GL_DEPTH_TEST); //enable the depth testing
   glShadeModel (GL_SMOOTH); //set the shader to smooth shader
   lightc();
}

void keyboard (unsigned char key, int x, int y)
{
    if (key=='q')
    {
      xrot += 1;
      if (xrot >360) xrot -= 360;
    }

    if (key=='z')
    {
      xrot -= 1;
      if (xrot < -360) xrot += 360;
    }

    if (key=='w')
    {
      float xrotrad, yrotrad;
      yrotrad = (yrot / 180 * 3.141592654f);
      xrotrad = (xrot / 180 * 3.141592654f);
      xpos += float(sin(yrotrad));
      zpos -= float(cos(yrotrad));
      ypos -= float(sin(xrotrad));
    }

    if (key=='s')
    {
      float xrotrad, yrotrad;
      yrotrad = (yrot / 180 * 3.141592654f);
      xrotrad = (xrot / 180 * 3.141592654f);
      xpos -= float(sin(yrotrad));
      zpos += float(cos(yrotrad));
      ypos += float(sin(xrotrad));
    }

    if (key=='d')
    {
      float yrotrad;
      yrotrad = (yrot / 180 * 3.141592654f);
      xpos += float(cos(yrotrad)) * 0.2;
      zpos += float(sin(yrotrad)) * 0.2;
    }

    if (key=='a')
    {
      float yrotrad;
      yrotrad = (yrot / 180 * 3.141592654f);
      xpos -= float(cos(yrotrad)) * 0.2;
      zpos -= float(sin(yrotrad)) * 0.2;
    }

    if (key=='p')
    {
      cout << "XPOS: " << xpos << " YPOS: " << ypos << " ZPOS: " << zpos << endl;
    }

    if (key=='b' && start == 0)
    {
      start++;
      cout << start << endl;
    }

    else if (key=='b' && start == 1)
    {
      start -= 1;
      cout << start << endl;
    }

    if (key=='n' && forward == 0)
    {
      forward++;
      cout << forward << endl;
    }

    else if (key=='n' && forward == 1)
    {
      forward -= 1;
      cout << forward << endl;
    }

    if (key=='u')
    {
      rotating = 1;
    }

    if (key==27)
    {
      exit(0);
    }
}

void mouseClicks(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    { 

      cout << x << " " << y << " " << button << endl;
      if(x > 50 && x < 100 && y > 50 && y < 100 && start == 0)
      {
          start = 1;
          return;
      }

      else if(x > 50 && x < 100 && y > 50 && y < 100 && start == 1)
      {
          start = 0;
          return;
      }

      if(x > 150 && x < 200 && y > 150 && y < 200 && forward == 0)
      {
          forward = 1;
          return;
      }

      else if(x > 150 && x < 200 && y > 150 && y < 200 && forward == 1)
      {
          forward = 0;
          return;
      }
    }
}

void myReshape (int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize(1000, 800);
   glutInitWindowPosition(200, 200);
   glutCreateWindow("HW 2");
   glutDisplayFunc (myDisplay);
   glutIdleFunc (myDisplay);
   glutReshapeFunc (myReshape);
   glutMouseFunc(mouseClicks);
   loadTextures();
   xpos = 0; ypos = 0; zpos = 0; xrot = 0; yrot = 0; angle=0.0; cRadius = 10.0f;

   glutKeyboardFunc (keyboard);
   myInit();
   glutMainLoop();
}
