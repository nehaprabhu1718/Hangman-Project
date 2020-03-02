#include "ofMain.h"
#include "ofApp.h"

//========================================================================

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "ofMain.h"


using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char**argv) {
	
	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	//can be OF_WINDOW or OF_FULLSCREEN	
	//pass in width and height too:
    ofRunApp( new ofApp());
	return 0;

}


