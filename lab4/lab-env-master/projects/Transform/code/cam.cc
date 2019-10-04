#include "cam.h"
#include "matlib.h"


void Cam::LookAt(Vector4D target, Vector4D up)
{
	Vector4D z_axis = (pos - target);
	z_axis = z_axis.Normalize();
	Vector4D x_axis = z_axis.CrossProduct(up);
	x_axis = x_axis.Normalize();
	Vector4D y_axis = x_axis.CrossProduct(z_axis);
	Matrix4D viewmat(
		x_axis.GetX(), x_axis.GetY(), x_axis.GetZ(), -1*x_axis.DotProduct(pos),
		y_axis.GetX(), y_axis.GetY(), y_axis.GetZ(), -1*y_axis.DotProduct(pos),
		z_axis.GetX(), z_axis.GetY(), z_axis.GetZ(), -1*z_axis.DotProduct(pos),
		0, 0, 0, 1
	);
	
	
}

