// TODO: Add Raspberry Pi 4 detection 
#if defined(_WIN32)
    #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\include\librealsense2\rs.hpp"
    // #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\samples\example.hpp"
#endif

#include <iostream>
#include <raylib.h>
#include <algorithm>

#include "gensim.h"

int main()
{
    rs2::pointcloud pc;
    rs2::points points;
    rs2::pipeline pipe;

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "GenSim");
    SetTargetFPS(60);

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 0.0f, 10.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };    // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type


    pipe.start();    

    GenSim gs = GenSim();

    while (!WindowShouldClose())
    {

        UpdateCamera(&camera, CAMERA_FREE);

        auto frames = pipe.wait_for_frames();
        auto depth = frames.get_depth_frame();
        points = pc.calculate(depth);

        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode3D(camera);
        
        gs.DrawPointCloud(points);
        EndMode3D();

        DrawFPS(10,10);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}