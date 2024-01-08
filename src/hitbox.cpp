#include "hitbox.h"
#if defined(_WIN32)
    #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\include\librealsense2\rs.hpp"
    // #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\samples\example.hpp"
#endif
#include <raylib.h>
#include <iostream>

HitBox::HitBox(Vector3 pos, float _len, float _width, float _depth){
    std::cout << "GenSim: Initialized" << std::endl;
}


void HitBox::DrawHitbox(){

}
