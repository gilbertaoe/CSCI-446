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
#include <unistd.h>
#include "./raygl.h"
#include "./raygldefs.h"

float xpos, ypos, zpos, xrot, yrot, zrot, angle5;
float lastx, lasty;
float cRadius; // our radius distance from our character
int rotating = 0;

int cowHeadMove = 0;
float cowHeadAngle = 0.0f;
int chickenAnimation = 0;
int ufoBeam = 0;
int egg = 0;
int abducted = 0;
float frontLegsRotate = 0;
float backLegsRotate = 0;
int isWalking = 0;
int phase = 1;
double angle, angle2 = 0;
double angle3, angle4 = 0;
double UFOAngle = 0;
int doors = 1;

int moviePhase1 = 0;
int moviePhase2 = 0;

float timer = 0.0;
float tempTimer = 0.0;

bool start = 0;
bool forward = 0;
GLfloat LAngle, RAngle;

GLuint texture[6];

GLfloat xUFO, yUFO, zUFO = 0;
GLfloat xChicken, yChicken, zChicken = 0;
GLfloat xCow, yCow, zCow = 0;

int lastSub = 1;
int lastAdd = 1;

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

void head(GLuint texture[])
{  
   glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

   glBindTexture( GL_TEXTURE_2D, texture[1]);

   glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -0.25, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 0.25, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 0.25, yCow + 1.0, zCow + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -0.25, yCow + 1.0, zCow + 1.5);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + 0.25, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 0.25, yCow + 1.0, zCow + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 0.25, yCow + 0.5, zCow + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + 0.25, yCow + 0.5, zCow + 1.0);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + 0.25, yCow + 0.5, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 0.25, yCow + 0.5, zCow + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + -0.25, yCow + 0.5, zCow + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -0.25, yCow + 0.5, zCow + 1.0);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -0.25, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + -0.25, yCow + 1.0, zCow + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + -0.25, yCow + 0.5, zCow + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -0.25, yCow + 0.5, zCow + 1.0);
   glEnd();

   glBindTexture( GL_TEXTURE_2D, texture[2]);

   glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -0.25, yCow + 1.0, zCow + 1.5);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 0.25, yCow + 1.0, zCow + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 0.25, yCow + 0.5, zCow + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -0.25, yCow + 0.5, zCow + 1.5);
   glEnd();

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
}

void backLeftLegTop()
{
   glTranslatef(xCow + 0.9f, yCow + -1.4f, zCow + -1.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-xCow + -0.9f, -yCow + 1.4f, -zCow + 1.9f);

   glBegin(GL_QUADS);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + -2.0);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -2.0);
   glEnd();
}

void backRightLegTop()
{
   glTranslatef(xCow + -0.9f, yCow + -1.4f, zCow + -1.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-xCow + 0.9f, -yCow + 1.4f, -zCow + 1.9f);

   glBegin(GL_QUADS);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + -2.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -2.0);
   glEnd();
}

void backLeftLegBot()
{
   glBegin(GL_QUADS);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + -2.0);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + -2.0);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + -2.0);
   glEnd();
} 

void backRightLegBot()
{
   glBegin(GL_QUADS);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + -1.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + -2.0);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + -2.0);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + -2.0);
   glEnd();
} 

void frontLeftLegBot()
{
   glBegin(GL_QUADS);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + 0.8);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.8, zCow + 0.8);
      glVertex3f(xCow + 0.8, yCow + -1.8, zCow + 0.8);
   glEnd();
}

void frontRightLegBot()
{
   glBegin(GL_QUADS);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.8, zCow + 0.8);
      glVertex3f(xCow + -0.8, yCow + -1.8, zCow + 0.8);
   glEnd();
}

void frontLeftLegTop()
{
   glTranslatef(xCow + 0.9f, yCow + -1.4f, zCow + 0.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-xCow + -0.9f, -yCow + 1.4f, -zCow + -0.9f);

   glBegin(GL_QUADS);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + 0.8);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + 0.8, yCow + -1.0, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.0, zCow + 0.8);
      glVertex3f(xCow + 1.0, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + 0.8, yCow + -1.4, zCow + 0.8);
   glEnd();
}

