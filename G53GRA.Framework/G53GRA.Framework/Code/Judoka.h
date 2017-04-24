#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include "../Framework/Interface/Input.h"
#include <math.h>

class Judoka :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Judoka();
	Judoka(string id);
	~Judoka(){};

	void Display();
    void Update(const double& deltaTime);
	void DrawBody();
	void DrawHead();
	void DrawLeftLeg();
	void DrawRightLeg();
	void DrawLeftArm();
	void DrawRightArm();
    void SetPositionModifier(string newPositionRef);
    void SetPositionModifier();

    // These functions set the body position of the judoka
    void reset();
    void ippon();
    void bow();
    void walk();
    void walkFrame(int i);

    double sind(double angle);
    double cosd(double angle);
    
    void HandleKey(unsigned char key, int state, int mX, int mY);

private:
	float BodyAngle =0;
	float RightKneeAngle = 0;
	float LeftKneeAngle = 0;
	float RightHipAngle = 0;
	float LeftHipAngle = 0;
	float RightElbowAngle = 0;
	float LeftElbowAngle = 0;
	float RightShoulderAngle = 0;
	float LeftShoulderAngle = 0;

	// Keyframes for walking
	int WalkRightHipAngleFrames[9] = {0, -10, -25, -10, 0, 10, 15, 10,0};
	int WalkRightKneeAngleFrames[9] = {0, 10, 20, 0, 0, 10, 8, 5,0};
	int WalkLeftHipAngleFrames[9] = {0, 10, 15, 10, 0, -10, -25, -10,0};
	int WalkLeftKneeAngleFrames[9] = {0, 10, 8, 5, 0, 10, 20, 0,0};

	//Keyframes for bowing
	int BowBodyAngleFrames[3] = {0, 60,0};
	int BowRightHipAngleFrames[3] = {0,-70,0};
	int BowLeftHipAngleFrames[3] = {0,-70,0};

	float direction = 0;

	//Variables used for animation
	int keyframe;
	int stage = -1;
	float animateTime = 0;
	float totalAnimateTime = 0;
	float interp;
	float speed = 6;
	int bowTime = 2;
	int walkTime = 4;

	// These parts define the relative dimentions of the player's body parts. They stat constant.
	float BodyDim[3] = {.3f, .55f, .2f};
	float LowerArmDim[3] = {.1f, .25f, .1f};
	float UpperArmDim[3] = {.13f, .25f, .13f};
	float LowerLegDim[3] = {.12f, .45f, .12f};
	float UpperLegDim[3] = {.16f, .4f, .16f};
	float HeadDim[3] = {.15, .15, .15};
	float NeckDim[3] = {.08, .08, .08};

	// This modifier is important. It is the key parameter that decides what position we are drawing from (i.e. when we call j -> setPosition()) what part of the body we are setting the position from
	float positionModifier[3] = {0,0,0};
	float positionModifierSize;
	string positionRef = "Left Foot";

	string ID;
};