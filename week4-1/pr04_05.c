#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void list_directory(const char *dir_path) {
    DIR *dp;
    struct dirent *dent;
    struct stat statbuf;
    char fullpath[1024];

    dp = opendir(dir_path);
    if (dp == NULL) {
        return;
    }

    while ((dent = readdir(dp)) != NULL) {
        if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_path, dent->d_name);

        if (stat(fullpath, &statbuf) == 0) {
            printf("Name: %s  Inode = %ld\n", dent->d_name, statbuf.st_ino);
        }

        if (dent->d_type == DT_DIR) {
            list_directory(fullpath);
        }
    }

    closedir(dp);
}

int main() {
    list_directory(".");
    return 0;
}

