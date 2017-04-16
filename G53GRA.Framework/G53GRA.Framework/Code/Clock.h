#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include "../Framework/Interface/Input.h"
#include <math.h>

class Clock :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Clock(){};
	~Clock(){};

	void Display();
	void Update(const double& deltaTime);

private:
	string[2] player1; // player country
	string[2] player2; // player country
	int player1Score[4]; // ippon, wazari, yuko, shido 
	int player22core[4]; // ippon, wazari, yuko, shido 


};