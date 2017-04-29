#pragma once

#include "../Framework/Interface/DisplayableObject.h"
#include "../Framework/Interface/Animation.h"
#include "../Framework/Interface/Input.h"
#include <cmath>

class Light :
  public DisplayableObject,
  public Animation,
  public Input
{
public:
  Light(unsigned int GL_LIGHT);
  ~Light();

  // Could use to represent light source with sphere (optional)
  void Display();
  void Update(const double& deltaTime);
  void HandleKey(unsigned char key, int state, int mX, int mY);

private:
  // reflectance model parameters for LIGHT
  GLfloat *_ambient, *_diffuse, *_specular;
  GLfloat *_ambientOn, *_diffuseOn, *_specularOn;
  unsigned int _GL_LIGHT;
  bool on=true;

  // flag for indicating positional or directional light source
  // 0.0f for directional, 1.0f for positional
};

