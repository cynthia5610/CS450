/**
*	Name: Cynthia Ha
*	Class: CS 450: Computer Graphics
**************************************************
*	Date: September 20, 2018
*	Assignment 2 (Sphere.cpp)
*	Modified: October 31, 2018
*	Assignment 3 (Sphere.cpp)
* 	Modified: December 6, 2018
*	Assignment 4 (Sphere.cpp)
**************************************************
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

bool Sphere::getIntersection(glm::vec3 rayStart, glm::vec3 rayDir, HitRecord &record) 
{
    double tVal = 0;
    glm::vec3 circleVector = rayStart-getCenter();
    double rayDirDot = glm::dot(rayDir, rayDir);
    double discriminate = (pow(glm::dot(rayDir, circleVector), 2)) - rayDirDot * (glm::dot(circleVector, circleVector) - pow(getRadius(),2));
    if(discriminate < 0) { return false; }
    else 
    {
        tVal = (glm::dot(-rayDir, circleVector) - sqrt(discriminate))/ rayDirDot;
        glm::vec3 recordPoint = rayStart+(rayDir*float(tVal));
        record.setPoint(recordPoint);
        record.setT(tVal);
        record.setMatIndex(getMaterialIndex());
        record.setNormal(glm::normalize(recordPoint-getCenter()));
        return true;
    }
}