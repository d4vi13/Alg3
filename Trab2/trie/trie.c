#include <string.h>
#include "trie.h"

void printLetterArray(PTRIE_NODE node){

    for (int i = 0; i < ALPH_LEN; i++){
        printf("%d ", node->letters[i] == NULL);
    }
    printf("\n");
}

PTRIE_NODE TrieAlloc(){
    PTRIE_NODE NewNode;

    NewNode =  malloc(sizeof * NewNode);
    if(!NewNode)
        return NULL;

    ZeroMemory(NewNode);

	NewNode->key = -1;

    return NewNode;
}

static inline BOOL TrieInsert(PTRIE_NODE node, char letter){
    PTRIE_NODE new;

    if (!LetterNode(node, letter)){

        new = TrieAlloc();
        if(!node)
            return FALSE;

        LetterNode(node, letter)= new;
    }

    return TRUE;
}

void InsertWord(PTRIE_TREE tree, char* word, int key){
    if (!word)
        return;

    PTRIE_NODE insertionNode = tree;
        
    for (int i = 0; i < strlen(word); i++){
        TrieInsert(insertionNode, word[i]);
        insertionNode = LetterNode(insertionNode, word[i]);
    }

    insertionNode->key = key;
}


inline int RetrieveKey(PTRIE_TREE tree, char* word){
    PTRIE_NODE node = tree;
    int i;
    for (i = 0; i < strlen(word); i++){
        if (!LetterNode(node, word[i]))
            return 0;
        node =  LetterNode(node,word[i]);
    }

    
    return node->key;
}

void RetrieveAllKeys(PTRIE_TREE tree, int** keys, int* count){
	printf("hi\n");
	if(tree->key >= 0){
		printf("alo ");
		*keys[*count] = tree->key;
		*count++;
		return;	
	}

	for (int i = 0; i < ALPH_LEN; i++){
		printf("oi\n");
		if (tree->letters[i])
			RetrieveAllKeys(tree->letters[i],keys,count);
	}

	return;

}

void TrieFree(PTRIE_TREE tree){
    for(int i = 0; i < ALPH_LEN; i++){
        if (tree->letters[i])
            TrieFree(tree->letters[i]);
    }
    free(tree);
}


