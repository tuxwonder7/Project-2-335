#include "avl.h"


AVL_Tree::AVL_Tree(){


}

const Tree & AVL_Tree::find ( const Tree & x ) const
{
	treeNode * t ;
	t = find (x , root ) ;
	if ( NULL != t )
	return t -> element ;
	else
		return x; //need fix
	// return some indication that it was not found
}


treeNode* AVL_Tree::find ( const Tree & x , treeNode *t ) const
{
	if ( NULL == t )
	 return NULL ;
	 else if ( x < t -> element )
	  return find ( x , t -> left ) ;
	 else if ( t -> element < x )
	  return find ( x , t -> right ) ;
	else
	return t ; // found it
}
