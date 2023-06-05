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
void board_clear()
{
	for (int i = 0; i < 30; i++)
	{
		chess_board[i] = 0;
	}
}

const int repeat_num = 2;

int main(void)
{
	clock_t start_time;
	clock_t end_time;
	double ElapsedTime;
	double total_ElapsedTime = 0;

	cin >> N;
	for (int i = 0; i < repeat_num; i++)
	{

		res = 0;
		board_clear();
		start_time = clock();
		dfs(0);
		end_time = clock();
		ElapsedTime = ((double)(end_time - start_time) / (CLOCKS_PER_SEC));
		total_ElapsedTime += ElapsedTime;
	}
	total_ElapsedTime /= repeat_num;

	cout << res << '\n';

	//cout << "10회 시행 평균 시간 : " << ElapsedTime << "\n\n";
	printf("10회 시행 평균 시간 : %.10lf\n\n", ElapsedTime);
	return 0;
}
