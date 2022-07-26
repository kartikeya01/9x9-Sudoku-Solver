#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector< vector<int> >& sudoku,int n, int val){
    for(int i = 0; i < n; i++){
        //row check
        if(sudoku[row][i] == val){
            return false;
        }
        //col check
        if(sudoku[i][col] == val){
            return false;
        }
        //3x3 grid check
        if(sudoku[ 3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == val){
            return false;
        }
    }
    
    return true;
}
bool solveSudoku(vector< vector<int> >& sudoku, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(sudoku[i][j] == 0){
                for(int testVal = 1; testVal <=9; testVal++){
                    if(isSafe(i, j, sudoku, n, testVal)){
                        sudoku[i][j] = testVal;

                        bool ans = solveSudoku(sudoku, n);
                        if(ans){
                            return true;
                        }
                        else{
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    
    return true;
}
void getSudoku(vector< vector<int> > &sudoku, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>sudoku[i][j];
        }
    }
}

void printSodoku(vector< vector<int> > &sudoku, int n){
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n = 9;
    vector< vector<int> > sudoku(n, vector<int>(n,0));
    
    cout<<endl;
    cout<<"Welcome to the 9x9 Sudoku Solver: "<<endl<<endl;
    cout<<"Enter the Sudoku puzzle row by row while enetering 0 for all the blank spots: "<<endl;
    cout<<endl;
    getSudoku(sudoku, n);

    if(solveSudoku(sudoku, n)){
        cout<<endl;
        cout<<"Solving.........."<<endl;
        cout<<endl;
        cout<<"Soltuion: "<<endl<<endl;
        printSodoku(sudoku, n);
        cout<<endl;
    }

    else{
        cout<<endl<<"Invalid Sudoku!!!!! "<<endl<<"Solution not possible."<<endl;
        cout<<endl;
    }
    
    return 0;
}