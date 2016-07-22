/*
 * building.cpp
 *
 *  Created on: Jun 26, 2016
 *      Author: Md.Nazmul
 */

#include "building.hpp"

building::building() {
	// TODO Auto-generated constructor stub

}

building::~building() {
	// TODO Auto-generated destructor stub
}

void building::readGMLFile(string filePath){
	  ifstream file_(filePath.c_str());
	  std::string line;
	  //to find the position of the <bldg:Building
	  int pos = 0;
	  int B_foundStartPos, B_foundEndPos;
	  int GS_foundStartPos, GS_foundEndPos;
	  int RS_foundStartPos, RS_foundEndPos;
	  int WS_foundStartPos, WS_foundEndPos;

	  if (file_.is_open()){
		  while(getline(file_,line)){
			  cityObjectMember.push_back(line);
			  if(line.find("<bldg:Building")!= std::string::npos){
				  B_foundStartPos=pos++;
			  }
			  else if(line.find("</bldg:Building>")!= std::string::npos){
				  B_foundEndPos=pos;
			  }
			  else if(line.find("<bldg:GroundSurface")!= std::string::npos){
			   		GS_foundStartPos=pos++;
			   	}
			  else if(line.find("</bldg:GroundSurface>")!= std::string::npos){
				  GS_foundEndPos=pos;
			  	}
			  else if(line.find("<bldg:RoofSurface")!= std::string::npos){
			   		RS_foundStartPos=pos++;
			   	}
			  else if(line.find("</bldg:RoofSurface>")!= std::string::npos){
				  RS_foundEndPos=pos;
			  	}
			  else if(line.find("<bldg:WallSurface")!= std::string::npos){
			   		WS_foundStartPos=pos++;
			   	}
			  else if(line.find("</bldg:WallSurface>")!= std::string::npos){
				  WS_foundEndPos=pos;
			  	}
			  else{
				  pos++;
			  }
		  }
		  file_.close();
	  }

	  else{
		  std::cout<<"The file is NOT open!";
	  }

	  for(int i=B_foundStartPos;i<B_foundEndPos;i++){
		  buildingGeom.push_back(cityObjectMember[i]);
	  }

	  for(int i=GS_foundStartPos;i<GS_foundEndPos;i++){
		  GroundSurface.push_back(cityObjectMember[i]);
	  }

	  for(int i=RS_foundStartPos;i<RS_foundEndPos;i++){
		  RoofSurface.push_back(cityObjectMember[i]);
	  }

	  for(int i=WS_foundStartPos;i<WS_foundEndPos;i++){
		  WallSurface.push_back(cityObjectMember[i]);
	  }

//	  building::WriteInFile(GroundSurface, "OutputFiles/GF.gml");
//	  building::WriteInFile(RoofSurface, "OutputFiles/RF.gml");
//	  building::WriteInFile(WallSurface, "OutputFiles/WF.gml");
//return buildingGeom;
}

void building::WriteInFile(vector<string> v, string fileName){
	  std::fstream fs;
	  fs.open (fileName.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

	for(unsigned int i=0; i<v.size();i++){
		fs << v[i]<<endl;
	}
	  fs.close();
}

