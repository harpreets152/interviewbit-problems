/*

Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Seen this


*/

bool r[9][9], c[9][9], s[3][3][9];
        memset(r, false, sizeof(r));
        memset(c, false, sizeof(c));
        memset(s, false, sizeof(s));
        int number;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] > '0' && board[i][j] <='9') {
                    number = board[i][j] - '1';
                    if (r[i][number]) return false;
                    r[i][number] = true;
                    if (c[j][number]) return false;
                    c[j][number] = true;
                    if (s[i / 3][j / 3][number]) return false;
                    s[i / 3][j / 3][number] = true;
                }
            }
        }
        return true;
