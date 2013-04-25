#include "ofMain.h"
#include "SnakeGame.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 700,500, OF_WINDOW); // <-------- setup the GL context
	ofSetFrameRate(20);	// A good speed for the game
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new SnakeGame());

}
