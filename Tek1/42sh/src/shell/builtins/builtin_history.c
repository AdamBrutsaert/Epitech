/*
** EPITECH PROJECT, 2023
** builtin_history.c
** File description:
** builtin_history.c
*/

#include "shell/builtins.h"
#include "shell/history.h"
#include "my/memory.h"
#include "my/vector.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

static bool has_entry_same_cmd_after(vec_t *history, size_t pos, char *cmd)
{
    history_t *entry;

    for (size_t i = pos + 1; i < VEC_LEN(history); i++) {
        entry = (history_t *) vec_get(history, i);
        if (entry == NULL)
            break;
        if (strcmp(entry->cmd, cmd) == 0)
            return true;
    }
    return false;
}

static void print_it(vec_t *history)
{
    struct history_entry *history_entry;
    char time[6];

    for (ssize_t i = (ssize_t) VEC_LEN(history) - 1; i >= 0; i--) {
        history_entry = (struct history_entry *) vec_get(history, i);
        if (history_entry == NULL)
            break;
        strftime(time, 6, "%H:%M", localtime(&history_entry->entry->time));
        printf("%6ld\t%s\t%s\n", history_entry->pos + 1,
            time, history_entry->entry->cmd);
    }
}

void builtin_history(shell_t *shell)
{
    vec_t *global_history = shell_get_history(shell);
    ssize_t len = (ssize_t) VEC_LEN(global_history);
    vec_t *history = vec_new(sizeof(struct history_entry));
    history_t *entry;
    struct history_entry history_entry;

    for (ssize_t i = len - 1; i >= 0; i--) {
        entry = (history_t *) vec_get(global_history, i);
        if (entry == NULL)
            break;
        if (has_entry_same_cmd_after(global_history, i, entry->cmd))
            continue;
        history_entry.pos = i;
        history_entry.entry = entry;
        vec_push(history, &history_entry);
    }
    print_it(history);
    vec_delete(history);
    shell_set_status(shell, 0);
}
