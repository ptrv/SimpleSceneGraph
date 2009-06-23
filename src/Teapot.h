#ifndef TEAPOT_H_
#define TEAPOT_H_

#include "Shape.h"

class Teapot : public Shape
{
public:
	Teapot(const std::string& name, const std::string& farbe, const double size);
	virtual ~Teapot();

	virtual void render();

	

private:
	double size_;
};

#endif /*TEAPOT_H_*/
