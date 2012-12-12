#include "Harvester.h"
#include "Toriverse.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

// Constructor: Defaults NULL harvester
Harvester::Harvester(){
  xPos = 0;
  yPos = 0;
  xMom = 0;
  yMom = 0;
  Energy = 0;
  Score = 0;
  HStatus = 1;
}

// Constructor: Default to NULL Toriverse with given momentum
Harvester::Harvester(char* filename){
  ifstream toriSpec(filename);
  toriSpec.seekg(0);

  string line;
  string val;

  while(!toriSpec.eof()){
    getline(toriSpec, line);
    size_t foundEnergy = line.find("Harvester Energy: ");
    size_t foundPos = line.find("Harvester Position: ");
    size_t foundLifeTime = line.find("Lifetime: ");

    if(foundEnergy!=string::npos){
      istringstream lineStr(line);
      vector<int> valsEnergy;
      while(getline(lineStr, val, ' ')){
  valsEnergy.push_back(atoi(val.c_str()));
      }
      Energy = valsEnergy[2];
    }

    if(foundPos!=string::npos){
      istringstream lineStr(line);
      vector<int> valsPos;
      while(getline(lineStr, val, ' ')){
	valsPos.push_back(atoi(val.c_str()));
      }
      xPos = valsPos[2];
      yPos = valsPos[3];
    }

    if(foundLifeTime!=string::npos){
      istringstream lineStr(line);
      vector<int> valsLife;
      while(getline(lineStr, val, ' ')){
	valsLife.push_back(atoi(val.c_str()));
      }
      Score = valsLife[1];
    }
    Score += Energy;

  }
  xMom = 0;
  yMom = 0;
  HStatus = 1;

}

Harvester::~Harvester(){}

void Harvester::HarvesterCMD(Toriverse& T, char cmd){
  if (HStatus && (Energy>0)){

    if (cmd =='w' || cmd == 'X' || cmd == 'x' || cmd == 'Y' || cmd == 'y'){

      if (cmd == 'w'){
	if ((xPos + xMom) <= T.getXDim()-1 &&
	    (xPos + xMom) >= 0){
	  xPos += xMom;
	  if ((yPos + yMom) <= T.getYDim()-1 &&
	      (yPos + yMom) >= 0){
	    yPos += yMom;
	  }
	  else if ((yPos + yMom) >= T.getYDim()){
	    yPos = (yPos + yMom) % (T.getYDim());
	  }
	  else {
	    yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	  }
	}
	else if ((xPos + xMom) >= T.getXDim() ||
		 (xPos + xMom) < 0){
	  if ((xPos + xMom) >= T.getXDim()){
	    xPos = (xPos + xMom) % (T.getXDim());
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	  
	  else {
	    xPos = T.getXDim() + ((xPos + xMom) % (T.getXDim()));
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getXDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	}
      }
      
      if (cmd=='X'){
	xMom++;
	Energy--;
	
	if ((xPos + xMom) <= T.getXDim()-1 &&
	    (xPos + xMom) >= 0){
	  xPos += xMom;
	  if ((yPos + yMom) <= T.getYDim()-1 &&
	      (yPos + yMom) >= 0){
	    yPos += yMom;
	  }
	  else if ((yPos + yMom) >= T.getYDim()){
	    yPos = (yPos + yMom) % (T.getYDim());
	  }
	  else {
	    yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	  }
	}
	else if ((xPos + xMom) >= T.getXDim() ||
		 (xPos + xMom) < 0){
	  if ((xPos + xMom) >= T.getXDim()){
	    xPos = (xPos + xMom) % (T.getXDim());
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	  
	  else {
	    xPos = T.getXDim() + ((xPos + xMom) % (T.getXDim()));
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getXDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	}
      }
      
      else if (cmd=='x'){
	xMom--;
	Energy--;
	
	if ((xPos + xMom) <= T.getXDim()-1 &&
	    (xPos + xMom) >= 0){
	  xPos += xMom;
	  if ((yPos + yMom) <= T.getYDim()-1 &&
	      (yPos + yMom) >= 0){
	    yPos += yMom;
	  }
	  else if ((yPos + yMom) >= T.getYDim()){
	    yPos = (yPos + yMom) % (T.getYDim());
	  }
	  else {
	    yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	  }
	}
	else if ((xPos + xMom) >= T.getXDim() ||
		 (xPos + xMom) < 0){
	  if ((xPos + xMom) >= T.getXDim()){
	    xPos = (xPos + xMom) % (T.getXDim());
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	  
	  else {
	    xPos = T.getXDim() + ((xPos + xMom) % (T.getXDim()));
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getXDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	}
      }
      else if (cmd=='y'){
	yMom--;
	Energy--;
	
	if ((xPos + xMom) <= T.getXDim()-1 &&
	    (xPos + xMom) >= 0){
	  xPos += xMom;
	  if ((yPos + yMom) <= T.getYDim()-1 &&
	      (yPos + yMom) >= 0){
	    yPos += yMom;
	  }
	  else if ((yPos + yMom) >= T.getYDim()){
	    yPos = (yPos + yMom) % (T.getYDim());
	  }
	  else {
	    yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	  }
	}
	else if ((xPos + xMom) >= T.getXDim() ||
		 (xPos + xMom) < 0){
	  if ((xPos + xMom) >= T.getXDim()){
	    xPos = (xPos + xMom) % (T.getXDim());
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	  
	  else {
	    xPos = T.getXDim() + ((xPos + xMom) % (T.getXDim()));
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getXDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	}
      }
      else if (cmd == 'Y'){
	yMom++;
	Energy--;
	
	if ((xPos + xMom) <= T.getXDim()-1 &&
	    (xPos + xMom) >= 0){
	  xPos += xMom;
	  if ((yPos + yMom) <= T.getYDim()-1 &&
	      (yPos + yMom) >= 0){
	    yPos += yMom;
	  }
	  else if ((yPos + yMom) >= T.getYDim()){
	    yPos = (yPos + yMom) % (T.getYDim());
	  }
	  else {
	    yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	  }
	}
	else if ((xPos + xMom) >= T.getXDim() ||
		 (xPos + xMom) < 0){
	  if ((xPos + xMom) >= T.getXDim()){
	    xPos = (xPos + xMom) % (T.getXDim());
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getYDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	  
	  else {
	    xPos = T.getXDim() + ((xPos + xMom) % (T.getXDim()));
	    
	    if ((yPos + yMom) <= T.getYDim()-1 &&
		(yPos + yMom) >= 0){
	      yPos += yMom;
	    }
	    else if ((yPos + yMom) >= T.getYDim()){
	      yPos = (yPos + yMom) % (T.getYDim());
	    }
	    else {
	      yPos = T.getXDim() + ((yPos + yMom) % (T.getYDim()));
	    }
	  }
	}
      }
    }
      
    else if (cmd == 'e') {
      if ((xMom % T.getXDim())!=0 || (yMom % T.getYDim())!=0){
	setFate("Error: Cannot end with momentum not 0!");
	setStatus(0);
	setScore(0);
      }
      else if (T.getNSLocks() != 0){
	setFate("Error: Space locks remain!");
	setStatus(0);
	setScore(0);
      }
      else {
	Score = Energy + T.getLifeTime();
	setStatus(0);
	setFate("Harvester exited safely");
      }
    }
    else {
      cout << "Error: Invalid command!" << endl;
    }
    
  }
      

  else {
    if (!HStatus) {
      setFate("Error: Destroyed by Black Hole!");
	}
    if (Energy<0) {
      cout << "Error: negative energy";
      setStatus(0);
    }
  }
}
