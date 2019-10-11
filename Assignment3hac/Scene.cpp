/**
*	Name: Cynthia Ha
*	Class: CS 450: Computer Graphics
*	Date: October 31, 2018
*   Modified Date: December 6, 2018
*	Assignment 3/4 (Scene.cpp)
**/
#include "Scene.h"
#include <glm/vec3.hpp> // glm::vec3
#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include <sstream>
#define GLM_ENABLE_EXPERIMENTAL

using namespace std;

//-------------------Constructors------------------//
Scene::Scene(){} //Default Constructor

//-------------------Destructors------------------//
Scene::~Scene() { cleanup(); }

//------------------Public Methods----------------//
int Scene::getLightCnt() { return allLights.size(); }
int Scene::getSurfaceCnt() { return allSpheres.size(); }
int Scene::getMaterialCnt() { return allMaterials.size(); }
float* Scene::getImageBuffer() { return imgBuffer; }
int Scene::getBufferWidth() { return bufferWidth; }
int Scene::getBufferHeight() { return bufferHeight; }

string Scene::toString()
{
    return "b " + to_string(backgroundColor.r) + " " + to_string(backgroundColor.g) + " " + to_string(backgroundColor.b) + "\n";
}

bool Scene::loadNFF(string filename, int windowWidth, int windowHeight)
{
    string line;
    ifstream file (filename);

    if (!file.is_open()) { return false; }
    else 
    {
        cleanup();
        int currentMatIndex = -1;
        while(!file.eof()) 
        {
            getline(file, line);
            stringstream ss(line);
            string word = "z";
            ss >> word;

            if (word.compare("l") == 0) 
            {
                Light *light;
                light = new Light();
                light->read(line);
                allLights.push_back(light);
            }
            else if (word.compare("s") == 0) 
            {
                Sphere *sphere;
                sphere = new Sphere();
                sphere->read(line);
                sphere->setMaterialIndex(currentMatIndex);
                allSpheres.push_back(sphere);
            }
            else if (word.compare("f") == 0) 
            {
                Material *material;
                material = new Material();
                material->read(line);
                allMaterials.push_back(material);
                currentMatIndex++;
            }
            else if (word.compare("b") == 0) 
            {
                ss >> backgroundColor.r;
                ss >> backgroundColor.g;
                ss >> backgroundColor.b;
            }
            else { } //No else given
        }
        file.close();
        bufferWidth = windowWidth;
        bufferHeight = windowHeight;

        return true;
    }
}

//------------------Private Methods----------------//
void Scene::cleanup() 
{
    int lights = getLightCnt();
    int spheres = getSurfaceCnt();
    int materials = getMaterialCnt();

    allLights.erase(allLights.begin(), allLights.begin() + lights);
    allSpheres.erase(allSpheres.begin(), allSpheres.begin() + spheres);
    allMaterials.erase(allMaterials.begin(), allMaterials.begin() + materials);

    if (!allLights.empty() || !allSpheres.empty() || !allMaterials.empty()) { cout << "Not Empty\n"; }

    allLights.clear();
    allMaterials.clear();
    allSpheres.clear();

    if (imgBuffer != NULL) 
    {
        memset(imgBuffer, 0, sizeof(imgBuffer));
        imgBuffer = NULL;
    }
}


