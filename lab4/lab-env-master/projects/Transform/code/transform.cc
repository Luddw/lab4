#include "transform.h"
#include "matlib.h"


Transform::Transform(Matrix4D translate, Matrix4D scale, Matrix4D rotate)
	:translation(translate), scale(scale), rot(rotate)
{
}

Transform::~Transform()
{
}

void Transform::RotX(float rad)
{
	rot = rot * Matrix4D::RotX_axis(rad);
}

void Transform::RotY(float rad)
{
	rot = rot * Matrix4D::RotY_axis(rad);
}

void Transform::RotZ(float rad)
{
	rot = rot * Matrix4D::RotY_axis(rad);
}

void Transform::RotVect(Vector4D vect, float rad)
{
	rot = rot * Matrix4D::RotVect_axis(vect, rad);
}

void Transform::Move(float x, float y, float z)
{
	this->translation[3] = x;
	this->translation[7] = y;
	this->translation[11] = z;
}

void Transform::Scale(float x, float y, float z)
{
	this->translation[0] = x;
	this->translation[5] = y;
	this->translation[10] = z;
}
Matrix4D Transform::MakeModel()
{
	return (translation * rot * scale);
}
