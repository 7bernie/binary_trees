#include "binary_trees.h"
#include "121-avl_insert.c"
#include "122-array_to_avl.c"
#include "103-binary_tree_rotate_left.c"
#include "104-binary_tree_rotate_right.c"
#include "14-binary_tree_balance.c"

/**
* sorted_array_to_avl - Builds an AVL tree from a sorted array.
* @array: Pointer to first element of array to convert.
* @size:  Number of element in the array.
* Return: Pointer to root node of created AVL tree, or NULL on failure.
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (array_to_avl(array, size));
}
