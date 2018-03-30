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
#define R 6372.8
#define TO_RAD (3.1415926536 / 180)
#ifndef _avl_h_
#define _avl_h_
#include <iostream>
#include <list>
#include <vector>
#include "tree.h"
#include <math.h>
static const int ALLOWED_IMBALANCE = 1;

   class AVL_Tree
        {
          public:
            AVL_Tree();
            AVL_Tree( const Tree & notFound);
            ~AVL_Tree( );
	    AVL_Tree ( const AVL_Tree & Tree );
            const Tree & findMin( ) const;
            const Tree & findMax( ) const;
            const Tree & find( const Tree & x ) const;
            bool isEmpty( ) const;
            void printTree( ) const;

            void clear( );
            void insert( const Tree & x );
            void remove( const Tree & x );
	    list < Tree > findallmatches ( const Tree & x ) const ;
            const AVL_Tree & operator=( const AVL_Tree & rhs );
	    int totalNodes(){ return totalNodeInsert;}
	    void incrementTotal();
	    void decrementTotal();
	    unsigned int AVL_TreeNodes_count() const;
	    unsigned int AVL_TreeNodes_count_of_tree_species(const string& species_name) const;
	    int getTotalSpec(const string& species_name) const;
	    int getTotalBoro(const string& boro_name)const;
	    void printInorder() const;
	    
	    list<string> getAllInZip(int zipcode) const;
	    list<string> get_all_near(double latitude, double longitude, double distance ) const;
	    double haversine(  double lat1, double lon1, double lat2, double lon2) const;



	 //   int const allSpeciesIDInputed(const string& boro_name)const {int count = 0; for(int x = 0; x < allTreeBoro.size(); x++){if(allTreeBoro.at(x) == boro_name) count++;} return count;}
          private:
            vector<string> allSpeciesInputed;
	    vector<string> allTreeBoro;
	   // vector<int> allSpeciesIDInputed;
	    struct treeNode
		{
		Tree element ;
		treeNode * leftChild ;
		treeNode * rightChild ;
		int height;
		treeNode(  const Tree& item , treeNode* lt , treeNode*rt, int h = 0 ):element(item), leftChild(lt), rightChild(rt), height( h ) {
		//cout << item <<  " ITEM " << endl;
		} //or do element = item (copy constructor maybe needed)
	    }; treeNode *root;
	    treeNode* getRoot() const;	
	    void get_all_nearFunc(double latitude, double longitude, double distance, list<string>& tempList,  treeNode * t) const;
	    void  getAllInZipRec(int zipcode, treeNode* t, list<string>& treeList) const;
	    treeNode* findallmatchesRec( const Tree& x, treeNode *root, list<Tree>& currList) const;
            const Tree & elementAt( treeNode *t ) const;
	    const Tree ITEM_NOT_FOUND;
            void insert( const Tree & x, treeNode * & t ) const;
 	    void utility_findallmatches( const Tree& x, const treeNode* currNode, list<Tree>& allMatches) const;
            treeNode * findMin( treeNode *t ) const;
            treeNode * findMax( treeNode *t ) const;
            treeNode * find( const Tree & x, treeNode *t ) const;
            void clear( treeNode * & t ) const;
	    void printInorderRec(treeNode * node) const;
            void printTree( treeNode *t ) const;
            treeNode * clone( treeNode *t ) const;
	    int totalNodeInsert = 0;
                // Avl manipulations
            int height( treeNode *t ) const;
            int max( int lhs, int rhs ) const;
            void LL_rotation( treeNode * & k2 ) const;
            void RR_rotation( treeNode * & k1 ) const;
            void LR_rotation( treeNode * & k3 ) const;
            void RL_rotation( treeNode * & k1 ) const;
	    unsigned int AVL_TreeNodes_count_recursive(const treeNode *root) const;
	    unsigned int AVL_TreeNodes_count_of_tree_species_recursive(const string& species_name, const treeNode *root) const;
	    void  remove ( const Tree & x , treeNode * & t );

  };

/*
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
		treeNode( const Tree& item , treeNode* lt , treeNode*rt): element(item), leftChild(lt), rightChild(rt) {} //or do element = item (copy constructor maybe needed)
		}; treeNode *root;
	void insert ( const Tree & x , treeNode * & t ) ;
	void remove ( const Tree & x , treeNode * & t ) ;
	treeNode * find ( const Tree & x , treeNode * t )const;
	treeNode * findMin ( treeNode * t ) const ;
	treeNode * findMax ( treeNode * t ) const ;
	void make_empty ( treeNode * t ) ;
	void print ( ostream & out , treeNode * t ) const ;
	treeNode * copy ( treeNode * t ) const ;
};*/
#endif
