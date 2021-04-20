// 20055 컨베이어 벨트 위의 로봇
// https://www.acmicpc.net/problem/20055

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

# include <stdio.h>
# include <cstring>
# include <queue>
using namespace std;

int n = 0, k = 0, step = 0, cnt = 0;
int belt[2][50] = {0,};
int robot[2][50] ={0,};
queue<pair<int,int>> q_robot;

// 내구도가 감소하는 경우
// 1. 어떤 칸에 올라가거나
// 2. 이동하는 경우
// 내려가는 위치에 로봇이 있는 경우 로봇은 반드시 땅으로 내려가야 한다.

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
	printf("\t ");
	for (int i = 0; i < n; i++)
		printf("%d ", robot[0][i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", belt[1][i]);
	printf("\t ");
	for (int i = 0; i < n; i++)
		printf("%d ", robot[1][i]);
	printf("\n"); printf("\n"); 
}

int get_zero_cnt(){
	int zero = 0;
	for (int i = 0; i < n; i++){
		if(belt[0][i]==0 || belt[1][i]==0)
			zero += 1;
	}
	return zero;
}

int main(void){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &belt[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &belt[1][i]);

	while(true){
		step += 1;
		printf("step: %d\n",step);
		rotation();
		
		if(belt[0][0] != 0 && robot[0][0] != 1){
			q_robot.push({0,0});
			belt[0][0] -= 1;
			robot[0][0] = 1;
			print();
			if (get_zero_cnt() == k) {
				printf("%d\n", step); return 0;
			}
		}
		int q_sz = q_robot.size();
		while(q_sz--){
			int rx = q_robot.front().first;
			int ry = q_robot.front().second;
			int ny = ry + 1;

			if(ny == n){ // on the ground
				q_robot.pop();
				robot[rx][ry] = 0;
				// belt도 빼야하나
			}
			if(robot[rx][ny] == 0 && belt[rx][ny] > 0){ // can move
				q_robot.pop();
				robot[rx][ry] = 0;
				robot[rx][ny] = 1;
				belt[rx][ny] -= 1;
				if (get_zero_cnt() == k) {
					printf("%d\n", step); break;
				}
				q_robot.push({rx,ny});
			}
			print();
		}		
	}
	return 0;
}
