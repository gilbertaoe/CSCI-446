#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include "Environment.h"
#include "./raygl.h"
#include "./raygldefs.h"

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

void drawFarm(GLuint texture[])
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

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glColor3f(0.80f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 30.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 30.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 0.1f, 48.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 0.1f, 48.0f);
	glEnd();

	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 30.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(48.0f, 0.1f, 48.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(48.0f, 5.0f, 48.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 30.0f);
	glEnd();

	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 30.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 30.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 5.0f, 30.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 30.0f);
	glEnd();

	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 0.1f, 48.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 48.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 5.0f, 48.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 48.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glColor3f(0.80f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(48.0f, 5.0f, 48.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(42.0f, 9.0f, 48.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(42.0f, 9.0f, 30.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(48.0f, 5.0f, 30.0f);
	glEnd();

	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(35.0f, 5.0f, 48.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(42.0f, 9.0f, 48.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(42.0f, 9.0f, 30.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(35.0f, 5.0f, 30.0f);
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

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glColor3f(0.80f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(35.0f, 5.0f, 48.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 48.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 0.1f, 35.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(35.0f, 5.0f, 35.0f);
	glEnd();

	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(35.0f, 5.0f, 35.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(35.0f, 0.1f, 35.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(35.0f, 0.1f, 30.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(35.0f, 5.0f, 30.0f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
		glVertex3f(34.9f, 5.0f, 39.0f);
		glVertex3f(34.9f, 0.1f, 39.0f);
	glEnd();
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

Environment::Environment()
{

}

void Environment::drawEnvironment(GLuint texture[])
{
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(0.0f, 0.0f, 52.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(52.0f, 0.0f, 52.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(52.f, 0.0f, 0.0f);
	glEnd();
	//glDisable (GL_TEXTURE_2D);

	drawPost();
	drawFarm(texture);
	drawTrough();
}