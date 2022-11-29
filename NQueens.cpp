#include <iostream>
#include <vector>
using namespace std;

bool possible(vector<vector<char>>& board, int row, int col, int n)
{
    // check row and col
    for(int i = 0; i < n;i++)
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
    for(int c = col; c >= 0 && r < n;r++, c--)
      if(board[r][c] == 'Q')
        return false;
    
    // check top right diagonal
    r = row;
    for(int c = col; c < n && r >= 0; c++, r--)
      if(board[r][c] == 'Q')
        return false;
    
    // check bottom right diagonal
    r = row;
    for(int c = col; c < n && r < n; r++, c++)
      if(board[r][c] == 'Q')
        return false;

    return true;
}
  
void saveBoard(vector<vector<char>>& board, vector<vector<string>>& lst)
{
    vector<string> l;
    int n = board.size();
    for(int i = 0; i < n; i++)
    {
        string s = "";
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 'Q')
                s += "Q";
            else
                s += ".";
        }
        l.push_back(s);
    }
    lst.push_back(l);
}
  
  // using backtracking 
void place(vector<vector<char>>& board, vector<vector<string>>& lst, int col, int n)
{
    // if n queens have been placed
    if(col == n)
    {
        saveBoard(board, lst);
        return;
    }
    
    for(int i = 0; i < n;i++)
    {
        if(possible(board, i, col, n))
        {
            board[i][col] = 'Q';
            place(board, lst, col+1, n);
            board[i][col] = '.';
        } 
    }
}
  
vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<char>> board;
    
    for(int i = 0; i < n; i++) 
    {
    	vector<char> v(n, '.');
    	board.push_back(v);
    }
    
    vector<vector<string>> lst; 
    place(board, lst, 0, n);
    return lst;
}

void print(vector<vector<string>> v)
{
	for(vector<string> vs : v) 
	{
		for(string s : vs)
			cout << s << endl;
		cout << "\n";
	}
}

int main()
{
	vector<vector<string>> v = solveNQueens(4);
	cout << "4 x 4\n" << endl;
	print(v);
	
	cout << "\n";
	v = solveNQueens(5);
	cout << "5 x 5\n" << endl;
	print(v);
	return 0;
}