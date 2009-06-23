/*
 *  Jumper.h
 *  Szenegraph3
 *
 *  Created by peter on 20.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef JUMPER_H_
#define JUMPER_H_

#include "Translate.h"

class Jumper : public Translate
{
public:
	float jumper;
	
	Jumper( const std::string& name, const float tx, const float ty, const float tz, const float speed, const bool on);
	virtual ~Jumper();
	
	virtual void simulate(float dt, float cx, float cz, float winkel1);
	virtual float get_coordinates();
	virtual void set_coordinates(float x, float y, float z);
	
private:
	float speed_;
	bool on_;
};

#endif