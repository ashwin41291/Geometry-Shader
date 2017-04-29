#version 410 core

 layout(points) in;
layout(line_strip, max_vertices = 4) out;
int i=0;
in vec4 fcolor[1];
out vec4 color;
    void main()
    {
//        for(i=0; i<2; i++)
//        {
        gl_Position = gl_in[0].gl_Position + vec4(-0.4, -0.2, 0.0, 0.0);
        color = fcolor[0];
        EmitVertex();

        gl_Position = gl_in[0].gl_Position + vec4(0.4, -0.2, 0.0, 0.0);
        color = fcolor[0];
        EmitVertex();
//
        gl_Position = gl_in[0].gl_Position + vec4(0.0, 0.4, 0.0, 0.0);
        color = fcolor[0];
        EmitVertex();

        gl_Position = gl_in[0].gl_Position + vec4(-0.4, -0.2, 0.0, 0.0);
        color = fcolor[0];
        EmitVertex();
//        }
        EndPrimitive();
    }