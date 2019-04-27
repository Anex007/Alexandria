#include "hashmap.h"

#define HASHME size_t h1 = hash(key) % hm->capacity

static char common;
static char* unique = &common;

hmap* hmap_init(size_t capacity, destroy_cb destroy)
{
	hmap *hm = malloc(sizeof(hmap));

	hm->capacity = capacity;
	hm->list = malloc(sizeof(void*) * capacity);
	memset(hm->list, unique, capacity * sizeof(void*));

	hm->destroy = destroy;
	hm->size = 0;
	return hm;
}

void hmap_insert(hmap *hm, const char *key, void *data)
{
	HASHME;
	hm->list[h1] = data;
	hm->size++;
}

void* hmap_get(hmap *hm, const char *key)
{
	HASHME;
	return hm->list[h1];
}

bool hmap_exists(hmap *hm, const char *key)
{
	HASHME;
	if (hm->list[h1] == unique)
		return false;
	return true
}

void hmap_remove(hmap *hm, const char *key)
{
	HASHME;
	hm->destroy(hm->list[h1]);
	hm->list[h1] = unique;
}

void hmap_delete(hmap *hm)
{
	for (size_t i = 0; i < hm->capacity; i++)
		if (hm->list[i] != unique)
			hm->destroy(hm->list[h1]);

	free(hm->list);
	free(hm);
	memset(hm, 0, sizeof(hmap));
}

static long hash(const char* data)
{
    long x;
    const unsigned char* p = data;
    int len = strlen(data);

    x = *data << 7;
    while (--len >= 0)
        x = (1000003*x) ^ *p++;
    x ^= strlen(data);
    if (x == 0)
        return -2;
    return x;
}

#undef HASHME
