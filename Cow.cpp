#include "Cow.h"

Cow::Cow()
{
	x = 0;
	y = 0;
	z = 0;
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

      glTexCoord2d(0.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + 0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + 0.25, y +1,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + 1,z + 1.5);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + 0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + 0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + 0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + 0.25,y + .5,z + 1.0);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + 0.25,y + .5,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + 0.25,y + .5,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.0);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.0);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.0);

   glEnd();

   FreeTexture(texture);

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);

   
   


   texture = LoadTexture( "minecraft_cow.ppm", 65, 64);

   glBindTexture( GL_TEXTURE_2D, texture);

   glBegin(GL_QUADS);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + 0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + 0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.5);

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
void body(){

   glTranslatef(x + 0.9f,y + -1.0f,z + -1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(x + -0.9f,y + 1.0f,z + 1.9f);

   glTranslatef(x + -0.9f,y + -1.0f,z + -1.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(x + 0.9f,y + 1.0f,z + 1.9f);

   glTranslatef(x + 0.9f,y + -1.0f,z + 0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(x + -0.9f,y + 1.0f,z + -0.9f);

   glTranslatef(x + -0.9f,y + -1.0f,z + 0.9f);
   glutSolidSphere(0.1f, 50.0f, 50.0f);
   glTranslatef(x + 0.9f,y + 1.0f,z + -0.9f);

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

   FreeTexture(texture);

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
   //glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
}
void Cow::drawCow()
{
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
   glTranslatef(x + 0.0f,y + 0.0f,z + -6.0f);  

   //glRotatef(-65.0f, 1.0f, 0.0f, 0.0f);
   glRotatef(65.0f, 0.0f, 1.0f, 0.0f);

   glPushMatrix();
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   //glColor3f(1.0f, 1.0f, 1.0f);

   //setFadeDistance(100.0);
   //setFadePower(2.0);

   glTranslatef(x + 1.0,y + 1.0,z + 0.0);
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
