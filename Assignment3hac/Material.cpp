/**
*	Name: Cynthia Ha
*	Class: CS 450: Computer Graphics
*	Date: October 31, 2018
*	Assignment 3 (Material.cpp)
**/
#include "Material.h"
#include <glm/vec3.hpp> //glm.vec3
#include <string>
#include <cstring>
#include <sstream>
#define GLM_ENABLE_EXPERIMENTAL

using namespace std;


//-------------------Constructors------------------//
Material::Material(){} //Default Constructor

//------------------Public Methods----------------//
glm::vec3 Material::getColor(){ return diffuseColor; }
float Material::getKd() { return diffuseCoefficientKd; }
float Material::getKs() { return specularCoefficientKs; }
float Material::getShine() { return shininess; }
float Material::getTransmittance() { return transmittance; }
float Material::getIndexRefraction() { return refractionIndex; }

void Material::read(string data)
{
	stringstream ss(data);
	char str[100];
	ss >> str;
	ss >> diffuseColor.r >> diffuseColor.g >> diffuseColor.b;
	ss >> diffuseCoefficientKd;
	ss >> specularCoefficientKs;
	ss >> shininess;
	ss >> transmittance;
	ss >> refractionIndex;
	return;
}

string Material::toString()
{
    glm::vec3 color = getColor();
    return "f " + to_string(color.r) + " " + to_string(color.g) + " " + to_string(color.b) + " " + to_string(getKd()) + " " + to_string(getKs()) + " " + to_string(getShine()) + " " + to_string(getTransmittance())  + " " + to_string(getIndexRefraction());
}
