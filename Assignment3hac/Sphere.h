/**
*	Name: Cynthia Ha
*	Class: CS 450: Computer Graphics
**************************************************
*	Date: September 20, 2018
*	Assignment 2 (Sphere.cpp)
*	Modified: October 31, 2018
*	Assignment 3 (Sphere.cpp)
**************************************************
**/

#ifndef SPHERE_H
#define SPHERE_H
#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include "glm/glm.hpp"					// NOTE: Need to compile, hence the quotes
#include "glm/gtx/string_cast.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <string>


using namespace std;

class Sphere
{
	public:
	//Constructors
		Sphere();
		Sphere(glm::vec3 center, double radius);
	//Public functions
		glm::vec3 getCenter();
		double getRadius();
		void read(string data);
		string toString();
		void setMaterialIndex(int matIndex);
		int getMaterialIndex();
	private:
		//Private Data
		glm::vec3 center = glm::vec3(0,0,0);
		double radius = 1.0;
		int matIndex = -1;
};
#endif /* SPHERE_H */
