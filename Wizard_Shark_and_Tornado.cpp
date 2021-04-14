// 20057 마법사 상어와 토네이도
// https://www.acmicpc.net/problem/20057

#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _pos {
	int x;
	int y;
	_pos(int _x, int _y) : x(_x), y(_y) {}
} Pos;

typedef struct _sandInfo {
	Pos pos;
	int ratio;
	_sandInfo(Pos _pos, int _ratio) : pos(_pos), ratio(_ratio) {}
} SandInfo;

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

int N = 0; Pos p_shk;
int grid[500][500] = { 0, };
queue<pair<int, int>> q_tor;

int main() {
	scanf("%d", &N);`

	p_shk = Pos((N / 2) + 1, (N / 2) + 1);
	for (int i = 1; i <= N; i++) {
		int a = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	// 1. tornado 방향을 구현 N*N-1번 움직임
	// 2. 방향에 따라 비율 계산이 달라진다는 것
	// 출력: 격자의 밖으로 나간 모래의 양
	return 0;
}