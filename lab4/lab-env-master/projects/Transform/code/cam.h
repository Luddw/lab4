#pragma once
#include "matlib.h"
class Vector4D;
class Matrix4D;


class Cam
{
private:
    Vector4D pos;
    Vector4D look_dir;
    
public:
    Cam(/* args */);
    ~Cam();
    void LookAt(Vector4D target, Vector4D up);
    void Rot(float rad);
};

