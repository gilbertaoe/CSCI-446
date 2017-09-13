#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "Cow.h"
#include "Camera.h"
#include "Environment.h"
#include "Chicken.h"
#include "UFO.h"

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glFlush();
}

void myInit(void)
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glColor3f(0.0f, 0.0f, 0.0f);
   glPointSize(4.0);
   glLoadIdentity();   
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);   
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(200, 200);
   glutCreateWindow("HW 2");

   myInit();

   glutDisplayFunc(myDisplay);

   glutMainLoop();
}