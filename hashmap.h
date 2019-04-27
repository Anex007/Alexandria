#ifndef HASHMAP_IMPL_ALEX
#define HASHMAP_IMPL_ALEX

#include <stdbool.h>
#include <stddef.h>

typedef	void(*destroy_cb)(void *ptr);

typedef struct
{
	size_t capacity;
	size_t size;
	destroy_cb destroy;
	void **list;
} hmap;

hmap* hmap_init(size_t capacity, destroy_cb destroy);
void hmap_insert(hmap *hm, const char *key, void *data);
void* hmap_get(hmap *hm, const char *key);
bool hmap_exists(hmap *hm, const char *key);
void hmap_remove(hmap *hm, const char *key);
void hmap_delete(hmap *hm);
static long hash(const char* data);

#endif /* HASHMAP_IMPL_ALEX */
