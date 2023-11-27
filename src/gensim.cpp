#include "gensim.h"
#if defined(_WIN32)
    #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\include\librealsense2\rs.hpp"
    // #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\samples\example.hpp"
#endif
#include <raylib.h>
#include <iostream>
GenSim::GenSim(){
    std::cout << "GenSim: Initialized" << std::endl;
}

float Vector3Distance(rs2::vertex v1, rs2::vertex v2) {
    return abs(sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2)));
}


void GenSim::DrawRoute(){

}

void GenSim::DrawRover(){

}

void GenSim::DrawPointCloud(rs2::points points){
    std::cout << "GenSim: Generating PointCloud" << std::endl;
    DrawGrid(10, 5.0);

    auto vertices = points.get_vertices();

    // int lastZ = vertices[0].z;

    for (size_t i = 0; i < points.size(); i+=10)
    {

        // std::cout << Vector3Distance(vertices[i], vertices[i+1]) << std::endl;

        if (vertices[i].z && Vector3Distance(vertices[i], vertices[i+1]) > 0.003)
        {

            // DrawLine3D(Vector-3{vertices[i].x*20, vertices[i].y*20, vertices[i].z*20}, Vector3{vertices[i+1].x*20, vertices[i+1].y*20, vertices[i+1].z*20}, BLUE);
            auto cubePos = Vector3{vertices[i].x*20, vertices[i].y*20, vertices[i].z*20};
            float hue = std::fmod((vertices[i].x + vertices[i].y + vertices[i].z) * 18.0f, 360.0f);
            auto cubeColor = ColorFromHSV(hue, 0.75f, 0.9f);
            float cubeSize = 0.1;
            DrawCube(cubePos, cubeSize, cubeSize, cubeSize, cubeColor);
        }
    }

}