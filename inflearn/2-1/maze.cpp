#include <iostream>

#define PATHWAY_COLOUR 0
#define WALL_COLOUR 1
#define BLOCKED_COLOUR 2 //아니다(더이상 갈곳없다) 선택되면 이색깔
#define PATH_COLOUR 3 //일단 방문하면 녹색

using namespace std;

int N = 8;
int X,Y = 0;
int i = 0;

bool findMazePath(int x, int y, int maze[][8]) {
    X = x;
    Y = y;
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    else if (maze[x][y] != PATHWAY_COLOUR)
        return false;
    else if (x == N-1 && y == N-1) { // 여기가 바로 출구인 곳이다.
        maze[x][y] = PATH_COLOUR;
        return true;
    }
    else {
        maze[x][y] = PATH_COLOUR;
        if (findMazePath(x - 1, y, maze) || findMazePath(x, y + 1, maze) ||
        findMazePath(x + 1, y , maze) || findMazePath(x - 1, y, maze)) {
            return true;
        }
        maze[x][y] = BLOCKED_COLOUR;
        return false;
    }
}

void printMaze(){
    cout << "현재 위치" << endl;
    cout << "X 좌표: " << X <<  " Y좌표: " << Y << " i: " << i << endl;
}

int main() {
    int maze[][8] = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 1, 0, 1},
        {0, 1, 1, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0, 1, 0, 0},
    };

    printMaze();
    bool result = findMazePath(0, 0, maze);
    cout << "result: " << result << endl;
    printMaze();

    return 0;
}