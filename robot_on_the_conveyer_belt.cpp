// 20055 컨베이어 벨트 위의 로봇
// https://www.acmicpc.net/problem/20055

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

# include <stdio.h>
# include <cstring>
using namespace std;

int n = 0, k = 0, step = 0;
int belt[2][50] = {0,};
int robot[2][50] ={0,};

// 내구도가 감소하는 경우
// 1. 어떤 칸에 올라가거나
// 2. 이동하는 경우

void rotation() {
	int up_b = belt[0][n-1], down_f = belt[1][0];
	for (int i = n-1; i > 0; i--)  // n-1 ~ 1까지
		belt[0][i] = belt[0][i-1];
	for (int i = 0; i < n-1; i++) // 0 ~ n-2까지
		belt[1][i] = belt[1][i + 1];
	
	belt[0][0] = down_f;
	belt[1][n-1] = up_b;
}

void print(){
	for (int i = 0; i < n; i++)
		printf("%d ", belt[0][i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", belt[1][i]);
	printf("\n");
}

int main(void){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &belt[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &belt[1][i]);

	for (int i = 0; i < n; i++)	{
		print();
		rotation();
	}

	return 0;
}
