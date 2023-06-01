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

	cout << result << '\n';

	cout << ElapsedTime << "\n\n";
	return 0;

}
