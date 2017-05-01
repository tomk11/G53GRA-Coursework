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
	void DrawRoof();
	void DrawSponsorAdvertisement(string filename);
    void DrawPlainAdvertisement();
    void DrawAdvertisementStrip();

private:
	float yDiffuse[4] = {1.0f,1.0f,0.0f,0.7f};
	float rDiffuse[4] = {1.0f,0.0f,0.0f,0.7f};
	float gDiffuse[4] = {0.8f, 0.f, 0.f,0.7f};
	float wDiffuse[4] = {0.5f, 0.5f, 0.5f,0.7f};
	float specular[4] = {1.0f,1.0f,1.0f,1.0f};
	float shininess = 128.0f;
	float compSize = 5;
	float boundarySize = 2;
	float seatingRows = 7;
};