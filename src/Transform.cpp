/*
 *  Group.cpp
 *  Szenegraph
 *
 *  Created by peter on 26.05.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Transform.h"

#define foreach( i, c )\
	typedef __typeof__( c ) c##_CONTAINERTYPE;\
	for( c##_CONTAINERTYPE::iterator i = c.begin(); i != c.end(); ++i )


Transform::Transform(const std::string& name) : Part(name)
{

}

Transform::~Transform()
{

}

void Transform::transform(void)
{
	

}

void Transform::simulate(float dt, float cx, float cy, float winkel1)
{
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

void Transform::apply_inverse(void)
{

}


void Transform::render(void)
{
	//get all children of the current node
	std::vector<Part*> children = getChildren();
	//put the current transformation matrix on the stack
	glPushMatrix();

	this->transform();		//apply transformation
	//go to children
	foreach ( i, children )
	{
		if ( *i != NULL )
		{
			(*i)->render();
		}
	}

	glPopMatrix();
}
void Transform::bind_lights(void)
{
	std::vector<Part*> children = getChildren();
	
	glPushMatrix();
	
	this->transform();
	
	foreach ( i, children )
	{
		if ( *i != NULL )
		{
			(*i)->bind_lights();
		}
	}
	
	glPopMatrix();
	
}