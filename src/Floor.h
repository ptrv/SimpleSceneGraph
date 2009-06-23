#ifndef FLOOR_H_
#define FLOOR_H_

#include "Shape.h"

class Floor : public Shape
{
public:
	Floor(const std::string& name, const std::string& farbe);
	virtual ~Floor();

	virtual void render();

private:
};

#endif /*FLOOR_H_*/
