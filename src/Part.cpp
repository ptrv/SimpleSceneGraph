/*
 *  part.cpp
 *  Szenegraph
 *
 *  Created by peter on 20.05.08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Part.h"
#include <string>
#include <OpenGL/GL.h>
//#include "Context.h"

#define foreach( i, c )\
	typedef __typeof__( c ) c##_CONTAINERTYPE;\
	for( c##_CONTAINERTYPE::iterator i = c.begin(); i != c.end(); ++i )

int p = 0; //index for recursive function

// constructors



Part::Part(const std::string& name) : name_( name )
{
	setParent(NULL);
}


// return name of part


Part::~Part()
{
	
}

const std::string& Part::getName()
{
	return this->name_;
}



// set parent part

void Part::setParent(Part* part)
{
	parent_ = part;
}

// get parent part

Part* Part::getParent() {
	return parent_;
}

// add a child

void Part::addChildren(Part* part)
{
	if(part->getParent() != NULL)
	{
		Part* parent = part->getParent();
		parent->removeChild(part);
	}
	children_.push_back(part);

	// Überschreibe parent pointer von aktuellem Kind part
	part->setParent(this);
}

std::vector<Part*> Part::getChildren(void)
{
	return children_;
}


void Part::removeChild(Part* part)
{
	std::vector<Part*>::iterator it( children_.begin() );
	int stelle = 0;
	if(!children_.empty())
	{

		for( it; it != children_.end(); ++it )
		{
			if ( (*it)->getName() == part->getName())
			{
				break;
			}
			++stelle;
		}
		//sicherheitsabfrage damit man nicht das letzte child löscht
		if((*it)->getName() == part->getName())
		{
			children_.erase(children_.begin() + stelle);
		}

	}
}

// print children in xml format
void Part::printChildren(void)
{
	std::vector<Part*> children = getChildren();
	foreach( i, children)
	{
		std::cout << "Current child is " << (*i)->getName() << std::endl;
	}
}

void Part::printChildOpen(unsigned int index)
{
	printTab(index);
	std::cout << "<" << getName() << ">" << std::endl;
}

void Part::printChildClose(unsigned int index)
{
	printTab(index);
	std::cout << "</" << getName() << ">" << std::endl;
}

void Part::printTab(unsigned int index)
{
	for (unsigned int i = 0; i<index; ++i)
	{
		std::cout << "\t";
	}
}

void Part::print(unsigned int index)
{
	std::vector<Part*> children = getChildren();
	
	printChildOpen(index);
	++index;
	foreach ( i, children )
	{
		if ( *i != NULL )
		{
			(*i)->print(index);
		}
	}
	--index;
	printChildClose(index);
}



//traversal functions
//
//each function gets vector with children and for each child
//execute function


void Part::simulate(float dt, float cx, float cy, float winkel1)
{

	std::vector<Part*> children = getChildren();
	foreach ( i, children )
	{
		if ( *i != NULL )
		{

			(*i)->simulate(dt, cx, cy, winkel1);
		}
	}
}

void Part::bind_camera(int w, int h)
{
	std::vector<Part*> children = getChildren();
	foreach ( i, children )
	{
		if ( *i != NULL )
		{
			(*i)->bind_camera(w,h);
		}
	}	
}

void Part::bind_lights()
{
	std::vector<Part*> children = getChildren();
		foreach ( i, children )
		{
			if ( *i != NULL )
			{
				(*i)->bind_lights();
			}
		}
}

void Part::render()
{
	std::vector<Part*> children = getChildren();
	foreach ( i, children )
	{
		if ( *i != NULL )
		{
			(*i)->render();
		}
	}
	}
