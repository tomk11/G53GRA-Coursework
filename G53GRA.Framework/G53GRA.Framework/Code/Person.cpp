#include "Person.h"

Person::Person(){
	// initialise the position modifier
	positionModifier[1]= 100*(LowerLegDim[1]* cosd(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * cosd(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * cosd(BodyAngle)) ;
	positionModifier[2]= 100*(LowerLegDim[1]* sind(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * sind(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * sind(BodyAngle)) ;
}

Person::Person(string id){
	ID = id;
	addInstruction("dummy", 0);
	Person();
}


// ANIMATION FUNCTIONS (INTERPOLATION)
void Person::reset(){
	BodyAngle =	RightKneeAngle = LeftKneeAngle = RightHipAngle = LeftHipAngle = RightElbowAngle = LeftElbowAngle = RightShoulderAngle = LeftShoulderAngle = 0;
}

void Person::addInstruction(string instruction, float time){
	float duration =0;
	if (instruction  == "walk" || instruction == "walkb"){
		duration = time * walkTime;
	}
	else if (instruction == "bow"){
		duration = time *bowTime;
	}
	else {
		duration = time;
	}
	instructions.push_back(instruction);
	instructionTimes.push_back(duration);
	totalAnimationTime += duration;
	totalInstructionTimes.push_back(totalAnimationTime);


	for(int i=0; i<instructions.size(); i++){
	  cout << instructions[i] << ' ';
	}
	cout << endl;
	for(int i=0; i<instructions.size(); i++){
	  cout << totalInstructionTimes[i] << ' ';
	}
	cout << endl;
	

}

void Person::turnC(){
	directionModifier  = -currentInstructionTime/totalInstructionTime * 90;
}
void Person::turnA(){
	directionModifier = currentInstructionTime/totalInstructionTime * 90;
}

void Person::bow(){
	if (currentInstructionTime >= keyframe +1){
		keyframe += 1;
	    if (keyframe ==2 ){
		    currentInstructionTime=0;
			keyframe = 0;
		} 
	}
	interp = 1+ keyframe-currentInstructionTime;
	LeftHipAngle = interp * BowLeftHipAngleFrames[keyframe] + (1-interp) * BowLeftHipAngleFrames[keyframe+1];
	RightHipAngle = interp * BowRightHipAngleFrames[keyframe] + (1-interp) * BowRightHipAngleFrames[keyframe+1];
	BodyAngle = interp * BowBodyAngleFrames[keyframe] + (1-interp) * BowBodyAngleFrames[keyframe+1];
}

void Person::walk(){
	if (currentInstructionTime >= keyframe + 1){
		keyframe += 1;
		if (keyframe == 2){
			SetPositionModifier("Right Foot");
		}
		if (keyframe == 6){
			SetPositionModifier("Left Foot");
		}
	    
	    if (keyframe == 8){
		    currentInstructionTime=0;
			keyframe = 0;
		} 
	}
	else{}

	interp = 1 +keyframe-currentInstructionTime;
	LeftHipAngle = interp * WalkLeftHipAngleFrames[keyframe] + (1-interp) * WalkLeftHipAngleFrames[keyframe+1];
	RightHipAngle = interp * WalkRightHipAngleFrames[keyframe] + (1-interp) * WalkRightHipAngleFrames[keyframe+1];
	LeftKneeAngle = interp * WalkLeftKneeAngleFrames[keyframe] + (1-interp) * WalkLeftKneeAngleFrames[keyframe+1];
	RightKneeAngle = interp * WalkRightKneeAngleFrames[keyframe] + (1-interp) * WalkRightKneeAngleFrames[keyframe+1];
    
}

void Person::walkb(){
	if (currentInstructionTime >= keyframe + 1){
		keyframe += 1;
		if (keyframe == 2){
			SetPositionModifier("Right Foot");
		}
		if (keyframe == 6){
			SetPositionModifier("Left Foot");
		}
	    
	    if (keyframe == 8){
		    currentInstructionTime=0;
			keyframe = 0;
		} 
	}
	else{}

	interp = 1 +keyframe-currentInstructionTime;
	LeftHipAngle = interp * WalkBLeftHipAngleFrames[keyframe] + (1-interp) * WalkBLeftHipAngleFrames[keyframe+1];
	RightHipAngle = interp * WalkBRightHipAngleFrames[keyframe] + (1-interp) * WalkBRightHipAngleFrames[keyframe+1];
	LeftKneeAngle = interp * WalkBLeftKneeAngleFrames[keyframe] + (1-interp) * WalkBLeftKneeAngleFrames[keyframe+1];
	RightKneeAngle = interp * WalkBRightKneeAngleFrames[keyframe] + (1-interp) * WalkBRightKneeAngleFrames[keyframe+1];
    
}

void Person::Update(const double& deltaTime)
{
	for (int i=1; i<instructions.size(); i++){
		if (totalInstructionTimes[i-1] <= currentAnimationTime && currentAnimationTime < totalInstructionTimes[i]){
			if (currentInstructionStage != i){
				reset();
				currentInstructionStage = i;
			    keyframe = -1;
			    currentInstructionTime = 0;
			    totalInstructionTime = instructionTimes[i];
			    currentInstruction = instructions[i];
			    SetPositionModifier("Left Foot");
				if (currentInstruction == "bow"){
		            speed=2;
				}
				if(currentInstruction == "walk" || currentInstruction == "walkb"){
		            speed=8;
		        }
		        if(directionModifier !=0){
		        	direction = direction + directionModifier;
		        	directionModifier = 0;
		        }
			}
			if (currentInstruction == "bow"){bow();}
			else if(currentInstruction == "walk"){walk();}
			else if(currentInstruction == "walkb"){walkb();}
			else if(currentInstruction == "turnA"){ turnA();}
			else if(currentInstruction == "turnC"){ turnC();}
		}
	}
	currentAnimationTime += speed * deltaTime;
	currentInstructionTime += speed * deltaTime;
}


// FUNCTIONS TO DISPLAY THE FUNCTION (HIERARCHICAL MODELING)
void Person::Display()
{
	glPushMatrix();
	SetPositionModifier();
    glTranslatef(pos[0], pos[1], pos[2]);
    glTranslatef(positionModifier[0], positionModifier[1], positionModifier[2]);
	glRotatef(direction + directionModifier, 0,1,0);
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

void Person::DrawBody(){
	glScalef(BodyDim[0],BodyDim[1],BodyDim[2]);
	glutSolidCube(100.0f);
}


void Person::DrawRightArm(){
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
void Person::DrawLeftArm(){
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

void Person::DrawRightLeg(){

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

void Person::DrawLeftLeg(){
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

void Person::DrawHead(){
	glScalef(HeadDim[0],HeadDim[1],HeadDim[2]);
	glTranslatef(0, 100, 0);
	glutSolidSphere(100.0f, 10,10);

}

double Person::sind(double angle)
{
	double angleradians = angle * M_PI / 180.0f;
	return sin(angleradians);
}

double Person::cosd(double angle)
{
	double angleradians = angle * M_PI / 180.0f;
	return cos(angleradians);
}

void Person::SetPositionModifier(){
	SetPositionModifier(string(positionRef));
}

void Person::SetPositionModifier(string newPositionRef){
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

