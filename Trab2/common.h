#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_WORD_SIZE 1024

enum _bool{
    FALSE,
    TRUE
};

typedef enum _bool BOOL, *PBOOL;

#endif
