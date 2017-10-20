#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include "Cow.h"
#include "Environment.h"
#include "Chicken.h"
#include "UFO.h"

using namespace std;

float xpos, ypos, zpos, xrot, yrot, zrot, angle;
float lastx, lasty;
float cRadius; // our radius distance from our character
int rotating = 0;

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
    glVertex3f(48.0f, 0.1f, 30.0f);
    glVertex3f(35.0f, 0.1f, 30.0f);
    glVertex3f(35.0f, 0.1f, 48.0f);
    glVertex3f(48.0f, 0.1f, 48.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(48.0f, 0.1f, 30.0f);
    glVertex3f(48.0f, 0.1f, 48.0f);
    glVertex3f(48.0f, 5.0f, 48.0f);
    glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(48.0f, 0.1f, 30.0f);
    glVertex3f(35.0f, 0.1f, 30.0f);
    glVertex3f(35.0f, 5.0f, 30.0f);
    glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(48.0f, 0.1f, 48.0f);
    glVertex3f(35.0f, 0.1f, 48.0f);
    glVertex3f(35.0f, 5.0f, 48.0f);
    glVertex3f(48.0f, 5.0f, 48.0f);
  glEnd();

  glColor3f(0.80f, 1.0f, 0.0f);
  glBegin(GL_QUADS);
    glVertex3f(48.0f, 5.0f, 48.0f);
    glVertex3f(42.0f, 9.0f, 48.0f);
    glVertex3f(42.0f, 9.0f, 30.0f);
    glVertex3f(48.0f, 5.0f, 30.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(35.0f, 5.0f, 48.0f);
    glVertex3f(42.0f, 9.0f, 48.0f);
    glVertex3f(42.0f, 9.0f, 30.0f);
    glVertex3f(35.0f, 5.0f, 30.0f);
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
    glVertex3f(35.0f, 5.0f, 48.0f);
    glVertex3f(35.0f, 0.1f, 48.0f);
    glVertex3f(35.0f, 0.1f, 35.0f);
    glVertex3f(35.0f, 5.0f, 35.0f);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(35.0f, 5.0f, 35.0f);
    glVertex3f(35.0f, 0.1f, 35.0f);
    glVertex3f(35.0f, 0.1f, 30.0f);
    glVertex3f(35.0f, 5.0f, 30.0f);
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
}

void drawTrough()
{
  glColor3f(0.0f, 0.0f, 0.0f);
  glBegin(GL_QUADS);
    glVertex3f(35.0f, 5.0f, 35.0f);
    glVertex3f(35.0f, 0.1f, 35.0f);
    glVertex3f(35.0f, 0.1f, 30.0f);
    glVertex3f(35.0f, 5.0f, 30.0f);
  glEnd();
}

void myDisplay() 
{
   glClearColor (0.0,0.0,0.0, 1.0); //clear the screen to black
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
   glLoadIdentity(); 
   //position();
   glEnable (GL_DEPTH_TEST); //enable the depth testing
   //glEnable (GL_LIGHTING); //enable the lighting
   //glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
   glShadeModel (GL_SMOOTH); //set the shader to smooth shader
   glColor3f(1.0f, 1.0f, 1.0f);




   glTranslatef(0.0f, 0.0f, -cRadius);
   glRotatef(xrot,1.0,0.0,0.0);
   glColor3f(1.0f, 0.0f, 0.0f);
   glutSolidCube(2); //Our character to follow
   glColor3f(0.0f, 0.0f, 1.0f);
   glBegin(GL_LINES);
      glVertex3f(0.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 2.5f, 0.0f);
   glEnd();

   glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
   glTranslated(-xpos,0.0f,-zpos); //translate the screen to the position of our camera
   glColor3f(1.0f, 1.0f, 1.0f);
   //cube(); //call the cube drawing function

   glColor3f(1.0f, 1.0f, 1.0f);
   glBegin(GL_QUADS);
      glVertex2f(0.0f, 0.0f);
      glVertex2f(0.0f, 15.0f);
      glVertex2f(15.0f, 15.0f);
      glVertex2f(0.0f, 15.0f);
   glEnd();

   glColor3f(0.0f, 1.0f, 0.0f);
   glBegin(GL_QUADS);
      glVertex3f(0.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 0.0f, 52.0f);
      glVertex3f(52.0f, 0.0f, 52.0f);
      glVertex3f(52.f, 0.0f, 0.0f);
   glEnd();

   drawPost();

   drawFarm();


   glutSwapBuffers(); //swap the buffers

   angle++;
}

void myInit(void)
{

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

    if (key=='u')
    {
      rotating = 1;
    }

    if (key==27)
    {
      exit(0);
    }
}

void mouseMovement(int x, int y)
{
    int diffx=x-lastx; //check the difference between the current x and the last x position
    int diffy=y-lasty; //check the difference between the current y and the last y position
    lastx=x; //set lastx to the current x position
    lasty=y; //set lasty to the current y position
    xrot += (float) diffy; //set the xrot to xrot with the addition of the difference in the y position
    yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
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
   glutPassiveMotionFunc(mouseMovement); //check for mouse movement
   xpos = 0; ypos = 0; zpos = 0; xrot = 0; yrot = 0; angle=0.0; cRadius = 10.0f;

   glutKeyboardFunc (keyboard);

   glutMainLoop();
}