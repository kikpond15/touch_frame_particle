#include "particleSystem.hpp"

ParticleSystem::ParticleSystem() {
}

ParticleSystem::ParticleSystem(ofVec2f pos) {
	origin.set(pos);
}

void ParticleSystem::addParticle() {
	particles.push_back(Particle(origin));
}

void ParticleSystem::run() {
	for (int i = particles.size() - 1; i >= 0; i--) {
		Particle p = particles[i];
		p.run();
		if (p.isDead()) {
			particles.erase(particles.begin() + i);
			//particles.erase(i);
		}
	}
}

void ParticleSystem::updatePos(ofVec2f pos) {
	origin.set(pos);
	for (int i = particles.size() - 1; i >= 0; i--) {
		particles[i].update();
		if (particles[i].isDead()) {
			particles.erase(particles.begin() + i);
		}
	}
}

void ParticleSystem::display() {
	for (int i = particles.size() - 1; i >= 0; i--) {
		particles[i].display();
	}
}