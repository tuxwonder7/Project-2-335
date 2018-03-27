/*******************************************************************************
  Title          : inputHandler.h
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : The interface file for the tree class, represents object called tree with name, location, etc
  Purpose        : Represents object called tree
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/
#ifndef _tree_h_
#define _tree_h_
#pragma once
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Tree{
	public:
	//Default constructor to deal with string variable (references but only puts data into private elements
	Tree(const string & treedata);
	//Outputs to file through overloaded operator<<
	friend ostream& operator<< (ostream & os, const Tree & t);
	//Not used currrently but returns string of elements in specific fashion
	string write();
	private:
	//All elements, names imply purpose
	string allInfo;
	string spc_common;
	string specInfo;
	ostringstream ospecInfo;
	unsigned int tree_id;
	unsigned int tree_dbh;
	string status;
	string health;
	string address;
	string boroname;
	int zipcode;
	double latitude;
	double longitude;
};



#endif

