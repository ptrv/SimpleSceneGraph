#include "Teapot.h"

//GLfloat mat_amb[] = {0.0,0.0,0.0,0.0};

Teapot::Teapot(const std::string& name, const std::string& farbe, const double size) : Shape(name, farbe), size_(size)
{
	//set_material(farbe);
}

Teapot::~Teapot()
{
	
}	


void Teapot::render()
{
	//set material and draw geometry
	
	this->Shape::apply_material();
	glutSolidTeapot(this->size_);
	GLfloat color2[] = {0.0,0.0,0.0, 0.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutWireTeapot(this->size_+0.0008);
	
}