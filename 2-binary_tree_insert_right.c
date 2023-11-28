#include "binary_trees.h"
/**
 * binary_tree_insert_right - Function creates a binary tree node
 * @parent: Pointer to the parent node of the created node
 * @value: Value to put in the new node
 * Return: Pointer to new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nodo = NULL;

	if (parent == NULL)
		return (NULL);

	nodo = binary_tree_node(parent, value);
	if (nodo == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		parent->right = nodo;
	}
	else
	{
		nodo->right = parent->right;
		parent->right = nodo;
		nodo->right->parent = nodo;
	}

	return (nodo);
}
