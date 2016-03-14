#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define SIZE_OF_HASH 8191

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
typedef struct __PHONE_BOOK_DETAIL_ENTRY {
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail_entry;
typedef struct __PHONE_BOOK_SEARCH_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detail_entry *detail;
    struct __PHONE_BOOK_SEARCH_ENTRY *pNext;
} entry;
entry *findName(char lastName[], entry *hash_table[]);
void append(char lastName[], entry *hash_table[]);
unsigned int hash_func(char lastName[]);

#endif
