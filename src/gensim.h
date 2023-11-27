#pragma once
#if defined(_WIN32)
    #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\include\librealsense2\rs.hpp"
    // #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\samples\example.hpp"
#endif
class GenSim{

    public:
    GenSim();
    void DrawPointCloud(rs2::points points);
    void DrawRover();
    void DrawRoute();

};