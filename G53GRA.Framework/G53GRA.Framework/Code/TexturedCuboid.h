#pragma once
#include "../Framework/Engine/Scene.h"

class TexturedCuboid{
public:
	TexturedCuboid(){};
	~TexturedCuboid(){};
	TexturedCuboid(const std::string& filename);
    TexturedCuboid(const std::string& front, const std::string& left,const std::string& back,const std::string& right,const std::string& top,const std::string& bottom); 
private:
	GLint texIDFront;
	GLint texIDBack;
	GLint texIDLeft;
	GLint texIDRight;
	GLint texIDTop;
	GLint texIDBottom;


};

