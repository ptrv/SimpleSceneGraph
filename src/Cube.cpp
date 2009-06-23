/*
 *  Cube.cpp
 *  Szenegraph3
 *
 *  Created by peter on 18.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Cube.h"

Cube::Cube(const std::string& name, const std::string& farbe, const double size) : Shape(name, farbe), size_(size)
{
	
}

Cube::~Cube()
{
	
}

void Cube::render()
{
	this->Shape::apply_material();
	glutSolidCube(this->size_);
	GLfloat color2[] = {0.0,0.0,0.0, 0.0};
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutWireCube(this->size_+0.0005);
	
}