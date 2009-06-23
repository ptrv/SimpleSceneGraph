/*
 *  Driving.cpp
 *  Szenegraph3
 *
 *  Created by peter on 22.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Driving.h"
#include <math.h>

Driving::Driving( const std::string& name, const float tx, const float ty, const float tz, const float winkel, const float rx, const float ry, const float rz, const bool on)
: Transform(name), tx_(tx), ty_(ty), tz_(tz), winkel_(winkel), rx_(rx), ry_(ry), rz_(rz), on_(on)
{
}

Driving::~Driving()
{
}

void Driving::set_coordinates(float x, float y, float z)
{
	this->tx_= x;
	this->ty_= y;
	this->tz_= z;
}

float Driving::get_coordinates()
{
	float coordinates[] = { this->tx_, this->ty_, this->tz_};
	return *coordinates;
	
}

void Driving::set_degree(float deg)
{
	this->winkel_= deg;
}

float Driving::get_degree()
{
	return this->winkel_;
	
}

void Driving::transform(void)
{
	glRotatef(-this->winkel_, this->rx_, this->ry_, this->rz_);
	glTranslatef(this->tx_,this->ty_, this->tz_);
	
	
}


void Driving::apply_inverse(void)
{
	
	glRotatef(-this->winkel_, -this->rx_, -this->ry_, -this->rz_);
	glTranslatef(-this->tx_, -this->ty_, -this->tz_);

			
}
void Driving::simulate(float dt, float cx, float cy, float winkel1)
{	
	
	this->set_coordinates(cx, 0.0, cy);
	this->set_degree(winkel1);
}