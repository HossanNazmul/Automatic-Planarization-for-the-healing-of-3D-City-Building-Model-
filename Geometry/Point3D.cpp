/*
 * Point3D.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: Md.Nazmul
 */

#include "Point3D.hpp"

Point3D::Point3D(double x, double y, double z){
//	cout<<"constracting Point3D";
//	cout<<x<<y<<z<<endl;
	setX(x);
	setY(y);
	setZ(z);
}
Point3D::Point3D(){
	setX(0);
	setY(0);
	setZ(0);
}
Point3D::~Point3D() {
}
double Point3D::getX() const {
	return X;
}

void Point3D::setX(double x) {
	X = x;
}

double Point3D::getY() const {
	return Y;
}

void Point3D::setY(double y) {
	Y = y;
}

double Point3D::getZ() const {
	return Z;
}

void Point3D::setZ(double z) {
	Z = z;
}

void Point3D::print()const{
	cout<<"the value of the point is ("<<std::setprecision(15)<< X <<", "<< Y << ", " << Z << ")" <<endl;
}
