#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

array arr_construct(size_t length, size_t element_size) {
  array construct;
  construct.data = calloc(length, element_size);
  construct.length = length;
  construct.element_size = element_size;
  construct.freed = false;

  return construct;
}

array arr_from_raw(void *data, size_t length, size_t element_size) {
  array construct;
  construct.data = data;
  construct.length = length;
  construct.element_size = element_size;
  construct.freed = false;

  data = NULL;
  return construct;
}

void arr_delete(array *arr) {
  if (arr->freed) {
    return;
  }

  free(arr->data);
  arr->data = NULL;
  arr->length = 0;
  arr->freed = true;
}

void *arr_get(array *arr, size_t index) {
  size_t skip_amt = index * arr->element_size;
  if (arr->freed || skip_amt < 0 || skip_amt >= (arr->length * arr->element_size)) {
    return NULL;
  }

  char *data = arr_as(char *, *arr);

  return (void *)(data + skip_amt);
}

void arr_extend(array *arr, size_t extension) {
  size_t total_amt = arr->length + extension;

  void *construct;
  construct = calloc(total_amt, arr->element_size);

  memcpy(construct, arr->data, arr->length * arr->element_size);
  free(arr->data);

  arr->data = construct;
  arr->length = total_amt;
  arr->element_size = arr->element_size;
  arr->freed = false;
}
