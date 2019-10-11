/**
*	Name: Cynthia Ha
*	Date: September 20, 2018
*	Class: CS 450: Computer Graphics
*	Assignment 2 (Light.cpp)
**/

#include "Light.h"
#include <glm/vec3.hpp> // glm::vec3
#include <string>
#include <cstring> 
#include <sstream>
#define GLM_ENABLE_EXPERIMENTAL //Needed for error mssg

using namespace std;

//-------------------Constructors------------------//
Light::Light(){} //Default Constructor

Light::Light(glm::vec3 pos) //Only position given
{
	position = glm::vec3(pos);
}

Light::Light(glm::vec3 pos, glm::vec3 color) //Both position and color given
{
	position = glm::vec3(pos);
	this->color = glm::vec3(color);
}

//------------------Public Methods----------------//
glm::vec3 Light::getPos(){ return position; }

glm::vec3 Light::getColor(){ return color; }

void Light::read(string data)
{
	stringstream ss(data);
	char str[100];
	ss >> str;
	ss >> position.x >> position.y >> position.z;
	if(ss >> color.r) //Check to see if there is color.r
		ss >> color.g >> color.b; 
	else
	{
		color.r = 1;
		color.g = 1;
		color.b = 1;
	}
	return;
}

string Light::toString()
{
    glm::vec3 position = getPos();
    glm::vec3 color = getColor();
    return "l " + to_string(position.x) + " " + to_string(position.y) + " " + to_string(position.z) + " " + to_string(color.r) + " " + to_string(color.g) + " " + to_string(color.b);
}
