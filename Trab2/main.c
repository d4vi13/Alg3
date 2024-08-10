#include "common.h"
#include "dict/dict.h"
#include "trie/trie.h"
#include "consulta.h"
#include <stdio.h>

static inline void MountTrieTree(PDICT dict, PTRIE_TREE tree){

    for (int i = 0; i < dict->MaxSize; i++){
        if (FetchWord(dict, i))
            InsertWord(tree, FetchWord(dict, i), i);
    }
}

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

    DICT dict;
    FILE *src = fopen("src", "r");

    PTRIE_TREE tree = TrieAlloc();

    MountDict(src, &dict);
    MountTrieTree(&dict, tree);
    KEY key;

    for (int i =0 ; i < dict.entryCount; i++){
        if(dict.words[i]){
            printf("%s %s\n", dict.words[i], dict.unnormalized_words[i]);
        }
    }

    int a = 0, *b = malloc(1024*sizeof*b);

    RetrieveAllKeys(tree, b, &a);

    for (int i = 0; i < a; i++){
        printf("%d %s\n", b[i], dict.unnormalized_words[b[i]]);
    }

    free(b);


    scanf("%d", &key);

    printf("%s\n", FetchWord(&dict, key));

    fclose(src);
    TrieFree(tree);
    DismountDict(&dict);

/* 
    PTRIE_TREE t  = TrieAlloc();	

    InsertWord(t, "davi", 1);
    InsertWord(t, "banana", 2);
    InsertWord(t, "bananas", 8);
    InsertWord(t, "fusca", 3);
    InsertWord(t, "banco", 4);
    
    
    int c = RetrieveKey(t, "banana");
    printf("ou : %d\n", c);


    int a = 0, *b = malloc(1024*sizeof*b);

    RetrieveAllKeys(t, b, &a);

    for (int i = 0; i < a; i++){
        printf("%d\n", b[i]);
    }

    free(b);

    TrieFree(t); */
    return 0;
}

