#include "particleSystem.hpp"

ParticleSystem::ParticleSystem() {
}

ParticleSystem::ParticleSystem(ofVec2f p) {
	origin.set(p);
}

void ParticleSystem::addParticle(ofVec2f v) {
	float rad = ofRandom(10, 50);
	ofColor c(0,100,255);
	//ofColor c(ofRandom(255), ofRandom(255), ofRandom(255));
	particles.push_back(Particle(v, rad, c));
}

void ParticleSystem::applyForce(ofVec2f v) {
	for (auto p: particles) {
		p.applyForce(v);
	}
}

void ParticleSystem::update() {
	if (particles.size() > 0) {
		for (int i = particles.size() - 1; i >= 0; i--) {
			particles[i].update();
			if (particles[i].isDead()) {
				particles.erase(particles.begin() + i);
			}
		}
	}
}

void ParticleSystem::display() {
	if (particles.size() > 0) {
		for (int i = particles.size()-1; i >= 0; i--) {
			particles[i].display();
		}
	}
}