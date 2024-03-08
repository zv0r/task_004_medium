#include "cryptography.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "misc.h"

int main(void) {
    FILE* fp = open_file();

    encrypt_file(fp);

    fclose(fp);
    exit(EXIT_SUCCESS);
}

char encrypt(char symbol, char key) {
    char result;
    if (symbol >= 'a' && symbol <= 'z') {
        result = ((symbol - FIRST_LETTER_CODE + key - FIRST_LETTER_CODE) % 26) + FIRST_LETTER_CODE;
    } else {
        result = symbol;
    }
    return result;
}

char normalize_symbol(char symbol) {
    if (symbol >= 'A' && symbol <= 'Z') {
        symbol += 32;
    }
    return symbol;
}

void encrypt_file(FILE* fp) {
    size_t counter = 0;
    char* abc = ENCRYPTION_KEY;
    size_t abc_length = strlen(abc);
    size_t abc_position = 0;
    char current_symbol, current_symbol_encrypted;
    while ((current_symbol = normalize_symbol(fgetc(fp))) != EOF) {
        abc_position = counter % abc_length;
        current_symbol_encrypted = encrypt(current_symbol, abc[abc_position]);
        fseek(fp, -1, SEEK_CUR);
        fputc(current_symbol_encrypted, fp);
        if (current_symbol != current_symbol_encrypted) {
            counter++;
        }
    }
}

FILE* open_file() {
    char* tmp_path;
    scanf("%ms", &tmp_path);
    FILE* fp = fopen(tmp_path, "r+");
    free(tmp_path);
    if (fp == NULL) {
        achtung();
    }
    return fp;
}