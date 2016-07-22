/*
 * SplitAndConvert.hpp
 *
 *  Created on: Jun 21, 2016
 *      Author: Md.Nazmul
 */

#ifndef SPLITANDCONVERT_HPP_
#define SPLITANDCONVERT_HPP_

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream class to read from file
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

class SplitAndConvert {
public:
	SplitAndConvert();
	virtual ~SplitAndConvert();
	std::string SplitStartTagAndCoord(string s, string delimiter);
	std::string SplitEndTagAndCoord(string s, string delimiter);
	double StringToCoord(string s);


};

#endif /* SPLITANDCONVERT_HPP_ */
