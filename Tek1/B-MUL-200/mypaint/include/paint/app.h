/*
** EPITECH PROJECT, 2023
** app.h
** File description:
** app.h
*/

#pragma once

#include <stdbool.h>

typedef struct app app_t;

app_t *app_create(void);
void app_destroy(app_t *app);

bool app_run(app_t *app);
