#include "include.h"
static bool isExist = false;
struct point2d
{
	int i;
	int j;
	point2d(int _i, int _j) :i(_i), j(_j){}
	bool operator==(point2d rhd)
	{
		return i == rhd.i && j == rhd.j;
	}
};
void dfs(const vector<vector<char>>& board, const string& word, int k, vector<point2d>current_path)
{
	if (k == word.size() && !current_path.empty() && board[current_path.back().i][current_path.back().j] == word.back())
	{
		isExist = true;
		return;
	}
	if (isExist)return;
	vector<point2d>candidates;
	if (current_path.empty())
	{
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				candidates.push_back(point2d(i, j));
			}
		}
	}
	else
	{
		point2d current = current_path.back();
		if (current.i - 1 >= 0 && find(current_path.begin(), current_path.end(), point2d(current.i - 1, current.j)) == current_path.end())
		{
			candidates.push_back(point2d(current.i - 1, current.j));
		}
		if (current.j + 1 < board[0].size() && find(current_path.begin(), current_path.end(), point2d(current.i, current.j + 1)) == current_path.end())
		{
			candidates.push_back(point2d(current.i, current.j + 1));
		}
		if (current.i + 1 < board.size() && find(current_path.begin(), current_path.end(), point2d(current.i + 1, current.j)) == current_path.end())
		{
			candidates.push_back(point2d(current.i + 1, current.j));
		}
		if (current.j - 1 >= 0 && find(current_path.begin(), current_path.end(), point2d(current.i, current.j - 1)) == current_path.end())
		{
			candidates.push_back(point2d(current.i, current.j - 1));
		}
	}
	vector<point2d>ccandidates;
	for (auto point : candidates)
	{
		char next = board[point.i][point.j];
		if (next == word[k])
		{
			ccandidates.push_back(point);
		}
	}
	if (ccandidates.empty())return;
	for (auto point : ccandidates)
	{
		current_path.push_back(point);
		dfs(board, word, k + 1, current_path);
		current_path.pop_back();
	}
}
bool exist(vector<vector<char>>& board, string word)
{
	if (board.empty() || word.empty())
	{
		return false;
	}
	vector<point2d>current_path;
	dfs(board, word, 0, current_path);
	return isExist;
}

//
//bool exist(vector<vector<char>>& board, string word)
//{
//	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
//
//	for (int i = 0; i < board.size(); ++i)
//	{
//		for (int j = 0; j < board[0].size(); ++j)
//		{
//			if (R(board, word, i, j, 0, visited))
//				return true;
//		}
//	}
//
//	return false;
//}
//
//bool R(const vector<vector<char>>& board, const string& word, int r, int c, int p, vector<vector<bool>>& visited)
//{
//	if (p >= word.size())
//		return true;
//
//	if (!is_valid(board, r, c))
//		return false;
//
//	if (visited[r][c])
//		return false;
//
//	bool flag = false;
//
//	if (word[p] == board[r][c])
//	{
//		visited[r][c] = true;
//
//		flag = R(board, word, r - 1, c, p + 1, visited)
//			|| R(board, word, r + 1, c, p + 1, visited)
//			|| R(board, word, r, c - 1, p + 1, visited)
//			|| R(board, word, r, c + 1, p + 1, visited);
//
//		// backtrack
//		visited[r][c] = false;
//	}
//
//	return flag;
//}
//
//bool is_valid(const vector<vector<char>>& board, int r, int c)
//{
//	if (r < 0 || r >= board.size())
//		return false;
//
//	if (c < 0 || c >= board[0].size())
//		return false;
//
//	return true;
//}
//
//
