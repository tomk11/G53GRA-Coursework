#pragma once
#include "../Framework/Engine/Scene.h"

class Cylinder
{
public:
	Cylinder(){};
	Cylinder(double radius, double height);
    Cylinder(double radius, double height, const std::string& texture);
    Cylinder(double radius, double height, const std::string& textureTop, const std::string& textureMid, const std::string& textureBot );
	~Cylinder(){};
private:
	GLint texIDTop;
	GLint texIDMid;
	GLint texIDBot;
};