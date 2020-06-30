//
//  main.cpp
//  37. Sudoku Solver 37 Sudoku Solver
//
//  Created by 睿于 on 2020/6/29.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 37 Sudoku Solver / Hard / Write a program to solve a Sudoku puzzle by filling the empty cells. Empty cells are indicated by the character '.'.

     Note:
     1 The given board contain only digits 1-9 and the character '.'.
     2 You may assume that the given Sudoku puzzle will have a single unique solution.
     3 The given board size is always 9x9.
 */

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <tuple>
using namespace::std;
typedef vector<vector<char>> grid;
typedef struct cell richNum;
typedef vector<vector<richNum>> richGrid;
typedef stack<tuple<int, int, int, richGrid, int>> stackAssum;


struct cell{
public:
    int num;
    set<int> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // possible options
    // construction function
    cell(int i=0){
        this->num = i;
    }
    // deconstruction function
    ~cell(){};
};

// update constrains
void update(richGrid& cells, int i, int j){
    int num = cells[i][j].num;
    // diable row
    for (int col=0; col<9; col++)
        cells[i][col].possible.erase(num);
    // disable column
    for (int row=0; row<9; row++)
        cells[row][j].possible.erase(num);
    // diable box
    int I = int(i/3); // 0, 1, 2
    int J = int(j/3); // 0, 1, 2
    for (int row=I*3; row<I*3+3; row++)
        for (int col=J*3; col<J*3+3; col++)
            cells[row][col].possible.erase(num);
}

// declaration
void enumerate(grid& board, richGrid& cells, int emptyCell);

// solve sudoku
void solveSudoku(grid& board) {
    vector<vector<cell>> cells(9, vector<cell>(9)); // richGrid
    int emptyCell = 81; // count of empty cells
    // board -> cells
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (board[i][j] != '.'){
                cells[i][j].num = board[i][j]-'0';
                emptyCell--;
                update(cells, i, j);
            }
        }
    }
    // find solution
    bool flag = 1; // solvable
    while (emptyCell && flag == 1) {
        flag = 0;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (cells[i][j].num == 0 && cells[i][j].possible.size() == 1){
                    flag = 1;
                    cells[i][j].num = *cells[i][j].possible.begin();
                    emptyCell--;
                    update(cells, i, j);
                }
            }
        }
    }
    // unsolvable, try enumerate method
    if (emptyCell != 0)
        enumerate(board, cells, emptyCell);
    // cells -> board
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            board[i][j] = cells[i][j].num + '0';
        }
    }
}

// make an assumption when the possible option is not unique
void giveATry(richGrid& cells, int& emptyCell, stackAssum& assumption){
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (cells[i][j].num == 0 && cells[i][j].possible.size() > 1){
                auto it = cells[i][j].possible.begin();
                // assumption stack
                while (++it != cells[i][j].possible.end())
                    assumption.push(make_tuple(i, j, *it, cells, emptyCell));
                // give a try
                auto lastTry = assumption.top();
                assumption.pop();
                cells = get<3>(lastTry);
                i = get<0>(lastTry);
                j = get<1>(lastTry);
                cells[i][j].num = get<2>(lastTry);
                emptyCell = get<4>(lastTry)-1;
                update(cells, i, j);
                return;
            }
        }
    }
}

// enumerate method
void enumerate(grid& board, vector<vector<cell>>& cells, int emptyCell){
    stack<tuple<int, int, int, richGrid, int>> assumption; // stackAssum
    giveATry(cells, emptyCell, assumption);
    bool flag = 1; // solvavle
    while (emptyCell) {
        flag = 0;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                // assumption failed, go back and try another assumption
                if (cells[i][j].num == 0 && cells[i][j].possible.size() == 0){
                    auto lastTry = assumption.top();
                    assumption.pop();
                    cells = get<3>(lastTry);
                    i = get<0>(lastTry);
                    j = get<1>(lastTry);
                    cells[i][j].num = get<2>(lastTry);
                    emptyCell = get<4>(lastTry)-1;
                    update(cells, i, j);
                    flag = 1;
                // assumption worked, keep going
                }else if (cells[i][j].num == 0 && cells[i][j].possible.size() == 1){
                    cells[i][j].num = *cells[i][j].possible.begin();
                    emptyCell--;
                    update(cells, i, j);
                    flag = 1;
                }
            }
        }
        // the possible option is not unique, give a try
        if (flag == 0)
            giveATry(cells, emptyCell, assumption);
    }
}

int main(int argc, const char * argv[]) {
    // test
    grid board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    grid board_2 = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}};
    solveSudoku(board_2);
    // print result
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout<< board_2[i][j] <<'\t';
        }
        cout<< '\n';
    }
    cout << endl;
    return 0;
}
