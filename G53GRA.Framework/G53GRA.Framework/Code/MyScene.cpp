#include "MyScene.h"
#include "Judoka.cpp"
#include "Floor.cpp"
#include "Table.cpp"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight){}

void MyScene::Initialise()
{
	// set the background colour of the scene to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// DEMO 5
	// Show floor and triangle
	Floor *f = new Floor();
	f->size(100.0f);
	AddObjectToScene(f);

	Judoka *j = new Judoka();
	j->size(0.5f);
	//AddObjectToScene(j);

	Table *t = new Table();
	//t ->position(-50,5,0);
	//t->size(2.f);
	AddObjectToScene(t);
}

/// set the perspective of camera
void MyScene::Projection()
{
    GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
    gluPerspective(60.0, aspect, 1.0, 1000.0);
}
