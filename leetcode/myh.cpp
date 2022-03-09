#include<iostream>
using namespace std;

int main() {
	float x, sum, max, min, score;
	int i;
	x = 0;
	score = 0;

	cout << "pleace liangfen: " << endl;
	float a, b;
	cin >> a >> b;
	if (a > b) {
		max = a;
		min = b;
	} else {
		max = b;
		min = a;
	}
    sum = a + b;
	for (i = 0; i < 8; i++) {
		cin >> x;
		if (x > max) {
			max = x;
		} else if (x < min) {
			min = x;
		}
		sum = sum + x;
	}
	score = (sum - max - min) / 8;
	cout << score << endl;
	return 0;
}