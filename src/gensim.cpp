#include "gensim.h"
#if defined(_WIN32)
    #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\include\librealsense2\rs.hpp"
    // #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\samples\example.hpp"
#endif



#include <raylib.h>
#include <iostream>
#include <vector>


GenSim::GenSim(){
    std::cout << "GenSim: Initialized" << std::endl;
}

float Vector3Distance(rs2::vertex v1, rs2::vertex v2) {
    return abs(sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2)));
}


void GenSim::DrawRoute(){

}

void GenSim::DrawRover(bool c){

    auto roverPos = Vector3{0, 0, 0};

    float rover_width_cm = 45; //cm
    float rover_length_cm = 69; //cm
    float rover_height_cm = 20; //cm

    // Todo tiene escala de 10
    if(c){
        DrawCube(roverPos, rover_width_cm/10, rover_height_cm/10, rover_length_cm/10, RED);
    }else{
        DrawCube(roverPos, rover_width_cm/10, rover_height_cm/10, rover_length_cm/10, BLUE);
    }

}

rs2::vertex get_point(const std::vector<rs2::vertex>& vertices, int width, int x, int y) {
    // Assuming row-major order (y * width + x)
    int index = y * width + x;
    return vertices[index];
}

void GenSim::DrawPointCloud(rs2::points points){

    DrawGrid(10, 5.0);
    auto vertices = points.get_vertices();

    bool colliding = false;

    // w      h
    // 1280 x 720 = 921600 = points.size() 
    for (size_t i = 0; i < points.size(); i+=10)
    {

        // std::cout << Vector3Distance(vertices[i], vertices[i+1]) << std::endl;

        if (vertices[i].z && Vector3Distance(vertices[i], vertices[i+1]) > 0.003)
        {

            // std::cout << vertices[i].x << std::endl;

            // DrawLine3D(Vector-3{vertices[i].x*20, vertices[i].y*20, vertices[i].z*20}, Vector3{vertices[i+1].x*20, vertices[i+1].y*20, vertices[i+1].z*20}, BLUE);
            auto cubePos = Vector3{vertices[i].x*20, vertices[i].y*20, vertices[i].z*20};
            float cubeSize = 0.1;

            // float hue = std::fmod((vertices[i].x + vertices[i].y + vertices[i].z) * 18.0f, 360.0f);
            // auto cubeColor = ColorFromHSV(hue, 0.75f, 0.9f);


            if(vertices[i].z*20 < 10){
                DrawCube(cubePos, cubeSize, cubeSize, cubeSize, RED);
                colliding = true;
            }else{
                DrawCube(cubePos, cubeSize, cubeSize, cubeSize, BLUE);
            }
        }
    }

    GenSim::DrawRover(colliding);

}