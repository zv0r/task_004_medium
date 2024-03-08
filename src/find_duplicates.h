#ifndef FIND_DUPLICATES_H
#define FIND_DUPLICATES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct file_t {
    FILE* fp;
    char* path;
} File;

File open_file();

void close_file(File* fp);

bool file_is_empty(const File* const file);

void compare_files(const File* const file1, const File* const file2);

void compare_action_empty(const File* const file1, const File* const file2);

void compare_actions_byte_by_byte(const File* const file1, const File* const file2);

#endif