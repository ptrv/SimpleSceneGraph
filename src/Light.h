#ifndef LIGHT_H_
#define LIGHT_H_

#include "Part.h"

class Light : public Part
{
public:
	//i is index for GL_LIGHTi, 
	Light(const std::string& name, const int i, const bool on, const float intensity, const float position);
	virtual ~Light();
	virtual void bind_lights();

private:
	int i_;
	bool on_;
	float intensity_;
	float position_;

};

#endif /*LIGHT_H_*/
