/**
 * @fileName Dictionary.c.
 * @author komat
 * @version 0.0
 * @date 8/2/16.
 * @description
 */

#include "Dictionary.h"


/**
 *
 * @param dict
 * @return
 */
dictionary *dictionary_new(hash *dict) {
    hash_item *pair = dict->head;

    dictionary *self;
    if (!(self = malloc(sizeof(dictionary)))) {
        return NULL;
    }
    self->next = pair;

    return self;
}


/**
 *
 * @param self
 * @return
 */
hash_item *dictionary_next(dictionary *self) {
    hash_item *curr = self->next;
    if (curr)
        self->next = curr->next;
    return curr;
}


/**
 *
 * 削除
 *
 * @param self
 */
void dictionary_destroy(dictionary *self) {
    free(self);
    self = NULL;
}


/**
 *
 * key の値が存在していれば削除
 *
 * @param self
 * @param key
 */
void dictionary_remove(hash *self, char *key) {
    hash_item *pair = dictionary_get(self, key);

    if (!pair) return;

    pair->prev ? (pair->prev->next = pair->next) : (self->head = pair->next);

    pair->next ? (pair->next->prev = pair->prev) : (self->tail = pair->prev);

    if (self->free) self->free(pair->key, pair->val);

    free(pair);
}


/**
 *
 * key の値が存在していれば取得
 *
 * @param self
 * @param key
 * @return
 */
hash_item *dictionary_get(hash *self, char *key) {
    dictionary *it = dictionary_new(self);
    hash_item *pair;

    while ((pair = dictionary_next(it))) {
        if (strcmp(key, pair->key) == 0) {
            dictionary_destroy(it);
            return pair;
        }
    }

    dictionary_destroy(it);
    return NULL;
}


/**
 *
 * key / value を設定
 * 既に key が存在している場合は上書き
 *
 * @param self
 * @param key
 * @param val
 * @return
 */
hash_item *dictionary_set(hash *self, char *key, void *val) {

    hash_item *pair = dictionary_get(self, key);

    if (pair) {
        if (self->free) self->free(pair->key, pair->val);
        pair->val = val;
    } else {
        pair = dictionary_hash_new(key, val);
        if (self->head) {
            pair->prev = self->tail;
            pair->next = NULL;
            self->tail->next = pair;
            self->tail = pair;
        } else {
            self->head = self->tail = pair;
            pair->prev = pair->next = NULL;
        }
    }

    return pair;
}
