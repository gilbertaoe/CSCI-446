
  /**************************************************/
  /* Name: Ben Linser                               */
  /*                                                */
  /* Generates a simple chicken with a basic        */
  /*       dark green mipmap applied                */ 
  /*								                */
  /* CSci 446 / fall 2017                           */
  /**************************************************/
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>

GLfloat RAngle = 0.0f;
GLfloat LAngle = 0.0f;
int lastAdd = 1;
int lastSub = 1;
int paused = 0;
GLuint texture;

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

//idle function
void idle()
{
		glutPostRedisplay();
}

void lWing()
{
	if(LAngle > -90 && lastSub == 1)
	{
		LAngle -= 1.0f;
	}
	else if(LAngle == -90)
	{
		lastSub = 0;
		LAngle += 1.0f;
	}
	else if(LAngle < 0 && lastSub == 0)
	{
		LAngle += 1.0f;
	}
	else if(LAngle == 0)
	{
		lastSub = 1;
		LAngle -= 1.0f;
	}
}

void rWing()
{
	if(RAngle < 90 && lastAdd == 1)
	{
		RAngle += 1.0f;
	}
	else if(RAngle == 90)
	{
		lastAdd = 0;
		RAngle -= 1.0f;
	}
	else if(RAngle > 0 && lastAdd == 0)
	{
		RAngle -= 1.0f;
	}
	else if(RAngle == 0)
	{
		lastAdd = 1;
		RAngle += 1.0f;
	}
	
}

