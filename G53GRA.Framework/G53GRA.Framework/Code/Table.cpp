#include "Table.h"
#include "TexturedCuboid.cpp"

Table::Table(){
	texture = "../Textures/wood.bmp";
}

void Table::Display()
{
	glPushMatrix();
	    
	    glPushAttrib(GL_ALL_ATTRIB_BITS);
        glTranslatef(pos[0], pos[1] + LegHeight, pos[2]);
	    glScalef(scale[0], scale[0], scale[0]);
	    
	    glPushMatrix();
	        DrawTop();
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(-LegPositionL,-LegPositionV, -LegPositionW);
	        DrawLeg();
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(LegPositionL,-LegPositionV, -LegPositionW);
	        DrawLeg();
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(-LegPositionL,-LegPositionV, LegPositionW);
	        DrawLeg();
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(LegPositionL,-LegPositionV, LegPositionW);
	        DrawLeg();
	    glPopMatrix();

	    glPopAttrib();

	glPopMatrix();
}

void Table::DrawTop(){
	glScalef(TopLength,Thickness,TopWidth);
    TexturedCuboid(string(texture));
}

void Table::DrawLeg(){
	glScalef(Thickness, LegHeight, Thickness);
    TexturedCuboid(string(texture));
}