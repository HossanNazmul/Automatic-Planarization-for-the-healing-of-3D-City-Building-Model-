/*
 * LinearRing.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: Md.Nazmul
 */

#include "LinearRing.hpp"


using namespace std;

LinearRing::LinearRing() {
	// TODO Auto-generated constructor stub
}

LinearRing::~LinearRing() {
	// TODO Auto-generated destructor stub
}
vector<string> LinearRing::getLinearRing(vector<string> Surface){

	//now parse the linear rings from the Surface
	vector<string> LinearRing;

	for(unsigned int i=0;i<Surface.size();i++){
		//	  	cout<<"new file :"<<i<<LinearRing[i]<<endl;
		if(Surface[i].find("<gml:LinearRing")){
			if(Surface[i].find("<gml:posList srsDimension=\"3\">") != std::string::npos){
				LinearRing.push_back(Surface[i]);
			}
		}
	}
	return LinearRing;
}

vector<double> LinearRing::getRingCoords(vector<string> LinearRing, unsigned int index){

	vector<double> RingCoords;
	string buf; // Have a buffer string
	std::string delimiter1 = "srsDimension=\"3\">";
	std::string delimiter2 = "</gml:posList>";

//	for(unsigned int i=0; i<LinearRing.size();i++){

		stringstream ss(LinearRing[index]); // Insert the string into a stream
		SplitAndConvert conv;

		while (ss >> buf)
		{
			if (buf=="<gml:posList"){
				//			  cout<<"Ignoring the first index"<<endl;
				//do nothing
			}
			else if (buf.find(delimiter1)!= std::string::npos){
				buf=conv.SplitStartTagAndCoord(buf,delimiter1);
				RingCoords.push_back(conv.StringToCoord(buf));
				//				cout<<"---------the dilimiter1 is found--------------"<<endl;
			}

			else if (buf.find(delimiter2)!= std::string::npos){
				buf=conv.SplitEndTagAndCoord(buf,delimiter2);
				RingCoords.push_back(conv.StringToCoord(buf));
				//				cout<<"xxxxxxxxxxxxxxxxx the dilimiter2 is found xxxxxxxxxxxx"<<endl;
			}
			else {
				RingCoords.push_back(conv.StringToCoord(buf));
				//					cout<<"RingCoords :"<< buf<<endl;
			}
		}
//	}

	return RingCoords;

}

