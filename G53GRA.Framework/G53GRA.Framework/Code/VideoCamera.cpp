#include "VideoCamera.h"
#include "Cylinder.cpp"

VideoCamera::VideoCamera(){}

void VideoCamera::Display(){
  glPushMatrix();
  // move to the correct position, rotate, and scale to size
  glTranslatef(pos[0], pos[1] + 100 * cos(tripodAngle * 3.1415/180), pos[2]); 
  glScalef(scale[0], scale[0], scale[0]);
  glRotatef(rotation[1], 0.0f, 1.0f, 0.0f); 
  glRotatef(rotation[2], 0.0f, 0.0f, 1.0f);
  glRotatef(rotation[0], 1.0f, 0.0f, 0.0f);

  // Draw the camera
  glPushMatrix();
  glTranslatef(0,20,0);
  glPushMatrix();
  DrawBody();
  glPopMatrix();
  glPushMatrix();
  DrawLense();
  glPopMatrix();
  glPopMatrix();

  // Draw the tripod
  glPushMatrix();
  DrawLeg();
  glPopMatrix();
  glPushMatrix();
  glRotatef(120,0,1,0);
  DrawLeg();
  glPopMatrix();
  glPushMatrix();
  glRotatef(240,0,1,0);
  DrawLeg();
  glPopMatrix();
  glPopMatrix();
}

void VideoCamera::DrawLeg(){	
  glRotatef(tripodAngle,0,0,1);
  glRotatef(90,1,0,0);
  GLUquadricObj *p = gluNewQuadric();
  gluCylinder(p,7,7,100,5,5);    
}

void VideoCamera::DrawBody(){
  glScalef(40,40,20);
  glutSolidCube(1);
}

void VideoCamera::DrawLense(){
  glTranslatef(0,0,10);
  Cylinder(15,20);
}
