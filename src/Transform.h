#ifndef TRANSFORM_H_
#define TRANSFORM_H_
#include "Part.h"



class Transform	: public Part {

private:


public:
	//Constructor
	Transform(const std::string& name);
	virtual ~Transform();
	
	
	virtual void transform(void);
	virtual void render();
	virtual void bind_lights();
	virtual void apply_inverse(void);
	virtual void simulate(float dt, float cx, float cy, float winkel1);

};

#endif /*TRANSFORM_H_*/
