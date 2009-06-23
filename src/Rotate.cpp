/*
 *  Rotate.cpp
 *  Szenegraph
 *
 *  Created by peter on 03.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Rotate.h"

#define foreach( i, c )\
typedef __typeof__( c ) c##_CONTAINERTYPE;\
for( c##_CONTAINERTYPE::iterator i = c.begin(); i != c.end(); ++i )

Rotate::Rotate(const std::string& name, const float winkel, const float rx, const float ry, const float rz)
	:  Transform(name), winkel_(winkel), rx_(rx), ry_(ry), rz_(rz)
{

}


Rotate::~Rotate()
{

}


//getter and setter

void Rotate::set_degree(float deg)
{
	this->winkel_= deg;
}

float Rotate::get_degree()
{
	return this->winkel_;
	
}



//apply transformation matrix
void Rotate::transform(void)
{
	glRotatef(this->winkel_, this->rx_, this->ry_, this->rz_);
}

//apply inverse transfomation
void Rotate::apply_inverse()
{
	glRotatef(-this->winkel_, -this->rx_, -this->ry_, -this->rz_);
}