/*
 * PlanarityCheck.hpp
 *
 *  Created on: Jun 4, 2016
 *      Author: Md.Nazmul
 */

#ifndef PROCESS_PLANARITYCHECK_HPP_
#define PROCESS_PLANARITYCHECK_HPP_

#include <iostream>
#include <vector>
class PlanarityCheck {
public:
	PlanarityCheck();	//default constructor
	virtual ~PlanarityCheck();	//default destructor
	void InputPoints(double p1, double p2, double p3);
	double NormalVector(double v1, double v2);
	double PlaneEquation(double a, double b, double c, double d);
	bool IsPlanar(double threshold);

private:
	std::vector <double> P1, P2, P3, N, A, B, C, D;
};

#endif /* PROCESS_PLANARITYCHECK_HPP_ */
