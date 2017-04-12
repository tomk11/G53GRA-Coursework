#include "Judoka.h"

void Judoka::Display()
{
	glPushMatrix();
	SetPositionModifier();
    glTranslatef(pos[0] + positionModifier[0], pos[1] + positionModifier[1], pos[2]);
	glScalef(scale[0], scale[0], scale[0]);

	glPushMatrix();
	DrawBody();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 50*BodyDim[1],0);
	glTranslatef(0, 100*NeckDim[1],0);
	DrawHead();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50*BodyDim[0], 50*BodyDim[1],0);
	DrawLeftArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50*BodyDim[0], 50*BodyDim[1],0);
	DrawRightArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-25*BodyDim[0], -50*BodyDim[1],0);
	DrawRightLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(25*BodyDim[0], -50*BodyDim[1],0);
	DrawLeftLeg();
	glPopMatrix();

	glPopMatrix();
}

void Judoka::DrawBody(){
	glScalef(BodyDim[0],BodyDim[1],BodyDim[2]);
	glutSolidCube(100.0f);
}

void Judoka::DrawRightLeg(){

	glPushMatrix();
	    glScalef(UpperLegDim[0],UpperLegDim[1],UpperLegDim[2]);
        glRotatef(90,1,0,0);
        GLUquadricObj *p = gluNewQuadric();
        gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
	glPopMatrix();

	glTranslatef(0, -100*UpperLegDim[1],0);

	glPushMatrix();
	    glScalef(LowerLegDim[0],LowerLegDim[1],LowerLegDim[2]);
        glRotatef(90,1,0,0);
        GLUquadricObj *q = gluNewQuadric();
        gluCylinder(q,50,50,100,10,10);    // Draw Our Cylinder
	glPopMatrix();
}

void Judoka::DrawRightArm(){
	glRotatef(RightShoulderAngle, 0,0,1);
    GLUquadricObj *p = gluNewQuadric();

    glPushMatrix();
	glScalef(UpperArmDim[0],UpperArmDim[1],UpperArmDim[2]);
    glRotatef(90,1,0,0);
    gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
    glPopMatrix();

	glTranslatef(0, -100*UpperArmDim[1],0);
	glRotatef(-RightShoulderAngle, 0,0,1);

    glPushMatrix();
	glScalef(LowerArmDim[0], LowerArmDim[1], LowerArmDim[2]);
    glRotatef(90,1,0,0);
    gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
    glPopMatrix();
}
void Judoka::DrawLeftArm(){
	glRotatef(LeftShoulderAngle, 0,0,1);
    GLUquadricObj *p = gluNewQuadric();

    glPushMatrix();
	glScalef(UpperArmDim[0],UpperArmDim[1],UpperArmDim[2]);
    glRotatef(90,1,0,0);
    gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
    glPopMatrix();


	glTranslatef(0, -100*UpperArmDim[1],0);
	glRotatef(-LeftShoulderAngle, 0,0,1);

    glPushMatrix();
	glScalef(LowerArmDim[0], LowerArmDim[1], LowerArmDim[2]);
    glRotatef(90,1,0,0);
    gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
    glPopMatrix();

}

void Judoka::DrawLeftLeg(){
    glRotatef(LeftHipAngle,1,0,0);
	glPushMatrix();
	    glScalef(UpperLegDim[0],UpperLegDim[1],UpperLegDim[2]);
        glRotatef(90,1,0,0);
        GLUquadricObj *p = gluNewQuadric();
        gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
	glPopMatrix();

	glTranslatef(0, -100*UpperLegDim[1],0);

	glPushMatrix();
	    glScalef(LowerLegDim[0],LowerLegDim[1],LowerLegDim[2]);
        glRotatef(90,1,0,0);
        glRotatef(LeftKneeAngle,1,0,0);
        gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
	glPopMatrix();

	}
void Judoka::DrawHead(){
	glScalef(HeadDim[0],HeadDim[1],HeadDim[2]);
	glTranslatef(0, 100, 0);
	glutSolidSphere(100.0f, 10,10);

}

void Judoka::SetPositionModifier(){
	if (positionRef == "Left Foot"){
	    positionModifier[1]= 100*(LowerLegDim[1]* cosd(LeftHipAngle - LeftKneeAngle) +UpperLegDim[1] * cosd(LeftHipAngle) + BodyDim[1]/2) ;
	    //cout << cosd(LeftHipAngle) << endl;

	    positionModifier[2]= 100*(LowerLegDim[2]* sind(LeftHipAngle - LeftKneeAngle) +UpperLegDim[2] * sind(LeftHipAngle) ) ;
	}
	if (positionRef == "Right Foot"){
		positionModifier[1]= 100*(LowerLegDim[1]* cosd(RightHipAngle - RightKneeAngle) +UpperLegDim[1] * cosd(RightHipAngle) + BodyDim[1]/2) ;
		positionModifier[2]= 100*(LowerLegDim[2]* sind(RightHipAngle - RightKneeAngle) +UpperLegDim[2] * sind(RightHipAngle)) ;
	}
}

double Judoka::sind(double angle)
{
	double angleradians = angle * M_PI / 180.0f;
	return sin(angleradians);
}

double Judoka::cosd(double angle)
{
	double angleradians = angle * M_PI / 180.0f;
	return cos(angleradians);
}

void Judoka::walk(int steps){
	if (positionRef == "LeftFoot"){
		if (LeftHipAngle > -10){

	}

}

void Judoka::Update(const double& deltaTime)
{
	for (int i=0; i<10000000; i++){
		while (LeftHipAngle < 10){
			LeftHipAngle += 1;
			RightHipAngle -= 1;
		}
		positionRef ="Right Foot";
		while (RightHipAngle < 10){
			LeftHipAngle -= 1;
			RightHipAngle += 1;
		}
		positionRef ="Left Foot";
		}
	}
}
