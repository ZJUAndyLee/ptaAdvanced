#include<iostream>
using namespace std;

int main() {
	int x1, x2, x3;
	scanf("%d.%d.%d", &x1, &x2, &x3);
	int y1, y2, y3;
	scanf("%d.%d.%d", &y1, &y2, &y3);
	int r1, r2, r3;
	r3 = (x3 + y3) % 29;
	r2 = (x2 + y2 + (x3 + y3) / 29) % 17;
	r1 = x1 + y1 + (x2 + y2 + (x3 + y3) / 29) / 17;
	printf("%d.%d.%d", r1, r2, r3);

}
