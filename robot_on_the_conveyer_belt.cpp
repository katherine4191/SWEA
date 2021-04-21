// 20055 컨베이어 벨트 위의 로봇
// deque로 푸는 것이 핵심인 문제였다
// https://www.acmicpc.net/problem/20055

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

# include <stdio.h>
# include <iostream>
# include <deque>
using namespace std;

int n = 0, k = 0, step = 0, cnt = 0;
deque <int> belt;
deque<bool> robot;

// 내구도가 감소하는 경우
// 1. 어떤 칸에 올라가거나
// 2. 이동하는 경우
// 내려가는 위치에 로봇이 있는 경우 로봇은 반드시 땅으로 내려가야 한다.

void print() {
	for (int i = 0; i < n; i++)
		printf("%d ", belt[i]);
	printf("\t ");
	for (int i = 0; i < n; i++)
		printf("%d ", robot[i]);
	printf("\n");
	for (int i = n; i < 2*n; i++)
		printf("%d ", belt[i]);
	printf("\t ");
	for (int i = n; i < 2*n; i++)
		printf("%d ", robot[i]);
	printf("\n"); printf("\n");
}

void rotation() {
	belt.push_front(belt.back());
	belt.pop_back();

	robot.push_front(robot.back());
	robot.pop_back();
}

void move() {
	for (int i = n-2; i >= 0; i--){
		if(robot[i] && !robot[i+1] && belt[i+1] >= 1){
			robot[i] = false;
			robot[i+1] = true;
			belt[i + 1]--;
		}
	}
	// robot 땅에 내리기
	robot[n - 1] = false;
}

void put_robot() {
	if(belt[0]>0) {
		belt[0]--;
		robot[0]=true;
	}	
}

int get_zero_cnt(){
	int zero = 0;
	for (int i = 0; i < 2*n; i++){
		if(belt[i]==0)
			zero++;
	}
	return zero;
}

int main(void){
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++){
		int val;
		cin >> val;
		belt.push_back(val);
		robot.push_back(false);
	}
	print();
	while(true){
		step += 1;
		rotation();
		move();
		put_robot();
		print();
		printf("zero: %d\n", get_zero_cnt());
		if(get_zero_cnt() >= k){
			cout << step << "\n";
			return 0;
		}
	}
	return 0;
}

