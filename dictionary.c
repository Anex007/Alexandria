#include "dictionary.h"
#include <stdlib.h>

dict* dict_new(size_t start_size)
{
	dict *d = malloc(sizeof(dict));
	d->list = LIST_new(start_size, free);
	d->map = hmap_init(start_size, free);
	return d;
}

void dict_insert(dict *d, char *key, void *item)
{
	hmap_insert(d->list, key, item);
	LIST_insert(d->map, key);
