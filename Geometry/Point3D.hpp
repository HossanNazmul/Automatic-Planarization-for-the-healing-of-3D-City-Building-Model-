/*
 * Point3D.hpp
 *
 *  Created on: Jun 4, 2016
 *      Author: Md.Nazmul
 */

#ifndef GEOMETRY_POINT3D_HPP_
#define GEOMETRY_POINT3D_HPP_

#include <iostream>
#include <iomanip>
using namespace std;

class Point3D {
	private:
	double X, Y, Z;  // Private data members

public:
   Point3D(double, double, double); // Constructor with default arguments
   Point3D();
   virtual ~Point3D();

   void print() const;
   double getX() const;
   double getY() const;
   double getZ() const;
   void setX(double);
   void setY(double);
   void setZ(double);


};

#endif /* GEOMETRY_POINT3D_HPP_ */
