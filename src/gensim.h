#pragma once
#if defined(_WIN32)
    #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\include\librealsense2\rs.hpp"
    // #include "C:\Program Files (x86)\Intel RealSense SDK 2.0\samples\example.hpp"
#endif

#include <raylib.h>
class GenSim{

    public:
    GenSim();
    void DrawPointCloud(rs2::points points);
    void DrawRover(bool c);
    void DrawRoute();
    Model getModel();


    private:
        Model model = LoadModel("C:\\Users\\rncb0\\Code\\genesis\\gensim\\src\\R6.glb");


};