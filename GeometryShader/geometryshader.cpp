// assignment1.cpp : CSC 433/533 assignment 1 - Spring 2017.
//	based on the 9th edition of the OpenGL Programming Guide (red book)
//
#include "vgl.h"

#include "LoadShaders.h"

#include <iostream>
#include <vector>
using namespace std;

#ifdef __APPLE__
#include <cmath>
#endif

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint VAOs1[NumVAOs];
GLuint Buffers[1];
GLuint Buffers1[1];

const GLuint NumVertices = 6;

GLuint program;
bool keyPressedQ=false;
bool keyPressedT=false;
bool keyPressedP=false;
bool keyPressedL=false;
bool keyPressedC=false;
bool keyPressedW=false;
bool keyPressedS=false;
//bool points = false;
//bool triangle = false;
//bool line = false;
int val;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
struct VertexData1 { GLfloat color[4]; GLfloat position[4];
};

//----------------------------------------------------------------------------
//
// init
//

void init(void) {

//    GLfloat vertices[NumVertices][2] = {
//            {-0.90f, -0.90f}, {0.85f, -0.90f}, {-0.90f, 0.85f}, // Triangle 1
//            {0.90f, -0.85f},  {0.90f, 0.90f},  {-0.85f, 0.90f}  // Triangle 2
//    };
    GLfloat vertices[] = {
            0.0f,  0.50f,
            0.5f,  -0.2f,
            -0.5f, -0.2f
    };
    vector<VertexData1> verticesVec1;
    VertexData1 data1;

    data1.color[0] = 1.0f;data1.color[1]=0.0f;data1.color[2]=0.0f;data1.color[3]=1.0f;
    data1.position[0]=0.0f;data1.position[1]=0.75f;
    verticesVec1.push_back(data1);
    //verticesVec2.push_back(data2);
    data1.color[0] = 0.0f;data1.color[1]=1.0f;data1.color[2]=0.0f;data1.color[3]=1.0f;
    data1.position[0]=0.75f;data1.position[1]=-0.25f;
    verticesVec1.push_back(data1);
    //verticesVec2.push_back(data2);
    data1.color[0] = 0.0f;data1.color[1]=0.0f;data1.color[2]=1.0f;data1.color[3]=1.0f;
    data1.position[0]=-0.75f;data1.position[1]=-0.25f;
    verticesVec1.push_back(data1);
    //verticesVec2.push_back(data2);

    VertexData1 *newVertices1 = new VertexData1[3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
            newVertices1[i].color[j]=verticesVec1[i].color[j];
        for(int j=0;j<2;j++)
            newVertices1[i].position[j]=verticesVec1[i].position[j];

    }
    vector<VertexData1> verticesVec;
    VertexData1 data;

    data.color[0] = 1.0f;data.color[1]=0.0f;data.color[2]=0.0f;data.color[3]=1.0f;
    data.position[0]=0.0f;data.position[1]=0.5f;
    verticesVec.push_back(data);
    //verticesVec2.push_back(data2);
    data.color[0] = 0.0f;data.color[1]=1.0f;data.color[2]=0.0f;data.color[3]=1.0f;
    data.position[0]=0.5f;data.position[1]=-0.2f;
    verticesVec.push_back(data);
    //verticesVec2.push_back(data2);
    data.color[0] = 0.0f;data.color[1]=0.0f;data.color[2]=1.0f;data.color[3]=1.0f;
    data.position[0]=-0.5f;data.position[1]=-0.2f;
    verticesVec.push_back(data);
    //verticesVec2.push_back(data2);

    VertexData1 *newVertices = new VertexData1[3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
            newVertices[i].color[j]=verticesVec[i].color[j];
        for(int j=0;j<2;j++)
            newVertices[i].position[j]=verticesVec[i].position[j];

    }
//    glGenVertexArrays(NumVAOs, VAOs);
//    glBindVertexArray(VAOs[Triangles]);
//
//    // glCreateBuffers(NumBuffers, Buffers);		//OpenGL 4.5 method
//    glGenBuffers(NumBuffers, Buffers);
//    // glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);
//    // OpenGL 4.5 method
//    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]); // ArrayBuffer is 0
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glEnableVertexAttribArray(vPosition);
//    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0,
//                          BUFFER_OFFSET(0)); // vPosition is 0
//    glGenBuffers(2, Buffers);
//    // glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);
//    // OpenGL 4.5 method
//    glBindBuffer(GL_ARRAY_BUFFER, Buffers[1]); // ArrayBuffer is 0
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,
//                          BUFFER_OFFSET(0)); // vPosition is 0

    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);
    glGenBuffers(1, Buffers);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);

    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData1)*(3), newVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData1),
                          BUFFER_OFFSET(0));
    glVertexAttribPointer(vPosition, 2, GL_FLOAT,
                          GL_FALSE, sizeof(VertexData1), BUFFER_OFFSET(sizeof(newVertices[0].color)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    if(keyPressedP) {
        if(val == 1){
        ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "geometry.vert"},
                                {GL_FRAGMENT_SHADER, "geometry.frag"},
                                {GL_GEOMETRY_SHADER, "points.geom"},
                                {GL_NONE, NULL}};
        program = LoadShaders(shaders);}
        else{
            ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "geometry.vert"},
                                    {GL_FRAGMENT_SHADER, "geometry.frag"},
                                    {GL_GEOMETRY_SHADER, "points2.geom"},
                                    {GL_NONE, NULL}};
            program = LoadShaders(shaders);
        }
    }
    else if(keyPressedL) {
        if(val == 1){
        ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "geometry.vert"},
                                {GL_FRAGMENT_SHADER, "geometry.frag"},
                                {GL_GEOMETRY_SHADER, "lines.geom"},
                                {GL_NONE, NULL}};
        program = LoadShaders(shaders);}
        else{
            ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "geometry.vert"},
                                    {GL_FRAGMENT_SHADER, "geometry.frag"},
                                    {GL_GEOMETRY_SHADER, "lines2.geom"},
                                    {GL_NONE, NULL}};
            program = LoadShaders(shaders);
        }
    }
