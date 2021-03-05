#include "ofApp.h"
#include <list>
// make a list to keep track of active touches
list <ofTouchEventArgs> touches;

//--------------------------------------------------------------
void ofApp::setup() {
	// Visual setup
	ofBackground(0);
	ofSetFrameRate(60);
	ofHideCursor();

	// Enable the Windows Touch Hook
	ofxMultitouch::EnableTouch();


	// Add touch listeners
	ofAddListener(ofxMultitouch::touchDown, this, &ofApp::touchDown);
	ofAddListener(ofxMultitouch::touchMoved, this, &ofApp::touchMove);
	ofAddListener(ofxMultitouch::touchUp, this, &ofApp::touchUp);

	particleSystem = ParticleSystem(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
}

//--------------------------------------------------------------
void ofApp::update() {
	list<ofTouchEventArgs> ::iterator it;
	for (it = touches.begin(); it != touches.end(); ++it) {
		//ofDrawCircle((*it).x, (*it).y, 50);

		//ofDrawBitmapString(ofToString((*it).x) + ", " + ofToString((*it).y), 100, 200);
		//cout << (*it).x << ", " << (*it).y << endl;

		particleSystem.addParticle();
		particleSystem.updatePos(ofVec2f((*it).x, (*it).y));
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	// Display frame rate
	ofDrawBitmapString(ofToString(roundf(ofGetFrameRate())), 100, 100);

	// Draw circles
	//ofSetColor(255, 255, 255, 150);

	particleSystem.display();
}


//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch) {
	// Add a new circle for this new touch
	touches.push_back(touch);
}


//--------------------------------------------------------------
void ofApp::touchMove(ofTouchEventArgs & touch) {
	// Move the corresponding circle
	std::list <ofTouchEventArgs> ::iterator it;
	for (it = touches.begin(); it != touches.end(); ++it) {
		if (it->id == touch.id) {
			*it = touch;
		}
	}
}


//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch) {
	// Remove the corresponding circle
	ofTouchEventArgs touchToRemove;
	std::list <ofTouchEventArgs> ::iterator it;
	for (it = touches.begin(); it != touches.end(); ++it) {
		if (it->id == touch.id) {
			touchToRemove = *it;
		}
	}
	touches.remove(touchToRemove);
}
