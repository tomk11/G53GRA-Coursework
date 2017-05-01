#pragma once
#include "../Framework/Interface/DisplayableObject.h"


class VideoCamera :
	public DisplayableObject
{
public:
	VideoCamera();
	~VideoCamera(){};

	void Display();
	void DrawLeg();
	void DrawBody();
	void DrawLense();
	void DrawArm();
	float tripodAngle=30;
};