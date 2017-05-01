#include "Cylinder.h"

Cylinder::Cylinder(double radius, double height){
	glPushMatrix();
	int subdivisions = 10;

    GLUquadricObj *q = gluNewQuadric();
	gluQuadricOrientation(q,GLU_OUTSIDE);
	gluCylinder(q, radius, radius, height, subdivisions, 1);


	gluQuadricOrientation(q,GLU_INSIDE);
	gluDisk( q, 0.0, radius, subdivisions, 1);
	glTranslatef( 0,0,height );

	gluQuadricOrientation(q,GLU_OUTSIDE);
	gluDisk( q, 0.0, radius, subdivisions, 1);
	glPopMatrix();
}