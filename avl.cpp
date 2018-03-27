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



