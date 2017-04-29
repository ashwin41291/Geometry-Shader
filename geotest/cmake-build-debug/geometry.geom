#version 410 core

 layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;
int i=0;
in VS_OUT {
    vec3 Normal;
    vec4 Position;
} gs_in[];

out vec3 Normal;
out vec4 Position;
out vec4 color;

    void main()
    {
        for(i=0; i<3; i++)
        {
        gl_Position = gl_in[i].gl_Position + vec4(-0.2, 0.0, 0.0, 0.0);
        color = vec4(1.0,0.0,0.0,1.0);
        EmitVertex();

        gl_Position = gl_in[i].gl_Position + vec4(0.2, 0.0, 0.0, 0.0);
        color = vec4(0.0,1.0,0.0,1.0);
        EmitVertex();

        gl_Position = gl_in[i].gl_Position + vec4(0.0, 0.2, 0.0, 0.0);
        color = vec4(0.0,0.0,1.0,1.0);
        EmitVertex();
        EndPrimitive();
        }
        //EndPrimitive();
        Normal = gs_in[0].Normal;
        Position = gs_in[0].Position;
    }