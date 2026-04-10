#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct Pos2D {
    int r;
    int c;
};
typedef struct Pos2D Element;
#include "CircularDequeue.h"

#define MAZE_DIM 6
char map[MAZE_DIM][MAZE_DIM] = {
    {'1', '1', '1', '1', '1', '1'},
    {'0', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'}
};

void push_loc(int r, int c) {
    if (r < 0 || c < 0 || r >= MAZE_DIM || c >= MAZE_DIM) {
        return;
    }
    if (map[r][c] != '0' && map[r][c] != 'x') {
        return;
    }
    if (map[r][c] == '0') {
        map[r][c] = '.';
    }

    Element pos = {r, c};
    add_rear(pos);
}

Element pop_loc() {
    return delete_rear();
}

void print_maze() {
    Element here = get_rear();
    for (int r = 0; r < MAZE_DIM; r++) {
        for (int c = 0; c < MAZE_DIM; c++) {
            if (here.r == r && here.c == c) {
                printf("@");
            }
            else {
                printf("%c", map[r][c]);
            }
        }
        printf("\n");
    }
}

#include <windows.h>
void main() {
    init_deque();
    push_loc(1, 0);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int found = 0;

    while (is_empty() == 0) {
        system("cls");
        print_maze();
        Sleep(1000);

        Element here = get_rear();
        int r = here.r;
        int c = here.c;

        if (!found && map[r][c] == 'x') {
            found = 1;
            printf("\n미로 탈출 성공\n");
            pop_loc();
            continue;
        }

        if (found) {
            pop_loc();
            continue;
        }

        int moved = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < MAZE_DIM
                && nc < MAZE_DIM
                && (map[nr][nc] == '0' || map[nr][nc] == 'x')) {
                push_loc(nr, nc);
                moved = 1;
                break;
            }
        }

        if (!moved) {
            pop_loc();
        }
    }
    printf("\n미로 탈출 실패\n");
}