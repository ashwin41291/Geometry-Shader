Interesting Scene:
Interesting scene is written on the InterestingScene.txt file.
The obj files for multiple objects are placed in the OBJfiles folder.

Questions:

1. Show the viewing matrix for the following settings:
i. Eye = 5,0,0
ii. Focal point = 0,0,0
iii. View up = 0,1,0

    vec3 eye(5.0f, 0.0f, 0.0f);
    vec3 center;
    center.x = 0.f;
    center.y = 0.f;
    center.z = 0.f;
    vec3 viewUp(0.f, 1.f, 0.f);

 mat4 viewMatrix = lookAt(eye, center, viewUp);

Viewmatrix = (0  0 -1  0
              0  1  0  0
              1  0  0 -5
              0  0  0  1)

2. For the world coordinate 3,0,0, what is its value in eye coordinates using the viewing matrix in the problem above?

eye coordinate = viewmatrix * vec4(world coordinate)

    = (0  0 -1  0         (3,
       0  1  0  0    *     0,
       1  0  0 -5          0,
       0  0  0  1)         1)

    = (0,
       0,
      -2,
       1)

The eye coordinate for the world coordinate value 3,0,0 is 0,0,-2.

3. Compute the face normal for a triangle described by these vertices (0,0,0), (1,0,0) and (0,1,0) in this order.
   Assume CCW ordering of these coordinates.

    vec3 normal;
    vec3 u = vec3 p2 - vec3 p1;
    vec3 v = vec3 p3 - vec3 p1;
    normal.x = (u.y * v.z) - (u.z * v.y);
    normal.y = (u.z * v.x) - (u.x * v.z);
    normal.z = (u.x * v.y) - (u.y * v.x);

Face normal for a triangle described by these vertices is (0, 0, 1).
