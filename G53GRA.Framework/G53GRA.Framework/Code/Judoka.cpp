#include "Judoka.h"

Judoka::Judoka() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.5f){}

void Judoka::Display()
{
	glPushMatrix();

	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(0.5f, scale, 0.5f);

	DrawBody();
	glPushMatrix();
	glTranslatef(0,100,0);
	DrawHead();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(120,0,0);
	DrawArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-120,0);
	DrawLeg();
	glPopMatrix();

	glPopMatrix();
}

void Judoka::DrawBody(){
	glutSolidCube(100.0f);
}

void Judoka::DrawLeg(){
	glScalef(0.5,1,0.5);
	glutSolidCube(100.0f);
}

void Judoka::DrawArm(){
	glScalef(0.5,1,0.5);
	glutSolidCube(100.0f);
}

void Judoka::DrawHead(){
	glutSolidCube(50.0f);
}

void Judoka::Update(const double& deltaTime)
{
	zrot += 10.0f * static_cast<float>(deltaTime);
}
