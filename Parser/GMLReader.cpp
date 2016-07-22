/*
 * GMLReader.cpp
 *
 *  Created on: Jun 22, 2016
 *      Author: Md.Nazmul
 */

#include "GMLReader.hpp"

GMLReader::GMLReader() {

	}

GMLReader::~GMLReader() {
	// TODO Auto-generated destructor stub
}

vector<double> GMLReader::ReadGMLLinearRings(string filePath){
	//std::ifstream file_("building.gml");
//	  ifstream file_("test.txt"); //or ("test.txt", std::ifstream::in);

	  ifstream file_(filePath.c_str());
	  std::string line;
	  vector<string> GroundSurface;
	  vector<string> LinearRing;
	  vector<double> LinearRingCoords; // Create vector to hold our coords

	  //to find the position of the text
	  int pos = 0;
	  int foundStartPos=0;
	  int foundEndPos=0;


	  if (file_.is_open()){
		  while(getline(file_,line)){
			  GroundSurface.push_back(line);
			  if(line.find("<bldg:GroundSurface")!= std::string::npos){
			   			foundStartPos=pos++;
//			   			cout<<"line "<<foundStartPos<<":"<<line<<endl;
			   		  }
			  else if(line.find("</bldg:GroundSurface>")!= std::string::npos){
				  foundEndPos=pos;
			  }
			  else{
			   			pos++;
			   	  }
			  }
		  file_.close();
		  }
	  else
	    {
	  	  std::cout<<"The file is NOT open!";
	    }

//	  for(int i=foundStartPos;i<foundEndPos;i++){
////	  	cout<<"new file :"<<i<<LinearRing[i]<<endl;
//	  	  if(GroundSurface[i].find("<gml:LinearRing")){
//	  	  		if(GroundSurface[i].find("<gml:posList srsDimension=\"3\">") != std::string::npos){
//	  	  			LinearRing.push_back(GroundSurface[i]);
//
//	  			string buf; // Have a buffer string
//	  			stringstream ss(GroundSurface[i]); // Insert the string into a stream
//
//			    std::string delimiter1 = "srsDimension=\"3\">";
//				std::string delimiter2 = "</gml:posList>";
//
//				SplitAndConvert conv;
//
//			  while (ss >> buf)
//			  {
//			  if (buf=="<gml:posList"){
////			  cout<<"Ignoring the first index"<<endl;
//			  //do nothing
//			  }
//			  else if (buf.find(delimiter1)!= std::string::npos){
//				  buf=conv.SplitStartTagAndCoord(buf,delimiter1);
//				  LinearRingCoords.push_back(conv.StringToCoord(buf));
////				cout<<"---------the dilimiter1 is found--------------"<<endl;
//			  }
//
//			  else if (buf.find(delimiter2)!= std::string::npos){
//				  buf=conv.SplitEndTagAndCoord(buf,delimiter2);
//				  LinearRingCoords.push_back(conv.StringToCoord(buf));
////				cout<<"xxxxxxxxxxxxxxxxx the dilimiter2 is found xxxxxxxxxxxx"<<endl;
//			  }
//			  else {
////					double coords = conv.StringToCoord(buf);
//				  LinearRingCoords.push_back(conv.StringToCoord(buf));
////					cout<<"LinearRingCoords :"<< buf<<endl;
//			  }
//			    }
//	  	  		}
//	  	  }
//	  }
//
//	  for(unsigned int i=0;i<LinearRing.size();i++){
//	  	cout<<"Linear Rings"<<i<<": "<<LinearRing[i]<<endl;
//	  }


	  return LinearRingCoords;
}

