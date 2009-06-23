

#include "Camera.h"

#define foreach( i, c )\
	typedef __typeof__( c ) c##_CONTAINERTYPE;\
	for( c##_CONTAINERTYPE::iterator i = c.begin(); i != c.end(); ++i )

Camera::Camera(const std::string& name, const bool on, const double fov) : Part(name), on_(on), fov_(fov)
{

}

Camera::~Camera()
{

}

void Camera::bind_camera(int w, int h)
{
	if (on_) {
		//set viewport with windowsize
		glViewport(0, 0, w, h);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//set perspective
		gluPerspective(this->fov_, (float)w/(float)h, 0.1, 100);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		//get parent
		Part* p = this->getParent();
		
		
		//upward traversal
		while (p != NULL)          // until no more parents found
		{
			Transform* t;
			if ((t = dynamic_cast<Transform*>(p)))     // look if it is a transform-object
			{
				t ->apply_inverse();        // apply its invers transformations
			}
			
			p = p->getParent();         // get its parent
		}
	}
}