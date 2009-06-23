/*
 *  Rotor.cpp
 *  Szenegraph3
 *
 *  Created by peter on 20.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Rotor.h"

Rotor::Rotor( const std::string& name, const float winkel, const float rx, const float ry, const float rz, const int speed, const bool on) : Rotate(name, winkel, rx, ry, rz), rspeed_(speed), on_(on)
{
	dwinkel = winkel_;
}

Rotor::~Rotor()
{
}

void Rotor::set_degree(float deg)
{
	this->winkel_= deg;
}

float Rotor::get_degree()
{
	return this->winkel_;
}

void Rotor::simulate(float dt, float cx, float cy, float winkel1)
{
	dwinkel = get_degree();
	dwinkel = this->rspeed_ * dt;
	if (this->on_)
	{
		set_degree(dwinkel);
	}

}