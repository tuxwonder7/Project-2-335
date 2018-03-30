/*******************************************************************************
  Title          : tree.h
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
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
class Tree{
	public:
	Tree();
	Tree ( int id, int diam, string status, string health, string spc, int zip, string addr, string boro, double latitude, double longitude );
	Tree(const Tree&);
	Tree(string currSPC, int treeID);
	//Default constructor to deal with string variable (references but only puts data into private elements
	Tree(const string & treedata);
	//Outputs to file through overloaded operator<<
	friend ostream& operator<< (ostream & os, const Tree & t);
	//Checks equality
	friend bool operator==(const Tree&t1, const Tree &t2);
	//Checks if less than (Tree name and ID)
	friend bool operator<(const Tree & t1, const Tree & t2);
	//Checks if trees are equal
	Tree& operator=(const Tree& other);
	//Checks if equal than (Tree name)
	friend bool samename(const Tree & t1,const Tree & t2);
	//Checks if less than (Tree name)
	friend bool islessname(const Tree & t1,const Tree & t2);
	//returns common name of tree
	string common_name() const;
	//returns borough tree is in
	string borough_name() const; 
	//returns nearby address where tree is located
	string nearest_address() const;
	//returns diameter of tree
	int diameter() const;
	//returns zip of tree 
	int zip() const;
	//returns currID of tree
	int currID() const;
	//returns position where tree is
	void get_position(double & latitude,double & longitude) const;

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

