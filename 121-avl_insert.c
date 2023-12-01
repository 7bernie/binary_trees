#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_rotate_right(avl_t *y);
avl_t *avl_rotate_left(avl_t *x);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
                            avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Measures height of a binary tree.
 * @tree: Pointer to root node of tree to measure height.
 *
 * Return: 0 if tree is NULL, else height
 */
size_t height(const binary_tree_t *tree)
{
    if (tree != NULL)
    {
        size_t l = 0, r = 0;

        l = tree->left ? 1 + height(tree->left) : 1;
        r = tree->right ? 1 + height(tree->right) : 1;
        return ((l > r) ? l : r);
    }
    return (0);
}

/**
 * balance - Measures the balance factor of binary tree.
 * @tree: Pointer to root node of tree to measure balance factor.
 *
 * Return: 0 if tree is NULL, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
    return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_rotate_right - Rotate a subtree to the right.
 * @y: Root of the subtree to rotate.
 *
 * Return: New root of the rotated subtree.
 */
avl_t *avl_rotate_right(avl_t *y)
{
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

/**
 * avl_rotate_left - Rotate a subtree to the left.
 * @x: Root of the subtree to rotate.
 *
 * Return: New root of the rotated subtree.
 */
avl_t *avl_rotate_left(avl_t *x)
{
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: Double pointer to the root node of the AVL tree to insert into.
 * @parent: Parent node of the current working node.
 * @new: Double pointer to store the new node.
 * @value: Value to insert into the AVL tree.
 *
 * Return: Pointer to new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
                            avl_t **new, int value)
{
    int bfactor;

    if (*tree == NULL)
        return (*new = binary_tree_node(parent, value));

    if ((*tree)->n > value)
    {
        (*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
        if ((*tree)->left == NULL)
            return (NULL);
    }
    else if ((*tree)->n < value)
    {
        (*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
        if ((*tree)->right == NULL)
            return (NULL);
    }
    else
        return (*tree);

    bfactor = balance(*tree);
    if (bfactor > 1 && (*tree)->left->n > value)
        *tree = avl_rotate_right(*tree);
    else if (bfactor < -1 && (*tree)->right->n < value)
        *tree = avl_rotate_left(*tree);
    else if (bfactor > 1 && (*tree)->left->n < value)
    {
        (*tree)->left = avl_rotate_left((*tree)->left);
        *tree = avl_rotate_right(*tree);
    }
    else if (bfactor < -1 && (*tree)->right->n > value)
    {
        (*tree)->right = avl_rotate_right((*tree)->right);
        *tree = avl_rotate_left(*tree);
    }

    return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to root node of the AVL tree to insert value
 * @value: Value to insert into the AVL tree.
 *
 * Return: Pointer to inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new = NULL;

    if (tree == NULL)
        return (NULL);
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }
    avl_insert_recursive(tree, *tree, &new, value);
    return (new);
}
