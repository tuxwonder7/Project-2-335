#include "avl.h"

        /**
         * Construct the tree.
         */
        
        AVL_Tree::AVL_Tree () :
           root( NULL )
        {
        }

        /**
         * Copy constructor.
         */
       
  	 AVL_Tree::AVL_Tree ( const Tree & notFound) :
           ITEM_NOT_FOUND( notFound ),root( NULL )
        {
        }

        /**
         * Destructor for the tree.
         */
        
        AVL_Tree::~AVL_Tree( )
        {
            clear( );
        }

        /**
         * Insert x into the tree; duplicates are ignored.
         */
        
        void AVL_Tree::insert( const Tree & x )
        {
            insert( x, root );
        }

        /**
         * Remove x from the tree. Nothing is done if x is not found.
         */
        
        void AVL_Tree::remove( const Tree & x )
        {
          remove(x, root);
        }
	void AVL_Tree::remove ( const Tree & x , treeNode * & t ){
		if ( t == NULL )
		t = new treeNode ( x , NULL , NULL ) ;
		else if ( x < t -> element ) {
			insert ( x , t -> leftChild ) ;
			if ( height ( t -> leftChild ) - height ( t -> rightChild ) == 2 )
			if ( x < t -> leftChild -> element )
			LL_rotation ( t ) ;
			else
			LR_rotation ( t ) ;
		}
		else if ( t -> element < x ) {
			insert ( x , t -> rightChild ) ;
			if ( height ( t -> rightChild ) - height ( t -> leftChild ) == 2 )
			if ( t -> rightChild -> element < x )
			RR_rotation ( t ) ;
			else
			RL_rotation ( t ) ;
		}
		else
		; // Duplicate ; do nothing
		t -> height = max ( height ( t -> leftChild ) , height ( t -> rightChild ) ) + 1;
	}

	

        /**
         * Find the smallest item in the tree.
         * Return smallest item or ITEM_NOT_FOUND if empty.
         */
        
        const Tree & AVL_Tree::findMin( ) const
        {
            return elementAt( findMin( root ) );
        }

        /**
         * Find the largest item in the tree.
         * Return the largest item of ITEM_NOT_FOUND if empty.
         */
        
        const Tree & AVL_Tree::findMax( ) const
        {
            return elementAt( findMax( root ) );
        }

        /**
         * Find item x in the tree.
         * Return the matching item or ITEM_NOT_FOUND if not found.
         */
        
        const Tree & AVL_Tree::find( const Tree & x ) const
        {
            return elementAt( find( x, root ) );
        }

        /**
         * Make the tree logically empty.
         */
        
        void AVL_Tree::clear( )
        {
            clear( root );
        }

        /**
         * Test if the tree is logically empty.
         * Return true if empty, false otherwise.
         */
        
        bool AVL_Tree::isEmpty( ) const
        {
            return root == NULL;
        }

     

        /**
         * Deep copy.
         */
        
        const AVL_Tree &AVL_Tree::operator=( const AVL_Tree & rhs )
        {
            if( this != &rhs )
            {
                clear( );
                root = clone( rhs.root );
            }
            return *this;
        }

        /**
         * Internal method to get element field in node t.
         * Return the element field or ITEM_NOT_FOUND if t is NULL.
         */
        
        const Tree & AVL_Tree::elementAt( treeNode *t ) const
        {
            if( t == NULL )
               return ITEM_NOT_FOUND;
            else
               return t->element;
        }

        /**
         * Internal method to insert into a subtree.
         * x is the item to insert.
         * t is the node that roots the tree.
         */
        
        void AVL_Tree::insert( const Tree & x, treeNode * & t ) const
        {
		//cout << "Temp checking" << endl;
	    
            if( t == NULL ){
		
                t = new treeNode( x, NULL, NULL );
		//cout << " THINGGGG " << t->element.borough_name() << endl;
		const_cast<AVL_Tree *>(this)->allTreeBoro.push_back(t->element.borough_name());
		const_cast<AVL_Tree *>(this)->allSpeciesInputed.push_back(t->element.common_name());
		//const_cast<AVL_Tree *>(this)->allSpeciesIDInputed.push_back(t->element.currID());
		
		}
            else if( x < t->element )
            {
                insert( x, t->leftChild);
                if( height( t->leftChild) - height( t->rightChild) == 2 )
                    if( x < t->leftChild->element )
                        LL_rotation( t );
                    else
                        LR_rotation( t );
            }
            else if( t->element < x )
            {
                insert( x, t->rightChild);
                if( height( t->rightChild) - height( t->leftChild) == 2 )
                    if( t->rightChild->element < x )
                        RR_rotation( t );
                    else
                        RL_rotation( t );
            }
            else
                ;  // Duplicate; do nothing
		
            t->height = max( height( t->leftChild), height( t->rightChild) ) + 1;
        }

        /**
         * Internal method to find the smallest item in a subtree t.
         * Return node containing the smallest item.
         */
        void AVL_Tree::incrementTotal(){ totalNodeInsert++; }
	void AVL_Tree::decrementTotal(){ totalNodeInsert--; }
        AVL_Tree::treeNode * AVL_Tree::findMin( treeNode *t ) const
        {
            if( t == NULL)
                return t;

            while( t->leftChild!= NULL )
                t = t->leftChild;
            return t;
        }

        /**
         * Internal method to find the largest item in a subtree t.
         * Return node containing the largest item.
         */
        
        AVL_Tree::treeNode * AVL_Tree::findMax( treeNode *t ) const
        {
            if( t == NULL )
                return t;

            while( t->rightChild!= NULL )
                t = t->rightChild;
            return t;
        }

        /**
         * Internal method to find an item in a subtree.
         * x is item to search for.
         * t is the node that roots the tree.
         * Return node containing the matched item.
         */
        
        AVL_Tree::treeNode *AVL_Tree::find( const Tree & x, treeNode *t ) const
        {
        if ( NULL == t )
		return NULL ;
	else if ( x < t -> element )
		return find ( x , t -> leftChild ) ;
	else if ( t -> element < x )
		return find ( x , t -> rightChild ) ;
	else
	    return t ; // found it
        }

        /**
         * Internal method to make subtree empty.
         */
        
        void AVL_Tree::clear( treeNode * & t ) const
        {
            if( t != NULL )
            {
                clear( t->leftChild);
                clear( t->rightChild);
                delete t;
            }
            t = NULL;
        }

        /**
         * Internal method to clone subtree.
         */
        
        AVL_Tree::treeNode * AVL_Tree::clone( treeNode * t ) const
        {
            if( t == NULL )
                return NULL;
            else
                return new treeNode( t->element, clone( t->leftChild),clone( t->rightChild), t->height );
        }

        /**
         * Return the height of node t or -1 if NULL.
         */
        
        int AVL_Tree::height( treeNode *t ) const
        {
            return t == NULL ? -1 : t->height;
        }

        /**
         * Return maximum of lhs and rhs.
         */
        
        int AVL_Tree::max( int lhs, int rhs ) const
        {
            return lhs > rhs ? lhs : rhs;
        }

        /**
         * Rotate binary tree node with leftChildchild.
         * For AVL trees, this is a single rotation for case 1.
         * Update heights, then set new root.
         */
        
        void AVL_Tree::LL_rotation( treeNode * & k2 ) const
        {
            treeNode *k1 = k2->leftChild;
            k2->leftChild= k1->rightChild;
            k1->rightChild= k2;
            k2->height = max( height( k2->leftChild), height( k2->rightChild) ) + 1;
            k1->height = max( height( k1->leftChild), k2->height ) + 1;
            k2 = k1;
        }

        /**
         * Rotate binary tree node with rightChildchild.
         * For AVL trees, this is a single rotation for case 4.
         * Update heights, then set new root.
         */
        
        void AVL_Tree::RR_rotation( treeNode * & k1 ) const
        {
            treeNode *k2 = k1->rightChild;
            k1->rightChild= k2->leftChild;
            k2->leftChild= k1;
            k1->height = max( height( k1->leftChild), height( k1->rightChild) ) + 1;
            k2->height = max( height( k2->rightChild), k1->height ) + 1;
            k1 = k2;
        }

        /**
         * Double rotate binary tree node: first leftChildchild.
         * with its rightChildchild; then node k3 with new leftChildchild.
         * For AVL trees, this is a double rotation for case 2.
         * Update heights, then set new root.
         */
        
        void AVL_Tree::LR_rotation( treeNode * & k3 ) const
        {
            RR_rotation( k3->leftChild);
            LL_rotation( k3 );
        }

        /**
         * Double rotate binary tree node: first rightChildchild.
         * with its leftChildchild; then node k1 with new rightChildchild.
         * For AVL trees, this is a double rotation for case 3.
         * Update heights, then set new root.
         */
        
        void AVL_Tree::RL_rotation( treeNode * & k1 ) const
        {
            LL_rotation( k1->rightChild);
            RR_rotation( k1 );
        }

        /**
         * Internal method to print a subtree in sorted order.
         * t points to the node that roots the tree.
         */
        
        void AVL_Tree::printTree( treeNode *t ) const //preorder
        {
		
		//cout << t->element<< " COmmon" << endl;
            if( t != NULL )
            {
		 cout << t->element << height(t)  << " Left child call " << endl;//" REE and root height " << height(t)
                printTree( t->leftChild);
               	 cout << "right child" << endl;
                printTree( t->rightChild);
            }
        }


	   /**
         * Print the tree contents in sorted order.
         */
        
        void AVL_Tree::printTree( ) const
        {
            if( isEmpty( ) )
                cout << "Empty tree" << endl;
            else
                printTree( root );
        }



	/* Function to print level order traversal a tree*/
	




	/* AVL_Tree::treeNode *AVL_Tree::find( const Tree & x, treeNode *t ) const
        {
        if ( NULL == t )
		return NULL ;
	else if ( x < t -> element )
		return find ( x , t -> leftChild ) ;
	else if ( t -> element < x )
		return find ( x , t -> rightChild ) ;
	else
	    return t ; // found it
        }*/

	void AVL_Tree::printInorder() const
	{
		printInorderRec(root);
	     
	}

	 void AVL_Tree::printInorderRec(treeNode * node) const{
	     if (node == NULL)
		  return;
	 
	     /* first recur on left child */
	     printInorderRec(node->leftChild);
	 
	     /* then print the data of node */
	     cout << node->element << endl;
	 
	     /* now recur on right child */
	     printInorderRec(node->rightChild);

	}
	
	list<string> AVL_Tree::getAllInZip(int zipcode) const{
		list<string> treeList;
		getAllInZipRec(zipcode, root, treeList);
		return treeList;
	}


	 void  AVL_Tree::getAllInZipRec(int zipcode, treeNode* t, list<string>& treeList) const{
		if(t == NULL){}
		else{
		 getAllInZipRec(zipcode, t->leftChild, treeList);
		  if(t->element.zip() == zipcode){
			treeList.push_back(t->element.common_name());
		  }
		 getAllInZipRec(zipcode, t->rightChild, treeList);
		}
	 } 
