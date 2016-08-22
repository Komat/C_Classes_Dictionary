/**
 * @fileName Hash.h.
 * @author komat
 * @version 0.0
 * @date 8/2/16.
 * @description
 */

#ifndef DICTIONARY_HASH_H
#define DICTIONARY_HASH_H


#include <string.h>
#include <stdlib.h>

/**
 *
 */
typedef struct hash_item_type {
    struct hash_item_type *prev;
    struct hash_item_type *next;
    char *key;
    void *val;
} hash_item;


/**
 *
 */
typedef struct {
    hash_item *head;
    hash_item *tail;

    void (*free)(char *key, void *val);
} hash;


/**
 *
 * @param key
 * @param val
 * @return
 */
hash_item *dictionary_hash_new(char *key, void *val);

/**
 *
 * @return
 */
hash *hash_new();

/**
 *
 * @param self
 */
void hash_destroy(hash *self);

#endif //DICTIONARY_HASH_H
