#pragma once

#include <stdbool.h>
#include <stddef.h>

/**
 * A generic array implementation that stores the array length alongside the
 * array itself. Array data is stored as a void pointer, so the accessing code
 * needs to know what the data is itself.
 */
typedef struct {
  void *data;
  size_t length;
  size_t element_size;
  bool freed;
} array;

#define arr_as(type, arr) ((type)((arr).data))

/**
 * Construct an empty array structure with a given length and element size.
 * The array is initialized to 0.
 */
array arr_construct(size_t length, size_t element_size);

/**
 * Construct an array structure from a raw void array. This is a move operation,
 * and the original data pointer is marked as [NULL], and becomes inaccessible.
 */
array arr_from_raw(void *data, size_t length, size_t element_size);

/**
 * Frees the data related to an array. Using safe operations on a deleted array
 * generally return NULL. Before unsafe operations, check if the array is freed
 * through the [array.freed] member.
 */
void arr_delete(array *arr);

/**
 * Gets an address of an element from the array as a void pointer.
 * If the given index was out of bounds, or if the array was freed, this value
 * is null.
 */
void *arr_get(array *arr, size_t index);

/**
 * Extends the size of the array by [extension] elements.
 */
void arr_extend(array *arr, size_t extension);
