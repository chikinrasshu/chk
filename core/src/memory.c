#include <chk/memory.h>

#include <stdlib.h>

void *get_memory(Size amount) {
  // Ensure the allocated memory is zero-filled, we're in the 21st century
  return calloc(amount, 1);
}

void free_memory(void *ptr) {
  // Wrap free, xd
  return free(ptr);
}
