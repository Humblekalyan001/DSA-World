class Solution 
{
public:
  vector<vector<string>> res;
  
  bool isValid(vector<string> &board, int row, int col)
  {
    // same column
    for(int i=row-1; i>=0; i--)
    {
      if(board[i][col] == 'Q')
      {
        return false;
      }
    }
    // left diagonal
    for(int i=row-1,j=col-1; i>=0 and j>=0; i--,j--)
    {
      if(board[i][j] == 'Q')
      {
        return false;
      }
    }
    // right diagonal
    for(int i=row-1, j = col+1; i>=0 and j<board.size(); i--,j++)
    {
      if(board[i][j] == 'Q')
      {
        return false;
      }
    }
    return true;
  }
  
  void nQueen(vector<string> &board, int row)
  {
    if(row == board.size())
    {
      res.push_back(board);
      return;
    }
    else
    {
      // selecting column one by one
      for(int j=0; j<board.size(); j++)
      {
        if(isValid(board,row,j)) // call to check for row and columns
        {
          // make decision and put queen
          board[row][j] = 'Q';
          
          // go for next row / next iteration
          nQueen(board,row+1);
          
          // if not satisfied then backtrack and put '.'
          board[row][j] = '.';
        }
      }
    }
  }
  
  vector<vector<string>> solveNQueens(int n) 
    {
    vector<string> board(n,string(n,'.')); // 1D board making and initialize with all '.'//
    nQueen(board,0);
    return res;
        
    }
};
