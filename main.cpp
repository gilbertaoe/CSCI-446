#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include "Cow.h"
#include "Environment.h"
#include "Chicken.h"
#include "UFO.h"

using namespace std;

float xpos, ypos, zpos, xrot, yrot, zrot, angle;
float lastx, lasty;
float cRadius; // our radius distance from our character

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

   glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
   glTranslated(-xpos,0.0f,-zpos); //translate the screen to the position of our camera
   glColor3f(1.0f, 1.0f, 1.0f);
   //cube(); //call the cube drawing function

   glColor3f(0.0f, 1.0f, 0.0f);
   glBegin(GL_QUADS);
      glVertex3f(-5.0f, -2.0f, 0.0f);
      glVertex3f(-5.0f, 30.0f, 0.0f);
      glVertex3f(30.0f, 30.0f, 0.0f);
      glVertex3f(30.f, -2.0f, 0.0f);
   glEnd();

   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glVertex3f(30.0f, 30.0f, 0.0f);
      glVertex3f(30.0f, 25.0f, 0.0f);
      glVertex3f(30.0f, 25.0f, 5.0f);
      glVertex3f(30.f, 30.0f, 5.0f);
   glEnd();

   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f(30.0f, 30.0f, 0.0f);
      glVertex3f(30.0f, 30.0f, 5.0f);
      glVertex3f(20.0f, 30.0f, 0.0f);
      glVertex3f(20.0f, 30.0f, 0.0f);
      glVertex3f(20.0f, 30.0f, 5.0f);
      glVertex3f(30.0f, 30.0f, 5.0f);
   glEnd();

   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f(30.0f, 30.0f, 5.0f);
      glVertex3f(25.0f, 30.0f, 7.0f);
      glVertex3f(20.0f, 30.0f, 5.0f);
   glEnd();//

   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f(30.0f, 30.0f, 0.0f);
      glVertex3f(20.0f, 30.0f, 0.0f);
      glVertex3f(20.0f, 25.0f, 0.0f);
      glVertex3f(20.0f, 25.0f, 0.0f);
      glVertex3f(30.0f, 25.0f, 0.0f);
      glVertex3f(30.0f, 30.0f, 0.0f);
   glEnd();

   glColor3f(0.0f, 0.0f, 0.0f);
   glBegin(GL_LINES);
      glVertex3f(30.0f, 30.0f, 0.0f);
      glVertex3f(30.0f, 25.0f, 0.0f);
      glVertex3f(30.0f, 25.0f, 0.0f);
      glVertex3f(20.0f, 25.0f, 0.0f);
      glVertex3f(20.0f, 30.0f, 0.0f);
      glVertex3f(30.0f, 30.0f, 0.0f);
      glVertex3f(20.0f, 30.0f, 5.0f);
      glVertex3f(30.0f, 30.0f, 5.0f);
      glVertex3f(30.0f, 30.0f, 0.0f);
      glVertex3f(30.0f, 30.0f, 5.0f);
      glVertex3f(30.0f, 25.0f, 5.0f);
      glVertex3f(30.0f, 25.0f, 5.0f);
   glEnd();

   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_QUADS);
      glVertex3f(20.0f, 30.0f, 0.0f);
      glVertex3f(20.0f, 25.0f, 0.0f);
      glVertex3f(20.0f, 25.0f, 5.0f);
      glVertex3f(20.f,30.0f, 5.0f);
   glEnd();


   glColor3f(0.5f, 0.35f, 0.05f);    
   glBegin(GL_QUADS);
      glVertex3f(20.0f, 30.0f, 5.0f);
      glVertex3f(25.0f, 30.0f, 7.0f);
      glVertex3f(25.0f, 25.0f, 7.0f);
      glVertex3f(20.0f, 25.0f, 5.0f);
   glEnd();

   glBegin(GL_QUADS);
      glVertex3f(30.0f, 30.0f, 5.0f);
      glVertex3f(25.0f, 30.0f, 7.0f);
      glVertex3f(25.0f, 25.0f, 7.0f);
      glVertex3f(30.0f, 25.0f, 5.0f);
   glEnd();

   glColor3f(1.0f, 1.0f, 1.0f);
   glBegin(GL_QUADS);
      glVertex3f(20.0f, 25.0f, 5.0f);
      glVertex3f(22.0f, 20.0f, 5.0f);
      glVertex3f(22.0f, 20.0f, 0.0f);
      glVertex3f(20.0f, 25.0f, 0.0f);
   glEnd();

   glBegin(GL_QUADS);
      glVertex3f(30.0f, 25.0f, 5.0f);
      glVertex3f(28.0f, 20.0f, 5.0f);
      glVertex3f(28.0f, 20.0f, 0.0f);
      glVertex3f(30.0f, 25.0f, 0.0f);
   glEnd();

   glColor3f(0.5f, 0.5f, 0.5f);
   glBegin(GL_QUADS);
      glVertex3f(10.0f, 28.0f, 2.0f);
      glVertex3f(15.0f, 28.0f, 2.0f);
      glVertex3f(15.0f, 25.0f, 2.0f);
      glVertex3f(10.0f, 25.0f, 2.0f);
   glEnd();

   glBegin(GL_QUADS);
      glVertex3f(11.0f, 28.0f, 1.0f);
      glVertex3f(14.0f, 28.0f, 1.0f);
      glVertex3f(14.0f, 25.0f, 1.0f);
      glVertex3f(11.0f, 25.0f, 1.0f);
   glEnd();

   glBegin(GL_LINES);
      glVertex3f(10.0f, 28.0f, 2.0f);
      glVertex3f(11.0f, 28.0f, 1.0f);
      glVertex3f(15.0f, 28.0f, 2.0f);
      glVertex3f(14.0f, 28.0f, 1.0f);
      glVertex3f(15.0f, 25.0f, 2.0f);
      glVertex3f(14.0f, 25.0f, 1.0f);
      glVertex3f(10.0f, 25.0f, 2.0f);
      glVertex3f(11.0f, 25.0f, 1.0f);

      glVertex3f(11.0f, 28.0f, 1.0f);
      glVertex3f(10.0f, 28.0f, 0.0f);
      glVertex3f(14.0f, 28.0f, 1.0f);
      glVertex3f(15.0f, 28.0f, 0.0f);
      glVertex3f(11.0f, 25.0f, 1.0f);
      glVertex3f(10.0f, 25.0f, 0.0f);
      glVertex3f(14.0f, 25.0f, 1.0f);
      glVertex3f(15.0f, 25.0f, 0.0f);
   glEnd();

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
   glutInitWindowSize(640, 480);
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