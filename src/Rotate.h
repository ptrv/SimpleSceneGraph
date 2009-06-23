#ifndef ROTATE_H_
#define ROTATE_H_

#include "Transform.h"

class Rotate : public Transform {

protected:
	float winkel_;
	float rx_;
	float ry_;
	float rz_;

public:
	
	//Constructor
	Rotate(const std::string& name, const float winkel, const float rx, const float ry, const float rz);
	virtual ~Rotate();
	
	//traversal functions
	
	virtual void transform(void);
	virtual void apply_inverse(void);
	virtual void set_degree(float deg);
	virtual float get_degree();
};

#endif /*ROTATE_H_*/
