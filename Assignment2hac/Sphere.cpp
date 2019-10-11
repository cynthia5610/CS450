/**
*	Name: Cynthia Ha
*	Date: September 20, 2018
*	Modified: October 31, 2018
*	Class: CS 450: Computer Graphics
*	Assignment 2 (Sphere.cpp)
**/

#include "Sphere.h"
#include <glm/vec3.hpp> // glm::vec3
#include <string>
#include <cstring> 
#include <sstream>
#define GLM_ENABLE_EXPERIMENTAL 

using namespace std;


//-------------------Constructors------------------//
Sphere::Sphere() {}
Sphere::Sphere(glm::vec3 center, double radius)
{
	this->center = glm::vec3(center);
	this->radius = radius;
}

//------------------Public Methods----------------//
glm::vec3 Sphere::getCenter()
{
	return center;
}

double Sphere::getRadius()
{
	return radius;
}

void Sphere::read(string data)
{
	stringstream ss(data);
	char str[100];

	ss >> str;
	ss >> center.x >> center.y >> center.z >> radius;
	return;
}

string Sphere::toString()
{
	glm::vec3 center = getCenter();
	return "s " + to_string(center.x) + " " + to_string(center.y) + " " + to_string(center.z) + " " + to_string(getRadius());
}

void Sphere::setMaterialIndex(int matIndex)
{
	this->matIndex = matIndex;
	return;
}

int Sphere::getMaterialIndex()
{
	return matIndex;
}