/**
*	Name: Cynthia Ha
*	Date: September 20, 2018
*	Class: CS 450: Computer Graphics
*	Assignment 2 (Light.h)
**/
#ifndef LIGHT_H
#define LIGHT_H
#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include "glm/glm.hpp"	
#include "glm/gtx/string_cast.hpp"
#include <glm/vec3.hpp> // glm::vec3

using namespace std;

class Light
{
	public:
	//Constructors
		Light();
		Light(glm::vec3 pos);
		Light(glm::vec3 pos, glm::vec3 color);
	//Public Functions
		glm::vec3 getPos();
		glm::vec3 getColor();
		void read(string data);
		string toString();
	private:
		//Private Data
        glm::vec3 position = glm::vec3(0,0,0);
        glm::vec3 color = glm::vec3(1,1,1);
};
#endif /* LIGHT_H */
