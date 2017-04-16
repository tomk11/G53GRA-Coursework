#include "Clock.h"

void Clock::Display()
{
	glPushMatrix();
	glScalef(0.5,0.5,0.2);
	glutSolidCube(100.0f);

	glPopMatrix();
}

void Clock::Update(const double& deltaTime)
{
}
