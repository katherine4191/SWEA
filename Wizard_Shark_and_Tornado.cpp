// 20057 마법사 상어와 토네이도
// https://www.acmicpc.net/problem/20057

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <queue>
#include <list>
using namespace std;

typedef struct _dir {
	int dx;
	int dy;
	_dir(int _dx, int _dy) : dx(_dx), dy(_dy) {}
} Dir;

int rotation(int dir) {
	switch (dir) {
	case 3:
		return 2; break;
	case 2:
		return 1; break;
	case 1:
		return 0; break;
	case 0:
		return 3; break;
	}
}

int N = 0, out_sand = 0;
int grid[500][500] = { 0, };
Dir arr_Dir[4] = { Dir(-1,0),Dir(0,1),Dir(1,0),Dir(0,-1) }; // 위, 오, 아, 왼
queue<int> q_tor;
int arr_dx[4][10] = { {1, 1, 0, 0, 1, 1, 0, 0, -2, -1},
					   {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
					   {-1, -1, 0, 0, 1, 1, 0, 0, 2, 1},
					   {-1, 1, -1, 1, -1, 1,-2, 2, 0, 0} };
int arr_dy[4][10] = { {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
					   {-1, -1, 0, 0, 1, 1, 0, 0, 2, 1 },
					   {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
					   {1, 1, 0, 0, -1, -1, 0, 0, -2, -1} };
float p[9] = { 0.01, 0.01, 0.07, 0.07, 0.10, 0.10, 0.02, 0.02, 0.05 };

int main() {
	// scanf("%d", &N);
	// for (int i = 0; i < N; i++)
	// 	for (int j = 0; j < N; j++)
	// 		scanf("%d", &grid[i][j]);
	N = 5;
	int shk_x = (N - 1) / 2;	int shk_y = (N - 1) / 2;
	int grid[5][5] = {{0,0,0,0,0}, {0,0,0,0,0}, {0,10,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

	// 1. tornado 방향
	// 규칙: (1 move,1 rotation)*2 + (2 move,1 rotation)*2
	int dir_idx = 3;
	for (int m = 1; m <= N - 1; m++) {
		for (int i = 0; i < 2; i++) {
			for (int cnt = 1; cnt <= m; cnt++)
				q_tor.push(dir_idx);
			dir_idx = rotation(dir_idx);
		}
	}
	// last move
	for (int cnt = 1; cnt <= N - 1; cnt++)
		q_tor.push(dir_idx);

	// 2. shark가 움직이는 방향에 따라 비율 계산이 달라진다는 것
	while (!q_tor.empty()) {
		int idx = q_tor.front();
		q_tor.pop();
		int dx = arr_Dir[idx].dx;		int dy = arr_Dir[idx].dy;
		int n_shk_x = shk_x + dx, n_shk_y = shk_y + dy;
		printf("%d, %d \n", n_shk_x, n_shk_y);
		int n_x = 0, n_y = 0;
		int total_sand = grid[n_shk_x][n_shk_y], flow_sand = 0;
		flow_sand = total_sand * p[idx];
		for (int j = 0; j < 9; j++) {
			n_x = n_shk_x - arr_dx[idx][j];
			n_y = n_shk_y - arr_dy[idx][j];
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) {
				out_sand += flow_sand;
				grid[n_shk_x][n_shk_y] -= flow_sand;
				continue;
			}
			grid[n_x][n_y] += flow_sand;
			grid[n_shk_x][n_shk_y] -= flow_sand;
		}
		n_x = n_shk_x - arr_dx[idx][9];
		n_y = n_shk_y - arr_dy[idx][9];
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) {
			out_sand += grid[n_shk_x][n_shk_y];
		} else {
			grid[n_x][n_y] += grid[n_shk_x][n_shk_y];
		}	
		grid[n_shk_x][n_shk_y] = 0;
		shk_x = n_shk_x; shk_y = n_shk_y;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				printf("%d ", grid[i][j]);
			}
			printf("\n");
		}
	}

	// 출력: 격자의 밖으로 나간 모래의 양
	printf("%d \n", out_sand);
	return 0;
}