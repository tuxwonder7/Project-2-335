/*******************************************************************************
  Title          : inputHandler.h
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : The interface file for the AVL_Tree class, represents object called AVL_Tree with name, location, etc of trees within a AVL_Tree implementation
  Purpose        : Represents object called AVL (Balanced Tree)
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/
#define R 6372.8
#define TO_RAD (3.1415926536 / 180)
#ifndef _avl_h_
#define _avl_h_
#include <iostream>
#include <list>
#include <vector>
#include "tree.h"
#include <math.h>
static const int ALLOWED_IMBALANCE = 1; //Ensures balance
//Tree to balance trees
   class AVL_Tree
        {
          public:
		//Default constructor
            AVL_Tree();
		//Copy Constructor for Tree copy
            AVL_Tree( const Tree & notFound);
		//Defualt Destructor
            ~AVL_Tree( );
		//Copy Constructor for AVL tree, copies node and such
	    AVL_Tree ( const AVL_Tree & Tree );
		//Find minimum element
		//Public warppers
            const Tree & findMin( ) const;
		//Finds maximum element
            const Tree & findMax( ) const;
		//finds element based on tree
            const Tree & find( const Tree & x ) const;
		//Checks if the tree is empty
            bool isEmpty( ) const;
		//Prints the current tree to screen
            void printTree( ) const;
		//Clear the tree
            void clear( );
		//Insert tree into AVL_Tree
            void insert( const Tree & x );
		//Remove tree from AVL_Tree
            void remove( const Tree & x );
		//Finds all matches of tree and returns a list of tree type
	    list < Tree > findallmatches ( const Tree & x ) const ;
		//Overloaded operator to ensure equal AVL_Tree's
            const AVL_Tree & operator=( const AVL_Tree & rhs );
		//Returns total node count
	    int totalNodes(){ return totalNodeInsert;}
		//TreeNode count
	    unsigned int AVL_TreeNodes_count() const;
		//Returns total amount of trees with same species as int
	    unsigned int AVL_TreeNodes_count_of_tree_species(const string& species_name) const;
		//Gets the total borough count
	    
	    void printInorder() const;
	    	//Returns a list of strings of the elements in a zipcode
	    list<string> getAllInZip(int zipcode) const;
		//Returns a list of strings of the elements that are within distance
	    list<string> get_all_near(double latitude, double longitude, double distance ) const;
		//Helper function to calculate within distance of another element
	    double haversine(  double lat1, double lon1, double lat2, double lon2) const;
	  //Vars
          private:
	    struct treeNode
		{
		Tree element ;
		treeNode * leftChild ;
		treeNode * rightChild ;
		int height;
		treeNode(  const Tree& item , treeNode* lt , treeNode*rt, int h = 0 ):element(item), leftChild(lt), rightChild(rt), height( h ) {
		}
	    }; treeNode *root;
		  // Avl manipulations
	    	//Gets the root from strcut treeNode
	    treeNode* getRoot() const;  
		//Searchs the avl tree with the root and with the help of haversine
	    void get_all_nearFunc(double latitude, double longitude, double distance, list<string>& tempList,  treeNode * t) const;  
		//Checks each node for the zip (O (N) time)
	    void  getAllInZipRec(int zipcode, treeNode* t, list<string>& treeList) const; 
		//returns a tree that is the element at that location of node
            const Tree & elementAt( treeNode *t ) const; 
		//used to prevent issue of finding nodes
	    const Tree ITEM_NOT_FOUND; 
		//Helper function to insert nodes with balancing
            void insert( const Tree & x, treeNode * & t ) const;
		//Helper function that checks less than O(N) time for all species that are equal to x(passed)
 	    void utility_findallmatches( const Tree& x, const treeNode* currNode, list<Tree>& allMatches) const; 
		//Helper function for findMin
            treeNode * findMin( treeNode *t ) const;
		//Helper function for findMax
            treeNode * findMax( treeNode *t ) const;
		//Helper fucntion for find (checks pre order)
            treeNode * find( const Tree & x, treeNode *t ) const;
		//Helper function to clear tree
            void clear( treeNode * & t ) const;
		//Helper function to print in order
	    void printInorderRec(treeNode * node) const;
		//Helper fucntion to print the tree in pre order
            void printTree( treeNode *t ) const;
		//Helper function to clone tree
            treeNode * clone( treeNode *t ) const;
		//Name implies usage 
	    int totalNodeInsert = 0;
                //returns height of tree (helper)
            int height( treeNode *t ) const;
		//returns max of two 
            int max( int lhs, int rhs ) const;
		//helper LL
            void LL_rotation( treeNode * & k2 ) const;
		//helper RR
            void RR_rotation( treeNode * & k1 ) const;
		//Helper LR
            void LR_rotation( treeNode * & k3 ) const;
		//Helper Right rotate (In case the previous ones were self-explanitory)
            void RL_rotation( treeNode * & k1 ) const;
		//Helper to recursive call to find total count of tree nodes with same root
	    unsigned int AVL_TreeNodes_count_recursive(const treeNode *root) const;
		//returns the total count of species of a certain type
	    unsigned int AVL_TreeNodes_count_of_tree_species_recursive(const string& species_name, const treeNode *root) const;
		//remove node from tree
	    void  remove ( const Tree & x , treeNode * & t );

  };

#endif
