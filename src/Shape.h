#ifndef SHAPE_H_
#define SHAPE_H_

#include "Part.h"


class Shape : public Part
{
public:
	Shape(const std::string& name, const std::string& farbe);
	virtual ~Shape();
	virtual void apply_material();
	
private:
	
	std::string farbe_;
};

#endif /*SHAPE_H_*/