//    else if(keyPressedC) {
//        glGenVertexArrays(NumVAOs, VAOs1);
//        glBindVertexArray(VAOs1[Triangles]);
//        glGenBuffers(1, Buffers1);
//        glBindBuffer(GL_ARRAY_BUFFER, Buffers1[0]);
//
//        glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData1)*(3), newVertices1, GL_STATIC_DRAW);
//        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData1),
//                              BUFFER_OFFSET(0));
//        glVertexAttribPointer(vPosition, 2, GL_FLOAT,
//                              GL_FALSE, sizeof(VertexData1), BUFFER_OFFSET(sizeof(newVertices1[0].color)));
//
//        glEnableVertexAttribArray(0);
//        glEnableVertexAttribArray(1);
//        ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "triangle2.vert"},
//                                {GL_FRAGMENT_SHADER, "triangle2.frag"},
//                                {GL_NONE, NULL}};
//        program = LoadShaders(shaders);
//    }
    else if(keyPressedT){
        if(val == 2){
        ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "geometry.vert"},
                                {GL_FRAGMENT_SHADER, "geometry.frag"},
                                {GL_GEOMETRY_SHADER, "triangles2.geom"},
                                {GL_NONE, NULL}};
        program = LoadShaders(shaders);}
        else{
            ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "geometry.vert"},
                                    {GL_FRAGMENT_SHADER, "geometry.frag"},
                                    {GL_GEOMETRY_SHADER, "triangles.geom"},
                                    {GL_NONE, NULL}};
            program = LoadShaders(shaders);
        }
    }
    else
    {
        glGenVertexArrays(NumVAOs, VAOs1);
        glBindVertexArray(VAOs1[Triangles]);
        glGenBuffers(1, Buffers1);
        glBindBuffer(GL_ARRAY_BUFFER, Buffers1[0]);

        glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData1)*(3), newVertices1, GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData1),
                              BUFFER_OFFSET(0));
        glVertexAttribPointer(vPosition, 2, GL_FLOAT,
                              GL_FALSE, sizeof(VertexData1), BUFFER_OFFSET(sizeof(newVertices1[0].color)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        ShaderInfo shaders[] = {{GL_VERTEX_SHADER,   "triangle2.vert"},
                                {GL_FRAGMENT_SHADER, "triangle2.frag"},
                                {GL_NONE, NULL}};
        program = LoadShaders(shaders);
    }
    if (program == NULL) {
        cerr << "Failed shader load" << endl;
    }
    glUseProgram(program);
}

//----------------------------------------------------------------------------
//
// display
//

void display(void) {
    static const float black[] = {0.0f, 0.0f, 0.0f, 0.0f};

    glClearBufferfv(GL_COLOR, 0, black);

    glUseProgram(program);

    if(keyPressedW)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if(keyPressedC)
    {
        glBindVertexArray(VAOs1[Triangles]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    } else if(val ==2){
        glBindVertexArray(VAOs[Triangles]);
        glDrawArrays(GL_TRIANGLES,0,3);
    }
    else if(val == 1)
    {
        glBindVertexArray(VAOs[Triangles]);
        glDrawArrays(GL_POINTS,0,3);
    } else{
        glBindVertexArray(VAOs1[Triangles]);
        glDrawArrays(GL_TRIANGLES,0,3);
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

    GLFWwindow *window = glfwCreateWindow(800, 800, "GeometryShader", NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window,key_callback);
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
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if ((key == GLFW_KEY_Q || key == GLFW_KEY_ESCAPE) && action == GLFW_PRESS) {
        if (keyPressedQ == false)
            keyPressedQ = true;
    }
    if ((key == GLFW_KEY_W) && action == GLFW_PRESS) {
        if (keyPressedW == false){
            keyPressedW = true;
            keyPressedS = false;
           }
    }
    if ((key == GLFW_KEY_S) && action == GLFW_PRESS) {
        if (keyPressedS == false){
            keyPressedS = true;
            keyPressedW = false;
   }
    }
    if ((key == GLFW_KEY_T) && action == GLFW_PRESS) {
            cout<<"You have selected Triangle as the output primitive"<<endl;
            cout<<"choose the input primitive"<<endl<<"1. Points"<<endl<<"2. Triangles"<<endl;
            cin>>val;
            keyPressedL = false;
            keyPressedT = true;
            keyPressedP = false;
            keyPressedC = false;
            init();
    }
    if ((key == GLFW_KEY_P) && action == GLFW_PRESS) {
            cout<<"You have selected Points as the output primitive"<<endl;
            cout<<"choose the input primitive"<<endl<<"1. Points"<<endl<<"2. Triangles"<<endl;
            cin>>val;
            keyPressedL = false;
            keyPressedT = false;
            keyPressedP = true;
            keyPressedC = false;
            init();
    }
    if ((key == GLFW_KEY_L) && action == GLFW_PRESS) {
            cout<<"You have selected Lines as the output primitive"<<endl;
            cout<<"choose the input primitive"<<endl<<"1. Points"<<endl<<"2. Triangles"<<endl;
            cin>>val;
            keyPressedL = true;
            keyPressedT = false;
            keyPressedP = false;
            keyPressedC = false;
            init();
    }
    if ((key == GLFW_KEY_C) && action == GLFW_PRESS) {
        if (keyPressedC == false){
            keyPressedL = false;
            keyPressedT = false;
            keyPressedP = false;
            keyPressedC = true;
            init();}
    }
}