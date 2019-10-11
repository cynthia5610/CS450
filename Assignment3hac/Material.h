/**
*	Name: Cynthia Ha
*	Class: CS 450: Computer Graphics
*	Date: October 31, 2018
*	Assignment 3 (Material.h)
**/
#ifndef MATERIAL_H
#define MATERIAL_H
#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include "glm/glm.hpp"	
#include "glm/gtx/string_cast.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <string>

using namespace std;

class Material
{
	public:
	//Constructors
		Material();
	//Public Functions
		glm::vec3 getColor();
		float getKd();
		float getKs();
		float getShine();
		float getTransmittance();
		float getIndexRefraction();
		void read(string data);
		string toString();
	private:
		//Private Data
        glm::vec3 diffuseColor = glm::vec3(1,1,1);
        float diffuseCoefficientKd = 1.0;
        float specularCoefficientKs = 1.0;
        float shininess = 1.0;
        float transmittance = 0.0;
        float refractionIndex = 1.0;
};
#endif /* MATERIAL_H */