void frontRightLegTop()
{

   glTranslatef(xCow + -0.9f, yCow + -1.4f, zCow + 0.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-xCow + 0.9f, -yCow + 1.4f, -zCow + -0.9f);

   glBegin(GL_QUADS);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + 0.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.0, zCow + 1.0);
      glVertex3f(xCow + -0.8, yCow + -1.0, zCow + 0.8);
      glVertex3f(xCow + -1.0, yCow + -1.4, zCow + 0.8);
      glVertex3f(xCow + -0.8, yCow + -1.4, zCow + 0.8);
   glEnd();
}

void body(GLuint texture[])
{
   glTranslatef(xCow + 0.9f, yCow + -1.0f, zCow + -1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-xCow + -0.9f, -yCow + 1.0f, -zCow + 1.9f);

   glTranslatef(xCow + -0.9f, yCow + -1.0f, zCow + -1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-xCow + 0.9f, -yCow + 1.0f, -zCow + 1.9f);

   glTranslatef(xCow + 0.9f, yCow + -1.0f, zCow + 0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-xCow + -0.9f, -yCow + 1.0f, -zCow + -0.9f);

   glTranslatef(xCow + -0.9f, yCow + -1.0f, zCow + 0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-xCow + 0.9f, -yCow + 1.0f, -zCow + -0.9f);

   glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

   glBindTexture( GL_TEXTURE_2D, texture[1]);

   glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -1.0, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 1.0, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 1.0, yCow + -1.0, zCow + 1.0);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -1.0, yCow + -1.0, zCow + 1.0);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -1.0, yCow + 1.0, zCow + -2.0); 
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 1.0, yCow + 1.0, zCow + -2.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 1.0, yCow + -1.0, zCow + -2.0);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -1.0, yCow + -1.0, zCow + -2.0);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -1.0, yCow + -1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 1.0, yCow + -1.0, zCow + 1.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 1.0, yCow + -1.0, zCow + -2.0);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -1.0, yCow + -1.0, zCow + -2.0);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -1.0, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 1.0, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 1.0, yCow + 1.0, zCow + -2.0);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -1.0, yCow + 1.0, zCow + -2.0);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + -1.0, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + -1.0, yCow + 1.0, zCow + -2.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + -1.0, yCow + -1.0, zCow + -2.0);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + -1.0, yCow + -1.0, zCow + 1.0);
      glTexCoord2d(0.0, 0.0); glVertex3f(xCow + 1.0, yCow + 1.0, zCow + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(xCow + 1.0, yCow + 1.0, zCow + -2.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(xCow + 1.0, yCow + -1.0, zCow + -2.0);
      glTexCoord2d(0.0, 1.0); glVertex3f(xCow + 1.0, yCow + -1.0, zCow + 1.0);
   glEnd();

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
}

void drawCow(GLuint texture[])
{
   glTranslatef(xCow, yCow, zCow);

   if(cowHeadMove == 1)
   {
      if(cowHeadAngle > -45)
      {
         glTranslatef(xCow + -0.25, yCow + 0.5, zCow + 1.0);
         glRotatef(cowHeadAngle,-1.0,0.0,0.0);
         glTranslatef(-xCow + 0.25, -yCow + -0.5, -zCow + -1.0);
         head(texture);
         glTranslatef(xCow + -0.25, yCow + 0.5, zCow + 1.0);
         glRotatef(-cowHeadAngle,-1.0,0.0,0.0);
         glTranslatef(-xCow + 0.25, -yCow + -0.5, -zCow + -1.0);
         cowHeadAngle--;
      }
      else
      {
         glTranslatef(xCow + -0.25, yCow + 0.5, zCow + 1.0);
         glRotatef(cowHeadAngle,-1.0,0.0,0.0);
         glTranslatef(-xCow + 0.25, -yCow + -0.5, -zCow + -1.0);
         head(texture);
         glTranslatef(xCow + -0.25, yCow + 0.5, zCow + 1.0);
         glRotatef(-cowHeadAngle,-1.0,0.0,0.0);
         glTranslatef(-xCow + 0.25, -yCow + -0.5, -zCow + -1.0);
         cowHeadAngle++;
      }
   }
   else
   {
      head(texture);
   }


   body(texture);

   /*frontRightLegTop(texture);
   frontLeftLegTop(texture);
   frontRightLegBot(texture);
   frontLeftLegBot(texture);
   backLeftLegTop(texture);         
   backRightLegTop(texture);
   backRightLegBot(texture);
   backLeftLegBot(texture);*/

   
   if(angle == -36 && phase == 1)
   {
      phase = 2;
   }

   if(angle2 == -36 && phase == 2)
   {
      phase = 3;
   }

   if (angle3 == 0 && phase == 3)
   {
      phase = 4;
   }

   if (angle == 0 && phase == 4)
   {
      phase = 5;
   }

   if (angle == -36 && phase == 5)
   {
      phase = 6;
   }
   if (angle2 == -36 && phase == 6)
   {
      phase = 3;
   }

   if (isWalking == 1 && phase <= 6)
   {
      if(phase == 1)
      {
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-xCow + -0.8f, -yCow + 1.0f,-zCow + -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(xCow + 0.8f,yCow +  -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-xCow + -0.8f,-yCow +  1.0f, -zCow + -0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f, -yCow + 1.0f, -zCow + -0.8f);
         frontLeftLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f,zCow +  0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f, -yCow + 1.0f, -zCow + -0.8f);
         angle -= 4;

         glTranslatef(xCow + 0.8f, yCow + -1.0f,zCow +  0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f, -yCow + 1.0f, -zCow + -0.8f);
            glTranslatef(xCow + 0.8f, yCow + -1.4f,zCow +  0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + -0.8f,-yCow +  1.4f,-zCow +  -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(xCow + 0.8f,yCow +  -1.4f, zCow + 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + -0.8f, -yCow + 1.4f,-zCow +  -0.8f);//same.1
         glTranslatef(xCow + 0.8f,yCow +  -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f, -yCow + 1.0f, -zCow + -0.8f);//same

         glTranslatef(xCow + 0.8f,yCow +  -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f, -yCow + 1.0f, -zCow + -0.8f);
            glTranslatef(xCow + 0.8f,yCow +  -1.4f,zCow +  0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + -0.8f,-yCow +  1.4f, -zCow + -0.8f);
               frontLeftLegBot();
            glTranslatef(xCow + 0.8f, yCow + -1.4f, zCow + 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + -0.8f,-yCow + 1.4f,-zCow +  -0.8f);
         glTranslatef(xCow + 0.8f,yCow +  -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f,-yCow +  1.0f, -zCow + -0.8f);
         angle3 += 4;

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f, -yCow + 1.0f, -zCow + 1.8f);
         backLeftLegTop();         
         glTranslatef(xCow + 0.8f,yCow +  -1.0f,zCow +  -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f,-yCow +  1.0f, -zCow + 1.8f);

         glTranslatef(xCow + -0.8f, yCow + -1.0f, zCow + -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + 0.8f, -yCow + 1.0f, -zCow + 1.8f);
         backRightLegTop();
         glTranslatef(xCow + -0.8f, yCow + -1.0f,zCow +  -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + 0.8f,-yCow +  1.0f, -zCow + 1.8f);
         //angle2--;

         glTranslatef(xCow + -0.8f,yCow +  -1.0f, zCow + -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + 0.8f, -yCow + 1.0f,-zCow +  1.8f);
            glTranslatef(xCow + -0.8f, yCow + -1.4f, zCow + -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + 0.8f, -yCow + 1.4f,-zCow +  1.8f);
               backRightLegBot();
            glTranslatef(xCow + -0.8f,yCow +  -1.4f, zCow + -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + 0.8f, -yCow + 1.4f, -zCow + 1.8f);
         glTranslatef(xCow + -0.8f, yCow + -1.0f, zCow + -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + 0.8f,-yCow +  1.0f, -zCow + 1.8f);

         glTranslatef(xCow + 0.8f, yCow + -1.0f,zCow +  -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f,-yCow +  1.0f, -zCow + 1.8f);
            glTranslatef(xCow + 0.8f,yCow +  -1.4f,zCow +  -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + -0.8f,-yCow +  1.4f,- zCow + 1.8f);
               backLeftLegBot();
            glTranslatef(xCow + 0.8f, yCow + -1.4f,zCow +  -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow + -0.8f,-yCow +  1.4f,-zCow +  1.8f);
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow + -0.8f,-yCow +  1.0f,-zCow +  1.8f);
         //angle4++;
      }
      if(phase == 2)
      {
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//inverse
         frontRightLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         frontLeftLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         //angle--;

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//inverse
               frontRightLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//same.1
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
               frontLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         angle3 += 4;

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         backLeftLegTop();         
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         backRightLegTop();
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         angle2 -= 4;

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
               backRightLegBot();
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
               backLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         angle4 += 4;
      }
      if(phase == 3)
      {
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//inverse
         frontRightLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         frontLeftLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         //angle++;

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//inverse
               frontRightLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//same.1
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
               frontLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         angle3 -= 4;

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         backLeftLegTop();         
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         backRightLegTop();
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         //angle2--;

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
               backRightLegBot();
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
               backLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         //angle4++;
      }
      if(phase == 4)
      {
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//inverse
         frontRightLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         frontLeftLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         angle += 4;

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//inverse
               frontRightLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//same.1
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
               frontLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         //angle3++;

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         backLeftLegTop();         
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         backRightLegTop();
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         angle2 += 4;

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
               backRightLegBot();
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
               backLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         //angle4++;
      }
      if(phase == 5)
      {
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//inverse
         frontRightLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         frontLeftLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         angle -= 4;

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//inverse
               frontRightLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//same.1
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
               frontLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         angle3 += 4;

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         backLeftLegTop();         
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         backRightLegTop();
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         angle2 += 4;

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
               backRightLegBot();
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
               backLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         //angle4++;
      }
      if(phase == 6)
      {
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//inverse
         frontRightLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         frontLeftLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         //angle--;

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//inverse
               frontRightLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//same.1
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
               frontLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         //angle3++;

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         backLeftLegTop();         
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         backRightLegTop();
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         angle2 -= 4;

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
               backRightLegBot();
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
               backLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         //angle4++;
      }
   }
   else
   {
      glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//inverse
         frontRightLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         frontLeftLegTop();
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         //angle--;

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//inverse
               frontRightLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);//same.1
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);//same

         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
               frontLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f,-yCow+ 1.4f, -zCow+-0.8f);
         glTranslatef(xCow + 0.8f, yCow + -1.0f, zCow + 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f,-zCow+-0.8f);
         //angle3++;

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         backLeftLegTop();         
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         backRightLegTop();
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
         //angle2--;

         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
               backRightLegBot();
            glTranslatef(xCow+-0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+-0.8f,yCow+ -1.0f,zCow+ -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+0.8f,-yCow+ 1.0f,-zCow+ 1.8f);

         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
               backLeftLegBot();
            glTranslatef(xCow+0.8f,yCow+ -1.4f,zCow+ -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-xCow+-0.8f, -yCow+1.4f, -zCow+1.8f);
         glTranslatef(xCow+0.8f, yCow+-1.0f, zCow+-1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-xCow+-0.8f, -yCow+1.0f, -zCow+1.8f);
         //angle4++;

         angle = 0; 
         angle2 = 0; 
         angle3 = 0;
         angle4 = 0;
         phase = 1;
   }
	

   glTranslatef(-xCow, -yCow, -zCow);
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
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture[0]);
   //The body
   glBegin(GL_QUADS);
   glColor3f(0.8f, 0.5f, 0.25f);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + 1.0f);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + -1.0f, zChicken + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + -1.0f, zChicken + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + -1.0f, zChicken + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + -1.0f, zChicken + -1.0f);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + -1.0f, zChicken + 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + -1.0f, zChicken + 1.0f);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + -1.0f, zChicken + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + -1.0f, zChicken + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + -1.0f);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + -1.0f, zChicken + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + -1.0f, zChicken + 1.0f);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + -1.0f, zChicken + 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + -1.0f, zChicken + -1.0f);
   glEnd();
   glDisable (GL_TEXTURE_2D);

   //The head  
   glPushMatrix();
   glTranslatef(xChicken + 0.0f, yChicken + 1.0f, zChicken + 1.0f);
   glRotatef(LAngle, 0.0f, 1.0f, 0.0f);
   glTranslatef(-xChicken + 0.0f, -yChicken + -1.0f, -zChicken + -1.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.87f, 0.68f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.5f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.5f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.5f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.5f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.0f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.0f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.5f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.5f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.0f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.0f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.5f, zChicken + 0.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.5f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.5f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.5f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.0f, zChicken + 0.8f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.5f, zChicken + 0.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.5f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.0f, zChicken + 0.8f);

      //The Eyes
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.5f, zChicken + 1.81f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.5f, zChicken + 1.81f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.25f, zChicken + 1.81f);
      glVertex3f(xChicken + 0.5f, yChicken + 1.25f, zChicken + 1.81f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.5f, zChicken + 1.81f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.5f, zChicken + 1.81f);
      glVertex3f(xChicken + -0.5f, yChicken + 1.25f, zChicken + 1.81f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.25f, zChicken + 1.81f);
     
      //The Beak
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.25f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.25f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.25f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.25f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.0f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.0f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.25f, zChicken + 2.2f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.25f, zChicken + 2.2f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.0f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.0f, zChicken + 2.2f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.25f, zChicken + 2.2f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.25f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.25f, yChicken + 1.0f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.25f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.25f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.0f, zChicken + 2.2f);
      glVertex3f(xChicken + 0.25f, yChicken + 1.0f, zChicken + 1.8f);    

      //The Gullet
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(xChicken + 0.125f, yChicken + 0.8f, zChicken + 1.0f);
      glVertex3f(xChicken + -0.125f, yChicken + 0.8f, zChicken + 1.0f);
      glVertex3f(xChicken + -0.125f, yChicken + 0.8f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.125f, yChicken + 0.8f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.125f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.125f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.125f, yChicken + 0.8f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.125f, yChicken + 0.8f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.125f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + -0.125f, yChicken + 1.0f, zChicken + 1.0f);
      glVertex3f(xChicken + -0.125f, yChicken + 0.8f, zChicken + 1.0f);
      glVertex3f(xChicken + -0.125f, yChicken + 0.8f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.125f, yChicken + 1.0f, zChicken + 1.0f);
      glVertex3f(xChicken + 0.125f, yChicken + 1.0f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.125f, yChicken + 0.8f, zChicken + 1.8f);
      glVertex3f(xChicken + 0.125f, yChicken + 0.8f, zChicken + 1.0f);
   glEnd();
   glPopMatrix();

   //The Legs
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f(xChicken + -0.33f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.66f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + -0.33f, yChicken + -2.0f, zChicken + -0.33f);
   glEnd();

   //Right leg
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f(xChicken + 0.66f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -2.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.33f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -1.0f, zChicken + -0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -1.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -2.0f, zChicken + 0.33f);
      glVertex3f(xChicken + 0.66f, yChicken + -2.0f, zChicken + -0.33f);
   glEnd();

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture[0]);

   //Left Wing
   glPushMatrix();
   glTranslatef(xChicken + -1.0f, yChicken +  1.0f, zChicken + 0.0f);
   glRotatef(LAngle, 0.0f, 0.0f, 1.0f);
   glTranslatef(-xChicken + 1.0f, -yChicken +  -1.0f, -zChicken + 0.0f);
   glBegin(GL_QUADS);
      glColor3f(0.8f, 0.5f, 0.25f);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + 0.75f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + -1.0f, yChicken + 1.0f, zChicken + -0.75f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + -0.33f, zChicken + -0.75f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + -1.0f, yChicken + -0.33f, zChicken + 0.75f);
   glEnd();
   glPopMatrix();

   glBindTexture(GL_TEXTURE_2D, texture[0]);
   //Right wing
   glPushMatrix();
   glTranslatef(xChicken + 1.0f, yChicken + 1.0f, zChicken + 0.0f);
   glRotatef(RAngle, 0.0f, 0.0f, 1.0f);
   glTranslatef(-xChicken + -1.0f, -yChicken + -1.0f, -zChicken + 0.0f);
   glBegin(GL_QUADS);
      glTexCoord2d(0.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + -0.75f);
      glTexCoord2d(1.0,0.0); glVertex3f(xChicken + 1.0f, yChicken + 1.0f, zChicken + 0.75f);
      glTexCoord2d(1.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + -0.33f, zChicken + 0.75f);
      glTexCoord2d(0.0,1.0); glVertex3f(xChicken + 1.0f, yChicken + -0.33f, zChicken + -0.75f);
   glEnd();
   glPopMatrix();

   if(chickenAnimation == 1)
   {
      lWing();
      rWing();
   }
}

