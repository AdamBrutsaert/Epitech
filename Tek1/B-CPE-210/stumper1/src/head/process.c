/*
** EPITECH PROJECT, 2023
** process.c
** File description:
** process.c
*/

#include "head.h"
#include "my/string.h"
#include "my/stdio.h"
#include "main.h"

static uint64_t number_of_lines(char const *string)
{
    uint64_t lines = 0;

    for (; *string; string++) {
        if (*string == '\n')
            lines++;
    }
    return lines;
}

static void get_lines_or_bytes(head_t *head, char *content,
    int64_t *lines, int64_t *bytes)
{
    uint64_t length = my_strlen(content);
    uint64_t lines_count = number_of_lines(content);

    *lines = 0;
    *bytes = 0;
    if (head->flags & FLAG_LINES) {
        if (head->lines < 0) {
            *lines = lines_count + head->lines;
        } else {
            *lines = head->lines;
        }
    }
    if (head->flags & FLAG_BYTES) {
        if (head->bytes < 0) {
            *bytes = length + head->bytes;
        } else {
            *bytes = head->bytes;
        }
    }
}

static void print_filename(head_t *head, char const *file, uint64_t index)
{
    if ((!(head->flags & FLAG_QUIET) && my_strarrlen(head->files) > 1)
        || head->flags & FLAG_VERBOSE) {
        if (index > 0)
            my_putc('\n');
        my_puts("==> ");
        my_puts(file);
        my_puts(" <==\n");
    }
}

static bool process_file(head_t *head, char const *file, uint64_t index)
{
    int64_t lines = 0;
    int64_t bytes = 0;
    char *content = open_file(file);

    if (!content)
        return false;
    get_lines_or_bytes(head, content, &lines, &bytes);
    print_filename(head, file, index);
    for (uint64_t i = 0; content[i] && (lines > 0 || bytes > 0); i++) {
        my_putc(content[i]);
        lines -= (lines != 0 && content[i] == '\n');
        bytes -= !!bytes;
    }
    free(content);
    return true;
}

int head_process(head_t *head)
{
    bool has_failed = false;

    if (my_strarrlen(head->files) == 0) {
        if (!process_file(head, "-", 0)) {
            has_failed = true;
        }
    }
    for (uint64_t i = 0; head->files[i]; i++) {
        if (!process_file(head, head->files[i], i)) {
            has_failed = true;
        }
    }
    return has_failed ? 1 : 0;
}
