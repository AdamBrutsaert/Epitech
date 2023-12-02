/*
** EPITECH PROJECT, 2023
** app_create.c
** File description:
** app_create.c
*/

#include "private/paint/app.h"
#include "my/memory.h"

static bool create(app_t *app)
{
    app->ctx = context_create(1280, 720, "My Paint");
    app->painting = painting_create();
    app->toolbox = toolbox_create();
    app->menu = menu_create();

    return app->ctx && app->painting && app->toolbox && app->menu;
}

static bool push(app_t *app)
{
    return context_push(app->ctx, app->painting)
        && context_push(app->ctx, app->toolbox)
        && context_push(app->ctx, app->menu);
}

static void set(app_t *app)
{
    toolbox_bind_tool(app->toolbox, painting_get_tool(app->painting));
    menu_bind_canvas(app->menu, painting_get_canvas(app->painting));
    menu_bind_tool(app->menu, painting_get_tool(app->painting));
}

app_t *app_create(void)
{
    app_t *app = my_calloc(sizeof(app_t));

    if (!app)
        return NULL;
    if (!create(app) || !push(app)) {
        app_destroy(app);
        return NULL;
    }
    set(app);
    return app;
}
