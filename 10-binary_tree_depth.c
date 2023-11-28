#include "binary_trees.h"

/**
 * binary_tree_depth - Measures depth of a binary tree
 * @tree: Pointer to root node of the tree to measure height
 * Return: 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL || (tree->parent == NULL))
		return (0);

	depth = binary_tree_depth(tree->parent);

	return (depth + 1);
}
