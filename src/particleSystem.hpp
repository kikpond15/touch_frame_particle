#pragma once
#ifndef particleSystem_hpp
#define particleSystem_hpp

#include "ofMain.h"
#include "particle.hpp"

class ParticleSystem {
public:
	ParticleSystem();
	ParticleSystem(ofVec2f pos);
	void addParticle();
	void run();
	void updatePos(ofVec2f pos);
	void display();

	std::vector<Particle> particles;
	ofVec2f origin;

};
#endif // !particleSystem_hpp



