#include "Stadium.h"

void Stadium::Display()
{
  glPushMatrix();
  glPushAttrib(GL_ALL_ATTRIB_BITS);
  glDisable(GL_COLOR_MATERIAL);
  glTranslatef(pos[0], pos[1], pos[2]);

  glPushMatrix();
  DrawMat();
  glPopMatrix();

  glScalef(scale[0], scale[1], scale[2]);

  for(int r=0; r<360; r+=90){
    glPushMatrix();
      glRotatef(r, 0,1,0);
      //if (r==0){
      //  glTranslatef(0,0.01,-1);
      //}
      glTranslatef(0, 0, -(compSize+boundarySize+ 5)/2);
    
      glPushMatrix();
        glTranslatef(0,.75,0);
        DrawSeating();
      glPopMatrix();
    
      glTranslatef(0,0,.5);
      glScalef(0.75, 0.748, 0.75);
      glTranslatef(4, 0, 0);
      DrawAdvertisementStrip();
    
      glPushMatrix();
        glScalef(2,1,1);
        glTranslatef(1,0,0);
        DrawSponsorAdvertisement("../Textures/white.bmp");
      glPopMatrix();
    
      glTranslatef(-4, 0, 0);
      DrawAdvertisementStrip();
      glTranslatef(-4, 0, 0);
      DrawAdvertisementStrip();
      glTranslatef(-2, 0, 0);
    
      glPushMatrix();
        glScalef(2,1,1);
        glTranslatef(-1,0,0);
        DrawSponsorAdvertisement("../Textures/white.bmp");
      glPopMatrix();
    
    glPopMatrix();
  }


  glPushMatrix();
  DrawRoof();
  glPopMatrix();

  glEnable(GL_COLOR_MATERIAL);
  glPopAttrib();
  glPopMatrix();

}

void Stadium::DrawRoof(){
  glDisable(GL_BLEND);
  glBegin(GL_QUADS);
  glMaterialfv(GL_FRONT, GL_SPECULAR, static_cast<GLfloat*>(specular));
  glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(wDiffuse));

  float h1=4.25;
  float h2=8;

  float length = compSize + boundarySize+2.5;
  glNormal3f(0.0f, 1.0f, 0.0f);
  glVertex3f(length, h2, length);
  glVertex3f(-length, h2, length);
  glVertex3f(-length, h2, -length);
  glVertex3f(length, h2, -length);

  glNormal3f(1.0f, 0.0f, 0.0f);
  glVertex3f(length, h2, -length);
  glVertex3f(-length, h2, -length);
  glVertex3f(-length, h1, -length);
  glVertex3f(length, h1, -length);

  glNormal3f(1.0f, 0.0f, 0.0f);
  glVertex3f(length, h2, length);
  glVertex3f(length, h1, length);
  glVertex3f(-length, h1, length);
  glVertex3f(-length, h2, length);

  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(-length, h2, length);
  glVertex3f(-length, h1, length);
  glVertex3f(-length, h1, -length);
  glVertex3f(-length, h2, -length);

  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(length, h2, length);
  glVertex3f(length, h2, -length);
  glVertex3f(length, h1, -length);
  glVertex3f(length, h1, length);

  glEnd();
}

void Stadium::DrawMat(){
  float p = 20;
  float sf = scale[0]/p;
  glScalef(sf,sf,sf);
  float inner = (compSize+1) * p / 2;
  float outer = (compSize + boundarySize + 1) * p / 2;
  float entire = (compSize + boundarySize + 5) * p / 2;
  glBegin(GL_QUADS);
  glMaterialfv(GL_FRONT, GL_SPECULAR, static_cast<GLfloat*>(specular));
  glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));

  
  for (int i = 0; i<=entire; i++){
    for (int j = 0; j<=entire; j++){
      if (abs(i) > outer or abs(j) > outer){ glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(wDiffuse));}
      else if (abs(i) > inner or abs(j) > inner){ glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(rDiffuse)); }
      else {glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(yDiffuse));}
      glNormal3f(0.0f, 1.0f, 0.0f);

      glVertex3f(i+1, 0, j+1);
      glVertex3f(i+1, 0, j);
      glVertex3f(i, 0, j);
      glVertex3f(i, 0, j+1);

      glVertex3f(-(i+1), 0, j+1);
      glVertex3f(-i, 0, j+1);
      glVertex3f(-i, 0, j);
      glVertex3f(-(i+1), 0, j);

      glVertex3f(i+1, 0, -(j+1));
      glVertex3f(i, 0, -(j+1));
      glVertex3f(i, 0, -j);
      glVertex3f(i+1, 0, -j);

      glVertex3f(-(i+1), 0, -(j+1));
      glVertex3f(-(i+1), 0, -j);
      glVertex3f(-i, 0, -j);
      glVertex3f(-i, 0, -(j+1));
    }
  }
  glEnd();

}


void Stadium::DrawSeating(){
  glDisable(GL_BLEND);
  glScalef(0.5,0.5,0.5);
  glBegin(GL_QUADS);
  glMaterialfv(GL_FRONT, GL_SPECULAR, static_cast<GLfloat*>(specular));
  glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(gDiffuse));

  int length;

  for (int i=0; i<seatingRows; i++){
    glNormal3f(0.0f, 1.0f, 0.0f);
    length = compSize + boundarySize + i + 6;
    glVertex3f(-length, i, -i+1);
    glVertex3f(length, i, -i+1);
    glVertex3f(length, i, -i);
    glVertex3f(-length, i, -i);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-length, i+1, -i);
    glVertex3f(-length, i, -i);
    glVertex3f(length, i, -i);
    glVertex3f(length, i+1, -i);

  }

  glEnd();
}

void Stadium::DrawPlainAdvertisement(){

  glDisable(GL_BLEND);
  glBegin(GL_QUADS);
  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0, 1, 0);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(1, 1, 0);
  glEnd();
}

void Stadium::DrawSponsorAdvertisement(string filename){

  glDisable(GL_BLEND);
  GLint texID = Scene::GetTexture(string(filename));
  glPushMatrix();
  glPushAttrib(GL_ALL_ATTRIB_BITS);

  // Enable Texturing
  glEnable(GL_TEXTURE_2D);
  glDisable(GL_ALPHA_TEST);

  // Enable setting the colour of the material the cube is made from
  // as well as the material for blending.
  glEnable(GL_COLOR_MATERIAL);

  // Tell openGL which texture buffer to use
  glBindTexture(GL_TEXTURE_2D, texID);

  glBegin(GL_QUADS);

  // draw the front face
  // set the normal of the front face
  glNormal3f(0.0f, 0.0f, 1.0f);

  // define texture coordinates for the 4 vertices
  glTexCoord2f(0, 1);
  glVertex3f(0, 1, 0);
  glTexCoord2f(0, 0);
  glVertex3f(0, 0, 0);
  glTexCoord2f(1, 0);
  glVertex3f(1, 0, 0);
  glTexCoord2f(1, 1);
  glVertex3f(1, 1, 0);

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
  glEnable(GL_BLEND);
}

void Stadium::DrawAdvertisementStrip(){
  glPushMatrix();
  glTranslatef(1,0,0);
  DrawSponsorAdvertisement("../Textures/IJFLogo.bmp");
  glScalef(3,1,1);
  glTranslatef(-1,0,0);
  DrawSponsorAdvertisement("../Textures/UONLogo2Border.bmp");
  glPopMatrix();
}
