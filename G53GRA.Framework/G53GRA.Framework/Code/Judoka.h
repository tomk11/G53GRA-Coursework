#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include <math.h>

class Judoka :
	public DisplayableObject,
	public Animation
{
public:
	Judoka(){};
	~Judoka(){};

	void Display();
	void Update(const double& deltaTime);
	void DrawBody();
	void DrawHead();
	void DrawLeftLeg();
	void DrawRightLeg();
	void DrawLeftArm();
	void DrawRightArm();
    void SetPositionModifier();
    void walk();
    double sind(double angle);
    double cosd(double angle);

private:
	float RightKneeAngle = 0;
	float LeftKneeAngle = 0;
	float RightHipAngle = 0;
	float LeftHipAngle = 0;
	float RightElbowAngle = 0;
	float LeftElbowAngle = 0;
	float RightShoulderAngle = -45;
	float LeftShoulderAngle = 45;

	float direction = 90;

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
	string positionRef = "Left Foot";
};