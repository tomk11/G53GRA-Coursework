#include "MyScene.h"
#include "Judoka.cpp"
#include "Floor.cpp"
#include "Table.cpp"
#include "Light.cpp"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight){}

void MyScene::Initialise()
{
	// set the background colour of the scene to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Floor *f = new Floor();
	f->size(100.0f);
	f -> position(0,-100,0);
	AddObjectToScene(f);

	Judoka *j = new Judoka();
	j -> position(0,-100,0);
	j -> size(1);
	AddObjectToScene(j);

	Table *t = new Table();
	t -> position(0,-100,-600);
	t -> size(1.5);
	AddObjectToScene(t);



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
