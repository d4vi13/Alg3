#include "common.h"
#include "dict.h"
#include "trie.h"
#include "consulta.h"
#include <stdio.h>

static inline void MountTrieTree(PDICT dict, PTRIE_TREE tree){

    for (int i = 0; i < dict->MaxSize; i++){
        if (FetchWord(dict, i))
            InsertWord(tree, FetchWord(dict, i), i);
    }
}


static inline void createFile(){
    char* e = malloc(MAX_WORD_SIZE*sizeof*e);
    FILE* arq = fopen("src", "w");

    while(scanf("%s", e) >= 0){
        sprintf(e,"%s\n",e);
        fputs(e,  arq);
    }
    
    free(e);
    fclose(arq);
}

int main() {

    createFile();
    
    DICT dict;
    FILE *src = fopen("src", "r");

    PTRIE_TREE tree = TrieAlloc();

    MountDict(src, &dict);
    MountTrieTree(&dict, tree);


    FILE *arq = fopen("consultas.txt", "r");
    Consulta(arq, tree, &dict);
    fclose(arq);

    fclose(src);
    TrieFree(tree);
    DismountDict(&dict);
    
    return 0;
}

