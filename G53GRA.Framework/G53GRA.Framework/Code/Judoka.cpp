#include "Judoka.h"

Judoka::Judoka(){
	// initialise the position modifier
	positionModifier[1]= 100*(LowerLegDim[1]* cosd(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * cosd(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * cosd(BodyAngle)) ;
	positionModifier[2]= 100*(LowerLegDim[1]* sind(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * sind(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * sind(BodyAngle)) ;
}

Judoka::Judoka(string id){
	ID = id;
	Judoka();
}

void Judoka::Display()
{
	glPushMatrix();
	SetPositionModifier();
    glTranslatef(pos[0], pos[1], pos[2]);
    glTranslatef(positionModifier[0], positionModifier[1], positionModifier[2]);
	glRotatef(direction, 0,1,0);
	glScalef(scale[0], scale[0], scale[0]);
	
	glRotatef(BodyAngle,1,0,0);
	glPushMatrix();
	DrawBody();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 50*BodyDim[1],0);
	glTranslatef(0, 100*NeckDim[1],0);
	DrawHead();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50*(BodyDim[0] + UpperArmDim[0]), 50*BodyDim[1],0);
	DrawLeftArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50*(BodyDim[0] + UpperArmDim[0]), 50*BodyDim[1],0);
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


void Judoka::DrawRightArm(){
	glRotatef(RightShoulderAngle, 0,0,1);
    GLUquadricObj *p = gluNewQuadric();

    glPushMatrix();
	glScalef(UpperArmDim[0],UpperArmDim[1],UpperArmDim[2]);
    glRotatef(90,1,0,0);
    gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
    glPopMatrix();

	glTranslatef(0, -100*UpperArmDim[1],0);

    glPushMatrix();
    glRotatef(RightElbowAngle, 0,0,1);
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

void Judoka::DrawRightLeg(){

    glRotatef(RightHipAngle,1,0,0);
	glPushMatrix();
	    glScalef(UpperLegDim[0],UpperLegDim[1],UpperLegDim[2]);
        glRotatef(90,1,0,0);
        GLUquadricObj *p = gluNewQuadric();
        gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
	glPopMatrix();

	glTranslatef(0, -100*UpperLegDim[1],0);

	glPushMatrix();
        glRotatef(RightKneeAngle,1,0,0);
	    glScalef(LowerLegDim[0],LowerLegDim[1],LowerLegDim[2]);
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
        glRotatef(LeftKneeAngle,1,0,0);
	    glScalef(LowerLegDim[0],LowerLegDim[1],LowerLegDim[2]);
        glRotatef(90,1,0,0);
        gluCylinder(p,50,50,100,10,10);    // Draw Our Cylinder
	glPopMatrix();
}

void Judoka::DrawHead(){
	glScalef(HeadDim[0],HeadDim[1],HeadDim[2]);
	glTranslatef(0, 100, 0);
	glutSolidSphere(100.0f, 10,10);

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

void Judoka::SetPositionModifier(){
	SetPositionModifier(string(positionRef));
}

void Judoka::SetPositionModifier(string newPositionRef){
	bool change = positionRef != newPositionRef;

	if (change){
	    positionRef = newPositionRef;
	    pos[2] += positionModifier[2];
	    pos[0] += positionModifier[0];
	}

	// In our model the person is drawn from the center of his body. The position modifier allows us to set the location of the player by a particular body part. It edits the global position modifier at the beginning and the end of the routine.
    if (positionRef == "Left Foot"){
	    positionModifier[1]= 100*(LowerLegDim[1]* cosd(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * cosd(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * cosd(BodyAngle)) ;
	    positionModifierSize= 100*(LowerLegDim[1]* sind(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * sind(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * sind(BodyAngle)) ;
    	positionModifier[0] = sind(direction) * positionModifierSize;
    	positionModifier[2] = cosd(direction) * positionModifierSize;
	}
	else if (positionRef == "Right Foot"){
		positionModifier[1] = 100*(LowerLegDim[1]* cosd(BodyAngle + RightHipAngle + RightKneeAngle) +UpperLegDim[1] * cosd(BodyAngle + RightHipAngle) + BodyDim[1]/2*cosd(BodyAngle)) ;
    	positionModifierSize= 100*(LowerLegDim[1]* sind(BodyAngle + RightHipAngle + RightKneeAngle) +UpperLegDim[1] * sind(BodyAngle + RightHipAngle) + BodyDim[1]/2*sind(BodyAngle)) ;
    	positionModifier[0] = sind(direction) * positionModifierSize;
    	positionModifier[2] = cosd(direction) * positionModifierSize;
    }
    else if (positionRef == "Body"){
    	positionModifier[0] = positionModifier[1] = positionModifier[2] = 0;
    }

	if (change){
	    pos[2] -= positionModifier[2];
	    pos[0] -= positionModifier[0];
	}
    
    
}


void Judoka::reset(){
	BodyAngle =	RightKneeAngle = LeftKneeAngle = RightHipAngle = LeftHipAngle = RightElbowAngle = LeftElbowAngle = RightShoulderAngle = LeftShoulderAngle = 0;
}

void Judoka::bow(){
	if (animateTime > keyframe + 1){
		keyframe += 1;
	    if (keyframe >1){
		    animateTime=0;
			keyframe = 0;
		} 
		cout << keyframe << endl;
	}
	interp = 1 +keyframe-animateTime;
	LeftHipAngle = interp * BowLeftHipAngleFrames[keyframe] + (1-interp) * BowLeftHipAngleFrames[keyframe+1];
	RightHipAngle = interp * BowRightHipAngleFrames[keyframe] + (1-interp) * BowRightHipAngleFrames[keyframe+1];
	BodyAngle = interp * BowBodyAngleFrames[keyframe] + (1-interp) * BowBodyAngleFrames[keyframe+1];
}

void Judoka::ippon(){
	reset();
}

void Judoka::walk(){
	if (animateTime >= keyframe + 1){
		keyframe += 1;
		if (keyframe == 2){
			SetPositionModifier("Right Foot");
		}
		if (keyframe == 6){
			SetPositionModifier("Left Foot");
		}
	    
	    if (keyframe>7){
		    animateTime=0;
			keyframe = 0;
		} 
	}
	else{}

	interp = 1 +keyframe-animateTime;
	LeftHipAngle = interp * WalkLeftHipAngleFrames[keyframe] + (1-interp) * WalkLeftHipAngleFrames[keyframe+1];
	RightHipAngle = interp * WalkRightHipAngleFrames[keyframe] + (1-interp) * WalkRightHipAngleFrames[keyframe+1];
	LeftKneeAngle = interp * WalkLeftKneeAngleFrames[keyframe] + (1-interp) * WalkLeftKneeAngleFrames[keyframe+1];
	RightKneeAngle = interp * WalkRightKneeAngleFrames[keyframe] + (1-interp) * WalkRightKneeAngleFrames[keyframe+1];
    
}

void Judoka::HandleKey(unsigned char key, int state, int mX, int mY){
	if (state == 1 && key == 'm'){
		RightShoulderAngle += 1.0;
	}
}


void Judoka::Update(const double& deltaTime)
{
	if(totalAnimateTime <= bowTime){
		if (stage == -1){
			speed=2;
			stage +=1 ;
			keyframe = -1;
			animateTime = 0;
		}
		bow();
	}
	else if(totalAnimateTime <= bowTime + 8*walkTime){ 
		if (stage == 0){
			speed = 6;
			stage += 1;
			cout << stage << endl;
			keyframe = -1;
			animateTime = 0;
		}
		walk();
	}
	else if (totalAnimateTime <= 8*walkTime + 2*bowTime){
		if (stage == 1){
			speed=2;
			stage = 2;
			cout << stage << endl;
			keyframe = -1;
			animateTime = 0;
		}
		bow();
	}
	else if (totalAnimateTime <= 13*walkTime + 2*bowTime){
		if (stage == 2){
			SetPositionModifier("Left Foot");
			if (ID == "left"){
				direction = 90;
			}
			else{
				direction = -90;
			}
			speed=6;
			stage = 3;
			cout << stage << endl;
			keyframe = -1;
			animateTime = 0;
		}
		walk();
	}
	else if (totalAnimateTime <= 13*walkTime + 3*bowTime){
		if (stage == 3){
			speed=2;
			stage = 4;
			cout << stage << endl;
			keyframe = -1;
			animateTime = 0;
		}
		bow();
	}
	animateTime += speed*deltaTime;
	totalAnimateTime += speed * deltaTime;
}