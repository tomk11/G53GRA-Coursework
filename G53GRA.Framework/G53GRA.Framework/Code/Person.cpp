#include "Person.h"

Person::Person(){
  // initialise the position modifier
  positionModifier[1]= 100*(LowerLegDim[1]* cosd(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * cosd(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * cosd(BodyAngle)) ;
  positionModifier[2]= 100*(LowerLegDim[1]* sind(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * sind(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * sind(BodyAngle)) ;
  addInstruction("dummy", 0);
}

void Person::setOpponent(Person* p){
  opponent = p;
  hasOpponent = true;
}

float* Person::getInfo(){
  float info[8] = {pos[0], pos[1], pos[2], positionModifier[0], positionModifier[1], positionModifier[2], direction, directionModifier};
  float* pointer;
  pointer= info;
  return pointer;
}

float* Person::getOpponentInfo(){
  float* oppInfo = opponent -> getInfo();
  float* pointer;
  pointer = oppInfo;
  return pointer;
}


// ANIMATION FUNCTIONS (INTERPOLATION)
void Person::reset(){
  BodyAngle =	RightKneeAngle = LeftKneeAngle = RightHipAngle = LeftHipAngle = RightElbowAngle = LeftElbowAngle = RightShoulderAngle = LeftShoulderAngle = 0;
}

void Person::addInstruction(string instruction, float time){
  // The instruction list is read by the update function to determine the movements of the players
  float duration =0;
  // some instructions require a particular duration of time. I.e you can't stop walking mid step.
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
    switch (keyframe){
      case 2: 
        SetPositionModifier("Right Foot"); 
        break;
      case 6: 
        SetPositionModifier("Left Foot"); 
        break;
      case 8: 
        currentInstructionTime=0; 
        keyframe = 0; 
        break;
    } 
  }

  interp = 1 +keyframe-currentInstructionTime;
  LeftHipAngle = interp * WalkLeftHipAngleFrames[keyframe] + (1-interp) * WalkLeftHipAngleFrames[keyframe+1];
  RightHipAngle = interp * WalkRightHipAngleFrames[keyframe] + (1-interp) * WalkRightHipAngleFrames[keyframe+1];
  LeftKneeAngle = interp * WalkLeftKneeAngleFrames[keyframe] + (1-interp) * WalkLeftKneeAngleFrames[keyframe+1];
  RightKneeAngle = interp * WalkRightKneeAngleFrames[keyframe] + (1-interp) * WalkRightKneeAngleFrames[keyframe+1];
}

void Person::walkb(){
  if (currentInstructionTime > keyframe + 1){
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

void Person::judoThrow(){
  if (currentInstructionTime >= keyframe + 1){
    keyframe += 1;
    if (keyframe == 1){
      SetPositionModifier("Right Foot");
    }

    if (keyframe == 8){
      currentInstructionTime=0;
      keyframe = 0;
    } 
  }
  else{}

  interp = 1 +keyframe-currentInstructionTime;
  LeftHipAngle = interp * throwLH[keyframe] + (1-interp) * throwLH[keyframe+1];
  RightHipAngle = interp * throwRH[keyframe] + (1-interp) * throwRH[keyframe+1];
  LeftKneeAngle = interp * throwLK[keyframe] + (1-interp) * throwLK[keyframe+1];
  RightKneeAngle = interp * throwRK[keyframe] + (1-interp) * throwRK[keyframe+1];
  BodyAngle = interp * throwB[keyframe] + (1-interp) * throwB[keyframe+1];

  directionModifier = interp * (throwD[keyframe]) + (1-interp)* throwD[keyframe + 1];
}

void Person::getThrown(){
  cout << opponent -> keyframe << endl;
  if (hasOpponent == true){
    if (opponent -> keyframe==2 ){
    float* info = getOpponentInfo();
    float size = 25;
    pos[0] = info[0] + info[3];
    pos[1] = info[1] + info[4];
    pos[2] = info[2] + info[5]; 
    positionModifier[0] = size * cosd(BodyAngle);
    positionModifier[1] = size * sind(BodyAngle);
    positionModifier[2] = 0;
    bas =  opponent -> BodyAngle - BodyAngle;
    BodyAngle = opponent -> BodyAngle;
  }
    if (opponent -> keyframe >= 3){
      if (BodyAngle < 270){
        BodyAngle += bas;
      }
    }
  }
}

void Person::sit(){
  SetPositionModifier("Body");
  LeftKneeAngle = 90;
  RightKneeAngle=90;
  LeftHipAngle=-90;
  RightHipAngle=-90;
}

void Person::Update(const double& deltaTime){
  for (int i=1; i<instructions.size(); i++){
    if (totalInstructionTimes[i-1] <= currentAnimationTime && currentAnimationTime < totalInstructionTimes[i]){
      if (currentInstructionStage != i){
        // This condition gets satisfied each time the animation moves onto a new stage. As such we reset to make sure everything is in order and get the new instruction
        reset();
        currentInstructionStage = i;
        keyframe = -1;
        currentInstructionTime = 0;
        totalInstructionTime = instructionTimes[i];
        currentInstruction = instructions[i];
        cout << currentInstruction << endl; 

        if(currentInstruction == "bow"){ speed=2;}
        if(currentInstruction == "judoThrow"){ SetPositionModifier("Left Foot"); speed=0.5;}
        if(currentInstruction == "walk" || currentInstruction == "walkb"){ speed=8; SetPositionModifier("Left Foot"); }
        if(currentInstruction == "getThrown"){ SetPositionModifier("Body");}
        if(directionModifier !=0){direction = direction + directionModifier;directionModifier = 0; }
      }
      if (currentInstruction == "bow"){bow();}
      else if(currentInstruction == "walk"){walk();}
      else if(currentInstruction == "walkb"){walkb();}
      else if(currentInstruction == "turnA"){ turnA();}
      else if(currentInstruction == "turnC"){ turnC();}
      else if(currentInstruction == "judoThrow"){ judoThrow();}
      else if(currentInstruction == "getThrown"){ 
        getThrown();
      }
    }
  }
  currentAnimationTime += speed * deltaTime;
  currentInstructionTime += speed * deltaTime;
  absoluteAnimationTime += deltaTime;

  if (absoluteAnimationTime >40 && loop == true){
    absoluteAnimationTime = 0;
    currentAnimationTime = 0;
    currentInstructionTime =0;
    currentInstructionStage = -1;
    direction=0; 
    pos[2] = -350;
    reset();
  }
}

void Person::SetPositionModifier(string newPositionRef){

  if (currentInstruction != "getThrown"){
    bool refChange = positionRef != newPositionRef;
    if (refChange){
      positionRef = newPositionRef;
      pos[2] += positionModifier[2];
      pos[0] += positionModifier[0];
    }

    // In our model the person is drawn from the center of his body. The position modifier allows us to set the location of the player by a particular body part. It edits the global position modifier at the beginning and the end of the routine.
    if (positionRef == "Left Foot"){
      positionModifier[1]= 100*(LowerLegDim[1]* cosd(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * cosd(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * cosd(BodyAngle)) ;
      positionModifierSizeX= 100*(LowerLegDim[1]* sind(BodyAngle + LeftHipAngle + LeftKneeAngle) +UpperLegDim[1] * sind(BodyAngle + LeftHipAngle) + BodyDim[1]/2 * sind(BodyAngle)) ;
    }
    else if (positionRef == "Right Foot"){
      positionModifier[1] = 100*(LowerLegDim[1]* cosd(BodyAngle + RightHipAngle + RightKneeAngle) +UpperLegDim[1] * cosd(BodyAngle + RightHipAngle) + BodyDim[1]/2*cosd(BodyAngle)) ;
      positionModifierSizeX= 100*(LowerLegDim[1]* sind(BodyAngle + RightHipAngle + RightKneeAngle) +UpperLegDim[1] * sind(BodyAngle + RightHipAngle) + BodyDim[1]/2*sind(BodyAngle)) ;
    }
    else if (positionRef == "Body"){
      positionModifier[0] = positionModifier[1] = positionModifier[2] = 0;
      positionModifierSizeX = 0;
    }
    positionModifier[0] = positionModifierSizeX * sind(directionModifier + direction);
    positionModifier[2] = positionModifierSizeX * cosd(directionModifier +direction);

    if (refChange){
      pos[2] -= positionModifier[2] ;
      pos[0] -= positionModifier[0] ;
    }
  }
}


void Person::setTextures(const std::string& frontText, const std::string& baseText,  const std::string& endText,  const std::string& skinText ){
  hasTexture =true;
  frontTexture = frontText;
  baseTexture = baseText;
  endTexture = endText;
  skinTexture = skinText;
}

// FUNCTIONS TO DISPLAY THE FUNCTION (HIERARCHICAL MODELING)
void Person::Display(){
  glPushMatrix();
  SetPositionModifier();

  // This order is important. The judoka will pivot on the foot that is set as a reference point
  glTranslatef(pos[0], pos[1], pos[2]); // translate to the final position on the screen. This has to be done after all rotations to avoid traveling in a circle
  glTranslatef(positionModifier[0], positionModifier[1], positionModifier[2]); // translate so the foot is on the origin 
  glRotatef(directionModifier + direction, 0,1,0);
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
  if (hasTexture == true){
    glScalef(100,100,100);
    TexturedCuboid(string(frontTexture),string(baseTexture),string(baseTexture),string(baseTexture),string(baseTexture),string(baseTexture));
  }
  else{
  glutSolidCube(100.0f);
  }
}

void Person::DrawRightArm(){
  glRotatef(RightShoulderAngle, 0,0,1);

  glPushMatrix();
  glScalef(UpperArmDim[0],UpperArmDim[1],UpperArmDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,string(baseTexture));
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();

  glTranslatef(0, -100*UpperArmDim[1],0);

  glPushMatrix();
  glRotatef(RightElbowAngle, 0,0,1);
  glScalef(LowerArmDim[0], LowerArmDim[1], LowerArmDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,baseTexture, endTexture, skinTexture);
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();
}

void Person::DrawLeftArm(){
  glRotatef(LeftShoulderAngle, 0,0,1);

  glPushMatrix();
  glScalef(UpperArmDim[0],UpperArmDim[1],UpperArmDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,string(baseTexture));
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();


  glTranslatef(0, -100*UpperArmDim[1],0);
  glRotatef(-LeftShoulderAngle, 0,0,1);

  glPushMatrix();
  glScalef(LowerArmDim[0], LowerArmDim[1], LowerArmDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,baseTexture, endTexture, skinTexture);
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();
}

void Person::DrawRightLeg(){
  glRotatef(RightHipAngle,1,0,0);
  glPushMatrix();
  glScalef(UpperLegDim[0],UpperLegDim[1],UpperLegDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,string(baseTexture));
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();

  glTranslatef(0, -100*UpperLegDim[1],0);

  glPushMatrix();
  glRotatef(RightKneeAngle,1,0,0);
  glScalef(LowerLegDim[0],LowerLegDim[1],LowerLegDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,baseTexture, endTexture, skinTexture);
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();
}

void Person::DrawLeftLeg(){
  glRotatef(LeftHipAngle,1,0,0);
  glPushMatrix();
  glScalef(UpperLegDim[0],UpperLegDim[1],UpperLegDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,string(baseTexture));
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();

  glTranslatef(0, -100*UpperLegDim[1],0);

  glPushMatrix();
  glRotatef(LeftKneeAngle,1,0,0);
  glScalef(LowerLegDim[0],LowerLegDim[1],LowerLegDim[2]);
  glRotatef(90,1,0,0);
  if (hasTexture){
    Cylinder(50,100,baseTexture, endTexture, skinTexture);
  }
  else{
    Cylinder(50,100);
  }
  glPopMatrix();
}

void Person::DrawHead(){
  glScalef(HeadDim[0],HeadDim[1],HeadDim[2]);
  glTranslatef(0, 100, 0);
  glutSolidSphere(100.0f, 10,10);

}

double Person::sind(double angle){
  double angleradians = angle * M_PI / 180.0f;
  return sin(angleradians);
}

double Person::cosd(double angle){
  double angleradians = angle * M_PI / 180.0f;
  return cos(angleradians);
}

void Person::SetPositionModifier(){
  SetPositionModifier(string(positionRef));
}
