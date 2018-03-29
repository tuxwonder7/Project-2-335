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
	//Default constructor to deal with string variable (references but only puts data into private elements
	Tree(const string & treedata);
	//Outputs to file through overloaded operator<<
	friend ostream& operator<< (ostream & os, const Tree & t);
	friend bool operator==(const Tree&t1, const Tree &t2);
	friend bool operator<(const Tree & t1, const Tree & t2);
	Tree& operator=(const Tree& other);
	friend bool samename(const Tree & t1,const Tree & t2);
	friend bool islessname(const Tree & t1,const Tree & t2);
	string common_name() const;
	string borough_name() const; 
	string nearest_address() const;
	int diameter() const; 
	int zip() const;
	int currID() const;
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

