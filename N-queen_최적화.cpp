#include<iostream>
#include<ctime>
using namespace std;

int chess_board[30];
int N, res;
bool check(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		if (chess_board[i] == chess_board[depth] || abs(chess_board[depth] - chess_board[i]) == depth - i)
		{
			return true;
		}
	}
	return false;
}

void dfs(int depth)
{
	if (depth == N)
		res++;
	for (int i = 0; i < N; i++)
	{
		chess_board[depth] = i;
		if (check(depth) == false)
		{
			dfs(depth + 1);
		}
	}

}

int main(void)
{
	clock_t start_time;
	clock_t end_time;
	double ElapsedTime;

	cin >> N;
	start_time = clock();
	dfs(0);
	end_time = clock();
	ElapsedTime = ((double)(end_time - start_time) / (CLOCKS_PER_SEC));
	cout << res << '\n';
	cout << ElapsedTime << "\n\n";
	return 0;
}
