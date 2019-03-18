//用了一个优先队列 但是其实内存的使用是O(N) 在这里如果要使空间复杂度为O（1）就必须要用归并排序 这里归并排序就先不写了。

struct cmp {
	bool operator()(ListNode *p1,ListNode *p2) {
		return p1->val > p2->val;
	}
};


class Solution {
public:
	ListNode* sortList(ListNode* head) {
		priority_queue<ListNode *, vector<ListNode*>, cmp> minheap;
		while (head) {
			minheap.push(head);
			head = head->next;
		}
		if (minheap.empty()) return head;
		ListNode *root = minheap.top();
		ListNode *tmp = root;
		minheap.pop();
		while (!minheap.empty()) {
			tmp->next = minheap.top();
			tmp = tmp->next;
			minheap.pop();
		}
		tmp->next = NULL;
	return root;
	}
};
