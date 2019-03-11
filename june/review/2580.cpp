#include <cstdio>
#include <cstring>

int map[9][9];
//위치와 숫자를 저장하기 위해서, 많이어려움 후;
bool check_cell[9][10] = {false,};
bool check_col[9][10] = {false,};;
bool check_row[9][10] = {false,};;


void sudoku() {
    int r = -1,c = -1;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(map[i][j] == 0) {
                r = i;
                c = j;
                break;
            }
        }
        if(r != -1) {
            break;
        }
    }

    if(r == -1) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d ", map[i][j]);
            } printf("\n");
        }
    }

    //0,1,2,
    //3,4,5,
    //6,7,8,
    int cell = 3*(r/3)+(c/3);
    for(int i=1; i<=9; i++) {
        if(!check_row[r][i] && !check_col[c][i] && !check_cell[cell][i]) {
            check_row[r][i] = check_col[c][i] = check_cell[cell][i] = true;
            map[r][c] = i;
            sudoku();
            map[r][c] = 0;
            check_row[r][i] = check_col[c][i] = check_cell[cell][i] = false;
        }
    }

}

int main() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int cell = 3*(i/3)+(j/3);
            scanf("%d", &map[i][j]);
            check_row[i][map[i][j]] = check_col[j][map[i][j]] = check_cell[cell][map[i][j]] = true;
        }
    }

    sudoku();

    return 0;
}
 