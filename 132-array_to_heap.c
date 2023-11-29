#include "binary_trees.h"

/**
* array_to_heap - Builds Max Binary Heap tree from an array.
* @array: Pointer to first element of array to convert
* @size: Number of element in the array.
* Return: Pointer to root of created Binary Heap, or NULL on failure.
*/
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t pos;

	for (pos = 0; pos < size; pos++)
		heap_insert(&tree, array[pos]);
	return (tree);
}
