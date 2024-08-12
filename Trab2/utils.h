#ifndef UTILS_H
#define UTILS_H

#include "common.h"

#define dist_From_A_to_a 'a' - 'A'

#define IsLowerCase(letter) ((letter >= 'a') && (letter <= 'z'))
#define IsUpperCase(letter) IsLowerCase(letter+dist_From_A_to_a)
#define IsSpecialCaracter(letter) !(IsUpperCase(letter) || IsLowerCase(letter))
#define LowerCase(letter) letter+dist_From_A_to_a
#define CONVERSION_TABLE_SIZE 50

extern BOOL normalizeWord(unsigned char* word);

extern unsigned int GetLineCount(FILE* src);

extern char* GetWord(FILE** src);

char* Normalized(char **word, char** copy);

extern char* GetNormalizedWord(FILE** src, char** copy);

#endif
