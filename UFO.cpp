#include "UFO.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include "./raygl.h"
#include "./raygldefs.h"

UFO::UFO()
{
	x = 0;
	y = 15;
	z = 0;
}

void UFO::drawUFO()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x+0, y+2, z+0);
		for (int angle2 = 0; angle2 < 360; angle2++)
		{
			glColor3f(0.0f, angle2/100, 0.0f);
			glVertex3f(x+sin(angle2) * 10, y+0, z+cos(angle2) * 10);
		}
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x+0, y+-2, z+0);
		for (int angle2 = 0; angle2 < 360; angle2++)
		{
			glColor3f(angle2/100, 0.0f, 0.0f);
			glVertex3f(x+sin(angle2) * 10, y+0, z+cos(angle2) * 10);
		}
	glEnd();

	glTranslatef(x+0.0f, y+1.5f, z+0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidSphere(1.0f, 50.0f, 50.0f);
	glTranslatef(-x+0.0f, -y+1.5f, -z+0.0f);
}