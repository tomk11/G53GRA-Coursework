#include "Light.h"

Light::Light(GLfloat d[], unsigned int GL_LIGHT)
{
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