#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#define ENCRYPTION_KEY "peeredu"
#define FIRST_LETTER_CODE 97

#include <stdio.h>

FILE* open_file();

void encrypt_file(FILE* fp);

char normalize_symbol(char symbol);

char encrypt(char symbol, char key);

#endif