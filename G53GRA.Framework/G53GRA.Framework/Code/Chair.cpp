#include "Chair.h"

Chair::Chair(string filename)
{
	texid = Scene::GetTexture(filename);
}


void Chair::Display()
{

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
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
	        glBindTexture(GL_TEXTURE_2D, texid);
	        DrawBack();
            glBindTexture(GL_TEXTURE_2D, 0);
	    glPopMatrix();
	
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void Chair::DrawBack(){
	glScalef(SeatSize/100,SeatSize/100, Thickness/100);
	glutSolidCube(100);
}

void Chair::DrawSeat(){
	glScalef(SeatSize,Thickness,SeatSize);
	glutSolidCube(1);
}

void Chair::DrawLeg(){
	glScalef(Thickness,LegHeight,Thickness);
	glutSolidCube(1);
}