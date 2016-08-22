/**
 * @fileName Dictionary.h.
 * @author komat
 * @version 0.0
 * @date 8/2/16.
 * @description
 */

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H


#include "Hash.h"

/**
 *
 */
typedef struct {
    hash_item *next;
} dictionary;


/**
 *
 * @param self
 * @param key
 * @param val
 * @return
 */
hash_item *dictionary_set(hash *self, char *key, void *val);

/**
 *
 * @param self
 * @param key
 * @return
 */
hash_item *dictionary_get(hash *self, char *key);

/**
 *
 * @param self
 * @param key
 */
void dictionary_remove(hash *self, char *key);

/**
 *
 * @param dict
 * @return
 */
dictionary *dictionary_new(hash *dict);

/**
 *
 * @param self
 * @return
 */
hash_item *dictionary_next(dictionary *self);

/**
 *
 * @param self
 */
void dictionary_destroy(dictionary *self);


#endif //DICTIONARY_DICTIONARY_H
