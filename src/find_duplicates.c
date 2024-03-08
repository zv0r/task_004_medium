#define _GNU_SOURCE

#include "find_duplicates.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "misc.h"

int main(void) {
    File file1 = open_file();
    File file2 = open_file();

    compare_files(&file1, &file2);

    close_file(&file1);
    close_file(&file2);
    exit(EXIT_SUCCESS);
}

void compare_actions_byte_by_byte(const File* const file1, const File* const file2) {
    bool files_are_same = true;
    while (files_are_same) {
        int char1, char2;
        char1 = fgetc(file1->fp);
        char2 = fgetc(file2->fp);
        files_are_same = char1 == char2;
        if (char1 == EOF || char2 == EOF) {
            break;
        }
    }
    if (files_are_same) {
        remove(file2->path);
    }
}

void compare_action_empty(const File* const file1, const File* const file2) {
    if (file_is_empty(file1) && file_is_empty(file2)) {
        remove(file2->path);
        exit(EXIT_SUCCESS);
    }
}

void compare_files(const File* const file1, const File* const file2) {
    compare_action_empty(file1, file2);
    compare_actions_byte_by_byte(file1, file2);
}

bool file_is_empty(const File* const file) {
    fseek(file->fp, 0, SEEK_END);
    bool result = ftell(file->fp) == 0;
    fseek(file->fp, 0, SEEK_SET);
    return result;
}

void close_file(File* file) {
    free(file->path);
    fclose(file->fp);
}

File open_file() {
    File result = {.fp = NULL, .path = NULL};

    scanf("%ms", &result.path);

    if ((result.fp = fopen(result.path, "rb")) != NULL) {
        return result;
    } else {
        free(result.path);
        achtung();
    }
    return result;
}