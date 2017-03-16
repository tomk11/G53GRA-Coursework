#pragma once
#include "../Framework/Interface/DisplayableObject.h"
#include <cmath>

class Floor :
	public DisplayableObject
{
public:
	Floor(){};
	~Floor(){};

	void Display();

private:
	int texId;
};

