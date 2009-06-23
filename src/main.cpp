#include <iostream>
#include "Part.h"
#include "Transform.h"
#include "Rotate.h"
#include "Sphere.h"
#include "Translate.h"
#include "Scale.h"
#include "Teapot.h"
#include "Cube.h"
#include "Camera.h"
#include "Light.h"
#include "Floor.h"
#include "Rotor.h"
#include "Jumper.h"
#include "Driving.h"
#include <math.h>
#include "tinyxml.h"


float dt = 0.0;
int w_width = 1000;
int w_height = 600;

Part *rootSc;

float cx = 0;
float cy = 0;
float cz = 0;
float winkel1 = 0;



bool isOn(const std::string& wert)
{
	if (wert=="true")
	{
		return true;
	}
	else 
	{ 
		return false; 
	}
}

//function for traversing the xml file
bool buildGraph(TiXmlElement *root,Part *part){
		
	std::string name = root->Value();
	
	if (name == "Part")
	{ 
		//get name of current Element
		Part *partName = new Part(root->Attribute("name"));
		
		//if Element is not root node add Node to parents children
		if (part != NULL)
		{
			part->addChildren(partName); 
		}
		else 
		{ 
			rootSc = partName; //node is  root node
		}
		//go one level deeper in the xml file
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	if (name == "Translate")
	{
		Translate *partName = new Translate(root->Attribute("name"),atof(root->Attribute("tx")),
											atof(root->Attribute("ty")),atof(root->Attribute("tz")));
		if (part != NULL)
		{ 
			part->addChildren(partName); 
		}
		else 
		{ 
			rootSc = partName; 
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Rotor"){
		Rotor *partName = new Rotor(root->Attribute("name"),atof(root->Attribute("winkel")),
									atof(root->Attribute("rx")),atof(root->Attribute("ry")),
									atof(root->Attribute("rz")), atof(root->Attribute("speed")), 
									isOn(root->Attribute("on")));
		if (part != NULL)
		{
			part->addChildren(partName);
		}
		else 
		{ 
			rootSc = partName;
		}
		if(!root->NoChildren()){
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Scale")
	{
		Scale *partName = new Scale(root->Attribute("name"),atof(root->Attribute("sx")),
											atof(root->Attribute("sy")),atof(root->Attribute("sz")));
		if (part != NULL)
		{ 
			part->addChildren(partName); 
		}
		else 
		{ 
			rootSc = partName; 
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Rotate")
	{
		Rotate *partName = new Rotate(root->Attribute("name"),atof(root->Attribute("winkel")),
									  atof(root->Attribute("rx")),atof(root->Attribute("ry")),
									  atof(root->Attribute("rz")));
		if (part != NULL)
		{ 
			part->addChildren(partName); 
		}
		else { rootSc = partName; }
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Jumper")
	{
		Jumper *partName = new Jumper(root->Attribute("name"),atof(root->Attribute("tx")),
									  atof(root->Attribute("ty")),atof(root->Attribute("tz")),
									  atof(root->Attribute("speed")),isOn(root->Attribute("on")));
		if (part != NULL)
		{ 
			part->addChildren(partName); 
		}
		else 
		{ 
			rootSc = partName; 
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Camera")
	{
		Camera *partName = new Camera(root->Attribute("name"),isOn(root->Attribute("on")),
									  atof(root->Attribute("fov")));
		if (part != NULL)
		{ 
			part->addChildren(partName);
		}
		else 
		{ 
			rootSc = partName; 
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	if (name == "Light")
	{
		Light *partName = new Light(root->Attribute("name"),atoi(root->Attribute("index"))
									,isOn(root->Attribute("on")), atof(root->Attribute("intensity")),
									atof(root->Attribute("position")));
		if (part != NULL)
		{ 
			part->addChildren(partName);
		}
		else 
		{ 
			rootSc = partName;
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Sphere")
	{
		Sphere *partName = new Sphere(root->Attribute("name"), root->Attribute("farbe"), 
									  atof(root->Attribute("radius")));
		if (part != NULL)
		{ 
			part->addChildren(partName); 
		}
		else { rootSc = partName;
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Teapot")
	{
		Teapot *partName = new Teapot(root->Attribute("name"), root->Attribute("farbe"), 
									  atof(root->Attribute("size")));
		if (part != NULL)
		{ 
			part->addChildren(partName);
		}
		else 
		{
			rootSc = partName;
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	if (name == "Cube")
	{
		Cube *partName = new Cube(root->Attribute("name"), root->Attribute("farbe"), 
									atof(root->Attribute("size")));
		if (part != NULL)
		{
			part->addChildren(partName);
		}
		else 
		{ 
			rootSc = partName;
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Floor")
	{
		Floor *partName = new Floor(root->Attribute("name"), root->Attribute("farbe"));
		if (part != NULL)
		{ 
			part->addChildren(partName);
		}
		else
		{
			rootSc = partName;
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	if (name == "Driving"){
		Driving *partName = new Driving(root->Attribute("name"),atof(root->Attribute("tx")),
										atof(root->Attribute("ty")),atof(root->Attribute("tz")),
										atof(root->Attribute("winkel")),atof(root->Attribute("rx")),
										atof(root->Attribute("ry")),atof(root->Attribute("rz")), 
										isOn(root->Attribute("on")));
		if (part != NULL)
		{
			part->addChildren(partName);
		}
		else 
		{ 
			rootSc = partName;
		}
		if(!root->NoChildren())
		{
			TiXmlElement *child = root->FirstChildElement();
			for( child ; child ; child=child->NextSiblingElement())
			{
				buildGraph(child,partName);
			}
		}
	}
	
	return true;
}

void InitGraph(void)
{
	//read xml
	//
	
	///-------set Path of xml file!!!------------
	TiXmlDocument xml("../../data/scene.xml");
	
	if(!xml.LoadFile()){
		printf("Error while loading file: %s\n", xml.ErrorDesc());
	}
	else{
		if(buildGraph(xml.RootElement(),0)){
			printf("-----------------\n");
			rootSc->print(0);	//print structure of xml file to console
			printf("-----------------\n");
		}
	}
	
}
void Reshape(int w, int h)
{
	w_width = w;
	w_height = h;
}


static void onIdle(void){
	//get time for animation

	dt = (glutGet(GLUT_ELAPSED_TIME)) / 500.0;
		
	glutPostRedisplay();
	
}

void Display(void)
{
	
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//start Traversal
	rootSc->simulate(dt, cx, cy, winkel1);
	rootSc->bind_camera(w_width, w_height);
	rootSc->bind_lights();
	rootSc->render();
		
	glutSwapBuffers();
	
}

//functions for user interaction; 


void Key(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
			exit(0);		//ESC for exit
			break;
		case 'r':
			InitGraph();	//r for reaload xml file
			break;
		case 'a':
			
		default:
			break;
	}
	
}

void specialKey(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
			cx -= 0.5;
			break;
			
		case GLUT_KEY_RIGHT:
			cx += 0.5;
			break;
			
		case GLUT_KEY_UP:
			cy = cy - 0.5;
			
			break;
			
		case GLUT_KEY_DOWN:
			cy = cy + 0.5;
			
			
			break;
		default:
			break;
	}
	
	glutPostRedisplay();
}

int main(int argc, char **argv)
{	
	InitGraph();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	glutInitWindowSize(w_width, w_height);
	glutCreateWindow("SceneGraph");
	glEnable( GL_NORMALIZE );
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Key);
	glutSpecialFunc(specialKey);
	glutIdleFunc(onIdle);
	
	glutMainLoop();
	
	rootSc->Part::~Part();
	
	return 0;
}
