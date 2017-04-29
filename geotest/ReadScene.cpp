//
// Created by Ashwin S on 2/15/17.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "ReadScene.h"

using namespace std;
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

// include glm extensions
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>
#include "loadObj.h"

using namespace glm;

ReadScene readFile(string fileName)
{
    ifstream myReadFile;
    myReadFile.open(fileName);
    string output;
    string final;
    int number = -1;
    vector<string> v;
    vector<string> obj;
    lightProperties light;
    ReadScene scene;
    vec3 eye,center,viewup;
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            v.push_back(output);
        }
    }
    else{
        cout<<"No file found. Check the filename"<<endl;
    }
    myReadFile.close();
    for(int i=0;i<v.size();i++) {
        //cout << v[i] << endl;
        if (v[i] == "view")
        {
            eye.x = stof(v[i+2]);
            eye.y = stof(v[i+3]);
            eye.z = stof(v[i+4]);

            center.x = stof(v[i+6]);
            center.y = stof(v[i+7]);
            center.z = stof(v[i+8]);

            viewup.x = stof(v[i+10]);
            viewup.y = stof(v[i+11]);
            viewup.z = stof(v[i+12]);

            scene.eye = eye;
            scene.center = center;
            scene.viewup = viewup;

        }
        else if(v[i] == "light")
        {
            number = number+1;
            for(int j=i+1; j<v.size();j++)
            {
                if(v[j] == "light")
                {
                    break;
                }
                if(v[j] == "type")
                {
                    if (v[j+1] == "directional")
                        light.isLocal = 0;
                    else if (v[j+1] == "spot"){
                        light.isSpot = 1;
                        light.isLocal = 1;}
                    else
                        light.isLocal = 1;
                }
                if(v[j] == "ambient")
                {
                    light.ambient.x = stof(v[j+1]);
                    light.ambient.y = stof(v[j+2]);
                    light.ambient.z = stof(v[j+3]);
                }
                if(v[j] == "color")
                {
                    light.color.x = stof(v[j+1]);
                    light.color.y = stof(v[j+2]);
                    light.color.z = stof(v[j+3]);
                }
                if(v[j] == "position")
                {
                    light.position.x = stof(v[j+1]);
                    light.position.y = stof(v[j+2]);
                    light.position.z = stof(v[j+3]);
                }
                if(v[j] == "constAtt")
                {
                    light.constantAttenuation = stof(v[j+1]);
                }
                if(v[j] == "linearAtt")
                {
                    light.linearAttenuation = stof(v[j+1]);
                }
                if(v[j] == "quadAtt")
                {
                    light.quadraticAttenuation = stof(v[j+1]);
                }
                if(v[j] == "coneDirection")
                {
                    light.coneDirection.x = stof(v[j+1]);
                    light.coneDirection.y = stof(v[j+2]);
                    light.coneDirection.z = stof(v[j+3]);
                }
                if(v[j] == "spotCosCutoff")
                {
                    light.spotCosCutoff = stof(v[j+1]);
                }
                if(v[j] == "spotExponent")
                {
                    light.spotExponent = stof(v[j+1]);
                }
            }
            light.isEnabled = 1;
            scene.lightvalues[number].ambient = vec3(0,0,0);
            scene.lightvalues[number].color = vec3(0,0,0);
            scene.lightvalues[number].coneDirection = vec3(0,0,0);
            scene.lightvalues[number].constantAttenuation = 0.0f;
            scene.lightvalues[number].halfVector = vec3(0,0,0);
            scene.lightvalues[number].isEnabled = 0;
            scene.lightvalues[number].isLocal = 0;
            scene.lightvalues[number].isSpot = 0;
            scene.lightvalues[number].linearAttenuation = 0.0f;
            scene.lightvalues[number].position = vec3(0,0,0);
            scene.lightvalues[number].quadraticAttenuation = 0.0f;
            scene.lightvalues[number].spotCosCutoff = 0.0f;
            scene.lightvalues[number].spotExponent = 0.0f;
            scene.lightvalues[number] = light;
        }
        else if(v[i] == "object")
        {
            objectinfo object;
            mat4 modelmatrix(1.0);
            object.name = v[i+1];
            for(int j= i+1; j<v.size();j++)
            {
                if(v[j] == "object")
                {
                    break;
                }
                if(v[j] == "shader")
                {
                   object.shader = v[j+1];
                }
                if(v[j] == "rx")
                {
                    object.rx = stof(v[j+1]);
                    vec3 axis;
                    axis.x = 1.0f; axis.y = 0.0f; axis.z = 0.0f;
                    mat4 rotmatrix = glm::rotate(mat4(), object.rx*3.14159f / 180.f, axis);
                    modelmatrix = rotmatrix  * modelmatrix;
                }
                if(v[j] == "ry")
                {
                    object.ry = stof(v[j+1]);
                    vec3 axis;
                    axis.x = 0.0f; axis.y = 1.0f; axis.z = 0.0f;
                    mat4 rotmatrix = glm::rotate(mat4(), object.ry*3.14159f / 180.f, axis);
                    modelmatrix = rotmatrix  * modelmatrix;
                }
                if(v[j] == "rz")
                {
                    object.rz = stof(v[j+1]);
                    vec3 axis;
                    axis.x = 0.0f; axis.y = 0.0f; axis.z = 1.0f;
                    mat4 rotmatrix = glm::rotate(mat4(), object.rz*3.14159f / 180.f, axis);
                    modelmatrix = rotmatrix  * modelmatrix;
                }
                if(v[j] == "t")
                {
                    object.translate.x = stof(v[j+1]);
                    object.translate.y = stof(v[j+2]);
                    object.translate.z = stof(v[j+3]);
                    mat4 translatematrix = glm::translate(mat4(), object.translate);
                    modelmatrix =translatematrix  * modelmatrix;
                }
                if(v[j] == "s")
                {
                    object.scale.x = stof(v[j+1]);
                    object.scale.y = stof(v[j+2]);
                    object.scale.z = stof(v[j+3]);
                    mat4 scalematrix = glm::scale(mat4(), object.scale);
                    modelmatrix =scalematrix * modelmatrix;
                }
            }
            object.modelmatrix = modelmatrix;
            scene.obj.push_back(object);
        }
    }
    scene.number = number;
    return scene;
}
