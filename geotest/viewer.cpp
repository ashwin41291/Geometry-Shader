// assignment1.cpp : CSC 433/533 assignment 1 - Spring 2017.
//	based on the 9th edition of the OpenGL Programming Guide (red book)
//
#include "vgl.h"

#include "LoadShaders.h"
#include "loadObj.h"
#include "ReadScene.h"
#include <iostream>
using namespace std;
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

// include glm extensions
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>
using namespace glm;

#ifdef __APPLE__
#include <cmath>

#endif

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void window_size_callback(GLFWwindow* window, int width, int height);
GLuint program;
objInfo *object1;
int count1;
ReadScene scene;
mat4 viewmatrix,staticview;
vec3 staticeye, staticcenter, staticviewup;
vector<objectinfo> objects;
vector<objInfo> objinfos;
bool keyPressedA=false;
bool keyPressedR=false;
bool keyPressedT=false;
bool keyPressedX=false;
bool keyPressedP=false;
bool keyPressedZ=false;
bool keyPressedQ=false;
bool keyPressedC=false;
bool keyPressedO=false;
bool keyPressedW=false;
bool keyPressedS=false;
bool keyPressedD=false;
bool keyPressedV=false;
string name;
int windowWidth = 800;
int windowHeight = 800;
mat4 projectionmatrix;
float aspect = 1.0f;
float boundsval;

//----------------------------------------------------------------------------
//
// init
//

void init(void) {

    ShaderInfo shaders[] = {{GL_VERTEX_SHADER, "BlinnPhong.vert"},
                            {GL_FRAGMENT_SHADER, "BlinnPhong.frag"},
                            {GL_GEOMETRY_SHADER, "geometry.geom"},
                            {GL_NONE, NULL}};

    program = LoadShaders(shaders);
    if (program == NULL) {
        cerr << "Failed shader load" << endl;
    }
    glUseProgram(program);
    scene = readFile(name);
    objects = scene.obj;
    for(int i = 0;i < objects.size();i++)
    {
        string str = scene.obj[i].name;
        char* p = new char[str.length()+1];
        memcpy(p, str.c_str(), str.length()+1);
        loadObjFile(p, &object1, &count1);
        for (int j = 0; j < count1; j++)
        {
            object1[j].modelMatrix = objects[i].modelmatrix;
            objinfos.push_back(object1[j]);
        }
    }
    viewmatrix = lookAt(vec3(scene.eye), vec3(scene.center), vec3(scene.viewup));
    staticview = viewmatrix;
    staticeye = scene.eye;
    staticcenter = scene.center;
    staticviewup = scene.viewup;
    if(abs(objinfos[0].bounds[4] + objinfos[0].bounds[5])>6)
    {
        boundsval = 5.0f;
    }
    else{
        boundsval = 1.0f;
    }
}

