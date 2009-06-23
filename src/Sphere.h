#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere(const std::string& name, const std::string& farbe, const double radius);
	virtual ~Sphere();

	//traversal functions
	virtual void render();
	

private:
	double radius_;
};

#endif /*SPHERE_H_*/
