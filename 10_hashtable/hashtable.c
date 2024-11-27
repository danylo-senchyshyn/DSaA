#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

unsigned int Hash(char *key, int htsize) {
    int i;
    unsigned int value = 0;
    for (i = 0; i < strlen(key); i++)
        value = (value << 5) + key[i];
    return value % htsize;
}

PHASHTABLE HTinit(int size) {
    int i;
    PHASHTABLE ht = malloc(sizeof(HASHTABLE));
    ht->size = size;
    ht->table = malloc(size * sizeof(PNODE));
    for (i = 0; i < size; i++)
        ht->table[i] = NULL;
    return ht;
}

void HTinsert(PHASHTABLE t, char *key) {
    unsigned int h;
    PNODE ptr, tmp;
    h = Hash(key, t->size);
    if (t->table[h] == NULL) {
        tmp = malloc(sizeof(NODE));
        tmp->key = key;
        tmp->next = NULL;
        t->table[h] = tmp;
    } else {
        ptr = t->table[h];
        while (ptr->next != NULL) {
            //no duplicate values
            if (strcmp(key, ptr->key) == 0)return;
            ptr = ptr->next;
        }
        //no duplicate values
        if (strcmp(key, ptr->key) == 0)return;
        tmp = malloc(sizeof(NODE));
        tmp->key = key;
        tmp->next = NULL;
        ptr->next = tmp;
    }
}

int HTmember(PHASHTABLE t, char *key) {
    unsigned int h;
    PNODE ptr;
    h = Hash(key, t->size);
    if (t->table[h] == NULL)return 0;
    ptr = t->table[h];
    while (ptr != NULL) {
        if (strcmp(key, ptr->key) == 0)return 1;
        ptr = ptr->next;
    }
    return 0;
}

void HTdelete(PHASHTABLE t, char *key) {
    if (key == NULL || t == NULL) {
        return;
    }

    unsigned int h = Hash(key, t->size);

    PNODE ptr = t->table[h];
    PNODE prev = NULL;

    if (ptr == NULL) {
        printf("Key '%s' not found in the hashtable.\n", key);
        return;
    }

    while (ptr != NULL) {
        if (strcmp(ptr->key, key) == 0) {
            if (prev == NULL) {
                t->table[h] = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("Key '%s' deleted from the hashtable.\n", key);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    printf("Key '%s' not found in the hashtable.\n", key);
}

void HTprint(PHASHTABLE t) {
    if (t == NULL) {
        //printf("Error: Hashtable is NULL.\n");
        return;
    }

    //printf("Hashtable contents:\n");

    for (int i = 0; i < t->size; i++) {
        printf("Slot %d:", i);

        PNODE ptr = t->table[i];

        if (ptr == NULL) {
            printf(" (empty)\n");
        } else {
            while (ptr != NULL) {
                printf(" -> %s", ptr->key);
                ptr = ptr->next;
            }
            printf("\n");
        }
    }
}