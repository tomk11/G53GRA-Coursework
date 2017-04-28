#include "MyScene.h"
#include "Person.cpp"
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
	

	Person *j1 = new Person();
	Person *j2 = new Person();

	/*
	j1 -> position(-350,-100,-350);
	j2 -> position(350,-100,-350);
	string j1Action[14] = {"bow","walk","turnA","bow", "walk", "bow", "judoThrow", "bow", "walkb", "bow", "turnC", "walkb", "bow", "wait" };
	string j2Action[14] = {"bow","walk","turnC","bow", "walk", "bow", "wait" , "bow", "walkb", "bow", "turnA", "walkb", "bow", "wait" };
    int j1Duration[14] =  { 1,    8,     3,      1,     5,      1,     3,       1,     5,       1,     1,       8,       1,     4};
    for (int i=0; i<14; i++){
	/*/
	j1 -> position(-100,-100,0);
	j2 -> position(100,-100,0);
	j1 -> setOpponent(j2);
	string j2Action[3] = {"turnA", "judoThrow", "wait" };
	string j1Action[3] = {"turnC", "getThrown", "wait" };
    int j1Duration[3] =  { 1,      8,     4};
    for (int i=0; i<3; i++){
    //*/

    	j1 -> addInstruction(j1Action[i], j1Duration[i]);
    	j2 -> addInstruction(j2Action[i], j1Duration[i]);
    }


	AddObjectToScene(j1);
	AddObjectToScene(j2);

	Table *t = new Table();
	t -> position(0,-100,-450);
	AddObjectToScene(t);

	Clock *c = new Clock();
	c -> position (0,20,-450);
	c -> size(1);
	AddObjectToScene(c);

	Chair *ch1 = new Chair();
	ch1 -> position(-55,-100,-500);
	AddObjectToScene(ch1);

	Chair *ch2 = new Chair();
	ch2 -> position(55,-100,-500);
	AddObjectToScene(ch2);

    static GLfloat leftDiffuse [] = { 0.8f , 0.8f , 0.8f , 1.0f };
    Light *l = new Light(leftDiffuse , GL_LIGHT0 );
	l ->position(-200,700,0);
	AddObjectToScene(l);

    static GLfloat rightDiffuse [] = { 0.8f , 0.8f , 0.8f , 1.0f };
    Light *r = new Light(rightDiffuse , GL_LIGHT1 );
	r ->position(200,700,0);
	AddObjectToScene(r);
}

/// set the perspective of camera
void MyScene::Projection()
{
    GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
    gluPerspective(60.0, aspect, 1.0, 2500.0);
}
