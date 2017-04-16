#pragma once

class TexturedCuboid{
public:
	TexturedCuboid(){};
	~TexturedCuboid(){};
	TexturedCuboid(const std::string& filename);
private:
	GLint texID;


};

