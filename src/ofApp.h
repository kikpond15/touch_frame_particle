#pragma once

#include "ofMain.h"
#include "ofxMultitouch.h"
#include "particleSystem.hpp"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	// add the touch listeners
	void touchDown(ofTouchEventArgs& touch);
	void touchMove(ofTouchEventArgs& touch);
	void touchUp(ofTouchEventArgs& touch);

	ParticleSystem particleSystem;

};
