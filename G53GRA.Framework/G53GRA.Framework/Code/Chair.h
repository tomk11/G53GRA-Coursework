#pragma once

#include "../Framework/Interface/DisplayableObject.h"

class Chair :
	public DisplayableObject
{
public:
	Chair(){};
	~Chair(){};
	Chair(GLuint _texid);    // Constructor with texture information

	void Display();
	void Draw();
	void Update(const double& deltaTime);
	void DrawLeg();
	void DrawSeat();
	void DrawBack();



private:
	float LegHeight = 60;
	float Thickness = 8;
	float SeatSize =80;
	float LegPositionH = (SeatSize - Thickness)/2;
	float LegPositionV = (LegHeight + Thickness)/2;
	
	bool toTexture = false;     // Flag to check if texture loaded correctly
	GLuint texid;               // Store a copy of the loaded texture binding id

};