//#include "haversine.cpp"




	list<string> AVL_Tree::get_all_near(double latitude, double longitude, double distance) const{
		list<string> tempList;
		 get_all_nearFunc(latitude, longitude, distance, tempList, root);
		return tempList;
	}
	void AVL_Tree::get_all_nearFunc(double latitude, double longitude, double distance, list<string>& tempList, treeNode * t) const{
		double longitudex, latitudex;
		t->element.get_position(latitudex, longitudex);
		int distancex = haversine(latitude, longitude,latitudex, longitudex); 
		if(distance > distancex){ tempList.push_back(t->element.common_name());}
	}


	
	double AVL_Tree::haversine(  double lat1, double lon1, double lat2, double lon2) const
	{
	    lat1        = TO_RAD * lat1;
	    lat2        = TO_RAD * lat2;
	    lon1        = TO_RAD * lon1;
	    lon2        = TO_RAD * lon2;
	    double dLat = (lat2 - lat1)/2;
	    double dLon = (lon2 - lon1)/2;
	    double a    = sin(dLat);
	    double b    = sin(dLon);
	    return 2*R * asin(sqrt(a*a + cos(lat1) * cos(lat2) * b*b));
	}
 







	list < Tree > AVL_Tree::findallmatches ( const Tree & x ) const{
		/*list<Tree> allMatches;
		//cout << this->root->element << " ROOOOOOOOOOOOOOOOOOOOOOOOOT " << " and species " << x << endl;
		findallmatchesRec(x, this->root, allMatches);
		//cout << allMatches.size() << " The currList size" << endl;
		//cout << " REEE " << endl;
		return allMatches;*/
		list<Tree> allMatches;
		Tree t1(0,0,"","", x.common_name(), 0, "", "",0,0);
		Tree t2(999999, 0, "", "", x.common_name(), 0, "", "", 0, 0);
		utility_findallmatches(root, allMatches, t1, t2);
		cout << "Size of all matches " << allMatches.size() << endl;
		return allMatches;
	}

	void AVL_Tree::utility_findallmatches(treeNode* t, list<Tree>& treeList, const Tree& x, const Tree& z) const{
		if(t == NULL){ return;}
		/*if(islessname(x,root->element)){
			utility_findallmatches(t->leftChild, treeList, x, z);
		}
		if((islessname(x,root->element)) && (islessname(root->element, z))){
			treeList.push_back(t->element);
		}
		if(islessname(root->element, z)){
			utility_findallmatches(t->rightChild, treeList, x, z);
		}*/
		if(x < t->element){
			//string testFirstThingx = "true";
			//string testThing = "";
			//if(islessname(x,root->element)){ testThing = "true";}else{ testThing = "false";}
			//cout << "(x < t->element)" << testFirstThingx <<  " anddd thing " << testThing << endl; 
			utility_findallmatches(t->leftChild, treeList, x, z);
			//testThing = "";
		}
		if((x< t->element) && (t->element < z))
			treeList.push_back(t->element);
		if(t->element < z)
			utility_findallmatches(t->rightChild, treeList, x, z);

	}


	
	AVL_Tree::treeNode* AVL_Tree::findallmatchesRec( const Tree& x, treeNode *root, list<Tree>& currList) const{
		//cout << "testarooooo " << endl;
		if(NULL == root){cout << " NULL " << endl; return NULL;}
		if(islessname(x,root->element)){ cout << "Less than  "<< root->element  << endl; return findallmatchesRec(x, root->leftChild, currList);}
		if(islessname(root->element, x)){ cout<< "More than  " << root->element  << endl; return findallmatchesRec(x, root->rightChild, currList);}
		if(samename(x,root->element)){ cout << "Equal " << root->element << endl; currList.push_back(root->element); 
			//cout << "Before left if" << endl;
				//if(root->leftChild != NULL && samename(x,root->leftChild->element)){cout << " made it through left" << endl; return findallmatchesRec(x, root->leftChild, currList);}
					//if(root->leftChild == NULL){ cout << "Size " << currList.size() << endl; }
				//else if(root->rightChild != NULL && samename(x,root->rightChild->element)){cout << " made it through right" << endl; return findallmatchesRec(x, root->leftChild, currList);}
				cout << "Before if equal " << x << root->leftChild->element<< endl;
				cout << "\nBefore if equal " << x << root->rightChild->element<< endl;
				//else{ cout << "Size " << currList.size() << endl; return root; }
				if(islessname(x,root->leftChild->element)){ cout << "Less than in Equal  "<< root->element  << endl; return findallmatchesRec(x, root->leftChild, currList);}
				else if(islessname(root->rightChild->element, x)){ cout<< "More than in Equal  " << root->element  << endl; return findallmatchesRec(x, root->rightChild, currList);}
				//cout << " AFter left if" << endl;
		}	
	} 
	


	unsigned int AVL_Tree::AVL_TreeNodes_count_recursive(const treeNode *root) const
	{
	    unsigned int count = 1;
	    if (root->leftChild != NULL) {
	       count += AVL_TreeNodes_count_recursive(root->leftChild);
	    }
	    if (root->rightChild != NULL) {
		count += AVL_TreeNodes_count_recursive(root->rightChild);
	    }
	    return count;
	}
	 
	unsigned int AVL_Tree::AVL_TreeNodes_count() const
	{
	    unsigned int count = 0;
	    if (this->root != NULL) {
		count = AVL_TreeNodes_count_recursive(this->root);
	    }
	    return count;
	}
	unsigned int AVL_Tree::AVL_TreeNodes_count_of_tree_species(const string& species_name) const{
	    unsigned int count = 0;
	    if (this->root != NULL) {
		//cout << " ree" << endl;
		cout << this->root->element << endl;
		//count = AVL_TreeNodes_count_of_tree_species_recursive(species_name, this->root);
	    }
	    return count;
	}
	unsigned int AVL_Tree::AVL_TreeNodes_count_of_tree_species_recursive(const string& species_name, const treeNode *root) const{
	 unsigned int count = 0	;	
	if ( NULL == root )
		return count ;
	else if ( species_name < root -> element.common_name() )
		AVL_TreeNodes_count_of_tree_species_recursive( species_name , root -> leftChild ) ;
	else if ( root -> element.common_name() < species_name )
		AVL_TreeNodes_count_of_tree_species_recursive( species_name , root -> rightChild ) ;
	else{
	    count++; // found one
		AVL_TreeNodes_count_of_tree_species_recursive( species_name , root -> leftChild );	
	  }
	}


