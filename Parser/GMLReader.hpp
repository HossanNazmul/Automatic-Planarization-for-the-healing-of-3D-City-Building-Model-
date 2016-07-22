/*
 * GMLReader.hpp
 *
 *  Created on: Jun 22, 2016
 *      Author: Md.Nazmul
 */

#ifndef PARSER_GMLREADER_HPP_
#define PARSER_GMLREADER_HPP_

// ifstream constructor.
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream class to read from file
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include "SplitAndConvert.hpp"

class GMLReader {
public:
	GMLReader();
	virtual ~GMLReader();
	vector<double> ReadGMLLinearRings(string path);
};

#endif /* PARSER_GMLREADER_HPP_ */
