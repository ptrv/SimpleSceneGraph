/*
 *  Driving.h
 *  Szenegraph3
 *
 *  Created by peter on 22.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DRIVING_H_
#define DRIVING_H_

#include "Transform.h"

class Driving : public Transform
{
public:
	Driving( const std::string& name, const float tx, const float ty, const float tz, const float winkel, const float rx, const float ry, const float rz, const bool on);
	virtual ~Driving();
	
	virtual void transform();
	virtual void apply_inverse();
	virtual float get_coordinates();
	virtual void set_coordinates(float x, float y, float z);
	virtual void set_degree(float deg);
	virtual float get_degree();
	virtual void simulate(float dt, float cx, float cy, float winkel1);
	
private:
	float tx_;
	float ty_;
	float tz_;
	float winkel_;
	float rx_;
	float ry_;
	float rz_;
	bool on_;
};

#endif