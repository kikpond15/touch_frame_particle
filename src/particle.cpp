#include "particle.hpp"

Particle::Particle(ofVec2f l) {
	acceleration = ofVec2f(0, 0.05);
	velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-2, 0));
	position = l;
	color.set(0, 50, 255);
	//Set random color
	//color.set(ofRandom(255), ofRandom(255), ofRandom(255));
	lifespan = 255.0;
}

void Particle::run() {
	update();
	display();
}

void Particle::update() {
	velocity += acceleration;
	position += velocity;
	lifespan -= 2.0;
}

void Particle::display() {
	ofSetColor(color, lifespan);
	ofDrawEllipse(position.x, position.y, 12, 12);
}

bool Particle::isDead() {
	if (lifespan < 0.0) {
		return true;
	} else {
		return false;
	}
}