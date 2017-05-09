#pragma once

#include "../Framework/Interface/DisplayableObject.h"

class Chair :
	public DisplayableObject
{
public:
	Chair(){};
	~Chair(){};

	void Display();
	void Update(const double& deltaTime);
	void DrawLeg();
	void DrawSeat();
	void DrawBack();
private:
	float LegHeight = 50;
	float Thickness = 7;
	float SeatSize =60;
	float LegPositionH = (SeatSize - Thickness)/2;
	float LegPositionV = (LegHeight + Thickness)/2;
	
};