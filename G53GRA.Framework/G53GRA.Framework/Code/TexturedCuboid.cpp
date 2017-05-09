#pragma once
#include "TexturedCuboid.h"
#include <string>

TexturedCuboid::TexturedCuboid(const std::string& filename){
	TexturedCuboid(filename, filename, filename, filename, filename, filename);
}

TexturedCuboid::TexturedCuboid(const std::string& front, const std::string& left,const std::string& back,const std::string& right,const std::string& top,const std::string& bottom) 
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	// Enable Texturing
	glEnable(GL_TEXTURE_2D);

	// Enable setting the colour of the material the cube is made from
	// as well as the material for blending.
	glEnable(GL_COLOR_MATERIAL);

	// Tell openGL which texture buffer to use
	texIDFront = Scene::GetTexture(front);
	texIDBack = Scene::GetTexture(back);
	texIDLeft = Scene::GetTexture(left);
	texIDRight = Scene::GetTexture(right);
	texIDTop = Scene::GetTexture(top);
	texIDBottom = Scene::GetTexture(bottom);

	glBindTexture(GL_TEXTURE_2D, texIDFront);
	// draw the front face
	glBegin(GL_QUADS);
	// set the normal of the front face
	glNormal3f(0.0f, 0.0f, 1.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glEnd();


	// draw the back face
	glBindTexture(GL_TEXTURE_2D, texIDBack);
	glBegin(GL_QUADS);
	// set the normal of the front face
	glNormal3f(0.0f, 0.0f, -1.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	// draw the left face
	glBindTexture(GL_TEXTURE_2D, texIDLeft);
	glBegin(GL_QUADS);
	// set the normal of the front face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();

	// draw the right face
	glBindTexture(GL_TEXTURE_2D, texIDRight);
	glBegin(GL_QUADS);
	// set the normal of the front face
	glNormal3f(1.0f, 0.0f, 0.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();

	// draw the top face
	glBindTexture(GL_TEXTURE_2D, texIDTop);
	glBegin(GL_QUADS);
	// set the normal of the front face
	glNormal3f(0.0f, 1.0f, 0.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();

	// draw the bottom face
	glBindTexture(GL_TEXTURE_2D, texIDBottom);
	glBegin(GL_QUADS);
	// set the normal of the front face
	glNormal3f(0.0f, -1.0f, 0.0f);
	// define texture coordinates for the 4 vertices
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();


	// Stop blending textures and colours
	glDisable(GL_COLOR_MATERIAL);
	// Bind to the blank buffer to stop ourselves accidentaly
	// using the wrong texture in the next draw call
	glBindTexture(GL_TEXTURE_2D, NULL);
	// Stop performing texturing
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopMatrix();
}
