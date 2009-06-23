#include "Shape.h"


Shape::Shape(const std::string& name, const std::string& farbe) : Part(name), farbe_(farbe)
{
}

Shape::~Shape()
{

}

//setting materials
void Shape::apply_material()
{	
	GLfloat mat_amb[] = {0.0, 0.0, 0.0, 0.0};
	if(this->farbe_ == "white")
	{
		glColor3d(1.0, 1.0, 1.0);
	}
	if(this->farbe_ == "green")
	{
		mat_amb[0] = 0.0;
		mat_amb[1] = 1.0;
		mat_amb[2] = 0.0; 
		mat_amb[3] = 0.0;
	}
	if (this->farbe_ == "red") {
		mat_amb[0] = 1.0;
		mat_amb[1] = 0.0;
		mat_amb[2] = 0.0; 
		mat_amb[3] = 0.0;
	}
	if (this->farbe_ == "blue") 
	{
		mat_amb[0] = 0.0;
		mat_amb[1] = 0.0;
		mat_amb[2] = 1.0; 
		mat_amb[3] = 0.0;
	}
	
	if (this->farbe_ == "purple") 
	{
		mat_amb[0] = 1.0;
		mat_amb[1] = 0.0;
		mat_amb[2] = 1.0; 
		mat_amb[3] = 0.0;
	}
	
	GLfloat mat_diff[] = { 1.0, 1.0, 1.0, 0.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diff);
	
}




