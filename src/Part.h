#ifndef PART_H_
#define PART_H_

#include <iostream>
#include <vector>
#include <string>
#include "GLUT/glut.h"
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
//#include "Context.h"




class Part {
// private fields and functions

private:

	std::string name_;
	Part* parent_;
	std::vector<Part*> children_;


public:
	//index for print function
	unsigned int index;
	// Constructor
	Part();
	Part ( const std::string& name );			

	virtual ~Part();

	
	
	//traversal functions
	virtual void simulate(float dt, float cx, float cy, float winkel1);
	virtual void bind_camera(int w, int h);
	virtual void bind_lights();
	virtual void render();

	// public functions
	
	void print(unsigned int index);
	void addChildren(Part *part);
	void removeChild(Part *part);
	std::vector<Part*> getChildren(void);
	void setParent ( Part *part );
	void printChildren(void);
	void printChildOpen(unsigned int index);
	void printChildClose(unsigned int index);
	void printTab(unsigned int index);
	Part* getParent ( void );
	const std::string& getName ( void );
	void setName (const std::string& name );




};

#endif /*PART_H_*/
