//前面是我不正确的递归方法很难受 做了一下午没做出来 直接不递归暴力O(M+N)也不是很久这就很骚
//主要思路就是一个二叉分解的方法 把两个不同的数组分成两个集合 使得左集合的最大值大于有集合的最小值且左集合数等于右集合数即可。

class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int l_max, r_min;
	if (nums1.size() >= nums2.size()) {
		int imin = 0, imax = nums2.size();
		int i, j, m = nums1.size(), n = nums2.size();
		if (m == 1 && n == 1) return (nums1[0] + nums2[0]) / 2.0;
		else if (n == 1) {
			j = m / 2; 
			if ((m + n) % 2==0) {
				if (nums1[j] > nums2[0]) {
					if (nums2[0] > nums1[j - 1])return (nums2[0] + nums1[j]) / 2.0;
					else return (nums1[j] + nums1[j - 1]) / 2.0;
				}
				else {
					if (nums2[0] > nums1[j + 1])return (nums1[j] + nums1[j + 1]) / 2.0;
					else return (nums1[j] + nums2[0]) / 2.0;
				}
			}
			else {
				if (nums2[0] > nums1[j])return nums1[j];
				else return nums2[0] > nums1[j - 1] ? nums2[0] : nums1[j - 1];
			}
		}
		while (1) {
			i = (imin + imax) / 2;
			j = (m + n) / 2 - i;
			if (i == 0) {
				if ((m + n) % 2) return nums1[j];
				else {
					if (m == n) return (nums1[j - 1] + nums2[0]) / 2.0;
					else return(nums1[j - 1] + nums1[j]) / 2.0;
				}
			}
			if (nums2[i - 1] <= nums1[j] && nums1[j - 1] <= nums2[i]) break;
			else if (nums2[i - 1] > nums1[j]) imax = i;
			else if (nums1[j - 1] > nums2[i]) imin = i;
			if (i == n - 1 && imax!=i) {
				j = (m + n) / 2 - i;
				if ((m + n) % 2) return nums1[j - 1];
				else {
					if (m == n) return (nums1[0] + nums2[i]) / 2.0;
					else return(nums1[j - 1] + nums1[j]) / 2.0;
				}
			}
		}
		l_max = nums2[i - 1] > nums1[j - 1] ? nums2[i - 1] : nums1[j - 1];
		r_min = nums2[i] < nums1[j] ? nums2[i] : nums1[j];
		if ((m + n) % 2) return r_min;
		else return (l_max + r_min) / 2.0;
	}
	else {
		int imin = 0, imax = nums1.size();
		int i, j, m = nums2.size(), n = nums1.size();
		if (n == 1) {
			j = m / 2;
			if ((m + n) % 2==0) {
				if (nums2[j] > nums1[0]) {
					if (nums1[0] > nums2[j - 1])return (nums1[0] + nums2[j]) / 2.0;
					else return (nums2[j] + nums2[j - 1]) / 2.0;
				}
				else {
					if (nums1[0] > nums2[j + 1])return (nums2[j] + nums2[j + 1]) / 2.0;
					else return (nums2[j] + nums1[0]) / 2.0;
				}
			}
			else {
				if (nums1[0] > nums2[j])return nums2[j];
				else return nums1[0] > nums2[j - 1] ? nums1[0] : nums2[j - 1];
			}
		}
		while (1) {
			i = (imin + imax) / 2;
			j = (m + n) / 2 - i;
			if (i == 0) {
				if ((m + n) % 2) return nums2[j];
				else return(nums2[j - 1] + nums2[j]) / 2.0;
			}
			if (nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i]) break;
			else if (nums1[i - 1] > nums2[j]) imax = i;
			else if (nums2[j - 1] > nums1[i]) imin = i;
			if (i == n - 1&&imax!=i) {
				j = (m + n) / 2 - i;
				if ((m + n) % 2) return nums2[j - 1];
				else return(nums2[j - 1] + nums2[j]) / 2.0;
			}
		}
		l_max = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
		r_min = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
		if ((m + n) % 2) return r_min;
		else return (l_max + r_min) / 2.0;
	}
}

};

//暴力求解的方法就不贴了 很简单
