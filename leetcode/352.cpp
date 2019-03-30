//动态区间插入问题用链表做的

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

class SummaryRanges {
public:
	struct node {
		Interval itv;
		node *next;
		node(int s,int e):itv(s,e),next(NULL){}
	};
	SummaryRanges():root(NULL) {

	}

	void addNum(int val) {
		if (!root) {
			node * ptr = new node(val, val);
			root = ptr;
		}
		else {
			node *tmp = root;
			if (tmp->itv.start > val) {
				if (tmp->itv.start - val == 1) {
					node *ptr = new node(val, tmp->itv.end);
					ptr->next = root->next;
					root = ptr;
				}
				else {
					node *ptr = new node(val, val);
					ptr->next = root;
					root = ptr;
				}
			}
			else if(tmp->itv.start < val) {
				while (tmp->next) {
					if (tmp->next->itv.start > val) {
						if (val > tmp->itv.end) {
							if (val - tmp->itv.end == 1 && tmp->next->itv.start - val > 1) {
								tmp->itv.end = val;
							}
							else if (val - tmp->itv.end > 1 && tmp->next->itv.start - val == 1) {
								tmp->next->itv.start = val;
							}
							else if (val - tmp->itv.end == 1 && tmp->next->itv.start - val == 1) {
								tmp->itv.end = tmp->next->itv.end;
								tmp->next = tmp->next->next;
							}
							else if (val - tmp->itv.end > 1 && tmp->next->itv.start - val > 1) {
								node *ptr = new node(val, val);
								ptr->next = tmp->next;
								tmp->next = ptr;
							}
						}
					}
					if (!tmp->next) break;//这个地方需要注意 因为前面有一个条件里面触发了tmp往下的条件所有在这里要提前判断是不是tmp已经到最后一个了 否则会导致循环判定条件有误
					tmp = tmp->next;
					
				}
				if (!tmp->next) {
					if (val - tmp->itv.end == 1) {
						tmp->itv.end = val;
					}
					else if (val - tmp->itv.end > 1) {
						node *ptr = new node(val, val);
						tmp->next = ptr;
					}
				}
			}
		}
	}

	vector<Interval> getIntervals() {
		node *tmp = root;
		vector<Interval> res;
		if (!root) return res;
		while (tmp) {
			res.push_back(tmp->itv);
			tmp = tmp->next;
		}
		return res;
	}
	node *root;
};
