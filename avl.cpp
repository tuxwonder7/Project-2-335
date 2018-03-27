#include "avl.h"

AVL_Tree::AVL_Tree(){


}
/*treeNode* AVL_Tree::find ( const Tree & x , treeNode *t ) const
{
	if ( NULL == t )
	 return NULL ;
	 else if ( x < t -> element ) //Need to overload operator< in tree class
	  return find ( x , t -> leftChild ) ;
	 else if ( t -> element < x )
	  return find ( x , t -> rightChild ) ;
	else
	return t ; // found it
}*/

AVL_Tree::treeNode * AVL_Tree::find ( const Tree & x , treeNode * t )const{
	if ( NULL == t )
	 return NULL ;
	 else if ( x < t -> element ) //Need to overload operator< in tree class
	  return find ( x , t -> leftChild ) ;
	 else if ( t -> element < x )
	  return find ( x , t -> rightChild ) ;
	else
	return t ; // found it
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



