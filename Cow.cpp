#include "Cow.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>


Cow::Cow()
{
	x = 10;
	y = .01;
	z = 15;
}

void Cow::head(GLuint texture[])
{  
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

   glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

   //texture = LoadTexture( "aaa.ppm", 560, 350);

   glBindTexture( GL_TEXTURE_2D, texture[1]);

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

   //FreeTexture(texture);

   
   


   //texture = LoadTexture( "minecraft_cow.ppm", 65, 64);

   glBindTexture( GL_TEXTURE_2D, texture[2]);

   glBegin(GL_QUADS);

      glTexCoord2d(0.0, 0.0); glVertex3f(x + -0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 0.0); glVertex3f(x + 0.25,y + 1,z + 1.5);
      glTexCoord2d(1.0, 1.0); glVertex3f(x + 0.25,y + .5,z + 1.5);
      glTexCoord2d(0.0, 1.0); glVertex3f(x + -0.25,y + .5,z + 1.5);

   glEnd();

   //FreeTexture(texture);

   glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
}

void Cow::backLeftLegTop(GLuint texture[])
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

void Cow::backRightLegTop(GLuint texture[])
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

void Cow::backLeftLegBot(GLuint texture[])
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

void Cow::backRightLegBot(GLuint texture[])
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

void Cow::frontLeftLegBot(GLuint texture[])
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

void Cow::frontRightLegBot(GLuint texture[])
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

void Cow::frontLeftLegTop(GLuint texture[])
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

void Cow::frontRightLegTop(GLuint texture[])
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

void Cow::body(GLuint texture[])
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

void Cow::drawCow(GLuint texture[])
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
