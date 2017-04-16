#include "Chair.h"

Chair::Chair(GLuint _texid)
{
    texid = _texid;             // Store the texture binding ID
}


void Chair::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texid);
	// Draw the object with texture between these calls
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void Chair::Display()
{

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texid);
	// Draw the object with texture between these calls

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
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}
void Chair::DrawBack(){
	glScalef(SeatSize,SeatSize, Thickness);
	glutSolidCube(1);
}

void Chair::DrawSeat(){
	glScalef(SeatSize,Thickness,SeatSize);
	glutSolidCube(1);
}

void Chair::DrawLeg(){
	glScalef(Thickness,LegHeight,Thickness);
	glutSolidCube(1);
}