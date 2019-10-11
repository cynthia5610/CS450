/**
*	Name: Cynthia Ha
*	Date: September 20, 2018
*	Modified: October 31, 2018
*	Class: CS 450: Computer Graphics
*	Assignment 2 (Sphere.h)
**/

#ifndef SPHERE_H
#define SPHERE_H
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/vec3.hpp> // glm::vec3
#include <string>
#include <cstring> 
#include <sstream>

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