void drawUFO()
{
   glDisable(GL_TEXTURE_2D);
   glColor3f(0.0f, 1.0f, 0.0f);
   if(ufoBeam == 1)
   {
      for(int i = 0; i < 360; i++)
      {
         glBegin(GL_LINES);
            glVertex3f(xUFO + sin(i), yUFO + -2.0f, zUFO + cos(i));
            glVertex3f(xUFO + sin(i), yChicken, zUFO + cos(i));
         glEnd();
      }
   }

   glTranslatef(xUFO, yUFO, zUFO);
   glRotatef(angle5,0.0,1.0,0.0);
   glTranslatef(-xUFO, -yUFO, -zUFO);

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + 0, yUFO + 2, zUFO + 0);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(0.0f, angle2/100, 0.0f);
         glVertex3f(xUFO + sin(angle2) * 10, yUFO + 0, zUFO + cos(angle2) * 10);
      }
   glEnd();

   glTranslatef(xUFO, yUFO, zUFO);
   glRotatef(-angle5,0.0,1.0,0.0);
   glTranslatef(-xUFO, -yUFO, -zUFO);

   glTranslatef(xUFO, yUFO, zUFO);
   glRotatef(-angle5,0.0,1.0,0.0);
   glTranslatef(-xUFO, -yUFO, -zUFO);

   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + 0, yUFO + -2, zUFO + 0);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(angle2/100, 0.0f, 0.0f);
         glVertex3f(xUFO + sin(angle2) * 10, yUFO + 0, zUFO + cos(angle2) * 10);
      }
   glEnd();

   glTranslatef(xUFO, yUFO, zUFO);
   glRotatef(angle5,0.0,1.0,0.0);
   glTranslatef(-xUFO, -yUFO, -zUFO);

   //landing gear
   glTranslatef(xUFO + -6.5f, yUFO + -3.0f, zUFO + -6.5f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glutSolidSphere(0.3f, 50.0f, 50.0f);
   glTranslatef(-xUFO + 6.5f, -yUFO + 3.0f, -zUFO + 6.5f);

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + -6.5, yUFO + -3, zUFO + -6.5);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(1.0f, 1.0f, 1.0f);
         glVertex3f(xUFO + sin(angle2) * 2, yUFO + 0, zUFO + cos(angle2) * 2);
      }
   glEnd();

   glTranslatef(xUFO + -6.5f, yUFO + -3.0f, zUFO + 6.5f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glutSolidSphere(0.3f, 50.0f, 50.0f);
   glTranslatef(-xUFO + 6.5f, -yUFO + 3.0f, -zUFO + -6.5f);

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + -6.5, yUFO + -3, zUFO + 6.5);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(1.0f, 1.0f, 1.0f);
         glVertex3f(xUFO + sin(angle2) * 2, yUFO + 0, zUFO + cos(angle2) * 2);
      }
   glEnd();

   glTranslatef(xUFO + 6.5f, yUFO + -3.0f, zUFO + 6.5f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glutSolidSphere(0.3f, 50.0f, 50.0f);
   glTranslatef(-xUFO + -6.5f, -yUFO + 3.0f, -zUFO + -6.5f);

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + 6.5, yUFO + -3, zUFO + 6.5);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(1.0f, 1.0f, 1.0f);
         glVertex3f(xUFO + sin(angle2) * 2, yUFO + 0, zUFO + cos(angle2) * 2);
      }
   glEnd();

   glTranslatef(xUFO + 6.5f, yUFO + -3.0f, zUFO + -6.5f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glutSolidSphere(0.3f, 50.0f, 50.0f);
   glTranslatef(-xUFO + -6.5f, -yUFO + 3.0f, -zUFO + 6.5f);

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + 6.5, yUFO + -3, zUFO + -6.5);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(1.0f, 1.0f, 1.0f);
         glVertex3f(xUFO + sin(angle2) * 2, yUFO + 0, zUFO + cos(angle2) * 2);
      }
   glEnd();

   glTranslatef(xUFO + 0.0f, yUFO + 1.5f, zUFO + 0.0f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glutSolidSphere(1.0f, 50.0f, 50.0f);
   glTranslatef(-xUFO + 0.0f, -yUFO + 1.5f, -zUFO + 0.0f);

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

   glEnable(GL_TEXTURE_2D);
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
///////////////////////////////////doors
   if(doors == 1)
   {
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
   glDisable(GL_TEXTURE_2D);

   drawPost();
   drawFarm(texture);
   drawTrough();
}   

void drawLaser(double x, double y, double z)
{
   glColor3f(1.0f, 0.0f, 0.0f);
   glLineWidth(8);
   glBegin(GL_LINES);
      glVertex3f(xUFO + 10, yUFO, zUFO);
      glVertex3f(x, y, z);
   glEnd();
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
   GLfloat ambient_intensity[] = {0.2f, 0.2f, 0.2f, 1.0f};
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

void drawEgg()
{
   //xChicken = 15; yChicken = 0.01; zChicken = 25;
   glTranslatef(15.0f, -0.02f, 22);
   glColor3f(0.5f, 0.5f, 0.5f);
   glutSolidSphere(0.3f, 50.0f, 50.0f);
   glTranslatef(-15.0f, -0.02f, -22);
}

void myDisplay()
{

   glClearColor (0.0,0.0,1.0, 1.0); //clear the screen to black
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

   rayglFrameBegin("movie");
   if(moviePhase1 == 0 && timer > 3)
   {
      moviePhase1++;
   }
   else if(moviePhase1 == 1)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-80.0f, -0.0f, 5);
      isWalking = 1;
      zCow += 0.01;
      if(zCow > 7.2)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 2)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-80.0f, -0.0f, 5);
      isWalking = 0;
      if(timer > 8)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 3)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-95.0f, -0.0f, 5);
      cowHeadMove = 1;
      if((timer-tempTimer) > 3)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 4)
   {
      glRotatef(-35,1.0,0.0,0.0);
      glTranslatef(5.0f, -20.0f, 30.0);
      cowHeadMove = 0;
      chickenAnimation = 1;
      if((timer-tempTimer) > 3)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 5)
   {
      glTranslatef(0.0f, -20.0f, -20.0);
      if(UFOAngle == 360)
      {
         UFOAngle = 0;
      }
      xUFO = -sin(UFOAngle) * 50; 
      zUFO = -cos(UFOAngle) * 50;
      yUFO += 0.1;
      UFOAngle += .01;
      
      chickenAnimation = 0;
      if(yUFO > 15)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 6)
   {
      glTranslatef(0.0f, -20.0f, -20.0);
      if(UFOAngle == 360)
      {
         UFOAngle = 0;
      }
      xUFO = -sin(UFOAngle) * 50; 
      zUFO = -cos(UFOAngle) * 50;
      UFOAngle += .01;
      
      if(zUFO < 13)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 7)
   {
      zUFO += 0.05;
      xUFO -= 0.05;
      
      if((timer-tempTimer) > 6)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 8)
   {
      xUFO += 0.05;
      
      if((timer-tempTimer) > 2)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 9)
   {
      zUFO -= 0.02;
      xUFO -= 0.05;
      
      if((timer-tempTimer) > 2)
      {
         moviePhase1++;
         tempTimer = timer;
      }
   }
   else if(moviePhase1 == 10)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-60.0f, -5.0f, -12.5);
      yUFO -= 0.01;
      
      chickenAnimation = 1;
      if(yUFO < 3.2)
      {
         moviePhase1++;
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 1)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-60.0f, -5.0f, -12.5);
      yUFO += 0.01;
      egg = 1;

      chickenAnimation = 1;
      if(yUFO > 9.1)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 2)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-60.0f, -5.0f, -12.5);
      yUFO += 0.01;
      zUFO -= 0.03;

      chickenAnimation = 1;
      if(yUFO > 14)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 3)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-60.0f, -5.0f, -12.5);
      yChicken += 0.01;
      ufoBeam = 1;
      chickenAnimation = 1;
      if(yChicken > 9)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 4)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-20,0.0,0.0,1.0);
      glTranslatef(-60.0f, -5.0f, -12.5);
      ufoBeam = 0;
      yChicken = -100;
      chickenAnimation = 0;
      if((timer-tempTimer) > 2)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 5)
   {
      zUFO -= 0.02;
      xUFO += 0.02;
      if((timer-tempTimer) > 6)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 6)
   {
      zCow += 0.02;
      xCow -= 0.02;
      isWalking = 1;
      if((timer-tempTimer) > 4)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 7)
   {
      zCow -= 0.02;
      xCow -= 0.02;
      if((timer-tempTimer) < 1)
      {
         drawLaser(25, 0, 25);
      }
      if((timer-tempTimer) > 4)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 8)
   {
      zCow += 0.01;
      //xCow -= 0.02;
      if((timer-tempTimer) < 1)
      {
         drawLaser(15, 0, 15);
      }
      if((timer-tempTimer) > 6)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 9)
   {
      xUFO -= .05;
      zCow += 0.01;
      xCow += 0.01;
      if((timer-tempTimer) < 1)
      {
         drawLaser(25, 0, 35);
      }
      if((timer-tempTimer) > 6)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 10)
   {
      xUFO -= .05;
      zCow += 0.01;
      xCow -= 0.01;
      if((timer-tempTimer) < 1)
      {
         drawLaser(25, 0, 40);
      }
      if((timer-tempTimer) > 2)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 11)
   {
      //zCow += 0.02;
      xCow += 0.02;
      if((timer-tempTimer) < 1)
      {
         drawLaser(40, 0, 40);
         doors = 0;
      }
      if((timer-tempTimer) > 6)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 12)
   {
      //zCow += 0.02;
      //xCow += 0.02;
      isWalking = 0;
      xUFO += .05;
      zUFO += .05;
      if((timer-tempTimer) < 1)
      {
         drawLaser(40, 5, 40);
         doors = 0;
      }
      if((timer-tempTimer) > 2 && (timer-tempTimer) < 2.5)
      {
         drawLaser(40, 5, 40);
         doors = 0;
      }
      if((timer-tempTimer) > 2.75 && (timer-tempTimer) < 3)
      {
         drawLaser(40, 5, 40);
         doors = 0;
      }
      if((timer-tempTimer) > 3.25 && (timer-tempTimer) < 3.5)
      {
         drawLaser(40, 5, 40);
         doors = 0;
      }
      if((timer-tempTimer) > 3.75 && (timer-tempTimer) < 4)
      {
         drawLaser(40, 5, 40);
         doors = 0;
      }
      if((timer-tempTimer) > 4.25 && (timer-tempTimer) < 4.5)
      {
         drawLaser(40, 5, 40);
         doors = 0;
      }
      if((timer-tempTimer) > 5)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 13)
   {
      glTranslatef(0.0f, -20.0f, -20.0);
      if(UFOAngle == 360)
      {
         UFOAngle = 0;
      }
      xUFO = -sin(UFOAngle) * 50; 
      zUFO = -cos(UFOAngle) * 50;
      yUFO += 0.1;
      UFOAngle += .01;
      
      if((timer-tempTimer) > 5)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 14)
   {
      glRotatef(90,0.0,1.0,0.0);
      glRotatef(-50,0.0,0.0,1.0);
      glRotatef(-180,0.0,1.0,0.0);
      glTranslatef(15.50f, -35.0f, -57);
      
      if((timer-tempTimer) > 3)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 15)
   {
      xCow -= 0.02;
      isWalking  = 1;
      
      if((timer-tempTimer) > 5)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 16)
   {
      xCow += 0.01;
      zCow -= 0.03;
      
      if((timer-tempTimer) > 5)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 17)
   {
      xCow += 0.01;
      
      if((timer-tempTimer) > 6)
      {
         moviePhase2++;
         tempTimer = timer;
      }
   }
   else if(moviePhase2 == 18)
   {
      exit(0);
      
      if((timer-tempTimer) > 6)
      {
         //moviePhase2++;
         tempTimer = timer;
      }
   }


   printf("%f %d %d %f %f %f %f\n", yChicken, moviePhase1, moviePhase2, timer, tempTimer, yUFO, zUFO);

   drawEnvironment(texture);
   drawUFO();
   drawChicken(texture);
   if(moviePhase2 >= 0)
   {
      drawCow(texture);
   }
   if(egg == 1)
   {
      drawEgg();
   }


   glutSwapBuffers(); //swap the buffers

   timer += 0.01;

   rayglFrameEnd();

   angle5++;
}

void myInit(void)
{
   xUFO = 5; yUFO = -10; zUFO = 0;
   xChicken = 15; yChicken = 0.01; zChicken = 25;
   xCow = 20; yCow = -0.5; zCow = 5;

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
    /*if (key=='q')
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
    }*/
    if (key=='q')
    {
      moviePhase1++;
    }
    if (key=='w')
    {
      moviePhase1--;
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
   glutCreateWindow("FINAL");
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
