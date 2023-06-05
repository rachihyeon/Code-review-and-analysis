#include<bits/stdc++.h>
#include<ctime>
using namespace std;

void innerRecurse(int ld, int col, int rd, int ex1, int  ex2, int& done, int& count) { 
	if (col == done) {
		count++;
		return;
	} 
	int poss = ~(ld | rd | col | ex1) & done;  
	while (poss) {
		int bit = poss & -poss;
		poss = poss ^ bit;      
		innerRecurse((ld | bit) >> 1, col | bit, (rd | bit) << 1, ex2, 0, done, count);  
		ex2 = 0;
	}
}

int modifiedCountNQueensSolutions(int n) {
	if (n == 0 || n == 1) return 1;
	int count = 0;
	int done = (1 << n) - 1;
	int excl = (1 << ((n / 2) ^ 0)) - 1; 
	innerRecurse(0, 0, 0, excl, n % 2 ? excl : 0, done, count);
	return count << 1;
}
const int repeat_num = 10;

int main(void)
{
	clock_t start_time;
	clock_t end_time;
	double ElapsedTime;

	int N;
	cin >> N;
	int result = -1;
	double total_ElapsedTime = 0;
	for (int i = 0; i < repeat_num; i++)
	{
		result = -1;
		start_time = clock();
		result = modifiedCountNQueensSolutions(N);
		end_time = clock();
		ElapsedTime = ((double)(end_time - start_time) / (CLOCKS_PER_SEC));
		total_ElapsedTime += ElapsedTime;
	}
	cout << result << '\n';
	//cout << total_ElapsedTime / repeat_num << "\n\n";
	printf("10회 占쏙옙占쏙옙 占쏙옙占� 占시곤옙 : %.10lf\n\n", ElapsedTime);
	return 0;
}
