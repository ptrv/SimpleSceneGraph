/*
 *  Jumper.cpp
 *  Szenegraph3
 *
 *  Created by peter on 20.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Jumper.h"
#include <math.h>

#define foreach( i, c )\
typedef __typeof__( c ) c##_CONTAINERTYPE;\
for( c##_CONTAINERTYPE::iterator i = c.begin(); i != c.end(); ++i )

Jumper::Jumper( const std::string& name, const float tx, const float ty, const float tz, const float speed, const bool on)
	: Translate(name, tx, ty, tz), speed_(speed), on_(on)
{
}

Jumper::~Jumper()
{
}

void Jumper::set_coordinates(float x, float y, float z)
{
	this->tx_= x;
	this->ty_= y;
	this->tz_= z;
}

float Jumper::get_coordinates()
{
	float coordinates[] = { this->tx_, this->ty_, this->tz_};
	return *coordinates;
}

void Jumper::simulate(float dt, float cx, float cy, float winkel1)
{
	if (this->on_) {
		jumper = 2.0 * fabs(sin(dt*this->speed_)*1.0);	//function for jumping
		set_coordinates(0.0, jumper, 0.0);
	}
	std::vector<Part*> children = getChildren();
	glPushMatrix();
	this->transform();
	foreach ( i, children )
	{
		if ( *i != NULL )
		{
			(*i)->simulate(dt, cx, cy, winkel1);
		}
	}
	
	glPopMatrix();
	
	
}