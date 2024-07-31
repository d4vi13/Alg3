#include "common.h"
#include "dict/dict.h"
#include "trie/trie.h"
#include "consulta.h"
#include <stdio.h>

static inline void MountTrieTree(PDICT dict, PTRIE_TREE tree){
    memset(tree, 0, sizeof * tree);
	char *word;
    for (int i = 0; i < dict->MaxSize; i++){
        
		word = FetchWord(dict, i);
		if(word){
			InsertWord(tree, FetchWord(dict, i), i);
		}
    }
}

int main() {
    DICT dict;
    TRIE_TREE tree;
    FILE* src = fopen("src", "r");

    MountDict(src, &dict);
    MountTrieTree(&dict, &tree);

    KEY key;

    scanf("%d", &key);

    printf("%s\n", FetchWord(&dict, key));

    fclose(src);
    //DismountDict(&dict);


	int count, *a = malloc(1024*sizeof * a);


	RetrieveAllKeys(&tree, &a, &count);

	for (int i = 0; i < count; i++){
		printf("%d \n", a[i]);
	}

    return 0;
}

