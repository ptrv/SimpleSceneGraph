/*
 *  Rotor.h
 *  Szenegraph3
 *
 *  Created by peter on 20.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ROTOR_H_
#define ROTOR_H_


#include "Rotate.h"

class Rotor : public Rotate 
{
public:
	float dwinkel;
	
	Rotor( const std::string& name, const float winkel, const float rx, const float ry, const float rz, const int speed, const bool on);
	virtual ~Rotor();
	
	virtual void simulate(float dt, float cx, float cy, float winkel1);
	virtual float get_degree();
	virtual void set_degree(float deg);	
	
private:
	int rspeed_;
	bool on_;
	
};


#endif