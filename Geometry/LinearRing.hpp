/*
 * LinearRing.hpp
 *
 *  Created on: Jun 29, 2016
 *      Author: Md.Nazmul
 */

#ifndef GEOMETRY_LINEARRING_HPP_
#define GEOMETRY_LINEARRING_HPP_

#include <fstream>      // std::ifstream class to read from file
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include "../Parser/SplitAndConvert.hpp"

using namespace std;

class LinearRing {
public:
	LinearRing();
	virtual ~LinearRing();
	vector<string> getLinearRing(vector<string> Surface);
	vector<double> getRingCoords(vector<string> LinearRing, unsigned int index);
};

#endif /* GEOMETRY_LINEARRING_HPP_ */
