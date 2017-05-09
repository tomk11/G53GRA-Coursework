#include "Cylinder.h"

Cylinder::Cylinder(double radius, double height, const std::string& texture){
	Cylinder(radius, height, texture, texture, texture);
}

Cylinder::Cylinder(double radius, double height, const std::string& textureTop, const std::string& textureMid, const std::string& textureBot ){

	glPushMatrix();
	glTranslatef( 0,0,height/2 );
	glRotatef(180, 1,0,0);
	glTranslatef( 0,0,-height/2 );

	int subdivisions = 10;
    GLUquadricObj *q = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	
	texIDTop = Scene::GetTexture(textureTop);
	texIDMid = Scene::GetTexture(textureMid);
	texIDBot = Scene::GetTexture(textureBot);
	
	gluQuadricTexture(q,true);
	gluQuadricNormals(q, GLU_SMOOTH);


	glBindTexture(GL_TEXTURE_2D, texIDMid);
	gluQuadricOrientation(q,GLU_OUTSIDE);
	gluCylinder(q, radius, radius, height, subdivisions, 1);

	glBindTexture(GL_TEXTURE_2D, texIDBot);
	gluQuadricOrientation(q,GLU_OUTSIDE);
	gluDisk( q, 0.0, radius, subdivisions, 1);
	glTranslatef( 0,0,height );

	glBindTexture(GL_TEXTURE_2D, texIDTop);
	gluQuadricOrientation(q,GLU_OUTSIDE);
	gluDisk( q, 0.0, radius, subdivisions, 1);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glPopMatrix();

}

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