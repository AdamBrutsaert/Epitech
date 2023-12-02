/*
** EPITECH PROJECT, 2022
** file.c
** File description:
** file.c
*/

#include "my/file.h"
#include "my/memory.h"
#include "my/string.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char get_type(struct stat *stats)
{
    if (S_ISREG(stats->st_mode))
        return FILE_TYPE_REGULAR;
    if (S_ISDIR(stats->st_mode))
        return FILE_TYPE_DIRECTORY;
    if (S_ISCHR(stats->st_mode))
        return FILE_TYPE_CHARACTER_DEVICE;
    if (S_ISBLK(stats->st_mode))
        return FILE_TYPE_BLOCK_DEVICE;
    if (S_ISFIFO(stats->st_mode))
        return FILE_TYPE_FIFO;
    if (S_ISLNK(stats->st_mode))
        return FILE_TYPE_SYMBOLIC_LINK;
    if (S_ISSOCK(stats->st_mode))
        return FILE_TYPE_SOCKET;
    return FILE_TYPE_NONE;
}

static uint16_t get_permission(struct stat *stats)
{
    uint16_t permissions = 0;

    if (stats->st_mode & S_ISUID) permissions |= FILE_PERMISSION_UID;
    if (stats->st_mode & S_ISGID) permissions |= FILE_PERMISSION_GID;
    if (stats->st_mode & S_ISVTX) permissions |= FILE_PERMISSION_STICKY;
    if (stats->st_mode & S_IRUSR) permissions |= FILE_PERMISSION_UR;
    if (stats->st_mode & S_IWUSR) permissions |= FILE_PERMISSION_UW;
    if (stats->st_mode & S_IXUSR) permissions |= FILE_PERMISSION_UX;
    if (stats->st_mode & S_IRGRP) permissions |= FILE_PERMISSION_GR;
    if (stats->st_mode & S_IWGRP) permissions |= FILE_PERMISSION_GW;
    if (stats->st_mode & S_IXGRP) permissions |= FILE_PERMISSION_GX;
    if (stats->st_mode & S_IROTH) permissions |= FILE_PERMISSION_OR;
    if (stats->st_mode & S_IWOTH) permissions |= FILE_PERMISSION_OW;
    if (stats->st_mode & S_IXOTH) permissions |= FILE_PERMISSION_OX;
    return permissions;
}

int32_t file_get(file_t *file, char *path, char *name)
{
    struct stat stats;
    ssize_t len;

    if (lstat(path, &stats))
        return 84;
    file->type = get_type(&stats);
    file->permission = get_permission(&stats);
    file->links = stats.st_nlink;
    file->owner = getpwuid(stats.st_uid)->pw_name;
    file->group = getgrgid(stats.st_gid)->gr_name;
    file->size = stats.st_size;
    file->blocks = stats.st_blocks;
    file->dev_major = major(stats.st_rdev);
    file->dev_minor = minor(stats.st_rdev);
    file->last_modification = stats.st_mtime;
    file->name = name;
    file->path = path;
    len = readlink(path, file->symlink, PATH_MAX);
    if (len) file->symlink[len] = '\0';
    return 0;
}

char *get_path(char const *directory, char const *file)
{
    uint64_t length = my_strlen(directory) + my_strlen(file) +
        (directory[my_strlen(directory) - 1] != '/') + 1;
    char *string = malloc(length);

    my_strcpy(string, directory);
    if (directory[my_strlen(directory) - 1] != '/')
        my_strcat(string, "/");
    my_strcat(string, file);
    string[length - 1] = 0;
    return string;
}

int32_t file_read_directory(file_vector_t *vector, char const *name)
{
    DIR *dir = opendir(name);
    struct dirent *entry;
    file_t file;
    char *path;

    if (dir == NULL) {
        perror(name);
        return 84;
    }
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        path = get_path(name, entry->d_name);
        file_get(&file, path, my_strdup(entry->d_name));
        file_vector_push(vector, &file);
    }
    closedir(dir);
    return 0;
}
