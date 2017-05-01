#include "SpotLight.h"

SpotLight::SpotLight(unsigned int GL_LIGHT){
  static GLfloat diffuse[] = {0.0f , 0.0f , 0.0f , 1.0f};
  _GL_LIGHT = GL_LIGHT;
  _diffuse = diffuse;
}


SpotLight::~SpotLight(){
}

void SpotLight::setFocus(Person *p){
  focus = p;
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

  glLightfv(_GL_LIGHT, GL_DIFFUSE, _diffuse);
  
  glLightf(_GL_LIGHT, GL_SPOT_CUTOFF, spot_cutoff);
  glLightfv(_GL_LIGHT, GL_SPOT_DIRECTION, spot_direction);
  glLightfv(_GL_LIGHT, GL_SPOT_EXPONENT, spot_exponent);

  GLfloat lPosition[4] = {pos[0], pos[1], pos[2], 1};
  glLightfv(_GL_LIGHT, GL_POSITION, lPosition);

  glEnable(_GL_LIGHT); 
}

void SpotLight::HandleKey(unsigned char key, int state, int mX, int mY){
  //if (state == 1 && key == 'm'){
    //on = !on;
  //}
}

void SpotLight::Update(const double& deltaTime){
  animationTime += deltaTime;
  //  Make the spotlights follow the players
  float x = pos[0] - focus -> getInfo()[0] - focus -> getInfo()[3];
  float y = pos[1] +100;
  float z = pos[2] - focus -> getInfo()[2] - focus -> getInfo()[5];
  spot_direction[0] = -x/y; 
  spot_direction[2] = -z/y; 

  //turn spotlights on during the animation
  if (animationTime > 2  && animationTime < 28){
    on = true;
  } else{
    on=false;
  }

  // fade spotlights in and out to intended brightness.
  if (on == true and _diffuse[0] < 1){
    _diffuse[0] += deltaTime;
    _diffuse[1] += deltaTime;
    _diffuse[2] += deltaTime;
  }
  if (on == false and _diffuse[0] >0){
    _diffuse[0] -= deltaTime;
    _diffuse[1] -= deltaTime;
    _diffuse[2] -= deltaTime;
  }

  if (animationTime> 40 && loop==true){
    animationTime = 0;
  }
}



