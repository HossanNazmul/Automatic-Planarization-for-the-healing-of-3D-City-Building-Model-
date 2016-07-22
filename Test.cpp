/*
 * Test.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: Md.Nazmul
 */

#include <iostream>
#include <vector>
#include <cmath>
#include "Geometry/Point3D.hpp"
#include "Geometry/building.hpp"
#include "Geometry/LinearRing.hpp"

using namespace std;


int main()
{
	Point3D A, B, C, newPoint;
	building getGeometries;
	LinearRing LR;
	vector<double> linearRingCoords;
	getGeometries.readGMLFile("InputFiles/building.gml");
	vector<string> G_surface= getGeometries.GroundSurface;
	vector<string> W_surface= getGeometries.WallSurface;
	vector<string> R_surface= getGeometries.RoofSurface;

	vector<string> L_rings;
	vector<string> GS_L_rings=LR.getLinearRing(G_surface);
	vector<string> RS_L_rings=LR.getLinearRing(R_surface);
	vector<string> WS_L_rings=LR.getLinearRing(W_surface);
	int iterate=1;

	while (iterate<4){
		if (iterate==1){
			L_rings= GS_L_rings;
			cout<<"___________________________Processing Ground surfaces_____________________"<<endl;
		}
		else if (iterate==2){
			L_rings= RS_L_rings;
			cout<<"___________________________Processing Roof surfaces_____________________"<<endl;

		}
		else{
			L_rings= WS_L_rings;
			cout<<"___________________________Processing Wall surfaces_____________________"<<endl;
		}

		for(unsigned int index=0; index<L_rings.size();index++){
			linearRingCoords=LR.getRingCoords(L_rings, index);
			cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Processing Linear Ring <<<<<<<<<<<<<<<<<<<<<<<<<<<<<: "<<index<<endl;

			//set the Point A, B, C
			A.setX(linearRingCoords[0]), A.setY(linearRingCoords[1]), A.setZ(linearRingCoords[2]);
			B.setX(linearRingCoords[3]), B.setY(linearRingCoords[4]), B.setZ(linearRingCoords[5]);
			C.setX(linearRingCoords[6]), C.setY(linearRingCoords[7]), C.setZ(linearRingCoords[8]);

			//	Point3D newPoint(24,4,4);
			//		A.print();
			//		B.print();
			//		C.print();

			//check if they are collinear
			double distAB = sqrt( pow((B.getX()- A.getX()),2) + pow((B.getY()- A.getY()),2) + pow((B.getZ()- A.getZ()),2));
			double distBC = sqrt( pow((C.getX()- B.getX()),2) + pow((C.getY()- B.getY()),2) + pow((C.getZ()- B.getZ()),2));
			double distAC = sqrt( pow((C.getX()- A.getX()),2) + pow((C.getY()- A.getY()),2) + pow((C.getZ()- A.getZ()),2));

			//		cout<<"distAB: "<<distAB<<endl;
			//		cout<<"distBC: "<<distBC<<endl;
			//		cout<<"distAC: "<<distAC<<endl;

			int j=9;
			//if condition is partialy implemented
			while ((distAB+distBC)==distAC || ((distAB+distAC)==distBC) || ((distBC+distAC)==distAB)){
				cout<<"<<<<<<<<< The points are colliear and couldn't define the plane >>>>>>>>>>>>"<<endl;
				//			for(unsigned int j=9; j<linearRingCoords.size();j=j+3){
				C.setX(linearRingCoords[j]), C.setY(linearRingCoords[j+1]), C.setZ(linearRingCoords[j+2]);
				distBC = sqrt( pow((C.getX()- B.getX()),2) + pow((C.getY()- B.getY()),2) + pow((C.getZ()- B.getZ()),2));
				distAC = sqrt( pow((C.getX()- A.getX()),2) + pow((C.getY()- A.getY()),2) + pow((C.getZ()- A.getZ()),2));
				//check if it is again co-linear
//				cout<<"calculating new distances"<<endl;
//				C.print();
				j=j+3;
				//			}
			}


			Point3D AB ((B.getX()-A.getX()), (B.getY()-A.getY()), (B.getZ()-A.getZ()));
			//	AB.print();

			Point3D AC ((C.getX()-A.getX()), (C.getY()-A.getY()), (C.getZ()-A.getZ()));
			//	AC.print();

			//compute Normal Vector
			Point3D n(0,0,0);
			n.setX((AB.getY() * AC.getZ())-(AB.getZ() * AC.getY()));
			n.setY((AB.getZ() * AC.getX())-(AB.getX() * AC.getZ()));
			n.setZ((AB.getX() * AC.getY())-(AB.getY() * AC.getX()));
			cout<<"normal vector is : ";
			n.print();

			//if the normal vector is 0 then there will be an error and new points are
			//to be chosen and calculate the normal vector again
			//compute D
			double D = -(n.getX()*B.getX() + n.getY()*B.getY() + n.getZ()*B.getZ());
			//		cout<<"the value of D is : "<<D<<endl;

			double threshold = 0.000000000;
			double checkPlanar;

			for (unsigned int i=9; i<linearRingCoords.size();i=i+3){

				//Set newPoint and check if it is on the plane
				newPoint.setX(linearRingCoords[i]), newPoint.setY(linearRingCoords[i+1]), newPoint.setZ(linearRingCoords[i+2]);
				newPoint.print();

				checkPlanar = (n.getX()*newPoint.getX()) + (n.getY()*newPoint.getY()) + (n.getZ()*newPoint.getZ()) + D ;
				//			cout<<"the check plane valuse is : "<<checkPlanar<<endl;

				if (checkPlanar > threshold){
					cout<<"the point ("<<newPoint.getX()<<" "<<newPoint.getY()<<" "<<newPoint.getZ()<<") is NOT on the Plane"<<endl;
					cout<<"----------------------------------------------------"<<endl;
				}
				else{
					cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
					cout<<"the point ("<<newPoint.getX()<<" "<<newPoint.getY()<<" "<<newPoint.getZ()<<") is on the Plane"<<endl;
				}
			}
		}
		iterate=iterate+1;
	}


   return 0;
}

