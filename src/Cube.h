/*
 *  Cube.h
 *  Szenegraph3
 *
 *  Created by peter on 18.06.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Shape.h"

class Cube : public Shape {
public:
	Cube(const std::string& name, const std::string& farbe, const double size);
	virtual ~Cube();
	
	virtual void render();
	
private:
	
	double size_;
};






#endif