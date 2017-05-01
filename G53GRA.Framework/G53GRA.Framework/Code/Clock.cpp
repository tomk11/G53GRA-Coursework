#include "Clock.h"

void Clock::Display()
{
	glPushMatrix();    
    glTranslatef(pos[0], pos[1] , pos[2]);
	glScalef(1,0.5,0.2);
	glutSolidCube(100.0f);

	glPopMatrix();
}

void Clock::Update(const double& deltaTime)
{
}
