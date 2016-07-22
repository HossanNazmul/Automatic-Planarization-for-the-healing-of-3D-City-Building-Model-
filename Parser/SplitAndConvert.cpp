/*
 * SplitAndConvert.cpp
 *
 *  Created on: Jun 21, 2016
 *      Author: Md.Nazmul
 */

#include "SplitAndConvert.hpp"

SplitAndConvert::SplitAndConvert() {
	// TODO Auto-generated constructor stub

}

SplitAndConvert::~SplitAndConvert() {
	// TODO Auto-generated destructor stub
}
std::string SplitAndConvert::SplitStartTagAndCoord(string s, string delimiter){
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
//		cout<<"StartDelimiter: "<< delimiter <<"StartPosition: "<<pos <<endl;
	    token = s.substr(0, pos);
	    s.erase(0, pos + delimiter.length());
//	    std::cout <<"StartToken: "<< s << std::endl;
	    }
	return s;
}

std::string SplitAndConvert::SplitEndTagAndCoord(string s, string delimiter){
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
//		cout<<"Enddelimiter: "<< delimiter <<"EndPosition: "<<pos <<endl;
	    token = s.substr(0, pos);
	    s.erase(0, pos + delimiter.length());
//	    std::cout <<"Endtoken: "<< token << std::endl;
	    }
	return token;
}

double SplitAndConvert::StringToCoord(string s){
	double result;//=std::numeric_limits<double>::max_digits10;;//number which will contain the result

	stringstream convert(s); // stringstream used for the conversion initialized with the contents of Text
	if ( !(convert >> result))//give the value to Result using the characters in the string
	    result = 0;//if that fails set Result to 0
	//Result now equal to 456
//	std::cout <<"the number after convertion is: "<<std::setprecision(15)<< result << std::endl;
	return result;
}

