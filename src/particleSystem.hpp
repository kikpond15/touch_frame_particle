#pragma once
#ifndef particleSystem_hpp
#define particleSystem_hpp

#include "ofMain.h"
#include "particle.hpp"

class ParticleSystem {
public:
	ParticleSystem();
	ParticleSystem(ofVec2f p);
	void addParticle(ofVec2f v);
	void applyForce(ofVec2f v);
	void update();
	void display();
	std::vector<Particle> particles;
	ofVec2f origin;

};
#endif // !particleSystem_hpp



