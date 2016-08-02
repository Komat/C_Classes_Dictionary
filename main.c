/**
 * @description
 * @fileName main.c.
 * @author komatsu
 * @version 0.0
 * @date 8/2/16.
 */

#include <stdio.h>
#include "classes/Dictionary/Dictionary.h"

int main(void) {


    /**
     * Dictionary Sample
     */
    hash *langs = hash_new();

    hash_template *c = dictionary_set(langs, "c", ".h");
    hash_template *c_head = dictionary_set(langs, "c", ".c");
    hash_template *js = dictionary_set(langs, "js", ".js");
    hash_template *ruby = dictionary_set(langs, "ruby", ".ruby");

    hash_template *pair;

    dictionary *it = dictionary_new(langs);

    printf("\n\n[01]\n");

    while ((pair = dictionary_next(it))) {
        printf("KEY : %s, VAL: %s\n", pair->key, (char *) pair->val);
    }

    hash_template *lang_js = dictionary_get(langs, "js");

    printf("LANG: %s\n", *lang_js);

    dictionary_destroy(it);

    it = dictionary_new(langs);

    dictionary_remove(langs, "js");

    printf("\n\n[02]\n");

    while ((pair = dictionary_next(it))) {
        printf("KEY : %s / VAL: %s\n", pair->key, (char *) pair->val);
    }

    dictionary_destroy(it);

    hash_destroy(langs);

    return 0;
}