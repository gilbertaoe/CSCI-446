//Author: Chase Davis
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <unistd.h>
 
/* Global variables */
char title[] = "3D Shapes";
float frontLegsRotate = 0;
float backLegsRotate = 0;
int isWalking = 0;
int backLegsGo = 0;
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);    
   glShadeModel(GL_SMOOTH);   
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}
void head(){
   glBegin(GL_POLYGON);
   //Head
   //Front Face
   glVertex3f(-0.25, 1, 1.0);
   glVertex3f(0.25, 1, 1.0);

   glVertex3f(0.25, 1, 1.0);
   glVertex3f(0.25, .5, 1.0);

   glVertex3f(0.25, .5, 1.0);
   glVertex3f(-0.25, .5, 1.0);

   glVertex3f(-0.25, .5, 1.0);
   glVertex3f(-0.25, 1, 1.0);

   //Back Face
   glVertex3f(-0.25, 1, 1.5);
   glVertex3f(0.25, 1, 1.5);

   glVertex3f(0.25, 1, 1.5);
   glVertex3f(0.25, .5, 1.5);

   glVertex3f(0.25, .5, 1.5);
   glVertex3f(-0.25, .5, 1.5);

   glVertex3f(-0.25, .5, 1.5);
   glVertex3f(-0.25, 1, 1.5);   

   //Connections
   glVertex3f(-0.25, 1, 1.0);
   glVertex3f(-0.25, 1, 1.5);

   glVertex3f(0.25, 1, 1.0);
   glVertex3f(0.25, 1, 1.5);

   glVertex3f(0.25, .5, 1.0);
   glVertex3f(0.25, .5, 1.5);

   glVertex3f(-0.25, .5, 1.0);
   glVertex3f(-0.25, .5, 1.5);
   
   glEnd();  // End of drawing color-cube
}
void backLegs(){
   glBegin(GL_POLYGON);
   //Back Right Leg
   //top face of leg

   glVertex3f(1.0, -1.0, -2.0);
   glVertex3f(1.0, -1.0, -1.8);

   glVertex3f(1.0, -1.0, -1.8);
   glVertex3f(0.8, -1.0, -1.8);

   glVertex3f(0.8, -1.0, -1.8);
   glVertex3f(0.8, -1.0, -2.0);

   glVertex3f(0.8, -1.0, -2.0);
   glVertex3f(1.0, -1.0, -2.0);

   //bottom face of leg

   glVertex3f(0.8, -1.8, -2.0);
   glVertex3f(0.8, -1.8, -1.8);

   glVertex3f(0.8, -1.8, -1.8);
   glVertex3f(1.0, -1.8, -1.8);

   glVertex3f(1.0, -1.8, -1.8);
   glVertex3f(1.0, -1.8, -2.0);

   glVertex3f(1.0, -1.8, -2.0);
   glVertex3f(0.8, -1.8, -2.0);

   //connections

   glVertex3f(0.8, -1.8, -2.0);
   glVertex3f(0.8, -1.0, -2.0);

   glVertex3f(0.8, -1.8, -1.8);
   glVertex3f(0.8, -1.0, -1.8);

   glVertex3f(1.0, -1.8, -1.8);
   glVertex3f(1.0, -1.0, -1.8);

   glVertex3f(1.0, -1.8, -2.0);
   glVertex3f(1.0, -1.0, -2.0);

   //Back Left Leg
   //top face of leg

   glVertex3f(-1.0, -1.0, -2.0);
   glVertex3f(-1.0, -1.0, -1.8);

   glVertex3f(-1.0, -1.0, -1.8);
   glVertex3f(-0.8, -1.0, -1.8);

   glVertex3f(-0.8, -1.0, -1.8);
   glVertex3f(-0.8, -1.0, -2.0);

   glVertex3f(-0.8, -1.0, -2.0);
   glVertex3f(-1.0, -1.0, -2.0);

   //bottom face of leg

   glVertex3f(-0.8, -1.8, -2.0);
   glVertex3f(-0.8, -1.8, -1.8);

   glVertex3f(-0.8, -1.8, -1.8);
   glVertex3f(-1.0, -1.8, -1.8);

   glVertex3f(-1.0, -1.8, -1.8);
   glVertex3f(-1.0, -1.8, -2.0);

   glVertex3f(-1.0, -1.8, -2.0);
   glVertex3f(-0.8, -1.8, -2.0);

   //connections

   glVertex3f(-0.8, -1.8, -2.0);
   glVertex3f(-0.8, -1.0, -2.0);

   glVertex3f(-0.8, -1.8, -1.8);
   glVertex3f(-0.8, -1.0, -1.8);

   glVertex3f(-1.0, -1.8, -1.8);
   glVertex3f(-1.0, -1.0, -1.8);

   glVertex3f(-1.0, -1.8, -2.0);
   glVertex3f(-1.0, -1.0, -2.0);

   glEnd();
 }
