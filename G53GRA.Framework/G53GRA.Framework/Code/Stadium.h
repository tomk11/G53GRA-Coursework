#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include <cmath>

class Stadium :
	public DisplayableObject
{
public:
	Stadium(){};
	~Stadium(){};

	void Display();
	void DrawMat();
	void DrawSeating();
private:
	float yDiffuse[4] = {1.0f,1.0f,0.0f,0.7f};
	float rDiffuse[4] = {1.0f,0.0f,0.0f,0.7f};
	float specular[4] = {1.0f,1.0f,1.0f,1.0f};
	float shininess = 128.0f;
	float compSize = 6;
	float boundarySize = 2;
	float seatingRows = 10;
};