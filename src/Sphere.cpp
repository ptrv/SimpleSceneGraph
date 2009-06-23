#include "Sphere.h"

Sphere::Sphere(const std::string& name, const std::string& farbe, const double radius) : Shape(name, farbe), radius_(radius)
{
	
}

Sphere::~Sphere()
{
	
}


void Sphere::render()
{
	//set material and draw geometry
	
	this->Shape::apply_material();
	glutSolidSphere(this->radius_, 40, 20);
	
	GLfloat color2[] = {0.0,0.0,0.0, 0.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, color2);
	glutWireSphere(this->radius_+0.0005, 40, 20);
	
}