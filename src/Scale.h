/*
 *  Scale.h
 *  Szenegraph3
 *
 *  Created by peter on 01.07.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SCALE_H_
#define SCALE_H_

#include "Transform.h"

class Scale : public Transform {
	
protected:
	float sx_;
	float sy_;
	float sz_;
	
public:
	//Constructor
	Scale(const std::string& name, const float sx, const float sy, const float sz);
	virtual ~Scale();
	
	
	
	virtual void transform(void);
	virtual void apply_inverse(void);
	virtual float get_coordinates();
	virtual void set_coordinates(float x, float y, float z);
};

#endif /*SCALE_H_*/
