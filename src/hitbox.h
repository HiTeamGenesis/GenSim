#pragma once
#if defined(_WIN32)
    #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\include\librealsense2\rs.hpp"
    // #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\samples\example.hpp"
#endif
#include <raylib.h>

class HitBox{

    public:
    HitBox(Vector3 pos, float _len, float _width, float _depth);

    void DrawHitbox();

    
};