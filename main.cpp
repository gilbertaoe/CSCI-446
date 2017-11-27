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

bool start = 0;
bool forward = 0;

Environment env;
UFO uf;

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

   env.drawEnvironment();
   uf.drawUFO();

   uf.x++;


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
   xpos = 0; ypos = 0; zpos = 0; xrot = 0; yrot = 0; angle=0.0; cRadius = 10.0f;

   glutKeyboardFunc (keyboard);

   glutMainLoop();
}