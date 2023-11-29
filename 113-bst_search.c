#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree
 * @tree: Pointer to root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to node with a value equal to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	tmp = (bst_t *)tree;
	while (tmp)
	{
		if (tmp->n == value)
			return (tmp);
		if (tmp->n < value)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (NULL);
}
