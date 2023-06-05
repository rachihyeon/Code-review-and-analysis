#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

bool board[30][30];
int result = 0;
int N;
bool isRightPosition()
{
	pair<int, int> position[30];
	int position_count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == true)
			{
				position[position_count].first = i;
				position[position_count].second = j;
				position_count++;
				break;
			}
		}
	}
	for (int i = 0; i < position_count - 1; i++)
	{
		for (int j = i + 1; j < position_count; j++)
		{
			if (position[i].second == position[j].second || abs(position[i].second - position[j].second) == j - i)
			{
				return false;
			}
		}
	}
	return true;
}

void dfs(int depth)
{
	if (depth == N)
	{
		bool check = isRightPosition();
		if (check)
			result++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		board[depth][i] = true;
		dfs(depth + 1);
		board[depth][i] = false;
	}

}

void board_clear()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			board[i][j] = false;
		}
	}
}
const int repeat_num = 10;

int main(void)
{
	clock_t start_time;
	clock_t end_time;
	double ElapsedTime;
	double total_ElapsedTime = 0;

	cin >> N;
	for (int i = 0; i < repeat_num; i++)
	{

		result = 0;
		board_clear();
		start_time = clock();
		dfs(0);
		end_time = clock();
		ElapsedTime = ((double)(end_time - start_time) / (CLOCKS_PER_SEC));
		total_ElapsedTime += ElapsedTime;
	}
	total_ElapsedTime /= repeat_num;

	cout << result << '\n';
	
	//cout << "10회 시행 평균 시간 : " << ElapsedTime << "\n\n";
	printf("10회 시행 평균 시간 : %.10lf\n\n", ElapsedTime);
	return 0;

}
