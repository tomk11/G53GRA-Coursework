#include "SpotLight.h"

SpotLight::SpotLight(GLfloat d[], unsigned int GL_LIGHT){
  // Set ambient colour of the light (off-grey)
  static GLfloat ambient[] = { 0.15f, 0.15f, 0.1f, 1.0f };
  // Set diffuse colour of the light (red)
  // Set specular colour (white)
  static GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

  _GL_LIGHT = GL_LIGHT;
  _ambient = ambient;
  _diffuse = d;
  _specular = specular;
}


SpotLight::~SpotLight(){
}

void SpotLight::setFocus(Person *p){
  focus = p;
}

void SpotLight::calibrate(){}

void SpotLight::Update(const double& deltaTime){
  //spot_direction[0] += deltaTime/10;
  cout << focus -> getInfo()[0] + focus -> getInfo()[3] << endl;
  float x = pos[0] - focus -> getInfo()[0] - focus -> getInfo()[3];
  float y = pos[1] +100;
  float z = pos[2] - focus -> getInfo()[2] - focus -> getInfo()[5];
  spot_direction[0] = -x/y; 
  spot_direction[2] = -z/y; 
}

void SpotLight::Display(){
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
  
  glLightf(_GL_LIGHT, GL_SPOT_CUTOFF, 9.0);
  glLightfv(_GL_LIGHT, GL_SPOT_DIRECTION, spot_direction);
  glLightfv(_GL_LIGHT, GL_SPOT_EXPONENT, spot_exponent);
  
  
  glLightf(_GL_LIGHT, GL_LINEAR_ATTENUATION, 0.000001f);
  glLightf(_GL_LIGHT, GL_QUADRATIC_ATTENUATION, 0.0000025f);

  GLfloat lPosition[4] = {pos[0], pos[1], pos[2], 1};
  glLightfv(_GL_LIGHT, GL_POSITION, lPosition);

  // enable GL_LIGHT0 with these defined properties
  glEnable(_GL_LIGHT); 
}

