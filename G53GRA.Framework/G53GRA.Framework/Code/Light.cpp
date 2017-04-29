#include "Light.h"

Light::Light(unsigned int GL_LIGHT)
{
  static GLfloat ambient[] = { 0.15f, 0.15f, 0.1f, 1.0f };
  static GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  static GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  static GLfloat ambientOn[] = {ambient[0], ambient[1], ambient[2]};
  static GLfloat diffuseOn[] = {diffuse[0], diffuse[1], diffuse[2]};
  static GLfloat specularOn[] = {specular[1], specular[2], specular[3]};

  _GL_LIGHT = GL_LIGHT;
  _ambient = ambient;
  _diffuse = diffuse;
  _specular = specular;
  _ambientOn = ambientOn;
  _diffuseOn = diffuseOn;
  _specularOn = specularOn;
}


Light::~Light()
{
}

void Light::Display()
{
  // Basic code to draw the position and direction of the light.
  // This is not suitable for a directional light source, as a 
  // directional light has no position.

  // Disable lighting on this geometry (since it is the source
  // of the light) so it will only be coloured by glColor call
  glDisable(GL_LIGHTING);
  
  glPushMatrix();
  glPushAttrib(GL_ALL_ATTRIB_BITS);
    // Match colour of sphere to diffuse colour of light
    glColor4fv(_diffuse);
    glTranslatef(pos[0], pos[1], pos[2]);
    glutSolidSphere(10.0, 10, 10);
  glPopAttrib();
  glPopMatrix();

  // Re-enable lighting once the light source has been drawn
  glEnable(GL_LIGHTING);

  glLightfv(_GL_LIGHT, GL_AMBIENT, _ambient);
  glLightfv(_GL_LIGHT, GL_DIFFUSE, _diffuse);
  glLightfv(_GL_LIGHT, GL_SPECULAR, _specular);
  
  glLightf(_GL_LIGHT, GL_LINEAR_ATTENUATION, 0.000001f);
  glLightf(_GL_LIGHT, GL_QUADRATIC_ATTENUATION, 0.0000025f);

  GLfloat lPosition[4] = {pos[0], pos[1], pos[2], 1};
  glLightfv(_GL_LIGHT, GL_POSITION, lPosition);

  // enable GL_LIGHT0 with these defined properties
  glEnable(_GL_LIGHT); 
}

void Light::HandleKey(unsigned char key, int state, int mX, int mY){
  if (state == 1 && key == 'n'){
    on = !on;
  }
}

void Light::Update(const double& deltaTime){
    if (on == true){
      if (_diffuse[0] < _diffuseOn[0]){
      _diffuse[0] += deltaTime * _diffuseOn[0];
      _diffuse[1] += deltaTime * _diffuseOn[1];
      _diffuse[2] += deltaTime * _diffuseOn[2];
      _ambient[0] += deltaTime * _ambientOn[0];
      _ambient[1] += deltaTime * _ambientOn[1];
      _ambient[2] += deltaTime * _ambientOn[2];
      _specular[0] += deltaTime * _specularOn[0];
      _specular[1] += deltaTime * _specularOn[1];
      _specular[2] += deltaTime * _specularOn[2];
      }
    }else{
      if (_diffuse[0] > 0){
      _diffuse[0] -= deltaTime * _diffuseOn[0];
      _diffuse[1] -= deltaTime * _diffuseOn[1];
      _diffuse[2] -= deltaTime * _diffuseOn[2];
      _ambient[0] -= deltaTime * _ambientOn[0];
      _ambient[1] -= deltaTime * _ambientOn[1];
      _ambient[2] -= deltaTime * _ambientOn[2];
      _specular[0] -= deltaTime * _specularOn[0];
      _specular[1] -= deltaTime * _specularOn[1];
      _specular[2] -= deltaTime * _specularOn[2];
    }
  }
}
