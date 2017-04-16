#include "MyScene.h"
#include "Judoka.cpp"
#include "Stadium.cpp"
#include "Table.cpp"
#include "Light.cpp"
#include "Clock.cpp"
#include "Chair.cpp"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight){}

void MyScene::Initialise()
{
	// set the background colour of the scene to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Stadium *s = new Stadium();
	s->size(100.0f);
	s-> position(0,-100,0);
	AddObjectToScene(s);

	Judoka *j = new Judoka();
	j -> position(0,-100,0);
	j -> size(1);
	//AddObjectToScene(j);

	Table *t = new Table();
	t -> position(0,-100,-400);
	AddObjectToScene(t);

	Clock *c = new Clock();
	c -> position (0,20,-400);
	c -> size(1);
	AddObjectToScene(c);

	Chair *ch1 = new Chair();
	ch1 -> position(-55,-100,-450);
	AddObjectToScene(ch1);

	Chair *ch2 = new Chair();
	ch2 -> position(55,-100,-450);
	AddObjectToScene(ch2);


    static GLfloat leftDiffuse [] = { 0.8f , 0.f , 0.0f , 1.0f };
    Light *l = new Light(leftDiffuse , GL_LIGHT0 );
	l ->position(-200,100,0);
	AddObjectToScene(l);
}

/// set the perspective of camera
void MyScene::Projection()
{
    GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
    gluPerspective(60.0, aspect, 1.0, 1000.0);
}