/*

unsigned int count = 1;
	    cout << species_name << " and " << root -> element.common_name() << root->element.zip() << endl;
	    if ((root->leftChild != NULL) && ( species_name < root -> element.common_name())) {
		cout << "test1" << endl;
	       count += AVL_TreeNodes_count_of_tree_species_recursive(species_name, root->leftChild);
	    }
	    if ((root->rightChild != NULL) && ( root -> element.common_name() < species_name  )) {
		cout << "test2" << endl;
		if(r
		count += AVL_TreeNodes_count_of_tree_species_recursive(species_name, root->rightChild);
	    }
	    return count;
*/


	int AVL_Tree::getTotalSpec(const string& species_name) const{ 
	 int count = 0; 
	
	 for(int x = 0; x < allSpeciesInputed.size(); x++){
	  if(allSpeciesInputed.at(x) == species_name) count++;
	   }  
	 return count;
	 }

	int AVL_Tree::getTotalBoro(const string& boro_name)const {
		
 		int count = 0;
		//cout << " reetree boro count " << allTreeBoro.size() << endl;
		for(int x = 0; x < allTreeBoro.size(); x++){
		 if(allTreeBoro.at(x) == boro_name){
		  
		  count++;
		 }
		//  cout << count << "De count and thing " << allTreeBoro.at(x)  << endl;
		}
		if(count < 1) return 0;
		return count;
	    }















