#include "Floor.h"

Floor::Floor(const std::string& name, const std::string& farbe) : Shape(name, farbe)
{

}

Floor::~Floor()
{

}

void Floor::render()
{
	//glColor3f( 1.0, 1.0, 1.0 );
	int gridLength = 7;

	// draw whole grid
	glBegin( GL_LINES );
	for( int i=-gridLength; i<=gridLength; ++i )
	{
		glVertex3f( i, 0, -gridLength );
		glVertex3f( i, 0, gridLength );

		glVertex3f( gridLength, 0, i );
		glVertex3f( -gridLength, 0, i );
	}
	glEnd();
}