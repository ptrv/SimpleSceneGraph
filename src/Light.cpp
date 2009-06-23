#include "Light.h"


//float intensity = 0.6;

//float position = 1.0;


//GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
//GLfloat light_diffuse[] = { 0.8,0.8, 0.8, 1.0 };
//GLfloat light_specular[] = { 0.8, 0.8, 0.8, 1.0 };
//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.5 };

Light::Light(const std::string& name, const int i,  const bool on, const float intensity, const float position)
: Part(name), on_(on), i_(i), intensity_(intensity), position_(position)
{
	
}
Light::~Light()
{
	
}

void Light::bind_lights()
{
	GLfloat light_ambient[] = { this->intensity_*0.1, this->intensity_*0.1,this->intensity_*0.1, 1.0 };
	GLfloat light_diffuse[] = {this->intensity_, this->intensity_,this->intensity_, 1.0 };
	GLfloat light_specular[] = {this->intensity_, this->intensity_,this->intensity_, 1.0 };
	GLfloat light_position[] = { this->position_, this->intensity_, this->intensity_, 1.0 };
	
	GLenum light = GL_LIGHT0 + this->i_;
	// if light is on, enable
	if(on_)
	{
		
		glEnable(GL_LIGHTING);
		glEnable(light);
		glEnable(GL_DEPTH_TEST);
		
		glLightfv(light, GL_AMBIENT, light_ambient);
		glLightfv(light, GL_DIFFUSE, light_diffuse);
		glLightfv(light, GL_SPECULAR, light_specular);
		glLightfv(light, GL_POSITION, light_position);
	}
	else
	{
		glDisable(light);
	}
	
}
