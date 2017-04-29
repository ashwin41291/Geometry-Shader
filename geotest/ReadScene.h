//
// Created by Ashwin S on 2/15/17.
//

#ifndef ASSIGNMENT2_READSCENE_H
#define ASSIGNMENT2_READSCENE_H


#include <string>
#include "loadObj.h"

//lightProperties light[4];

class objectinfo
{
public:
    string name;
    string shader;
    float rx,ry,rz;
    vec3 translate;
    vec3 scale;
    mat4 modelmatrix;
};

class ReadScene
{
public:
    lightProperties lightvalues[4];
    vec3 eye;
    vec3 center;
    vec3 viewup;
    int number;
    vector<objectinfo> obj;

};


ReadScene readFile(string fileName);

#endif //ASSIGNMENT2_READSCENE_H