/*******************************************************************************
  Title          : Tree_collection.h
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : The interface file for the Tree_collection class
  Purpose        : Handling input data and verifying integrity of input information
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/
#ifndef __Tree_collection_h__
#define __Tree_collection_h__
#pragma once
#include "command.h"
#include "avl.h"
#include "tree_species.h"
#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;	

class Tree_collection{
	public:
	Tree_collection();
	~Tree_collection(){}
	//Checks if the input follows conditions regarding input file, output file, integer for coin flip, and if it succeded in total
	//bool inputVerify(stringstream& iFile,stringstream& oFile, stringstream& iV, bool* sucessfulHandling);
	//Creates new system to use the census system, pushes input file, output file, and the current seed, assumed to have been checked
	void newCensusSystem(stringstream& iFile,stringstream& oFile);
	int total_tree_count() const;
	int count_of_tree_species ( const string& species_name ) const;
	int count_of_trees_in_boro( const string& boro_name ) const;
	list<string> get_matching_species(const string & species_name) const;
	list<string> get_all_in_zipcode(int zipcode) const;
	list<string> get_all_near(double latitude, double longitude, double distance) const;
	void checkCommandFunc(ifstream &fin, string fileName, Command& command);

	struct Vector3d{
	string borosV = "";
	int boroInt = 0;
	};



	
	private:
	 //Elements, names imply purpose
	 string inputFile;
	 string outputFile;
	 AVL_Tree newAVLTree;
	 TreeSpecies newTreeSpecies;
	 vector<Vector3d> boroughList;
	 //typedef pair<string, int> boroPair;
};


#endif

