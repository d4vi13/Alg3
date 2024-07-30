#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"

#define ZeroMemory(mem) memset(mem, 0, sizeof * mem)
#define LetterIndex(letter) letter - 'a'
#define LetterNode(node, letter) node->letters[LetterIndex(letter)]

#define ALPH_LEN 26

typedef struct TrieNode TRIE_NODE, *PTRIE_NODE;

typedef TRIE_NODE TRIE_TREE, *PTRIE_TREE;

struct TrieNode {
    PTRIE_NODE letters[ALPH_LEN];
    int key;
};

extern PTRIE_NODE TrieAlloc();

extern void InsertWord(PTRIE_TREE tree, char* word, int key);

extern int RetrieveKey(PTRIE_TREE tree, char* word);

extern void TrieFree(PTRIE_TREE tree);

#endif
