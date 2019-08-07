//先遍历一遍将位置数值都相同的点给删除，然后在剩下的字符串中找到相同的数字出现次数最少的数值然后累加
class Solution {
public:
   string getHint(string secret, string guess) {
	int bulls = 0, cows = 0;
  vector<int> ns(10, 0);
	vector<int> ng(10, 0);
	for (int i = 0; i < secret.size(); i++) {
		if (secret[i] == guess[i]) {
			secret.erase(secret.begin() + i);
			guess.erase(guess.begin() + i);
			i--;
			bulls++;
		}
    else{
      ns[secret[i] - '0']++;
		  ng[guess[i] - '0']++;
    }
	}
	for (int i = 0; i < 10; i++) {
		if (ns[i] > 0 && ng[i] > 0) {
			cows += min(ns[i], ng[i]);
		}
	}
	string res = "";
	res += to_string(bulls) + "A" + to_string(cows) + "B";
	return res;
}
};
