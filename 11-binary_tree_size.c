#include "binary_trees.h"

/**
 * binary_tree_size - Measures size of a binary tree
 * @tree: Pointer to root node of the tree to measure size
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}
