#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include "../Framework/Interface/Input.h"

#include <cmath>

class Light :
  public DisplayableObject,
//  public Animation,
  public Input
{
public:
  Light(GLfloat d[], unsigned int GL_LIGHT);
  ~Light();

  // Could use to represent light source with sphere (optional)
  void Display();

private:
  // reflectance model parameters for LIGHT
  GLfloat *_ambient, *_diffuse, *_specular;
  unsigned int _GL_LIGHT;

  // flag for indicating positional or directional light source
  // 0.0f for directional, 1.0f for positional
};

