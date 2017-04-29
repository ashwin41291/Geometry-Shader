#version 410 core

 layout(points) in;
layout(triangle_strip, max_vertices = 9) out;
in vec4 fcolor[1];

//out vec4 color[3];
out vec4 color;
int i=0;

    void main()
    {
//        for(i=0; i<3; i++)
//        {
        gl_Position = gl_in[0].gl_Position + vec4(-0.4, -0.2, 0.0, 0.0);
        //frag.color = vertices[0].color;
        color = fcolor[0];
        EmitVertex();

        gl_Position = gl_in[0].gl_Position + vec4(0.4, -0.2, 0.0, 0.0);
        //frag.color = vertices[0].color;
        color = fcolor[0];
        EmitVertex();

        gl_Position = gl_in[0].gl_Position + vec4(0.0, 0.4, 0.0, 0.0);
        //frag.color = vertices[0].color;
        color = fcolor[0];
        EmitVertex();

        //color = fcolor[0];
        //color = vec4(1.0,1.0,1.0,1.0);
        EndPrimitive();

//        gl_Position = gl_in[1].gl_Position + vec4(-0.4, -0.2, 0.0, 0.0);
//        //frag.color = vertices[1].color;
//        color = fcolor[0];
//        EmitVertex();
//
//        gl_Position = gl_in[1].gl_Position + vec4(0.4, -0.2, 0.0, 0.0);
//        //frag.color = vertices[1].color;
//        color = fcolor[0];
//        EmitVertex();
//
//        gl_Position = gl_in[1].gl_Position + vec4(0.0, 0.4, 0.0, 0.0);
//        //frag.color = vertices[1].color;
//        color = fcolor[0];
//        EmitVertex();
//
//        //color = fcolor[1];
//        //color = vec4(0.0,1.0,0.0,1.0);
//        EndPrimitive();
//
//        gl_Position = gl_in[2].gl_Position + vec4(-0.4, -0.2, 0.0, 0.0);
//        //frag.color = vertices[2].color;
//        color = fcolor[0];
//        EmitVertex();
//
//        gl_Position = gl_in[2].gl_Position + vec4(0.4, -0.2, 0.0, 0.0);
//        //frag.color = vertices[2].color;
//        color = fcolor[0];
//        EmitVertex();
//
//        gl_Position = gl_in[2].gl_Position + vec4(0.0, 0.4, 0.0, 0.0);
//        //frag.color = vertices[2].color;
//        color = fcolor[0];
//        EmitVertex();
////
//
//        //color = vec4(0.0,0.0,1.0,1.0);
//        EndPrimitive();
        //}


        //color = gs_in[0].fcolor;


    //}
//        double r =0.6;
//       int steps = 10;
//        if(r!=0 && steps!=0){
//        float PI = atan(1)*4 ;
//        float stepSize = (2*PI)/steps;
//
//        for(float theta = 0.0;theta <= 2*PI;theta+=stepSize){
//
//            gl_Position = gl_in[i].gl_Position + vec4(r*cos(theta), r*sin(theta), 0.0, 0.0);
//            EmitVertex();
//
//        }
//        }
  //      EndPrimitive();
    }