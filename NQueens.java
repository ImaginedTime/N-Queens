import java.util.*;

class NQueens
{
	public static void main(String args[])
	{
		Solution s = new Solution();
		List<List<String>> ls = s.solveNQueens(4);
		System.out.println(ls); 
		System.out.println(); 
		
		ls = s.solveNQueens(5);
		System.out.println(ls); 
	}
}

class Solution 
{
  
  public boolean possible(char[][] board, int row, int col)
  {
    // check row and col
    for(int i = 0; i < board.length;i++)
    {
      if(board[i][col] == 'Q')
        return false;
      if(board[row][i] == 'Q')
        return false;
    }
    
    // check top left diagonal
    int r = row;
    for(int c = col; c >= 0 && r >= 0;c--, r--)
      if(board[r][c] == 'Q')
        return false;
    
    // check bottom left diagonal
    r = row;
    for(int c = col; c >= 0 && r < board.length;r++, c--)
      if(board[r][c] == 'Q')
        return false;
    
    // check top right diagonal
    r = row;
    for(int c = col; c < board.length && r >= 0; c++, r--)
      if(board[r][c] == 'Q')
        return false;
    
    // check bottom right diagonal
    r = row;
    for(int c = col; c < board.length && r < board.length; r++, c++)
      if(board[r][c] == 'Q')
        return false;

    return true;
  }
  
  public void saveBoard(char[][] board, List<List<String>> lst)
  {
    List<String> l = new ArrayList<>();
    for(int i = 0; i < board.length;i++)
    {
      String s = "";
      for(int j = 0; j < board.length;j++)
      {
        if(board[i][j] == 'Q')
          s += "Q";
        else
          s += ".";
      }
      l.add(s);
    }
    lst.add(l);
  }
  
  // using backtracking 
  public void place(char[][] board, List<List<String>> lst, int col)
  {
    // if n queens have been placed
    if(col == board.length)
    {
      saveBoard(board, lst);
      return;
    }
    
    for(int i = 0; i < board.length;i++)
    {
      if(possible(board, i, col))
      {
        board[i][col] = 'Q';
        place(board, lst, col+1);
        board[i][col] = '.';
      }
    }
  }
  
  public List<List<String>> solveNQueens(int n) 
  {
    char[][] board = new char[n][n];
    List<List<String>> lst = new ArrayList<>();
    
    place(board, lst, 0);
    return lst;
  }
}