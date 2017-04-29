#version 410 core

 layout(triangles) in;
layout(points, max_vertices = 9) out;
in vec4 fcolor[3];
out vec4 color;
int i=0;

    void main()
    {
        for(i=0; i<3; i++)
        {
        gl_Position = gl_in[i].gl_Position + vec4(-0.4, -0.2, 0.0, 0.0);
        color = fcolor[i];
        EmitVertex();

        gl_Position = gl_in[i].gl_Position + vec4(0.4, -0.2, 0.0, 0.0);
        color = fcolor[i];
        EmitVertex();

        gl_Position = gl_in[i].gl_Position + vec4(0.0, 0.4, 0.0, 0.0);
        color = fcolor[i];
        EmitVertex();

        }
        EndPrimitive();
    }