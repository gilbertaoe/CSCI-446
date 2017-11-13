//Austin Gilbert
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

float xpos, ypos, zpos, xrot, yrot, zrot, angle;
float lastx, lasty;
float cRadius; // our radius distance from our character
int rotating = 0;

bool start = 0;
bool forward = 0;

GLuint texture; //the array for our texture

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

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );
    free( data );
    return texture;
}

void FreeTexture( GLuint texture )
{
  glDeleteTextures( 1, &texture );
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

void drawFarm()
{
  texture = LoadTexture( "index.ppm", 270, 187 ); //load our texture

  glBindTexture( GL_TEXTURE_2D, texture ); //bind our texture

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

  glColor3f(0.80f, 0.0f, 0.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(48.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(35.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(35.0f, 0.1f, 48.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(48.0f, 0.1f, 48.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(48.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(48.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(48.0f, 5.0f, 48.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(48.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(35.0f, 0.1f, 30.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(35.0f, 5.0f, 30.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(48.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(35.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(35.0f, 5.0f, 48.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(48.0f, 5.0f, 48.0f);
  glEnd();

  FreeTexture( texture );
  texture = LoadTexture( "roof.ppm", 500, 330 ); //load our texture
  glBindTexture( GL_TEXTURE_2D, texture ); //bind our texture
  glColor3f(0.80f, 1.0f, 0.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(48.0f, 5.0f, 48.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(42.0f, 9.0f, 48.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(42.0f, 9.0f, 30.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(35.0f, 5.0f, 48.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(42.0f, 9.0f, 48.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(42.0f, 9.0f, 30.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(35.0f, 5.0f, 30.0f);
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

  glColor3f(0.80f, 0.0f, 1.0f);
  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(35.0f, 5.0f, 48.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(35.0f, 0.1f, 48.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(35.0f, 0.1f, 35.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(35.0f, 5.0f, 35.0f);
  glEnd();

  glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(35.0f, 5.0f, 35.0f);
    glTexCoord2d(1.0, 0.0); glVertex3f(35.0f, 0.1f, 35.0f);
    glTexCoord2d(1.0, 1.0); glVertex3f(35.0f, 0.1f, 30.0f);
    glTexCoord2d(0.0, 1.0); glVertex3f(35.0f, 5.0f, 30.0f);
  glEnd();

  glColor3f(0.0f, 0.0f, 0.0f);
  glBegin(GL_LINES);
    glVertex3f(34.9f, 5.0f, 48.0f);
    glVertex3f(34.9f, 0.1f, 39.0f);

    glVertex3f(34.9f, 5.0f, 39.0f);
    glVertex3f(34.9f, 0.1f, 48.0f);
  glEnd();

  glBegin(GL_LINES);
    glVertex3f(34.9f, 5.0f, 39.0f);
    glVertex3f(34.9f, 0.1f, 30.0f);

    glVertex3f(34.9f, 5.0f, 30.0f);
    glVertex3f(34.9f, 0.1f, 39.0f);
  glEnd();

  glBegin(GL_LINES);
    glVertex3f(34.9f, 5.0f, 39.0f);
    glVertex3f(34.9f, 0.1f, 39.0f);
  glEnd();

  glBindTexture( GL_TEXTURE_2D, 0 ); //bind our texture
  FreeTexture( texture );
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

void myDisplay()
{
   glClearColor (0.0,0.0,0.0, 1.0); //clear the screen to black
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
   glLoadIdentity(); 
   //position();
   glEnable (GL_DEPTH_TEST); //enable the depth testing
   glShadeModel (GL_SMOOTH); //set the shader to smooth shader
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);

   GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
   GLfloat cyan[] = {0.0f, 0.8f, 0.8f, 1.0f};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
   glMaterialfv(GL_FRONT, GL_AMBIENT, white);

   GLfloat lightpos[] = {10, 10, 10, 1.0};
   glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

   glColor3f(1.0f, 1.0f, 1.0f);


   glTranslatef(0.0f, 0.0f, -50);
   glRotatef(35,1.0,0.0,0.0);
    //glRotatef(xrot,1.0,0.0,0.0);


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

   texture = LoadTexture( "grass.ppm", 225, 225 ); //load our texture
   glBindTexture( GL_TEXTURE_2D, texture ); //bind our texture

   glColor3f(0.0f, 1.0f, 0.0f);
   glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0); glVertex3f(0.0f, 0.0f, 0.0f);
      glTexCoord2d(1.0, 0.0); glVertex3f(0.0f, 0.0f, 52.0f);
      glTexCoord2d(1.0, 1.0); glVertex3f(52.0f, 0.0f, 52.0f);
      glTexCoord2d(0.0, 1.0); glVertex3f(52.f, 0.0f, 0.0f);
   glEnd();

   glBindTexture(GL_TEXTURE_2D, 0);
   FreeTexture( texture );

   drawPost();
   drawFarm();
   drawTrough();


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

   angle++;
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

void myInit(void)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
  glEnable(GL_TEXTURE_2D);
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
   xpos = 0; ypos = 0; zpos = 0; xrot = 0; yrot = 0; angle=0.0; cRadius = 10.0f;

   glutKeyboardFunc(keyboard);

   cout << texture << endl;

   myInit();
   glutMainLoop ();
}
