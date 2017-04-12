#pragma once

#include "../Framework/Interface/DisplayableObject.h"

class Table :
	public DisplayableObject
{
public:
	Table(){};
	~Table(){};

	void Display();
	void DrawTop();
	void DrawLeg();
private:
};