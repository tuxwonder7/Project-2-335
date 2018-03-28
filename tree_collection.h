/*******************************************************************************
  Title          : tree_collection.h
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : The interface file for the tree_collection class
  Purpose        : Handling input data and verifying integrity of input information
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/
#ifndef __tree_collection_h__
#define __tree_collection_h__
#pragma once

#include "avl.h"
#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <iostream>



using namespace std;	

class tree_collection{
	public:
	tree_collection(){}
	~tree_collection(){}
	//Checks if the input follows conditions regarding input file, output file, integer for coin flip, and if it succeded in total
	//bool inputVerify(stringstream& iFile,stringstream& oFile, stringstream& iV, bool* sucessfulHandling);
	//Creates new system to use the census system, pushes input file, output file, and the current seed, assumed to have been checked
	void newCensusSystem(stringstream& iFile,stringstream& oFile);
	
	private:
	 //Elements, names imply purpose
	 string inputFile;
	 string outputFile;


};


#endif

