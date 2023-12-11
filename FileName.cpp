#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//int main() {
//	int result;
//	int n, t, floors[100]{}, f_i;
//	cin >> n >> t;
//	for (int i = 0; i < n; i++) {
//		cin >> floors[i];
//	}
//	cin >> f_i;
//	//cout << floors[f_i - 1];
//	int minfl{ floors[0] }, maxfl{ floors[n - 1] };
//	int nfloor{ floors[f_i - 1] };
//	if (maxfl - t <= nfloor|| minfl + t >= nfloor) {
//		result = maxfl - minfl;
//	}
//	else {
//		int topDown, downTop;
//		topDown = maxfl - nfloor + maxfl - minfl;
//		downTop = nfloor - minfl + maxfl - minfl;
//		if (topDown < downTop) { result = topDown; }
//		else { result = downTop; }
//
//	}
//
//	cout << result << endl;
//	return 0;
//}
int countDigits(int n);

int maximizeNum(int num);

int getDigit(int num, int count, int i);

void task() {
	int n, k;
	cin >> n >> k;
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	int summ = 0;

	while (k > 0) {
		int* difference = new int[n];
		for (int i = 0; i < n; i++) {
			difference[i] = maximizeNum(array[i]) - array[i];
		}
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (difference[i] != 0) {
				flag = 1;
			}
		}
		if (flag == false) {
			delete[]difference;
			break;
		}
		k--;
		int Imax = 0;
		int maxDiff = 0;
		for (int i = 0; i < n; i++) {
			if (maxDiff < difference[i]) {
				maxDiff = difference[i];
				Imax = i;
			}
		}
		array[Imax] = maximizeNum(array[Imax]);
		summ = summ + maxDiff;
		delete[]difference;
	}
	cout << "your maximal difference is:" << summ << endl;
	delete[]array;
}

void task2() {
	int a, b;
	cin >> a >> b;
	if (a < b) { cout << -1; }
}

void runCodeRepeat(void(*task)()) {
	string YN;

	do {
		task();
		cout << "for repeat press y:";
		cin >> YN;
	} while (YN == "y");
}



int main() {
	runCodeRepeat(/*your code running here -->*/task );
	return 0;
}




int countDigits(int num) {
	int count = 1;
	for (; num / static_cast<int>(pow(10, count));) {
		count++;
	}
	return count;
}

int getDigit(int num, int count, int i) {
	//num 2814234 = (2214234 / 1000000) % 10 
	// 99323485 
	//= num / pow(10,count-1-i) % 10;
	// if 
	int getdigit = 0;
	getdigit = num / static_cast<int>(pow(10, count - 1 - i)) % 10;
	return getdigit;
}

int maximizeNum(int num) {

	// подсчет количества цифр  
	int count = countDigits(num);

	for (int i = 0; i < count; i++) {
		int digit = getDigit(num, count, i);
		if (digit < 9) {
			int result = num + (9 - digit) * static_cast<int>(pow(10, count - 1 - i));
			return result;
		}
	}
	return num;
}
