#include "Chicken.h"

Chicken::Chicken()
{
	x = 0;
	y = 0;
	z = 0;
}

GLuint texture[1];

void loadTextures(void)
{
	int c;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	Image *image[1];
	for(c = 0; c < 1; c++)
	{
		image[c] = (Image *) malloc(sizeof(Image));
		if(image[c] == NULL) exit(0);
	}
	
	if(!imageLoad("./25-brown-black-bird-nice-feather-texture.ppm", image[0])) exit(0);
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image[0]->sizeX, image[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);    
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
void Chicken::drawChicken(GLuint **texture)
{
	  glBindTexture(GL_TEXTURE_2D, texture[0]);
	  //The body
  	glBegin(GL_QUADS);
   	  //Top face
      glColor3f(0.8f, 0.5f, 0.25f);
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + 1.0f, z + 1.0f);
	  glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + 1.0f, z + 1.0f);

      //Bottom face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + -1.0f);
 
      //Front face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + 1.0f);
 
      //Back face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + 1.0f, z + -1.0f);
      
      //Left face
      glTexCoord2d(0.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + -1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + -1.0f, y + -1.0f, z + 1.0f);
      
      //Right face
      glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + -1.0f);
      glTexCoord2d(1.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + 1.0f);
      glTexCoord2d(1.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + 1.0f);
      glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -1.0f, z + -1.0f);
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
      	glVertex3f(x + 0.5f, y + 1.5f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.5f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
      	glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
      	
      	//Bottom face
      	glVertex3f(x + 0.5f, y + 1.0f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.0f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.0f, z + 1.8f);
      	glVertex3f(x + 0.5f, y + 1.0f, z + 1.8f);
      	
      	//Front face
      	glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
      	glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
      	glVertex3f(x + -0.5f, y + 1.0f, z + 1.8f);
      	glVertex3f(x + 0.5f, y + 1.0f, z + 1.8f);
      	
      	//Back face
      	glVertex3f(x + 0.5f, y + 1.0f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.0f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.5f, z + 0.8f);
      	glVertex3f(x + 0.5f, y + 1.5f, z + 0.8f);
      	
      	//Left face
      	glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
      	glVertex3f(x + -0.5f, y + 1.5f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.0f, z + 0.8f);
      	glVertex3f(x + -0.5f, y + 1.0f, z + 1.8f);
      	
      	//Right face
      	glVertex3f(x + 0.5f, y + 1.5f, z + 0.8f);
      	glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
      	glVertex3f(x + 0.5f, y + 1.0f, z + 1.8f);
      	glVertex3f(x + 0.5f, y + 1.0f, z + 0.8f);
	//glEnd();
	
	//The Eyes
	//glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);
		//Right eye
		glVertex3f(x + 0.5f, y + 1.5f, z + 1.8f);
		glVertex3f(x + 0.25f, y + 1.5f, z + 1.8f);
		glVertex3f(x + 0.25f, y + 1.25f, z + 1.8f);
		glVertex3f(x + 0.5f, y + 1.25f, z + 1.8f);
		
		//Left eye
		glVertex3f(x + -0.25f, y + 1.5f, z + 1.8f);
		glVertex3f(x + -0.5f, y + 1.5f, z + 1.8f);
		glVertex3f(x + -0.5f, y + 1.25f, z + 1.8f);
		glVertex3f(x + -0.25f, y + 1.25f, z + 1.8f);
	//glEnd();
	
	//The Beak
	//glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		
		//Top face
		glVertex3f(x + 0.25f, y + 1.25f, z + 1.8f);
		glVertex3f(x + -0.25f, y + 1.25f, z + 1.8f);
		glVertex3f(x + -0.25f, y + 1.25f, z + 2.2f);
		glVertex3f(x + 0.25f, y + 1.25f, z + 2.2f);
		
		//Bottom face
		glVertex3f(x + 0.25f, y + 1.0f, z + 1.8f);
		glVertex3f(x + -0.25f, y + 1.0f, z + 1.8f);
		glVertex3f(x + -0.25f, y + 1.0f, z + 2.2f);
		glVertex3f(x + 0.25f, y + 1.0f, z + 2.2f);
		
		//Front face
		glVertex3f(x + 0.25f, y + 1.25f, z + 2.2f);
		glVertex3f(x + -0.25f, y + 1.25f, z + 2.2f);
		glVertex3f(x + -0.25f, y + 1.0f, z + 2.2f);
		glVertex3f(x + 0.25f, y + 1.0f, z + 2.2f);
		
		//Left face
		glVertex3f(x + -0.25f, y + 1.25f, z + 2.2f);
		glVertex3f(x + -0.25f, y + 1.25f, z + 1.8f);
		glVertex3f(x + -0.25f, y + 1.0f, z + 1.8f);
		glVertex3f(x + -0.25f, y + 1.0f, z + 2.2f);
		
		//Right face
		glVertex3f(x + 0.25f, y + 1.25f, z + 1.8f);
		glVertex3f(x + 0.25f, y + 1.25f, z + 2.2f);
		glVertex3f(x + 0.25f, y + 1.0f, z + 2.2f);
		glVertex3f(x + 0.25f, y + 1.0f, z + 1.8f);		
	//glEnd();
	
	//The Gullet
	//glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		
		//Bottom face
		glVertex3f(x + 0.125f, y + 0.8f, z + 1.0f);
		glVertex3f(x + -0.125f, y + 0.8f, z + 1.0f);
		glVertex3f(x + -0.125f, y + 0.8f, z + 1.8f);
		glVertex3f(x + 0.125f, y + 0.8f, z + 1.8f);
		
		//Front face
		glVertex3f(x + 0.125f, y + 1.0f, z + 1.8f);
		glVertex3f(x + -0.125f, y + 1.0f, z + 1.8f);
		glVertex3f(x + -0.125f, y + 0.8f, z + 1.8f);
		glVertex3f(x + 0.125f, y + 0.8f, z + 1.8f);
		
		//Left face
		glVertex3f(x + -0.125f, y + 1.0f, z + 1.8f);
		glVertex3f(x + -0.125f, y + 1.0f, z + 1.0f);
		glVertex3f(x + -0.125f, y + 0.8f, z + 1.0f);
		glVertex3f(x + -0.125f, y + 0.8f, z + 1.8f);
		
		//Right face
		glVertex3f(x + 0.125f, y + 1.0f, z + 1.0f);
		glVertex3f(x + 0.125f, y + 1.0f, z + 1.8f);
		glVertex3f(x + 0.125f, y + 0.8f, z + 1.8f);
		glVertex3f(x + 0.125f, y + 0.8f, z + 1.0f);
	glEnd();
	glPopMatrix();
	
	//The Legs
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		//Left leg
		//Bottom face
		glVertex3f(x + -0.33f, y + -2.0f, z + -0.33f);
		glVertex3f(x + -0.66f, y + -2.0f, z + -0.33f);
		glVertex3f(x + -0.66f, y + -2.0f, z + 0.33f);
		glVertex3f(x + -0.33f, y + -2.0f, z + 0.33f);
		
		//Front face
		glVertex3f(x + -0.33f, y + -1.0f, z + 0.33f);
		glVertex3f(x + -0.66f, y + -1.0f, z + 0.33f);
		glVertex3f(x + -0.66f, y + -2.0f, z + 0.33f);
		glVertex3f(x + -0.33f, y + -2.0f, z + 0.33f);
		
		//Back face
		glVertex3f(x + -0.33f, y + -1.0f, z + -0.33f);
		glVertex3f(x + -0.66f, y + -1.0f, z + -0.33f);
		glVertex3f(x + -0.66f, y + -2.0f, z + -0.33f);
		glVertex3f(x + -0.33f, y + -2.0f, z + -0.33f);
		
		//Left face
		glVertex3f(x + -0.66f, y + -1.0f, z + 0.33f);
		glVertex3f(x + -0.66f, y + -1.0f, z + -0.33f);
		glVertex3f(x + -0.66f, y + -2.0f, z + -0.33f);
		glVertex3f(x + -0.66f, y + -2.0f, z + 0.33f);
		
		//Right face
		glVertex3f(x + -0.33f, y + -1.0f, z + -0.33f);
		glVertex3f(x + -0.33f, y + -1.0f, z + 0.33f);
		glVertex3f(x + -0.33f, y + -2.0f, z + 0.33f);
		glVertex3f(x + -0.33f, y + -2.0f, z + -0.33f);
	glEnd();
	
	//Right leg
	//Bottom face
	glBegin(GL_QUADS);
		glVertex3f(x + 0.66f, y + -2.0f, z + -0.33f);
		glVertex3f(x + 0.33f, y + -2.0f, z + -0.33f);
		glVertex3f(x + 0.33f, y + -2.0f, z + 0.33f);
		glVertex3f(x + 0.66f, y + -2.0f, z + 0.33f);
		
		//Front face
		glVertex3f(x + 0.66f, y + -1.0f, z + 0.33f);
		glVertex3f(x + 0.33f, y + -1.0f, z + 0.33f);
		glVertex3f(x + 0.33f, y + -2.0f, z + 0.33f);
		glVertex3f(x + 0.66f, y + -2.0f, z + 0.33f);
		
		//Back face
		glVertex3f(x + 0.66f, y + -1.0f, z + -0.33f);
		glVertex3f(x + 0.33f, y + -1.0f, z + -0.33f);
		glVertex3f(x + 0.33f, y + -2.0f, z + -0.33f);
		glVertex3f(x + 0.66f, y + -2.0f, z + -0.33f);
		
		//Left face
		glVertex3f(x + 0.33f, y + -1.0f, z + 0.33f);
		glVertex3f(x + 0.33f, y + -1.0f, z + -0.33f);
		glVertex3f(x + 0.33f, y + -2.0f, z + -0.33f);
		glVertex3f(x + 0.33f, y + -2.0f, z + 0.33f);
		
		//Right face
		glVertex3f(x + 0.66f, y + -1.0f, z + -0.33f);
		glVertex3f(x + 0.66f, y + -1.0f, z + 0.33f);
		glVertex3f(x + 0.66f, y + -2.0f, z + 0.33f);
		glVertex3f(x + 0.66f, y + -2.0f, z + -0.33f);
	glEnd();

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	//The wings
	//Left Wing
	glPushMatrix();
	glTranslatef(-1.0f, 1.0f, 0.0f);
	glRotatef(LAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.0f, -1.0f, 0.0f);
	glBegin(GL_QUADS);
	    glColor3f(0.8f, 0.5f, 0.25f);
		glTexCoord2d(0.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + 0.75f);
		glTexCoord2d(1.0,0.0); glVertex3f(x + -1.0f, y + 1.0f, z + -0.75f);
		glTexCoord2d(1.0,1.0); glVertex3f(x + -1.0f, y + -0.33f, z + -0.75f);
		glTexCoord2d(0.0,1.0); glVertex3f(x + -1.0f, y + -0.33f, z + 0.75f);
	glEnd();
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	//Right wing
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRotatef(RAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-1.0f, -1.0f, 0.0f);
	glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + -0.75f);
		glTexCoord2d(1.0,0.0); glVertex3f(x + 1.0f, y + 1.0f, z + 0.75f);
		glTexCoord2d(1.0,1.0); glVertex3f(x + 1.0f, y + -0.33f, z + 0.75f);
		glTexCoord2d(0.0,1.0); glVertex3f(x + 1.0f, y + -0.33f, z + -0.75f);
	glEnd();
	glPopMatrix();
	
}
