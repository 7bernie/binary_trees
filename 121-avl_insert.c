#include "binary_trees.h"

/**
 * avl_insert_full - Inserts a value
 *
 * @tree: Pointer to the root
 * @parent: Parent of node
 * @value: Value input
 * Return: Pointer to new node node
 */
avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		new_node = binary_tree_node(parent, value);
		if (parent->n > new_node->n)
			parent->left = new_node;
		else
			parent->right = new_node;
		return (new_node);
	}
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (avl_insert_full(tree->left, tree, value));
	else
		return (avl_insert_full(tree->right, tree, value));
}


/**
 * val_balancer - Rebalances AVL tree if required
 *
 * @root: Pointer to root of the tree
 * @tree: Pointer to the node to rebalance
 * @value: Value for insertion
 * Return: 0
 */

void val_balancer(avl_t **root, avl_t *tree, int value)
{
	int new_balance;

	new_balance = binary_tree_balance(tree);
	if (new_balance > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (new_balance < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
				*root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}


/**
 * avl_insert - Insets the value in avl
 *
 * @tree: Double pointer to root
 * @value: Value input
 * Return: Pointer to the new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *predecessor;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}
	new_node = avl_insert_full(*tree, NULL, value);

	if (new_node == NULL)
		return (NULL);

	predecessor = new_node->parent;

	while (predecessor != NULL)
	{
		val_balancer(tree, predecessor, value);
		predecessor = predecessor->parent;
	}

	return (new_node);
}
