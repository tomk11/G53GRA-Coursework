#include "MyScene.h"
#include "Stadium.cpp"
#include "Table.cpp"
#include "Light.cpp"
#include "SpotLight.cpp"
#include "Chair.cpp"
#include "VideoCamera.cpp"

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

	//*
	j1 -> position(-350,-100,-350);
	j2 -> position(350,-100,-350);
	int actions =15;
	string j1Action[actions] = {"wait", "bow","walk","turnA","bow", "walk", "bow", "wait", "bow", "walkb", "bow", "turnC", "walkb", "bow", "wait" };
	string j2Action[actions] = {"wait", "bow","walk","turnC","bow", "walk", "bow", "wait" , "bow", "walkb", "bow", "turnA", "walkb", "bow", "wait" };
    int j1Duration[actions] =  {5     ,  1,    8,     3,      1,     5,      1,     3,       1,     5,       1,     1,       8,       1,     4};
    for (int i=0; i<actions; i++){
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

	camera.TrackPlayer(j1);


	// Add the table and chairs that the judges sit at.
	Table *t = new Table();
	t -> position(0,-100,-400);
	AddObjectToScene(t);
	Chair *ch1 = new Chair();
	ch1 -> position(-55,-100,-450);
	AddObjectToScene(ch1);
	Chair *ch2 = new Chair();
	ch2 -> position(55,-100,-450);
	AddObjectToScene(ch2);

	// Lighting. We have two spotlights that follow the two players and a main light that illumates the entire arena
	Light *l1 = new Light(GL_LIGHT0);
	l1-> position(0, 700, 0);
	AddObjectToScene(l1);
    SpotLight *sl1 = new SpotLight(GL_LIGHT1 );
	sl1 -> setFocus(j1); // we send a pointer to the player so that the spotlight can follow it
	sl1 ->position(-200,700,0);
	AddObjectToScene(sl1); // we send a pointer to the player so that the spotlight can follow it
    SpotLight *sl2 = new SpotLight(GL_LIGHT2 ); 
	sl2 -> setFocus(j2);
	sl2 ->position(200,700,0);
	AddObjectToScene(sl2);

	// Draw our cameramen and cameras
	VideoCamera *v1 = new VideoCamera();
	v1 ->position(460,0,-180);
	v1 ->orientation(0,-90,0);
	AddObjectToScene(v1);

	VideoCamera *v2 = new VideoCamera();
	v2 ->position(460,0,0);
	v2 ->orientation(0,-90,0);
	AddObjectToScene(v2);

	VideoCamera *v3 = new VideoCamera();
	v3 ->position(460,0,180);
	v3 ->orientation(0,-90,0);
	AddObjectToScene(v3);

}

/// set the perspective of camera
void MyScene::Projection()
{
    GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
    gluPerspective(60.0, aspect, 1.0, 2500.0);
}
