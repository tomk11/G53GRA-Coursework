#include "Chair.h"
#include "TexturedCuboid.cpp"

void Chair::Display()
{
	glPushMatrix();
        glTranslatef(pos[0], pos[1] + LegHeight, pos[2]);
	    glScalef(scale[0], scale[0], scale[0]);

	    glPushMatrix();
	        DrawSeat();	
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(-LegPositionH,-LegPositionV, -LegPositionH);
	        DrawLeg();
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(LegPositionH,-LegPositionV, -LegPositionH);
	        DrawLeg();
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(-LegPositionH,-LegPositionV, LegPositionH);
	        DrawLeg();
	    glPopMatrix();
	    glPushMatrix();
	        glTranslatef(LegPositionH,-LegPositionV, LegPositionH);
	        DrawLeg();
	    glPopMatrix();

	    glPushMatrix();
	        glTranslatef(0,SeatSize/2, -LegPositionH);
	        DrawBack();
	    glPopMatrix();
	glPopMatrix();
	
}
void Chair::DrawBack(){
	glScalef(SeatSize,SeatSize, Thickness);
	TexturedCuboid("../Textures/wood.bmp");
}

void Chair::DrawSeat(){
	glScalef(SeatSize,Thickness,SeatSize);
	TexturedCuboid("../Textures/wood.bmp");
}

void Chair::DrawLeg(){
	glScalef(Thickness,LegHeight,Thickness);
	TexturedCuboid("../Textures/wood.bmp");
}