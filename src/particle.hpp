#pragma once

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"

class Particle {
public:
	Particle(ofVec2f l);
	void update();
	void run();
	void display();
	bool isDead();

	ofVec2f position, velocity, acceleration;
	ofColor color;
	float lifespan;


};

#endif