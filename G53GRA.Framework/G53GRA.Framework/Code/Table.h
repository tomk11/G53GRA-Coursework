#pragma once

#include "../Framework/Interface/DisplayableObject.h"

class Table :
	public DisplayableObject
{
public:
	Table();
	~Table(){};

	void Display();
	void DrawTop();
	void DrawLeg();
private:
	float LegHeight = 90;
	float Thickness = 8;
	float TopLength=260;
	float TopWidth=100;
	float LegPositionL = (TopLength - Thickness)/2;
	float LegPositionW = (TopWidth - Thickness)/2;
	float LegPositionV = (LegHeight + Thickness)/2;

	string texture;
};