//----------------------------------------------------------------------------
//
// display
//

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    static const float black[] = {1, 1, 1, 0.0f};

    glClearBufferfv(GL_COLOR, 0, black);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    glUseProgram(program);
    if(!keyPressedO){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if(keyPressedO){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if(keyPressedP){
        viewmatrix = staticview;
        scene.eye = staticeye;
        scene.center = staticcenter;
        scene.viewup = staticviewup;
        keyPressedP = false;
    }
    if(keyPressedW)
    {
        vec3 gaze = scene.center - scene.eye;
        scene.eye = scene.eye + 0.1f * gaze;
        scene.center = scene.center + 0.1f * gaze;
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedW = false;
    }
    if(keyPressedS)
    {
        vec3 gaze = scene.center - scene.eye;
        scene.eye = scene.eye - 0.1f * gaze;
        scene.center = scene.center - 0.1f * gaze;
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedS = false;
    }
    if(keyPressedA)
    {
        vec3 gaze = -(scene.center - scene.eye);
        vec3 left = cross(scene.viewup, gaze);
        scene.eye = scene.eye - 0.1f * left;
        scene.center = scene.center - 0.1f * left;
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedA = false;
    }
    if(keyPressedD)
    {
        vec3 gaze = -(scene.center - scene.eye);
        vec3 right = cross(scene.viewup, gaze);
        scene.eye = scene.eye + 0.1f * right;
        scene.center = scene.center + 0.1f * right;
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedD = false;
    }
    if(keyPressedX){
        mat4 temp = rotate(mat4(1.0), -1.0f*3.14159f / 180.0f, scene.viewup);
        scene.eye = vec3(temp * vec4(scene.eye, 1.0f));
        scene.center = vec3(temp * vec4(scene.center, 1.0f));
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedX = false;
    }
    if(keyPressedZ){
        mat4 temp = rotate(mat4(1.0), 1.0f*3.14159f / 180.0f, scene.viewup);
        scene.eye = vec3(temp * vec4(scene.eye, 1.0f));
        scene.center = vec3(temp * vec4(scene.center, 1.0f));
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedZ = false;
    }
    if(keyPressedC){
        vec3 gaze = scene.center - scene.eye;
        mat4 temp = rotate(mat4(1.0), 1.0f*3.14159f / 180.0f, gaze);
        scene.viewup = vec3(temp * vec4(scene.viewup,1.0f));
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedC = false;
    }
    if(keyPressedV){
        vec3 gaze = scene.center - scene.eye;
        mat4 temp = rotate(mat4(1.0), -1.0f*3.14159f / 180.0f, gaze);
        scene.viewup = vec3(temp * vec4(scene.viewup,1.0f));
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedV = false;
    }
    if(keyPressedR)
    {
        scene.eye = scene.eye + boundsval * scene.viewup;
        scene.center = scene.center + boundsval * scene.viewup;
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedR = false;
    }
    if(keyPressedT)
    {
        scene.eye = scene.eye - boundsval * scene.viewup;
        scene.center = scene.center - boundsval * scene.viewup;
        viewmatrix = lookAt(scene.eye, scene.center, scene.viewup);
        keyPressedT = false;
    }
    projectionmatrix = perspective(45.0f, aspect, 1.5f, 3200.f);
    for(int j=0; j<objinfos.size(); j++)
    {
        objInfo obj = objinfos[j];
        GLuint loc;
        mat4 mvpmatrix = projectionmatrix * viewmatrix * obj.modelMatrix;
        vec3 temp1;
        glBindVertexArray(obj.VAO);
        for (int i = 0;i <= scene.number;i++)
        {
            lightProperties temp = scene.lightvalues[i];
            if(temp.isLocal != 0){
                vec4 posvec(temp.position, 1.0);
                vec4 temp2 = viewmatrix * posvec;
                temp1 = vec3(temp2);
                temp.position.x = temp2.x;
                temp.position.y = temp2.y;
                temp.position.z = temp2.z;}
            else{
                temp1 = mat3(viewmatrix)*temp.position;
                temp.position.x = temp1.x;
                temp.position.y = temp1.y;
                temp.position.z = temp1.z;
            }
            GLuint loc;
            char uniformName[50];
            sprintf(uniformName, "Lights[%1d].isEnabled", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1i(loc, temp.isEnabled);

            sprintf(uniformName, "Lights[%1d].isLocal", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1i(loc, temp.isLocal);

            sprintf(uniformName, "Lights[%1d].isSpot", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1i(loc, temp.isSpot);

            sprintf(uniformName, "Lights[%1d].ambient", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform3f(loc, temp.ambient.x, temp.ambient.y,
                        temp.ambient.z);

            sprintf(uniformName, "Lights[%1d].color", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform3f(loc, temp.color.x, temp.color.y,
                        temp.color.z);

            sprintf(uniformName, "Lights[%1d].position", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform3f(loc, temp1.x, temp1.y,
                        temp1.z);

            sprintf(uniformName, "Lights[%1d].halfVector", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform3f(loc, temp.halfVector.x, temp.halfVector.y,
                        temp.halfVector.z);

            sprintf(uniformName, "Lights[%1d].coneDirection", i);
            loc = glGetUniformLocation(program, uniformName);
            vec3 temp1 = mat3(viewmatrix)*temp.coneDirection;
            glUniform3f(loc, temp1.x, temp1.y, temp1.z);

            sprintf(uniformName, "Lights[%1d].spotCosCutoff", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1f(loc, temp.spotCosCutoff);

            sprintf(uniformName, "Lights[%1d].spotExponent", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1f(loc, temp.spotExponent);

            sprintf(uniformName, "Lights[%1d].constantAtteuation", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1f(loc, temp.constantAttenuation);

            sprintf(uniformName, "Lights[%1d].linearAttenuation", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1f(loc, temp.linearAttenuation);

            sprintf(uniformName, "Lights[%1d].quadraticAttenuation", i);
            loc = glGetUniformLocation(program, uniformName);
            glUniform1f(loc, temp.quadraticAttenuation);
        }

        loc = glGetUniformLocation(program, "MVPMatrix");
        glUniformMatrix4fv(loc, 1, false, glm::value_ptr(mvpmatrix));

        mat4 mvmatrix = viewmatrix * obj.modelMatrix;
        loc = glGetUniformLocation(program, "MVMatrix");
        glUniformMatrix4fv(loc, 1, false, glm::value_ptr(mvmatrix));

        mat3 normalmatrix = mat3(mvmatrix);
        loc = glGetUniformLocation(program, "NormalMatrix");
        glUniformMatrix3fv(loc, 1, false, glm::value_ptr(normalmatrix));


        loc = glGetUniformLocation(program, "ambient");
        glUniform3f(loc, obj.Ka.r, obj.Ka.g, obj.Ka.b);

        loc = glGetUniformLocation(program, "diffuse");
        glUniform3f(loc, obj.Kd.r, obj.Kd.g, obj.Kd.b);

        loc = glGetUniformLocation(program, "specular");
        glUniform3f(loc, obj.Ks.r, obj.Ks.g, obj.Ks.b);

        loc = glGetUniformLocation(program, "shininess");
        glUniform1f(loc, obj.n);


        glDrawArrays(GL_TRIANGLES, 0, obj.VAOsize);
    }

}

//----------------------------------------------------------------------------
//
// main
//

#undef _WIN32
#ifdef _WIN32
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance,
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
#else
int main(int argc, char **argv)
#endif
{
    glfwInit();

#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 4.1 latest version of OpenGL for OSX 10.9 Mavericks
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Geometry Shader", NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window,key_callback);
    //glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
    glfwSetWindowSizeCallback(window, window_size_callback);

    gl3wInit();

#define CHECK_VERSION
#ifdef CHECK_VERSION
    // code from OpenGL 4 Shading Language cookbook, second edition
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *vendor = glGetString(GL_VENDOR);
    const GLubyte *version = glGetString(GL_VERSION);
    const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    cout << "GL Vendor            :" << vendor << endl;
    cout << "GL Renderer          :" << renderer << endl;
    cout << "GL Version (string)  :" << version << endl;
    cout << "GL Version (integer) :" << major << " " << minor << endl;
    cout << "GLSL Version         :" << glslVersion << endl;
    cout << "major version: " << major << "  minor version: " << minor << endl;
#endif
    name = argv[1];
    init();

    while (!glfwWindowShouldClose(window)) {
        if(keyPressedQ)
        {
            break;
        }
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    aspect =(float) (width)/(float)(height);
    if(aspect<1.0f)
    {
        aspect = 1.0f;
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if ((key == GLFW_KEY_Q || key == GLFW_KEY_ESCAPE) && action == GLFW_PRESS) {
        if (keyPressedQ == false)
            keyPressedQ = true;
    }

    if (key == GLFW_KEY_P && action == GLFW_PRESS) {
        if (keyPressedP == false)
            keyPressedP = true;
    }

    if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        if (keyPressedO == false)
            keyPressedO = true;
        else
            keyPressedO = false;
    }

    if ((key == GLFW_KEY_W || key == GLFW_KEY_UP) && action != GLFW_RELEASE) {
        if (keyPressedW == false)
            keyPressedW = true;
    }

    if ((key == GLFW_KEY_A || key == GLFW_KEY_LEFT) && action != GLFW_RELEASE) {
        if (keyPressedA == false)
            keyPressedA = true;
    }

    if ((key == GLFW_KEY_S || key == GLFW_KEY_DOWN) && action != GLFW_RELEASE) {
        if (keyPressedS == false)
            keyPressedS = true;
    }

    if ((key == GLFW_KEY_D || key == GLFW_KEY_RIGHT) && action != GLFW_RELEASE) {
        if (keyPressedD == false)
            keyPressedD = true;
    }

    if (key == GLFW_KEY_R && action != GLFW_RELEASE) {
        if (keyPressedR == false)
            keyPressedR = true;
    }

    if (key == GLFW_KEY_T && action != GLFW_RELEASE) {
        if (keyPressedT == false)
            keyPressedT = true;
    }

    if (key == GLFW_KEY_X && action != GLFW_RELEASE) {
        if (keyPressedX == false)
            keyPressedX = true;
    }

    if (key == GLFW_KEY_Z && action != GLFW_RELEASE) {
        if (keyPressedZ == false)
            keyPressedZ = true;
    }

    if (key == GLFW_KEY_C && action != GLFW_RELEASE) {
        if (keyPressedC == false)
            keyPressedC = true;
    }

    if (key == GLFW_KEY_V && action != GLFW_RELEASE) {
        if (keyPressedV == false)
            keyPressedV = true;
    }
}