void frontLegs(){
   glBegin(GL_POLYGON);
      //Front Left Leg
      //top face of leg
      glVertex3f(-1.0, -1.0, 1.0);
      glVertex3f(-1.0, -1.0, 0.8);

      glVertex3f(-1.0, -1.0, 0.8);
      glVertex3f(-0.8, -1.0, 0.8);

      glVertex3f(-0.8, -1.0, 0.8);
      glVertex3f(-0.8, -1.0, 1.0);

      glVertex3f(-0.8, -1.0, 1.0);
      glVertex3f(-1.0, -1.0, 1.0);

      //bottom face of leg

      glVertex3f(-0.8, -1.8, 1.0);
      glVertex3f(-0.8, -1.8, 0.8);

      glVertex3f(-0.8, -1.8, 0.8);
      glVertex3f(-1.0, -1.8, 0.8);

      glVertex3f(-1.0, -1.8, 0.8);
      glVertex3f(-1.0, -1.8, 1.0);

      glVertex3f(-1.0, -1.8, 1.0);
      glVertex3f(-0.8, -1.8, 1.0);

      //connections

      glVertex3f(-0.8, -1.8, 1.0);
      glVertex3f(-0.8, -1.0, 1.0);

      glVertex3f(-0.8, -1.8, 0.8);
      glVertex3f(-0.8, -1.0, 0.8);

      glVertex3f(-1.0, -1.8, 0.8);
      glVertex3f(-1.0, -1.0, 0.8);

      glVertex3f(-1.0, -1.8, 1.0);
      glVertex3f(-1.0, -1.0, 1.0);

      //Front Right Leg
      //top face of leg

      glVertex3f(1.0, -1.0, 1.0);
      glVertex3f(1.0, -1.0, 0.8);

      glVertex3f(1.0, -1.0, 0.8);
      glVertex3f(0.8, -1.0, 0.8);

      glVertex3f(0.8, -1.0, 0.8);
      glVertex3f(0.8, -1.0, 1.0);

      glVertex3f(0.8, -1.0, 1.0);
      glVertex3f(1.0, -1.0, 1.0);

      //bottom face of leg

      glVertex3f(0.8, -1.8, 1.0);
      glVertex3f(0.8, -1.8, 0.8);

      glVertex3f(0.8, -1.8, 0.8);
      glVertex3f(1.0, -1.8, 0.8);

      glVertex3f(1.0, -1.8, 0.8);
      glVertex3f(1.0, -1.8, 1.0);

      glVertex3f(1.0, -1.8, 1.0);
      glVertex3f(0.8, -1.8, 1.0);

      //connections

      glVertex3f(0.8, -1.8, 1.0);
      glVertex3f(0.8, -1.0, 1.0);

      glVertex3f(0.8, -1.8, 0.8);
      glVertex3f(0.8, -1.0, 0.8);

      glVertex3f(1.0, -1.8, 0.8);
      glVertex3f(1.0, -1.0, 0.8);

      glVertex3f(1.0, -1.8, 1.0);
      glVertex3f(1.0, -1.0, 1.0);

      glEnd();
}
void body(){
   glBegin(GL_POLYGON);

   glVertex3f(-1.0, 1.0, 1.0);
   glVertex3f(1.0, 1.0, 1.0);

   glVertex3f(1.0, 1.0, 1.0);
   glVertex3f(1.0, -1.0, 1.0);

   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(-1.0, -1.0, 1.0);

   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(-1.0, 1.0, 1.0);

   glVertex3f(-1.0, 1.0, 1.0);
   glVertex3f(-1.0, 1.0, -2.0);

   glVertex3f(-1.0, 1.0, -2.0);
   glVertex3f(1.0, 1.0, -2.0);

   glVertex3f(1.0, 1.0, -2.0);
   glVertex3f(1.0, -1.0, -2.0);

   glVertex3f(1.0, -1.0, -2.0);
   glVertex3f(-1.0, -1.0, -2.0);

   glVertex3f(-1.0, -1.0, -2.0);
   glVertex3f(-1.0, 1.0, -2.0);

   glVertex3f(1.0, 1.0, 1.0);
   glVertex3f(1.0, 1.0, -2.0);

   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(1.0, -1.0, -2.0);

   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(-1.0, -1.0, -2.0);

   glEnd();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);     
 
   
   glLoadIdentity();                
   glTranslatef(0.0f, 0.0f, -6.0f);  
   
   glRotatef(65.0f, 0.0f, 1.0f, 0.0f);
   glPushMatrix();
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glColor3f(1.0f, 0.0f, 0.0f);

   body();

   if (isWalking == 1)
   {
   //glTranslatef(0.0f, 0.0f, 0.0f);
   if (frontLegsRotate < 35)
   {
      frontLegsRotate += 1;
      if (frontLegsRotate == 35)
      {
         frontLegsRotate = 0;
      }
      glTranslatef(-1.0, -1.0, 1.0);
      glRotatef(-frontLegsRotate, 1.0, 0.0, 0.0); 
      glTranslatef(1.0f, 1.0f, -1.0f);   
   }
   frontLegs();  
   if (frontLegsRotate < 35)
   {
         glTranslatef(-1.0, -1.0, 1.0);
         glRotatef(frontLegsRotate, 1.0, 0.0, 0.0); 
         glTranslatef(1.0f, 1.0f, -1.0f);; 
         
   } 
      if (frontLegsRotate == 15)
      {
         backLegsGo = 1;
      }

   }
   else
   {
      frontLegs();
   }


   if (backLegsGo == 1)
   {
      if (isWalking == 1)
      {
      //glTranslatef(0.0f, 0.0f, 0.0f);
      if (backLegsRotate > -35)
      {
         backLegsRotate -= 1;
         if (backLegsRotate == -35)
         {
            backLegsRotate = 0;
         }
         glTranslatef(1.0, -1.0, -2.0);
         glRotatef(-backLegsRotate, 1.0, 0.0, 0.0); 
         glTranslatef(-1.0f, 1.0f, 2.0f);   
      }
      backLegs();  
      if (backLegsRotate > -35)
      {
            glTranslatef(1.0, -1.0, -2.0);
            glRotatef(backLegsRotate, 1.0, 0.0, 0.0); 
            glTranslatef(-1.0f, 1.0f, 2.0f); 
            
      } 
         //if (backLegsRotate == -34)
         //{
         //   isWalking = 0;
         //}
      
      }
      else
      {
         backLegs();
      }

   }
   else
   {
      backLegs();
   }
   
   head();

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
         else if (x <= 20 && y <= 20 && isWalking == 1)
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

 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
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
 
/* Main function: GLUT runs as a console application starting at main() */
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