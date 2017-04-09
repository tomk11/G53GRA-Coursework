#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include "../Framework/Interface/Input.h"

class Table :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Table();
	~Table(){};

	void Display();
	void Update(const double& deltaTime);
	void DrawTop();
	void DrawLeg();

	void HandleSpecialKey(int key, int state, int x, int y){}
	void HandleMouse(int button, int state, int x, int y){}
	void HandleMouseDrag(int x, int y){}
	void HandleMouseMove(int x, int y){}

private:
	float xrot, yrot, zrot;
	float scale;
};