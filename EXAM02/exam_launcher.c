/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:00:12 by igur              #+#    #+#             */
/*   Updated: 2025/06/07 22:00:15 by igur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_ASSIGNMENTS 100
#define MAX_PATH 512
#define LEVEL_COUNT 4

const char *levels[LEVEL_COUNT] = {"level1", "level2", "level3", "level4"};

// Recursive .c file collector
int collect_c_files(const char *base_path, char assignments[][MAX_PATH], int count) {
    DIR *dir = opendir(base_path);
    struct dirent *entry;
    char path[MAX_PATH];

    if (!dir) return count;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR &&
            strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", base_path, entry->d_name);
            count = collect_c_files(path, assignments, count);  // recurse
        } else if (entry->d_type == DT_REG && strstr(entry->d_name, ".c")) {
            snprintf(assignments[count], MAX_PATH, "%s/%s", base_path, entry->d_name);
            count++;
        }
    }

    closedir(dir);
    return count;
}

void pick_random_from_levels() {
    char assignments[MAX_ASSIGNMENTS][MAX_PATH];
    int count;

    srand(time(NULL));

    printf("\n🎯 Random Exam Pick:\n");

    for (int l = 0; l < LEVEL_COUNT; l++) {
        count = collect_c_files(levels[l], assignments, 0);

        if (count > 0) {
            int r = rand() % count;
            printf("📚 %s → %s\n", levels[l], assignments[r]);
        } else {
            printf("📚 %s → [No .c files found]\n", levels[l]);
        }
    }
}

int main(void) {
    char input;

    do {
        pick_random_from_levels();
        printf("\n🔁 Press [Enter] to re-roll, [q] to quit: ");
        input = getchar();
        while (getchar() != '\n'); // flush stdin
    } while (input != 'q');

    printf("🚀 Done. Go crush it!\n");
    return 0;
}
