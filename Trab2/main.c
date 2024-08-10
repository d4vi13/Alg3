#include "common.h"
#include "dict/dict.h"
#include "trie/trie.h"
#include "consulta.h"
#include <stdio.h>

/*
static inline void MountTrieTree(PDICT dict, PTRIE_TREE tree){
    memset(tree, 0, sizeof * tree);

    for (int i = 0; i < dict->MaxSize; i++){
        InsertWord(tree, FetchWord(dict, i), i);
    }
}
*/

int main() {
    /*
    DICT dict;
    TRIE_TREE tree;
    FILE* src = fopen("src", "r");

    MountDict(src, &dict);
    MountTrieTree(&dict, &tree);

    KEY key;

    scanf("%d", &key);

    printf("%s\n", FetchWord(&dict, key));

    fclose(src);
    DismountDict(&dict);
    */

    PTRIE_TREE t  = TrieAlloc();	

    InsertWord(t, "davi", 1);
    InsertWord(t, "banana", 2);
    InsertWord(t, "bananas", 8);
    InsertWord(t, "fusca", 3);
    InsertWord(t, "banco", 4);
    
    
    int a = RetrieveKey(t, "banana");
    printf("%d\n", a);


    TrieFree(t);
    return 0;
}

