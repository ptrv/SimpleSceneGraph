#ifndef CAMERA_H_
#define CAMERA_H_

#include "Part.h"
#include "Transform.h"

class Camera : public Part
{

public:
	Camera(const std::string& name, const bool on, const double fov);
	virtual ~Camera();
	virtual void bind_camera(int w, int h);

private:
	bool on_;
	double fov_;
};

#endif /*CAMERA_H_*/
