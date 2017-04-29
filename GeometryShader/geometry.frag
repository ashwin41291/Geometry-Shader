#version 410 core
in vec4 color;
out vec4 fColor;

void main()
{
    //fColor = vec4(1.0,0.0,0.0, 1.0);
    fColor = color;
    //fColor[0] = color[0];
    //fColor[1] = color[1];
    //fColor[2] = color[2];
}