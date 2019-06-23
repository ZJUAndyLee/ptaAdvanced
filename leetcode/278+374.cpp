//简单的二分查找

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
	if (isBadVersion(1))
		return 1;
	long long st = 1, ed = n, mid = (st + ed) / 2;
	while (st < ed) {
		if (isBadVersion(mid)) {
			ed = mid;
		}
		else {
			st = mid + 1;
		}
		mid = (st + ed) / 2;
	}
	return st;
}
};

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
	long long st = 1, ed = n, mid = (st + ed) / 2;
	while (st < ed) {
		if (guess(mid) < 0) {
			ed = mid;
		}
		else if (guess(mid) > 0) {
			st = mid + 1;
		}
		else {
			return mid;
		}
        mid = (st + ed) / 2;
	}
	return st;
}
};
