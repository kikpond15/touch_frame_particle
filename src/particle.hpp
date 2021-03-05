#pragma once

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"

class Particle {
public:
	Particle(ofVec2f p, float r, ofColor c);
	void update();
	void applyForce(ofVec2f f);
	void display();
	bool isDead();

	ofVec2f position, velocity, acceleration;
	ofColor color;
	float lifespan, rad;
};

#endif