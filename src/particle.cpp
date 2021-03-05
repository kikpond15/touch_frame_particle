#include "particle.hpp"

Particle::Particle(ofVec2f p, float r, ofColor c) {
	acceleration = ofVec2f(0, 0.05);
	velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-2, 0));
	position = p;
	color.set(c);
	lifespan = 255.0;
	rad = r;
}

void Particle::applyForce(ofVec2f f){
	acceleration += f;
}

void Particle::update() {
	velocity += acceleration;
	position += velocity;
	lifespan -= 2.0;
	acceleration = ofVec2f(0, 0);
}

void Particle::display() {
	ofSetColor(color, lifespan);
	ofDrawEllipse(position.x, position.y, rad, rad);
}

bool Particle::isDead() {
	if (lifespan < 0.0) {
		return true;
	} else {
		return false;
	}
}