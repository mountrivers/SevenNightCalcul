#include <vector>
#include <iostream>

using namespace std;

vector<int> normal(12, 0);
vector<int> normalCost = { 300,800,1300,1820,2720,4120,6020,8370,9550,11500,13810 };

vector<int> special(4, 0);
vector<int> specialCost = { 800,2800,6140 };

int over20Possible = 22;
int over40Possible = 4;
int basic = 2060;
int present = 9000;
int day = 0;
int allCost = 0; 
bool isEnd(int a, int b, int c, int d) {
	if (a != 63)
		return true;
	if (b != 18)
		return true;
	if (c != 4)
		return true;
	if (d != 18)
		return true;
	return false;
}

void normalCal(int n) {
	if (n == 3) {
		while (over20Possible >0 && normal[n] > 0 && normalCost[n] < present) {
			normal[n]--;
			normal[n + 1]++;
			basic += 4;
			present -= normalCost[n];
			allCost += normalCost[n];
			over20Possible--;
		}
	}
	else if (n == 7) {
		while (over40Possible > 0 && normal[n] > 0 && normalCost[n] < present) {
			normal[n]--;
			normal[n + 1]++;
			basic += 4;
			present -= normalCost[n];
			allCost += normalCost[n];
			over40Possible--;
		}
	}
	else {
		while (normal[n] > 0 && normalCost[n] < present) {
			normal[n]--;
			normal[n + 1]++;
			if (n == 4)
				basic += 8;
			else
				basic += 4;
			present -= normalCost[n];
			allCost+= normalCost[n];
		}
	}
}
void specialCal(int n) {
	while (special[n] > 0 && specialCost[n] < present) {
		special[n]--;
		special[n + 1]++;
		basic += 4;
		present -= specialCost[n];
		allCost += specialCost[n];
	}
}
int main() {
	normal[0] = 85;
	special[0] = 18;
	while (isEnd(normal[3], normal[7], normal[11], special[3]) ){
		present += basic;
		if(normal[0] > 0)
			normalCal(0);
		if (normal[1] > 0)
			normalCal(1);
		specialCal(0);
		if (normal[2] > 0)
			normalCal(2);
		if (normal[4] > 0)
			normalCal(4);
		if (normal[3] > 0)
			normalCal(3);
		specialCal(1);
		if (normal[5] > 0)
			normalCal(5);
		if (normal[6] > 0)
			normalCal(6);
		specialCal(2);
		if (normal[7] > 0)
			normalCal(7);
		if (normal[8] > 0)
			normalCal(8);
		if (normal[9] > 0)
			normalCal(9);
		if (normal[10] > 0)
			normalCal(10);
		day++;
	}
	int cost = normal[3] * 1400 + normal[7] * 6520 + normal[11] * 13040 + special[3] * 7780;
	cout << day << "일 " << basic << " 하루 갯수";
	cout << endl << "이후 모두 만렙가지 필요 인연의 실 : "<<cost << " 필요 일" << cost / 3800+1;

	cout << endl << "총합 : " << allCost << " / " << allCost + cost;
	return 0;
}

