#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include "../Framework/Interface/Input.h"
using namespace std;

class Person :
	public DisplayableObject, 
	public Animation,
	public Input
{
public:
	Person();
	~Person(){};
    void Update(const double& deltaTime);

    // Display functions. These are used for hierachical modelling.
	void Display();
	void DrawBody();
	void DrawHead();
	void DrawLeftLeg();
	void DrawRightLeg();
	void DrawLeftArm();
	void DrawRightArm();
    void reset();

	// Position functions 
    void SetPositionModifier(string newPositionRef);
    void SetPositionModifier();

    // This is the control function.
    void addInstruction(string instruction, float duration);

    // Animation functions
    void bow();
    void walk();
    void walkb();
    void turnA();
    void turnC();
    void wait();
    void judoThrow();
    void getThrown();
    
    // Functions that allow our objects to talk to one another
    void setOpponent(Person* p);
    float* getOpponentInfo();
    float* getInfo();

    // Helper Functions
    double sind(double angle);
    double cosd(double angle);

	//Variables used for animation
    // INSTRUCTION refers to a variable that tracks just a single segment of the animation and ANIMATION refers to variables that track the whole sequence.
    // Also CURRENT refers to variables that track the current state while TOTAL refers to the time at the end of this sequence
    vector<string> instructions;
    vector<float> instructionTimes; 
    vector<float> totalInstructionTimes; 

    float currentAnimationTime = 0, currentInstructionTime = 0, totalAnimationTime = 0, totalInstructionTime = 0, absoluteAnimationTime;
    int currentInstructionStage = 0, keyframe=0;
    string currentInstruction;
	float bowTime = 2, walkTime = 4, speed=1, interp=0;


private:
	float BodyAngle =0;
	float RightKneeAngle = 0, LeftKneeAngle = 0;
	float RightHipAngle = 0, LeftHipAngle = 0;
	float RightElbowAngle = 0, LeftElbowAngle = 0;
	float RightShoulderAngle = 0, LeftShoulderAngle = 0;

	Person* opponent;
	bool hasOpponent;

	// Keyframes for Throw
	const static int tFrames = 9;
	int throwRightHipFrames[tFrames] =  {0, -30, -30, -60,   0,   0,   0,   0,   0};
	int throwRightKneeFrames[tFrames] = {0,   0,  50,   0,   0,   0,   0,   0,   0};
	int throwLeftHipFrames[tFrames] =   {0,  20, -30, -60,   0,   0,   0,   0,   0};
	int throwLeftKneeFrames[tFrames] =  {0,  20,  50,   0,   0,   0,   0,   0,   0};
	int throwBodyFrames[tFrames] =      {0,   0,   0,  50,   0,   0,   0,   0,   0};
	int throwDirectionFrames[tFrames] = {0,  15, 180, 180, 180, 360, 360, 360, 360};

	// Keyframes for walking
	int WalkRightHipAngleFrames[9] = {0, -10, -25, -10, 0, 10, 15, 10,0};
	int WalkRightKneeAngleFrames[9] = {0, 10, 20, 0, 0, 10, 8, 5,0};
	int WalkLeftHipAngleFrames[9] = {0, 10, 15, 10, 0, -10, -25, -10,0};
	int WalkLeftKneeAngleFrames[9] = {0, 10, 8, 5, 0, 10, 20, 0, 0};

	int WalkBRightHipAngleFrames[9] = {0, 10, 15, 10, 0, -10, -25, -10, 0};
	int WalkBRightKneeAngleFrames[9] = {0, 5, 8, 10, 0, 0, 20, 10, 0};
	int WalkBLeftHipAngleFrames[9] = {0, -10, -25, -10, 0, 10, 15, 10, 0};
	int WalkBLeftKneeAngleFrames[9] = {0, 0, 20, 10, 0, 5, 8, 10, 0};

	//Keyframes for turning
	int turnAKF[3] ={0,90,0};
	int turnCKF[3] ={0,-90,0};

	//Keyframes for bowing
	int BowBodyAngleFrames[4] = {0, 60,0, 60};
	int BowRightHipAngleFrames[4] = {0,-70,0, -70};
	int BowLeftHipAngleFrames[4] = {0,-70,0, -70};


	// These parts define the relative dimensions of the player's body parts. They stat constant.
	float BodyDim[3] = {.3f, .55f, .2f};
	float LowerArmDim[3] = {.1f, .25f, .1f}, UpperArmDim[3] = {.13f, .25f, .13f};
	float LowerLegDim[3] = {.12f, .45f, .12f}, UpperLegDim[3] = {.16f, .4f, .16f};
	float HeadDim[3] = {.15, .15, .15}, NeckDim[3] = {.08, .08, .08};

	// This modifier is important. It is the key parameter that decides what position we are drawing from (i.e. when we call j -> setPosition()) what part of the body we are setting the position from
	float positionModifier[3] = {0,0,0};
	float positionModifierSizeX;
	string positionRef = "Left Foot";
	float direction = 0, directionModifier =0;
};