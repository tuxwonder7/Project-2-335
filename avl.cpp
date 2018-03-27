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
            makeEmpty( );
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
            cout << "Sorry, remove unimplemented; " << x <<
                 " still present" << endl;
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
        
        const Tree & AVL_Tree::
                                 find( const Tree & x ) const
        {
            return elementAt( find( x, root ) );
        }

        /**
         * Make the tree logically empty.
         */
        
        void AVL_Tree::makeEmpty( )
        {
            makeEmpty( root );
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
         * Print the tree contents in sorted order.
         */
        
        void AVL_Tree::printTree( ) const
        {
            if( isEmpty( ) )
                cout << "Empty tree" << endl;
            else
                printTree( root );
        }

        /**
         * Deep copy.
         */
        
        const AVL_Tree &AVL_Tree::operator=( const AVL_Tree & rhs )
        {
            if( this != &rhs )
            {
                makeEmpty( );
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
            if( t == NULL )
                t = new treeNode( x, NULL, NULL );
            else if( x < t->element )
            {
                insert( x, t->leftChild);
                if( height( t->leftChild) - height( t->rightChild) == 2 )
                    if( x < t->leftChild->element )
                        rotateWithLeftChild( t );
                    else
                        doubleWithLeftChild( t );
            }
            else if( t->element < x )
            {
                insert( x, t->rightChild);
                if( height( t->rightChild) - height( t->leftChild) == 2 )
                    if( t->rightChild->element < x )
                        rotateWithRightChild( t );
                    else
                        doubleWithRightChild( t );
            }
            else
                ;  // Duplicate; do nothing
            t->height = max( height( t->leftChild), height( t->rightChild) ) + 1;
        }

        /**
         * Internal method to find the smallest item in a subtree t.
         * Return node containing the smallest item.
         */
        
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
            while( t != NULL )
                if( x < t->element )
                    t = t->leftChild;
                else if( t->element < x )
                    t = t->rightChild;
                else
                    return t;    // Match

            return NULL;   // No match
        }

        /**
         * Internal method to make subtree empty.
         */
        
        void AVL_Tree::makeEmpty( treeNode * & t ) const
        {
            if( t != NULL )
            {
                makeEmpty( t->leftChild);
                makeEmpty( t->rightChild);
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
        
        void AVL_Tree::rotateWithLeftChild( treeNode * & k2 ) const
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
        
        void AVL_Tree::rotateWithRightChild( treeNode * & k1 ) const
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
        
        void AVL_Tree::doubleWithLeftChild( treeNode * & k3 ) const
        {
            rotateWithRightChild( k3->leftChild);
            rotateWithLeftChild( k3 );
        }

        /**
         * Double rotate binary tree node: first rightChildchild.
         * with its leftChildchild; then node k1 with new rightChildchild.
         * For AVL trees, this is a double rotation for case 3.
         * Update heights, then set new root.
         */
        
        void AVL_Tree::doubleWithRightChild( treeNode * & k1 ) const
        {
            rotateWithLeftChild( k1->rightChild);
            rotateWithRightChild( k1 );
        }

        /**
         * Internal method to print a subtree in sorted order.
         * t points to the node that roots the tree.
         */
        
        void AVL_Tree::printTree( treeNode *t ) const
        {
            if( t != NULL )
            {
                printTree( t->leftChild);
                cout << t->element << endl;
                printTree( t->rightChild);
            }
        }
	











