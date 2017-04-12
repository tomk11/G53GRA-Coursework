#include "Table.h"

void Table::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

    glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[0], scale[0]);
	glPushMatrix();
	DrawTop();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50,0,-25);
	DrawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50,0,25);
	DrawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50,0,-25);
	DrawLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50,0,25);
	DrawLeg();
	glPopMatrix();

	glPopAttrib();

	glPopMatrix();
}

void Table::DrawTop(){
	glTranslatef(0,100,0);
	glScalef(1,0.05,0.5);
	glutSolidCube(100.0f);
}

void Table::DrawLeg(){
	glTranslatef(0,50,0);
	glScalef(0.05,1,0.05);
	glutSolidCube(100.0f);
}