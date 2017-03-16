#include "Judoka.h"

/// initalise the triangles properties
Judoka::Judoka() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.5f){}

/// draw the triangle in the scene
void Judoka::Display()
{
	glPushMatrix();

	glTranslatef(0.0f, 0.0f, 0.0f);

	// rotate the triangle by the given degrees
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	// scale the traingle
	glScalef(0.5f, scale, 0.5f);

	// disable culling (removal) of backface triangles so that when we look at
	// triangle to does not disappearthe back of the
	glDisable(GL_CULL_FACE);

	DrawBody();
	// re-enable face culling for other objects in the scene
	glEnable(GL_CULL_FACE);

	// revert back to the matrix we had before we added the triangles transforms 
	// in the scene are not effected by the triangles transformations so that 
	// other objects 
	glPopMatrix();
}

void Judoka::DrawBody(){

	glutSolidCube(100.0f);
}

/// update the Z rotation variable with change in time
void Judoka::Update(const double& deltaTime)
{
	zrot += 10.0f * static_cast<float>(deltaTime);
}
