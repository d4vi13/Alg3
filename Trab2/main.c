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

    FILE* arq = fopen("entrada", "r");
    if (arq == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *word = NULL;
    int dist = 0;

    LerUmaConsulta(arq, &word, &dist);

    printf("%s %d\n", word, dist);

    fclose(arq);

    return 0;
}

