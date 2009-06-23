#include "Translate.h"
#include "GLUT/glut.h"


#define foreach( i, c )\
typedef __typeof__( c ) c##_CONTAINERTYPE;\
for( c##_CONTAINERTYPE::iterator i = c.begin(); i != c.end(); ++i )


Translate::Translate(const std::string& name, const float tx, const float ty, const float tz)
	:  Transform(name), tx_(tx), ty_(ty), tz_(tz)
{

}

Translate::~Translate()
{

}
void Translate::set_coordinates(float x, float y, float z)
{
	this->tx_= x;
	this->ty_= y;
	this->tz_= z;
}

float Translate::get_coordinates()
{
	float coordinates[] = { this->tx_, this->ty_, this->tz_};
	return *coordinates;
	
}

void Translate::transform(void)
{
	//std::cout << "Translate " << getName() << std::endl;
	glTranslatef(this->tx_,this->ty_,this->tz_);

}


void Translate::apply_inverse(void)
{
	glTranslatef(-this->tx_, -this->ty_, -this->tz_);
}
