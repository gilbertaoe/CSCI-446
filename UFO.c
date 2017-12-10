#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>

float xpos, ypos, zpos, xrot, yrot, zrot, angle;
float lastx, lasty;
float cRadius; // our radius distance from our character
int rotating = 0;

GLfloat LAngle, RAngle;

GLfloat xUFO, yUFO, zUFO = 0;
GLfloat xChicken, yChicken, zChicken = 0;
GLfloat xCow, yCow, zCow = 0;

int lastSub = 1;
int lastAdd = 1;

void drawUFO()
{
   glColor3f(1.0f, 0.0f, 0.0f);
   glLineWidth(8);
   glBegin(GL_LINES);
      glVertex3f(xUFO + 10, yUFO, zUFO);
      glVertex3f(xUFO + 30, yUFO + -10, zUFO + 20);
   glEnd();

   glRotatef(angle,0.0,1.0,0.0);

   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + 0, yUFO + 2, zUFO + 0);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(0.0f, angle2/100, 0.0f);
         glVertex3f(xUFO + sin(angle2) * 10, yUFO + 0, zUFO + cos(angle2) * 10);
      }
   glEnd();

   glRotatef(-angle,0.0,1.0,0.0);

   glRotatef(-angle,0.0,1.0,0.0);

   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_TRIANGLE_FAN);
      glVertex3f(xUFO + 0, yUFO + -2, zUFO + 0);
      for (int angle2 = 0; angle2 < 360; angle2++)
      {
         glColor3f(angle2/100, 0.0f, 0.0f);
         glVertex3f(xUFO + sin(angle2) * 10, yUFO + 0, zUFO + cos(angle2) * 10);
      }
   glEnd();

   glRotatef(angle,0.0,1.0,0.0);


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

void lightc()
{
}

void myDisplay()
{

   glClearColor (0.0,0.0,0.0, 1.0); //clear the screen to black
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
   glLoadIdentity();

   glColor3f(1.0f, 1.0f, 1.0f);
   glTranslatef(0.0f, 0.0f, -50);
   glRotatef(-angle,1.0,0.0,0.0);

   //glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
   //glTranslated(-19, 0.0f,-25); //translate the screen to the position of our camera
   glColor3f(1.0f, 1.0f, 1.0f);

   //rayglFrameBegin("movie");

   xUFO = 0; yUFO = 0; zUFO = 0;
   drawUFO();

   //glRotatef(-angle,1.0,0.0,0.0);

   glutSwapBuffers(); //swap the buffers

   //rayglFrameEnd();

   angle++;
}

void myInit(void)
{
   //rayglTextureType(0);
   //rayglTranslateTexture(0, 0, 0);
   //rayglScaleTexture(1, 1, 1);
   //setFadeDistance(1000);
   //setFadePower(1.4);
   glEnable (GL_DEPTH_TEST); //enable the depth testing
   glShadeModel (GL_SMOOTH); //set the shader to smooth shader
   lightc();
}

void keyboard (unsigned char key, int x, int y)
{
    if (key==27)
    {
      exit(0);
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
   xpos = 0; ypos = 0; zpos = 0; xrot = 0; yrot = 0; angle=0.0; cRadius = 10.0f;

   glutKeyboardFunc (keyboard);
   myInit();
   glutMainLoop();
}