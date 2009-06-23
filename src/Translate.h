#ifndef TRANSLATE_H_
#define TRANSLATE_H_

#include "Transform.h"

class Translate : public Transform {

protected:
	float tx_;
	float ty_;
	float tz_;

public:
	//Constructor
	Translate(const std::string& name, const float tx, const float ty, const float tz);
	virtual ~Translate();



	virtual void transform(void);
	virtual void apply_inverse(void);
	virtual float get_coordinates();
	virtual void set_coordinates(float x, float y, float z);
};

#endif /*TRANSLATE_H_*/
