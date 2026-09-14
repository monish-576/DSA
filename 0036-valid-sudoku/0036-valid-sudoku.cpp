class Solution {
public:
    bool isValid(int row,int col,vector<vector<char>>&board,char num)
    {
          for(int i=0;i<9;i++)
          {
              if(board[i][col]==num) return false;
              if(board[row][i]==num) return false;
              if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
          }
          return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    char x=board[i][j];
                    board[i][j]='.';
                    if(!isValid(i,j,board,x))
                       return false;
                    board[i][j]=x;
                }
            }
        }
        return true;
    }
};