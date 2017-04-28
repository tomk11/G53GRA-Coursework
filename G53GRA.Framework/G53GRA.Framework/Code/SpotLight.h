#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include "../Framework/Interface/Input.h"
#include <cmath>

class SpotLight:
  public DisplayableObject,
  public Animation,
  public Input
{
public:
  SpotLight(GLfloat d[], unsigned int GL_LIGHT);
  ~SpotLight();

  // Could use to represent light source with sphere (optional)
  void Display();
  void setFocus(Person *d);
  void calibrate();
  void Update(const double& deltaTime);

private:
  // reflectance model parameters for LIGHT
  GLfloat *_ambient, *_diffuse, *_specular;
  unsigned int _GL_LIGHT;
  Person *focus;
  GLfloat spot_direction[3] = { 0.0, -1.0, 0.0 };
  GLfloat spot_exponent[3] = { 85.0, 85.0, 85.0 };

  // flag for indicating positional or directional light source
  // 0.0f for directional, 1.0f for positional
};

