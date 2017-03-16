#include "Floor.h"

void Floor::Display()
{
	// Draws an exciting chequered floor
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glDisable(GL_COLOR_MATERIAL);
	//float bDiffuse[] = {0.0f,0.0f,0.0f,1.0f};
	//float wDiffuse[] = {1.0f,1.0f,1.0f,1.0f};
	float bDiffuse[] = {1.0f,1.0f,1.0f,1.0f};
	float wDiffuse[] = {0.0f,0.0f,0.0f,1.0f};
	float yDiffuse[] = {1.0f,1.0f,0.0f,0.7f};
	float rDiffuse[] = {1.0f,0.0f,0.0f,0.7f};
	float specular[] = {1.0f,1.0f,1.0f,1.0f};
	float shininess = 128.0f;

	glBegin(GL_QUADS);
	glMaterialfv(GL_FRONT, GL_SPECULAR, static_cast<GLfloat*>(specular));
	glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));

	for (int i = -6; i<6; i++){
		for (int j = -6; j<6; j++){
			if (abs(i) > 3 or abs(j) > 3){
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(rDiffuse));
			}
			else {
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(yDiffuse));
			}
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f(scale[0] * static_cast<float>(i) + scale[0], -100.0f, scale[2] * static_cast<float>(j) + scale[2]);
				glVertex3f(scale[0] * static_cast<float>(i) + scale[0], -100.0f, scale[2] * static_cast<float>(j));
				glVertex3f(scale[0] * static_cast<float>(i), -100.0f, scale[2] * static_cast<float>(j));
				glVertex3f(scale[0] * static_cast<float>(i), -100.0f, scale[2] * static_cast<float>(j) + scale[2]);
		}
	}
	
	glEnd();
	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();
}