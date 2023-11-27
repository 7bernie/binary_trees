#include "binary_trees.h"
/**
 * binary_tree_insert_left - Function creates a binary tree node
 * @parent: Pointer to the parent node of created node
 * @value: Value to put in the new node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nodo = NULL;

	if (parent == NULL)
		return (NULL);

	nodo = binary_tree_node(parent, value);
	if (nodo == NULL)
		return (NULL);

	if (parent->left == NULL)
	{
		parent->left = nodo;
	}
	else
	{
		nodo->left = parent->left;
		parent->left = nodo;
		nodo->left->parent = nodo;
	}

	return (nodo);
}
