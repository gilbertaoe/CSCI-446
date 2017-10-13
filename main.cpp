#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "Cow.h"
#include "Camera.cpp"
#include "Environment.h"
#include "Chicken.h"
#include "UFO.h"

Camera *cam = new Camera;

void myDisplay()
{
   glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
   glLoadIdentity(); 
   cam->position();
   glEnable (GL_DEPTH_TEST); //enable the depth testing
   glEnable (GL_LIGHTING); //enable the lighting
   glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
   glShadeModel (GL_SMOOTH); //set the shader to smooth shader
   glColor3f(1.0f, 1.0f, 1.0f);

   glPushMatrix();
   glutSolidCube(1); //draw the cube
   glPopMatrix();

   glutSwapBuffers(); //swap the buffers
}

void myInit(void)
{

}

void myReshape(int w, int h)
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

   glutMainLoop();
}