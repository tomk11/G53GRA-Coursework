#include "Stadium.h"

void Stadium::Display()
{
	glPushMatrix();
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glDisable(GL_COLOR_MATERIAL);
	DrawMat();
	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();

}

void Stadium::DrawMat(){

	glBegin(GL_QUADS);
	glMaterialfv(GL_FRONT, GL_SPECULAR, static_cast<GLfloat*>(specular));
	glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));

	for (int i = -(compSize + boundarySize)/2; i<=(compSize + boundarySize)/2; i++){
		for (int j = -(compSize + boundarySize)/2; j<=(compSize + boundarySize)/2; j++){
			if (abs(i) > compSize/2 or abs(j) > compSize/2){
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(rDiffuse));
			}
			else {
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(yDiffuse));
			}
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f(i+1, 0, j+1);
				glVertex3f(i+1, 0, j);
				glVertex3f(i, 0, j);
				glVertex3f(i, 0, j+1);
		}
	}
	
	glEnd();

}


void Stadium::DrawSeating(){
	glBegin(GL_QUADS);
	glPushMatrix();

	for (int i=0; i<seatingRows; i++){
		glVertex3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, 1);
	}
	glEnd();
}
