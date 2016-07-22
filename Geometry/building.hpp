/*
 * building.hpp
 *
 *  Created on: Jun 26, 2016
 *      Author: Md.Nazmul
 */

#ifndef GEOMETRY_BUILDING_HPP_
#define GEOMETRY_BUILDING_HPP_

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream class to read from file
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class building {
public:
	building();
	virtual ~building();
	void readGMLFile(string filePath);
	void WriteInFile(vector<string> v, string fileName);
	vector<string> cityObjectMember, buildingGeom, GroundSurface, RoofSurface, WallSurface;
};

#endif /* GEOMETRY_BUILDING_HPP_ */
