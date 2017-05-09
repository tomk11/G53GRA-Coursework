#pragma once

#include "../Framework/Engine/Scene.cpp"
#include "Stadium.cpp"
#include "Table.cpp"
#include "Light.cpp"
#include "SpotLight.cpp"
#include "Chair.cpp"
#include "VideoCamera.cpp"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};

private:
	void Initialise();
	void Projection();

};