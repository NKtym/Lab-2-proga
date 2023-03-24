#include "intvector.h"

intvector *int_vector_new(size_t initial_capacity) {
  intvector *v = NULL;
  v = malloc(sizeof(*v));
  if (!v)
    return NULL;
  v->data = calloc(initial_capacity, sizeof(int));
  if (!v->data) {
    free(v);
    return NULL;
  }
  v->capacity = initial_capacity;
  return v;
}

intvector *int_vector_copy(const intvector *v) {
  intvector *copy = NULL;
  copy = malloc(sizeof(*v));
  copy->capacity=int_vector_get_capacity(v);
  if (!copy)
    return NULL;
  copy->data = calloc(copy->capacity, sizeof(int));
  if (!copy->data) {
    free(copy);
    return NULL;
  }
  for (int i = 0; i < copy->capacity; i++) {
    copy->data[i] = v->data[i];
  }
  copy->capacity=v->capacity;
  copy->size=v->size;
  return copy;
}

void int_vector_free(intvector *v) {
  free(v->data);
  free(v);
}

int int_vector_get_item(const intvector *v, size_t index) {
  int get = v->data[index];
  return get;
}

void int_vector_set_item(intvector *v, size_t index, int item) {
  if (int_vector_get_size(v) < int_vector_get_capacity(v)) {
    v->data[index] = item;
    v->size++;
  } else {
    int_vector_push_back(v, item);
    v->size++;
  }
}

size_t int_vector_get_size(const intvector *v) { return v->size; }

size_t int_vector_get_capacity(const intvector *v) { return v->capacity; }

int int_vector_push_back(intvector *v, int item) {
  size_t size = int_vector_get_size(v);
  size_t cap = int_vector_get_capacity(v);
  if (size < cap) {
    v->data[size] = item;
    v->size++;
  } else {
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * sizeof(int));
    if (!v->data) {
      free(v);
      return -1;
    }
    v->data[size] = item;
    v->size++;
  }
  if (v->data[size] == item)
    return 0;
  else
    return -1;
}

void int_vector_pop_back(intvector *v) {
  if (int_vector_get_size(v) != 0) {
    for (int i = int_vector_get_capacity(v) - 1; i > 0; i--) {
      if (v->data[i] > 0) {
        v->data[i] = 0;
        v->size--;
        break;
      }
    }
  }
}

int int_vector_shrink_to_fit(intvector *v) {
  v->capacity = int_vector_get_size(v);
  v->data = realloc(v->data, int_vector_get_capacity(v) * sizeof(int));
  if (!v->data) {
    free(v);
    return -1;
  }
  if (int_vector_get_capacity(v) == int_vector_get_size(v))
    return 0;
  else
    return -1;
}

int int_vector_resize(intvector *v, size_t new_size) {
  if (int_vector_get_size(v) < new_size &&
      new_size < int_vector_get_capacity(v)) {
    for (int i = int_vector_get_size(v); i < new_size; i++) {
      v->data[i] = 0;
    }
    v->size = new_size;
  } else if (new_size < int_vector_get_size(v)) {
    for (int i = new_size; i < int_vector_get_size(v); i++) {
      v->data[i] = 0;
    }
    v->size = new_size;
    // v->size=new_size;
    // int_vector_shrink_to_fit(v);
  } else if (new_size > int_vector_get_capacity(v)) {
    v->data=realloc(v->data,new_size * sizeof(int));
    if(!v->data){
	free(v);
	return -1;
    }
    for (int i = int_vector_get_capacity(v); i < new_size; i++) {
      v->data[i] = 0;
    }
    v->size = new_size;
  }
  if (int_vector_get_size(v) == new_size)
    return 0;
  else
    return -1;
}

int int_vector_reserve(intvector *v, size_t new_capacity) {
  if (new_capacity <= int_vector_get_capacity(v))
    return 0;
  v->data = realloc(v->data, new_capacity * sizeof(int));
  if (!v->data) {
    free(v);
    return -1;
  }
  v->capacity = new_capacity;
  if (v->capacity == int_vector_get_capacity(v))
    return 0;
  else
    return -1;
}
