/*
 *  Scale.cpp
 *  Szenegraph3
 *
 *  Created by peter on 01.07.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Scale.h"

//#include "GLUT/glut.h"


#define foreach( i, c )\
typedef __typeof__( c ) c##_CONTAINERTYPE;\
for( c##_CONTAINERTYPE::iterator i = c.begin(); i != c.end(); ++i )


Scale::Scale(const std::string& name, const float sx, const float sy, const float sz)
:  Transform(name), sx_(sx), sy_(sy), sz_(sz)
{
	
}

Scale::~Scale()
{
	
}
void Scale::set_coordinates(float x, float y, float z)
{
	this->sx_= x;
	this->sy_= y;
	this->sz_= z;
}

float Scale::get_coordinates()
{
	float coordinates[] = { this->sx_, this->sy_, this->sz_};
	return *coordinates;
	
}

void Scale::transform(void)
{
	glScalef(this->sx_,this->sy_,this->sz_);	
}


void Scale::apply_inverse(void)
{
	glScalef(1/(this->sx_), 1/(this->sy_), 1/(this->sz_));
}
