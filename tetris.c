#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BLOCK_SIZE 4

int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
int current_piece[BLOCK_SIZE][BLOCK_SIZE] = {0};
int current_x = 0;
int current_y = 0;

// Фигуры тетриса
const int PIECES[7][BLOCK_SIZE][BLOCK_SIZE] = {
    // I
    {{0,0,0,0},
     {1,1,1,1},
     {0,0,0,0},
     {0,0,0,0}},
    // O
    {{0,0,0,0},
     {0,1,1,0},
     {0,1,1,0},
     {0,0,0,0}},
    // T
    {{0,0,0,0},
     {0,1,0,0},
     {1,1,1,0},
     {0,0,0,0}},
    // L
    {{0,0,0,0},
     {1,0,0,0},
     {1,1,1,0},
     {0,0,0,0}},
    // J
    {{0,0,0,0},
     {0,0,1,0},
     {1,1,1,0},
     {0,0,0,0}},
    // S
    {{0,0,0,0},
     {0,1,1,0},
     {1,1,0,0},
     {0,0,0,0}},
    // Z
    {{0,0,0,0},
     {1,1,0,0},
     {0,1,1,0},
     {0,0,0,0}}
};

void init_game() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);
    srand(time(NULL));
}

void draw_board() {
    clear();
    
    // Отрисовка поля
    for(int i = 0; i < BOARD_HEIGHT; i++) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            if(board[i][j])
                mvprintw(i, j*2, "[]");
            else
                mvprintw(i, j*2, "  ");
        }
    }
    
    // Отрисовка текущей фигуры
    for(int i = 0; i < BLOCK_SIZE; i++) {
        for(int j = 0; j < BLOCK_SIZE; j++) {
            if(current_piece[i][j]) {
                mvprintw(current_y + i, (current_x + j)*2, "[]");
            }
        }
    }
    
    refresh();
}

void new_piece() {
    int piece = rand() % 7;
    for(int i = 0; i < BLOCK_SIZE; i++)
        for(int j = 0; j < BLOCK_SIZE; j++)
            current_piece[i][j] = PIECES[piece][i][j];
    
    current_x = BOARD_WIDTH/2 - 2;
    current_y = 0;
}

int check_collision() {
    for(int i = 0; i < BLOCK_SIZE; i++) {
        for(int j = 0; j < BLOCK_SIZE; j++) {
            if(current_piece[i][j]) {
                if(current_y + i >= BOARD_HEIGHT || 
                   current_x + j < 0 || 
                   current_x + j >= BOARD_WIDTH ||
                   board[current_y + i][current_x + j])
                    return 1;
            }
        }
    }
    return 0;
}

void merge_piece() {
    for(int i = 0; i < BLOCK_SIZE; i++) {
        for(int j = 0; j < BLOCK_SIZE; j++) {
            if(current_piece[i][j]) {
                board[current_y + i][current_x + j] = 1;
            }
        }
    }
}

void clear_lines() {
    for(int i = BOARD_HEIGHT-1; i >= 0; i--) {
        int line_full = 1;
        for(int j = 0; j < BOARD_WIDTH; j++) {
            if(!board[i][j]) {
                line_full = 0;
                break;
            }
        }
        
        if(line_full) {
            for(int k = i; k > 0; k--) {
                for(int j = 0; j < BOARD_WIDTH; j++) {
                    board[k][j] = board[k-1][j];
                }
            }
            i++;
        }
    }
}

void rotate_piece() {
    int temp[BLOCK_SIZE][BLOCK_SIZE] = {0};
    
    // Копируем текущую фигуру
    for(int i = 0; i < BLOCK_SIZE; i++)
        for(int j = 0; j < BLOCK_SIZE; j++)
            temp[i][j] = current_piece[i][j];
    
    // Поворачиваем
    for(int i = 0; i < BLOCK_SIZE; i++)
        for(int j = 0; j < BLOCK_SIZE; j++)
            current_piece[i][j] = temp[BLOCK_SIZE-1-j][i];
    
    // Если collision, возвращаем обратно
    if(check_collision()) {
        for(int i = 0; i < BLOCK_SIZE; i++)
            for(int j = 0; j < BLOCK_SIZE; j++)
                current_piece[i][j] = temp[i][j];
    }
}

int main() {
    init_game();
    new_piece();
    
    while(1) {
        draw_board();
        
        int ch = getch();
        
        switch(ch) {
            case KEY_LEFT:
                current_x--;
                if(check_collision())
                    current_x++;
                break;
            case KEY_RIGHT:
                current_x++;
                if(check_collision())
                    current_x--;
                break;
            case KEY_UP:
                rotate_piece();
                break;
            case KEY_DOWN:
                current_y++;
                if(check_collision()) {
                    current_y--;
                    merge_piece();
                    clear_lines();
                    new_piece();
                    if(check_collision()) {
                        // Game Over
                        endwin();
                        return 0;
                    }
                }
                break;
            case 'q':
                endwin();
                return 0;
        }
        
        // Автоматическое падение
        current_y++;
        if(check_collision()) {
            current_y--;
            merge_piece();
            clear_lines();
            new_piece();
            if(check_collision()) {
                // Game Over
                endwin();
                return 0;
            }
        }
        
        usleep(100000);
    }
    
    endwin();
    return 0;
}
