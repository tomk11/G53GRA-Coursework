#include "Table.h"

Table::Table() : xrot(0.0f), yrot(0.0f), zrot(0.0f){}

void Table::Display()
{
	glPushMatrix();

	glTranslatef(0.0f, 0.0f, 0.0f);

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


	glPopMatrix();
}

void Table::DrawTop(){
	glScalef(1,0.05,0.5);
	glutSolidCube(100.0f);
}

void Table::DrawLeg(){
	glScalef(0.05,1,0.05);
	glTranslatef(0,-50,0);
	glutSolidCube(100.0f);
}

void Table::Update(const double& deltaTime)
{
}
