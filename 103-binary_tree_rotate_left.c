#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on binary tree
 * @tree: Pointer to root node of the tree to rotate
 *
 * Return: Pointer to new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);
	tree->parent = tree->right;
	if (tree->right)
	{
		tree->right = tree->right->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;
		if (tree->right)
			tree->right->parent = tree;
		return (tree->parent);
	}
	return (tree);
}
