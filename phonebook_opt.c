#include <stdlib.h>
#include<string.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *hash_table[])
{
    /* TODO: implement */
    unsigned int hashV;
    entry *e;
    hashV=hash_func(lastName);
    e=hash_table[hashV];
    while(e != NULL) {
        if(strcasecmp(e->lastName,lastName)==0)
            return e;
        e=e->pNext;
    }
    return NULL;
}

void append(char lastName[], entry * hash_table[])
{
    /* allocate memory for the new entry and put lastName */
    entry *e;
    unsigned int hashV;

    e=(entry*)malloc(sizeof(entry));
    e->pNext=NULL;
    strcpy(e->lastName,lastName);
    hashV=hash_func(lastName);
    if(hash_table[hashV]==NULL) {
        hash_table[hashV]=e;
    } else {
        e->pNext=hash_table[hashV]->pNext;
        hash_table[hashV]->pNext=e;
    }

    return ;
}

unsigned int hash_func(char lastName[]) //djb2 hash function
{
    unsigned int hash_value=5381;
    int c;

    while ((c=*lastName++)) {
        hash_value=((hash_value<<5)+hash_value)+c;
    }
    return hash_value % SIZE_OF_HASH;
}



