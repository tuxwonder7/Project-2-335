/*******************************************************************************
  Title          : inputHandler.h
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : The interface file for the Tree class, represents object called Tree with name, location, etc
  Purpose        : Represents object called Tree
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/

#ifndef _avl_h_
#define _avl_h_
#include <iostream>
#include <list>
#include "tree.h"

class AVL_Tree
	{
	public :
	AVL_Tree ( ); // default
	AVL_Tree ( const AVL_Tree & Tree ); // copy constructor
	~ AVL_Tree ( ); // destructor
	// Search methods :
	const Tree & find ( const Tree & x ) const ;
	
	const Tree & findMin () const ;
	const Tree & findMax () const ;
	list < Tree >& findallmatches ( const Tree & x ) const ;
	// Traversals :
	// prints the Tree objects onto the ostream using inorder traversal .
	// Each of the members of the Tree object is printed , in the exact
	// same order as they are above , e . g . , with the Tree spc_common name
	// first , then the Tree_id . Fields should be separated by commas
	// in the output stream .
	void print ( ostream & out ) const ; // prints the Tree objects
	// Methods to consider adding - getting all Trees in a zipcode ,
	// or near a given point
	// Tree modifiers :
	void clear (); // empty the Tree
	void insert ( const Tree & x ); // insert element x
	void remove ( const Tree & x ); // remove element x
	private:
		
		struct treeNode
		{
		Tree element ;
		treeNode * leftChild ;
		treeNode * rightChild ;
		//friend AVL_Tree;
		// treeNode(){}
		}; treeNode *root;
	void insert ( const Tree & x , treeNode * & t ) ;
	void remove ( const Tree & x , treeNode * & t ) ;
	treeNode * find ( const Tree & x , treeNode * t )const;
	treeNode * findMin ( treeNode * t ) const ;
	treeNode * findMax ( treeNode * t ) const ;
	void make_empty ( treeNode * t ) ;
	void print ( ostream & out , treeNode * t ) const ;
	treeNode * copy ( treeNode * t ) const ;
};



#endif
