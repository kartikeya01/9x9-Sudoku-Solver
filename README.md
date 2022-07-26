# 9x9-Sudoku-Solver
This is a friendly 9x9 Sudoku Solver which uses the concepts of recursion and backtracking for solving the sudoku.

The Time Complexity of this Sudoku Solver is O(9^m) where m is the number of empty spots which are to be filled.
The Space Complexity of this Sudoku Solver is O(1) as the only space used is a 2D vector of size 9x9 and few variables which occupy constant space. The recursion stack can also have a maximum of 81 (9*9 = 81) calls which can be considered constant too.
