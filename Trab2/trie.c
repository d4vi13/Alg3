#include <string.h>
#include "trie.h"

void printLetterArray(PTRIE_NODE node){

    for (int i = 0; i < ALPH_LEN; i++){
        printf("%d ", node->letters[i] != NULL);
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
    for (i = 0; i < strlen(word) ; i++){
        if (!LetterNode(node, word[i]))
            return 0;
        node =  LetterNode(node,word[i]);
        //printLetterArray(node);
        //printf("%d\n", node->key);
    }

    
    return node->key;
}

void RetrieveAllKeys(PTRIE_TREE t, int* keys, int *count){

    PTRIE_NODE p = t; 

    if (t->key >= 0 ){
        keys[*count] = t->key; 
        (*count)++;
    }

    for(int i = 0; i < ALPH_LEN; i++){
        if (p->letters[i])
            RetrieveAllKeys(p->letters[i], keys, count);
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


