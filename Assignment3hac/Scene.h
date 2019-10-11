/**
*	Name: Cynthia Ha
*	Class: CS 450: Computer Graphics
*	Date: October 31, 2018
*	Assignment 3 (Scene.h)
**/
#ifndef SCENE_H
#define SCENE_H
#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include "glm/glm.hpp"					// NOTE: Need to compile, hence the quotes
#include "glm/gtx/string_cast.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <string>
#include "Light.h"
#include "Sphere.h"
#include "Material.h"
#include <vector>

using namespace std;

class Scene
{
	public:
	//Constructors
		Scene();
	//Destructors
		~Scene();
	//Public Functions
		int getLightCnt();
	    int getSurfaceCnt();
	    int getMaterialCnt();
	    int getBufferWidth();
	    int getBufferHeight();
	    float* getImageBuffer();		
		string toString();
		bool loadNFF(string filename, int windowWidth, int windowHeight);
	private:
		//Private Data
	    std::vector<Light*> allLights;
	    std::vector<Material*> allMaterials;
	    std::vector<Sphere*> allSpheres;
	    float* imgBuffer = NULL;
	    int bufferWidth = 0;
	    int bufferHeight = 0;
	    glm::vec3 backgroundColor = glm::vec3(0,0,0);
        //Private Functions
        void cleanup();
};
#endif /* SCENE_H */