//drawing function
void myDisplay(void)
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -7.0f);
	glRotatef(20, 1, 1, 0);
	glRotatef(30, 1, 1, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glBindTexture(GL_TEXTURE_2D, texture);
	//The body
  	glBegin(GL_QUADS);
   	  //Top face
      glColor3f(0.8f, 0.5f, 0.25f);
      glTexCoord2d(0.0,0.0); glVertex3f( 1.0f, 1.0f, -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(-1.0f, 1.0f, -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(-1.0f, 1.0f,  1.0f);
	  glTexCoord2d(0.0,1.0); glVertex3f( 1.0f, 1.0f,  1.0f);

      //Bottom face
      glTexCoord2d(0.0,0.0); glVertex3f( 1.0f, -1.0f,  1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(-1.0f, -1.0f,  1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f( 1.0f, -1.0f, -1.0f);
 
      //Front face
      glTexCoord2d(0.0,0.0); glVertex3f( 1.0f,  1.0f, 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(-1.0f,  1.0f, 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(-1.0f, -1.0f, 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f( 1.0f, -1.0f, 1.0f);
 
      //Back face
      glTexCoord2d(0.0,0.0); glVertex3f( 1.0f, -1.0f, -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(-1.0f, -1.0f, -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(-1.0f,  1.0f, -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f( 1.0f,  1.0f, -1.0f);
      
      //Left face
      glTexCoord2d(0.0,0.0); glVertex3f(-1.0f, 1.0f, 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(-1.0f, 1.0f, -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(-1.0f, -1.0f, 1.0f);
      
      //Right face
      glTexCoord2d(0.0,0.0); glVertex3f(1.0f,  1.0f, -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(1.0f,  1.0f,  1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(1.0f, -1.0f,  1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(1.0f, -1.0f, -1.0f);
   	glEnd();
  	glDisable (GL_TEXTURE_2D);
   	
   	//The head	
   	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 1.0f);
	glRotatef(LAngle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, -1.0f, -1.0f);
   	glBegin(GL_QUADS);
   		//Top face
		glColor3f(1.0f, 0.87f, 0.68f);
      	glVertex3f( 0.5f, 1.5f, 0.8f);
      	glVertex3f(-0.5f, 1.5f, 0.8f);
      	glVertex3f(-0.5f, 1.5f,  1.8f);
      	glVertex3f( 0.5f, 1.5f,  1.8f);
      	
      	//Bottom face
      	glVertex3f( 0.5f, 1.0f,  0.8f);
      	glVertex3f(-0.5f, 1.0f,  0.8f);
      	glVertex3f(-0.5f, 1.0f, 1.8f);
      	glVertex3f( 0.5f, 1.0f, 1.8f);
      	
      	//Front face
      	glVertex3f( 0.5f, 1.5f, 1.8f);
      	glVertex3f(-0.5f, 1.5f, 1.8f);
      	glVertex3f(-0.5f, 1.0f, 1.8f);
      	glVertex3f(0.5f, 1.0f, 1.8f);
      	
      	//Back face
      	glVertex3f(0.5f, 1.0f, 0.8f);
      	glVertex3f(-0.5f, 1.0f, 0.8f);
      	glVertex3f(-0.5f, 1.5f, 0.8f);
      	glVertex3f(0.5f, 1.5f, 0.8f);
      	
      	//Left face
      	glVertex3f(-0.5f, 1.5f, 1.8f);
      	glVertex3f(-0.5f, 1.5f, 1.8f);
      	glVertex3f(-0.5f, 1.0f, 1.8f);
      	glVertex3f(-0.5f, 1.0f, 1.8f);
      	
      	//Right face
      	glVertex3f(0.5f, 1.5f, 0.8f);
      	glVertex3f(0.5f, 1.5f, 1.8f);
      	glVertex3f(0.5f, 1.0f, 1.8f);
      	glVertex3f(0.5f, 1.0f, 0.8f);
	//glEnd();
	
	//The Eyes
	//glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);
		//Right eye
		glVertex3f(0.5f, 1.5f, 1.8f);
		glVertex3f(0.25f, 1.5f, 1.8f);
		glVertex3f(0.25f, 1.25f, 1.8f);
		glVertex3f(0.5f, 1.25f, 1.8f);
		
		//Left eye
		glVertex3f(-0.25f, 1.5f, 1.8f);
		glVertex3f(-0.5f, 1.5f, 1.8f);
		glVertex3f(-0.5f, 1.25f, 1.8f);
		glVertex3f(-0.25f, 1.25f, 1.8f);
	//glEnd();
	
	//The Beak
	//glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		
		//Top face
		glVertex3f(0.25f, 1.25f, 1.8f);
		glVertex3f(-0.25f, 1.25f, 1.8f);
		glVertex3f(-0.25f, 1.25f, 2.2f);
		glVertex3f(0.25f, 1.25f, 2.2f);
		
		//Bottom face
		glVertex3f(0.25f, 1.0f, 1.8f);
		glVertex3f(-0.25f, 1.0f, 1.8f);
		glVertex3f(-0.25f, 1.0f, 2.2f);
		glVertex3f(0.25f, 1.0f, 2.2f);
		
		//Front face
		glVertex3f(0.25f, 1.25f, 2.2f);
		glVertex3f(-0.25f, 1.25f, 2.2f);
		glVertex3f(-0.25f, 1.0f, 2.2f);
		glVertex3f(0.25f, 1.0f, 2.2f);
		
		//Left face
		glVertex3f(-0.25f, 1.25f, 2.2f);
		glVertex3f(-0.25f, 1.25f, 1.8f);
		glVertex3f(-0.25f, 1.0f, 1.8f);
		glVertex3f(-0.25f, 1.0f, 2.2f);
		
		//Right face
		glVertex3f(0.25f, 1.25f, 1.8f);
		glVertex3f(0.25f, 1.25f, 2.2f);
		glVertex3f(0.25f, 1.0f, 2.2f);
		glVertex3f(0.25f, 1.0f, 1.8f);		
	//glEnd();
	
	//The Gullet
	//glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		
		//Bottom face
		glVertex3f(0.125f, 0.8f, 1.0f);
		glVertex3f(-0.125f, 0.8f, 1.0f);
		glVertex3f(-0.125f, 0.8f, 1.8f);
		glVertex3f(0.125f, 0.8f, 1.8f);
		
		//Front face
		glVertex3f(0.125f, 1.0f, 1.8f);
		glVertex3f(-0.125f, 1.0f, 1.8f);
		glVertex3f(-0.125f, 0.8f, 1.8f);
		glVertex3f(0.125f, 0.8f, 1.8f);
		
		//Left face
		glVertex3f(-0.125f, 1.0f, 1.8f);
		glVertex3f(-0.125f, 1.0f, 1.0f);
		glVertex3f(-0.125f, 0.8f, 1.0f);
		glVertex3f(-0.125f, 0.8f, 1.8f);
		
		//Right face
		glVertex3f(0.125f, 1.0f, 1.0f);
		glVertex3f(0.125f, 1.0f, 1.8f);
		glVertex3f(0.125f, 0.8f, 1.8f);
		glVertex3f(0.125f, 0.8f, 1.0f);
	glEnd();
	glPopMatrix();
	
	//The Legs
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		//Left leg
		//Bottom face
		glVertex3f(-0.33f, -2.0f, -0.33f);
		glVertex3f(-0.66f, -2.0f, -0.33f);
		glVertex3f(-0.66f, -2.0f, 0.33f);
		glVertex3f(-0.33f, -2.0f, 0.33f);
		
		//Front face
		glVertex3f(-0.33f, -1.0f, 0.33f);
		glVertex3f(-0.66f, -1.0f, 0.33f);
		glVertex3f(-0.66f, -2.0f, 0.33f);
		glVertex3f(-0.33f, -2.0f, 0.33f);
		
		//Back face
		glVertex3f(-0.33f, -1.0f, -0.33f);
		glVertex3f(-0.66f, -1.0f, -0.33f);
		glVertex3f(-0.66f, -2.0f, -0.33f);
		glVertex3f(-0.33f, -2.0f, -0.33f);
		
		//Left face
		glVertex3f(-0.66f, -1.0f, 0.33f);
		glVertex3f(-0.66f, -1.0f, -0.33f);
		glVertex3f(-0.66f, -2.0f, -0.33f);
		glVertex3f(-0.66f, -2.0f, 0.33f);
		
		//Right face
		glVertex3f(-0.33f, -1.0f, -0.33f);
		glVertex3f(-0.33f, -1.0f, 0.33f);
		glVertex3f(-0.33f, -2.0f, 0.33f);
		glVertex3f(-0.33f, -2.0f, -0.33f);
	glEnd();
	
	//Right leg
	//Bottom face
	glBegin(GL_QUADS);
		glVertex3f(0.66f, -2.0f, -0.33f);
		glVertex3f(0.33f, -2.0f, -0.33f);
		glVertex3f(0.33f, -2.0f, 0.33f);
		glVertex3f(0.66f, -2.0f, 0.33f);
		
		//Front face
		glVertex3f(0.66f, -1.0f, 0.33f);
		glVertex3f(0.33f, -1.0f, 0.33f);
		glVertex3f(0.33f, -2.0f, 0.33f);
		glVertex3f(0.66f, -2.0f, 0.33f);
		
		//Back face
		glVertex3f(0.66f, -1.0f, -0.33f);
		glVertex3f(0.33f, -1.0f, -0.33f);
		glVertex3f(0.33f, -2.0f, -0.33f);
		glVertex3f(0.66f, -2.0f, -0.33f);
		
		//Left face
		glVertex3f(0.33f, -1.0f, 0.33f);
		glVertex3f(0.33f, -1.0f, -0.33f);
		glVertex3f(0.33f, -2.0f, -0.33f);
		glVertex3f(0.33f, -2.0f, 0.33f);
		
		//Right face
		glVertex3f(0.66f, -1.0f, -0.33f);
		glVertex3f(0.66f, -1.0f, 0.33f);
		glVertex3f(0.66f, -2.0f, 0.33f);
		glVertex3f(0.66f, -2.0f, -0.33f);
	glEnd();

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	//The wings
	//Left Wing
	glPushMatrix();
	glTranslatef(-1.0f, 1.0f, 0.0f);
	glRotatef(LAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.0f, -1.0f, 0.0f);
	glBegin(GL_QUADS);
	    glColor3f(0.8f, 0.5f, 0.25f);
		glTexCoord2d(0.0,0.0); glVertex3f(-1.0f, 1.0f, 0.75f);
		glTexCoord2d(1.0,0.0); glVertex3f(-1.0f, 1.0f, -0.75f);
		glTexCoord2d(1.0,1.0); glVertex3f(-1.0f, -0.33f, -0.75f);
		glTexCoord2d(0.0,1.0); glVertex3f(-1.0f, -0.33f, 0.75f);
	glEnd();
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D, texture);
	//Right wing
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRotatef(RAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-1.0f, -1.0f, 0.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(1.0f, 1.0f, -0.75f);
		glTexCoord2d(1.0,0.0); glVertex3f(1.0f, 1.0f, 0.75f);
		glTexCoord2d(1.0,1.0); glVertex3f(1.0f, -0.33f, 0.75f);
		glTexCoord2d(0.0,1.0); glVertex3f(1.0f, -0.33f, -0.75f);
	glEnd();
	glPopMatrix();
	
	//Buttons
	/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(3.0f, 0.7f);
		glVertex2f(2.0f, 0.7f);
		glVertex2f(2.0f, 0.0f);
		glVertex2f(3.0f, 0.0f);
		
		glVertex2f(3.0f, 0.0f);
		glVertex2f(2.0f, 0.0f);
		glVertex2f(2.0f, -0.7f);
		glVertex2f(3.0f, -0.7f);
	glEnd();
	
	//Pause Logo
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
		glVertex2f(2.4f, 0.6f);
		glVertex2f(2.2f, 0.6f);
		glVertex2f(2.2f, 0.1f);
		glVertex2f(2.4f, 0.1f);
		
		glVertex2f(2.8f, 0.6f);
		glVertex2f(2.6f, 0.6f);
		glVertex2f(2.6f, 0.1f);
		glVertex2f(2.8f, 0.1f);
	glEnd();
	
	//R for Restart
	glBegin(GL_LINE_STRIP);
		glVertex2f(2.3f, -0.6f);
		glVertex2f(2.3f, -0.1f);
		glVertex2f(2.7f, -0.25f);
		glVertex2f(2.3f, -0.4f);
		glVertex2f(2.7f, -0.6f);
	glEnd();*/
	
	if(paused == 0)
	{
		glutSwapBuffers();
		lWing();
		rWing();
	}
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	GLfloat lightpos[] = {1.0, -2.0, 2.0, .5};
	GLfloat white[] = {0.8, 0.8, 0.8, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glMaterialfv(GL_FRONT, GL_AMBIENT, white);
} 

//reshape function
void reshape(GLsizei width, GLsizei height)
{
	if(height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);	
}

//settings function
void myInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glPointSize(2.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    glEnable(GL_TEXTURE_2D);
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && 484 < x && x < 566 && 240 < y && y < 297)
	{
		LAngle = 0;
		RAngle = 0;
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && 484 < x && x < 566 && 183 < y && y < 240)
	{
		if(paused == 0)
		{
			paused = 1;
		}
		else
		{
			paused = 0;
		}
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Homework 7");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
    texture = LoadTexture( "25-brown-black-bird-nice-feather-texture.ppm", 500, 300);
	myInit();
	glutMainLoop();
	return 1;
}
