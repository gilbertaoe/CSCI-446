//Author: Chase Davis
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include "./raygl.h"
#include "./raygldefs.h"
#include "Cow.h"
 
using namespace std;



char title[] = "3D Shapes";
float frontLegsRotate = 0;
float backLegsRotate = 0;
int isWalking = 0;
int phase = 1;
double angle, angle2 = 0;
double angle3, angle4 = 0;

GLuint texture;

GLuint LoadTexture( const char * filename, int width, int height )
{
    GLuint texture;
    unsigned char * data;
    FILE * file;

    file = fopen( filename, "rb" );
    if ( file == NULL ) return 0;
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );

    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );


    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );
    free( data );
    return texture;
}

void FreeTexture( GLuint texture ){
  glDeleteTextures( 1, &texture ); 
}

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);
   

   //glDepthFunc(GL_LEQUAL);    
   //glShadeModel(GL_SMOOTH);   
   //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glEnable(GL_TEXTURE_2D);

  rayglScaleTexture(.1, .1, .1);
  rayglTranslateTexture(0, 0, 0);
  rayglTextureType(0);

   glEnable(GL_BLEND);

}

void head(){
   
   //Head
   /*
   glVertex3f(-0.25, 1, 1.0); 1
   glVertex3f(0.25, 1, 1.0);  2
   glVertex3f(0.25, .5, 1.0); 3
   glVertex3f(-0.25, .5, 1.0);4
   glVertex3f(-0.25, 1, 1.5); 5
   glVertex3f(0.25, 1, 1.5);  6
   glVertex3f(0.25, .5, 1.5); 7
   glVertex3f(-0.25, .5, 1.5);8

   glTexCoord2d(0.0, 0.0);
   glTexCoord2d(1.0, 0.0); 
   glTexCoord2d(1.0, 1.0); 
   glTexCoord2d(0.0, 1.0); 
   */

   glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

   texture = LoadTexture( "aaa.ppm", 560, 350);

   glBindTexture( GL_TEXTURE_2D, texture);

   glBegin(GL_QUADS);

      glTexCoord2d(0.0, 0.0); glVertex3f(-0.25, 1, 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(0.25, 1, 1.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(0.25, 1, 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(-0.25, 1, 1.5);

      glTexCoord2d(0.0, 0.0); glVertex3f(0.25, 1, 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(0.25, 1, 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(0.25, .5, 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(0.25, .5, 1.0);

      glTexCoord2d(0.0, 0.0); glVertex3f(0.25, .5, 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(0.25, .5, 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(-0.25, .5, 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(-0.25, .5, 1.0);

      glTexCoord2d(0.0, 0.0); glVertex3f(-0.25, 1, 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(-0.25, 1, 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(-0.25, .5, 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(-0.25, .5, 1.0);

   glEnd();

   FreeTexture(texture);

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);

   
   


   texture = LoadTexture( "minecraft_cow.ppm", 65, 64);

   glBindTexture( GL_TEXTURE_2D, texture);

   glBegin(GL_QUADS);

      glTexCoord2d(0.0, 0.0); glVertex3f(-0.25, 1, 1.5);
      glTexCoord2d(1.0, 0.0); glVertex3f(0.25, 1, 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(0.25, .5, 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(-0.25, .5, 1.5);

   glEnd();

   FreeTexture(texture);

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);

   
   
 }

void backLeftLegTop(){

   glTranslatef(0.9f, -1.4f, -1.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-0.9f, 1.4f, 1.9f);

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

   glVertex3f(0.8, -1.0, -1.8);
   glVertex3f(0.8, -1.0, -2.0);
   glVertex3f(0.8, -1.4, -2.0);
   glVertex3f(0.8, -1.4, -1.8);

   glVertex3f(0.8, -1.0, -1.8);
   glVertex3f(1.0, -1.0, -1.8);
   glVertex3f(1.0, -1.4, -1.8);
   glVertex3f(0.8, -1.4, -1.8);

   glVertex3f(1.0, -1.0, -1.8);
   glVertex3f(1.0, -1.0, -2.0);
   glVertex3f(1.0, -1.4, -2.0);
   glVertex3f(1.0, -1.4, -1.8);

   glVertex3f(0.8, -1.0, -2.0);
   glVertex3f(1.0, -1.0, -2.0);
   glVertex3f(1.0, -1.4, -2.0);
   glVertex3f(0.8, -1.4, -2.0);

   glEnd();
 }

void backRightLegTop(){

   glTranslatef(-0.9f, -1.4f, -1.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(0.9f, 1.4f, 1.9f);

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

   glVertex3f(-1.0, -1.0, -1.8);
   glVertex3f(-1.0, -1.0, -2.0);
   glVertex3f(-1.0, -1.4, -2.0);
   glVertex3f(-1.0, -1.4, -1.8);

   glVertex3f(-1.0, -1.0, -1.8);
   glVertex3f(-0.8, -1.0, -1.8);
   glVertex3f(-0.8, -1.4, -1.8);
   glVertex3f(-1.0, -1.4, -1.8);

   glVertex3f(-0.8, -1.0, -1.8);
   glVertex3f(-0.8, -1.0, -2.0);
   glVertex3f(-0.8, -1.4, -1.8);
   glVertex3f(-0.8, -1.4, -2.0);

   glVertex3f(-1.0, -1.0, -1.8);
   glVertex3f(-0.8, -1.0, -2.);
   glVertex3f(-1.0, -1.4, -2.0);
   glVertex3f(-0.8, -1.4, -2.0);

   glEnd();
 }

void backLeftLegBot(){

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

   glVertex3f(0.8, -1.4, -1.8);
   glVertex3f(0.8, -1.4, -2.0);
   glVertex3f(0.8, -1.8, -2.0);
   glVertex3f(0.8, -1.8, -1.8);

   glVertex3f(0.8, -1.4, -1.8);
   glVertex3f(1.0, -1.4, -1.8);
   glVertex3f(1.0, -1.8, -1.8);
   glVertex3f(0.8, -1.8, -1.8);

   glVertex3f(1.0, -1.4, -1.8);
   glVertex3f(1.0, -1.4, -2.0);
   glVertex3f(1.0, -1.8, -2.0);
   glVertex3f(1.0, -1.8, -1.8);

   glVertex3f(0.8, -1.4, -2.0);
   glVertex3f(1.0, -1.4, -2.0);
   glVertex3f(1.0, -1.8, -2.0);
   glVertex3f(0.8, -1.8, -2.0);

   glEnd();
 } 

void backRightLegBot(){

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

   glVertex3f(-1.0, -1.4, -1.8);
   glVertex3f(-1.0, -1.4, -2.0);
   glVertex3f(-1.0, -1.8, -2.0);
   glVertex3f(-1.0, -1.8, -1.8);

   glVertex3f(-1.0, -1.4, -1.8);
   glVertex3f(-0.8, -1.4, -1.8);
   glVertex3f(-0.8, -1.8, -1.8);
   glVertex3f(-1.0, -1.8, -1.8);

   glVertex3f(-0.8, -1.4, -1.8);
   glVertex3f(-0.8, -1.4, -2.0);
   glVertex3f(-0.8, -1.8, -1.8);
   glVertex3f(-0.8, -1.8, -2.0);

   glVertex3f(-1.0, -1.4, -1.8);
   glVertex3f(-0.8, -1.4, -2.);
   glVertex3f(-1.0, -1.8, -2.0);
   glVertex3f(-0.8, -1.8, -2.0);

   glEnd();
 } 

void frontLeftLegBot(){

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

   glVertex3f(0.8, -1.4, 1.0);
   glVertex3f(0.8, -1.4, 0.8);
   glVertex3f(0.8, -1.8, 0.8);
   glVertex3f(0.8, -1.8, 1.0);

   glVertex3f(0.8, -1.4, 1.0);
   glVertex3f(1.0, -1.4, 1.0);
   glVertex3f(1.0, -1.8, 1.0);
   glVertex3f(0.8, -1.8, 1.0);

   glVertex3f(1.0, -1.4, 1.0);
   glVertex3f(1.0, -1.4, 0.8);
   glVertex3f(1.0, -1.8, 0.8);
   glVertex3f(1.0, -1.8, 1.0);

   glVertex3f(0.8, -1.4, 0.8);
   glVertex3f(1.0, -1.4, 0.8);
   glVertex3f(1.0, -1.8, 0.8);
   glVertex3f(0.8, -1.8, 0.8);

   glEnd();
 }

void frontRightLegBot(){
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

   glVertex3f(-1.0, -1.4, 1.0);
   glVertex3f(-1.0, -1.4, 0.8);
   glVertex3f(-1.0, -1.8, 0.8);
   glVertex3f(-1.0, -1.8, 1.0);

   glVertex3f(-1.0, -1.4, 1.0);
   glVertex3f(-0.8, -1.4, 1.0);
   glVertex3f(-0.8, -1.8, 1.0);
   glVertex3f(-1.0, -1.8, 1.0);

   glVertex3f(-0.8, -1.4, 1.0);
   glVertex3f(-0.8, -1.4, 0.8);
   glVertex3f(-0.8, -1.8, 1.0);
   glVertex3f(-0.8, -1.8, 0.8);

   glVertex3f(-1.0, -1.4, 1.0);
   glVertex3f(-0.8, -1.4, 0.8);
   glVertex3f(-1.0, -1.8, 0.8);
   glVertex3f(-0.8, -1.8, 0.8);

   glEnd();
 }

void frontLeftLegTop(){

   glTranslatef(0.9f, -1.4f, 0.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(-0.9f, 1.4f, -0.9f);

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

   glVertex3f(0.8, -1.0, 1.0);
   glVertex3f(0.8, -1.0, 0.8);
   glVertex3f(0.8, -1.4, 0.8);
   glVertex3f(0.8, -1.4, 1.0);

   glVertex3f(0.8, -1.0, 1.0);
   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(1.0, -1.4, 1.0);
   glVertex3f(0.8, -1.4, 1.0);

   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(1.0, -1.0, 0.8);
   glVertex3f(1.0, -1.4, 0.8);
   glVertex3f(1.0, -1.4, 1.0);

   glVertex3f(0.8, -1.0, 0.8);
   glVertex3f(1.0, -1.0, 0.8);
   glVertex3f(1.0, -1.4, 0.8);
   glVertex3f(0.8, -1.4, 0.8);

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

void frontRightLegTop(){

   glTranslatef(-0.9f, -1.4f, 0.9f);
   glutSolidSphere(0.125f, 50.0f, 50.0f);
   glTranslatef(0.9f, 1.4f, -0.9f);

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

   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(-1.0, -1.0, 0.8);
   glVertex3f(-1.0, -1.4, 0.8);
   glVertex3f(-1.0, -1.4, 1.0);

   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(-0.8, -1.0, 1.0);
   glVertex3f(-0.8, -1.4, 1.0);
   glVertex3f(-1.0, -1.4, 1.0);

   glVertex3f(-0.8, -1.0, 1.0);
   glVertex3f(-0.8, -1.0, 0.8);
   glVertex3f(-0.8, -1.4, 1.0);
   glVertex3f(-0.8, -1.4, 0.8);

   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(-0.8, -1.0, 0.8);
   glVertex3f(-1.0, -1.4, 0.8);
   glVertex3f(-0.8, -1.4, 0.8);
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

void body(){

   glTranslatef(0.9f, -1.0f, -1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-0.9f, 1.0f, 1.9f);

   glTranslatef(-0.9f, -1.0f, -1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(0.9f, 1.0f, 1.9f);

   glTranslatef(0.9f, -1.0f, 0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(-0.9f, 1.0f, -0.9f);

   glTranslatef(-0.9f, -1.0f, 0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(0.9f, 1.0f, -0.9f);

   glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

   texture = LoadTexture( "aaa.ppm", 560, 350);

   glBindTexture( GL_TEXTURE_2D, texture);

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

   glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(1.0, -1.0, 1.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, -1.0, 1.0);

   glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, 1.0, -2.0); 
   glTexCoord2d(1.0, 0.0); glVertex3f(1.0, 1.0, -2.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(1.0, -1.0, -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, -1.0, -2.0);

   /////////////////////////////////

   glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(1.0, -1.0, -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, -1.0, -2.0);

   glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(1.0, 1.0, -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, 1.0, -2.0);

   ///////////////////////////

   glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(-1.0, 1.0, -2.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(-1.0, -1.0, -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, -1.0, 1.0);

   glTexCoord2d(0.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
   glTexCoord2d(1.0, 0.0); glVertex3f(1.0, 1.0, -2.0);
   glTexCoord2d(1.0, 1.0); glVertex3f(1.0, -1.0, -2.0);
   glTexCoord2d(0.0, 1.0); glVertex3f(1.0, -1.0, 1.0);
   glEnd();

   FreeTexture(texture);

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
   //glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);     

   glEnable(GL_LIGHTING);
   //glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);

   GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
   GLfloat cyan[] = {0.0f, 0.8f, 0.0f, 1.0f};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
   glMaterialfv(GL_FRONT, GL_AMBIENT, white);

   GLfloat lightpos[] = { -2.0, -1.0, -3.0, 1};
   glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
   rayglFrameBegin("./test");

   
   glLoadIdentity();                
   glTranslatef(0.0f, 0.0f, -6.0f);  

   //glRotatef(-65.0f, 1.0f, 0.0f, 0.0f);
   glRotatef(65.0f, 0.0f, 1.0f, 0.0f);

   glPushMatrix();
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   //glColor3f(1.0f, 1.0f, 1.0f);

   //setFadeDistance(100.0);
   //setFadePower(2.0);

   glTranslatef(1.0, 1.0, 0.0);
   head();
   body();


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
         glTranslatef(0.8f, -1.0f, 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         frontLeftLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         angle -= 4;

         glTranslatef(0.8f, -1.0f, 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//same.1
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
               frontLeftLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         angle3 += 4;

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         backLeftLegTop();         
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         backRightLegTop();
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         //angle2--;

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
               backRightLegBot();
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
               backLeftLegBot();
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         //angle4++;
      }
      if(phase == 2)
      {
         glTranslatef(0.8f, -1.0f, 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         frontLeftLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         //angle--;

         glTranslatef(0.8f, -1.0f, 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//same.1
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
               frontLeftLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         angle3 += 4;

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         backLeftLegTop();         
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         backRightLegTop();
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         angle2 -= 4;

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
               backRightLegBot();
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
               backLeftLegBot();
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         angle4 += 4;
      }
      if(phase == 3)
      {
         glTranslatef(0.8f, -1.0f, 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         frontLeftLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         //angle++;

         glTranslatef(0.8f, -1.0f, 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//same.1
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
               frontLeftLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         angle3 -= 4;

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         backLeftLegTop();         
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         backRightLegTop();
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         //angle2--;

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
               backRightLegBot();
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
               backLeftLegBot();
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         //angle4++;
      }
      if(phase == 4)
      {
         glTranslatef(0.8f, -1.0f, 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         frontLeftLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         angle += 4;

         glTranslatef(0.8f, -1.0f, 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//same.1
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
               frontLeftLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         //angle3++;

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         backLeftLegTop();         
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         backRightLegTop();
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         angle2 += 4;

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
               backRightLegBot();
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
               backLeftLegBot();
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         //angle4++;
      }
      if(phase == 5)
      {
         glTranslatef(0.8f, -1.0f, 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         frontLeftLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         angle -= 4;

         glTranslatef(0.8f, -1.0f, 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//same.1
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
               frontLeftLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         angle3 += 4;

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         backLeftLegTop();         
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         backRightLegTop();
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         angle2 += 4;

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
               backRightLegBot();
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
               backLeftLegBot();
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         //angle4++;
      }
      if(phase == 6)
      {
         glTranslatef(0.8f, -1.0f, 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         frontLeftLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         //angle--;

         glTranslatef(0.8f, -1.0f, 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//same.1
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
               frontLeftLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         //angle3++;

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         backLeftLegTop();         
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         backRightLegTop();
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         angle2 -= 4;

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
               backRightLegBot();
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
               backLeftLegBot();
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         //angle4++;
      }
   }
   else
   {
      glTranslatef(0.8f, -1.0f, 0.8f); // point is closest to the origin
         glRotatef(angle, 1.0f, 0.0f, 0.0f);// pos angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//inverse
         frontRightLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);// neg angle + BS
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         frontLeftLegTop();
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         //angle--;

         glTranslatef(0.8f, -1.0f, 0.8f); //this tri is exactly as it's corrosponding top
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f); //point on the actual bot portion closest to origin
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//inverse
               frontRightLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f); //same.1
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);//same.1
         glTranslatef(0.8f, -1.0f, 0.8f);//same
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);//same

         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
               frontLeftLegBot();
            glTranslatef(0.8f, -1.4f, 0.8f);
            glRotatef(-angle3, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, -0.8f);
         glTranslatef(0.8f, -1.0f, 0.8f);
         glRotatef(-angle, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, -0.8f);
         //angle3++;

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         backLeftLegTop();         
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         backRightLegTop();
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
         //angle2--;

         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
               backRightLegBot();
            glTranslatef(-0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.8f, 1.4f, 1.8f);
         glTranslatef(-0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(0.8f, 1.0f, 1.8f);

         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
               backLeftLegBot();
            glTranslatef(0.8f, -1.4f, -1.8f);
            glRotatef(-angle4, 1.0f, 0.0f, 0.0f);
            glTranslatef(-0.8f, 1.4f, 1.8f);
         glTranslatef(0.8f, -1.0f, -1.8f);
         glRotatef(-angle2, 1.0f, 0.0f, 0.0f);
         glTranslatef(-0.8f, 1.0f, 1.8f);
         //angle4++;

         angle = 0; 
         angle2 = 0; 
         angle3 = 0;
         angle4 = 0;
         phase = 1;
   }
   
   glTranslatef(0.0f, 0.0f, -6.0f); 

   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   glOrtho(0.0, 640, 480, 0.0, -1.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   
   glLoadIdentity();
   glDisable(GL_CULL_FACE);

   glClear(GL_DEPTH_BUFFER_BIT);

   glBegin(GL_QUADS);
       glColor3f(0.0f, 0.0f, 1.0f);
       glVertex2f(0.0, 0.0);
       glVertex2f(20.0, 0.0);
       glVertex2f(20.0, 20.0);
       glVertex2f(0.0, 20.0);
   glEnd();

   glBegin(GL_QUADS);
       glColor3f(0.0f, 0.0f, 1.0f);
       glVertex2f(25.0, 25.0);
       glVertex2f(45.0, 25.0);
       glVertex2f(45.0, 45.0);
       glVertex2f(25.0, 45.0);
   glEnd();

   glColor3f(1.0f, 1.0f, 1.0f);

   /*
   texture = LoadTexture( "cow_white_red.bmp", 300, 300);

   glBindTexture( GL_TEXTURE_2D, texture);

   glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0); glVertex2f(0.0, 0.0);
      glTexCoord2d(1.0, 0.0); glVertex2f(300.0, 0.0);
      glTexCoord2d(1.0, 1.0); glVertex2f(300.0, 300.0);
      glTexCoord2d(0.0, 1.0); glVertex2f(0.0, 300.0);
   glEnd();

   FreeTexture(texture);
   */

   rayglFrameEnd();

   glColor3f(1.0f, 0.0f, 0.0f);
   
   glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glMatrixMode(GL_MODELVIEW);
   
   
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void mouseClicks(int button, int state, int x, int y) {
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
         if (x <= 20 && y <= 20 && isWalking == 0)
         {
            isWalking = 1;
         }
         else if (x <= 45 && y <= 45 && isWalking == 1 && x >= 25 && y >= 25)
         {
            isWalking = 0;
         }
   }
}

void keyboard (unsigned char key, int x, int y)
{
    //if (key=='q')
    //{
    //  isWalking = 1;
    //}

    if (key==27)
    {
      exit(0);
    }
}

 

void reshape(GLsizei width, GLsizei height) {  
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutIdleFunc (display);
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutMouseFunc(mouseClicks);
   initGL();                       // Our own OpenGL initialization
   glutKeyboardFunc(keyboard);
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
