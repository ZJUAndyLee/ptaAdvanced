//链表插入线性查找O(1)插入

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
		ListNode *tmp = head->next;
		ListNode *root = new ListNode(head->val);
		ListNode *tmp_res = root;
		while (tmp) {
            tmp_res = root;
			if (tmp->val <= root->val) {
				ListNode *ptr = new ListNode(tmp->val);
				ptr->next = root;
				root = ptr;
				tmp = tmp->next;
			}
			else {
				while (tmp_res->next) {
					if (tmp->val < tmp_res->next->val) {
						ListNode *ptr = new ListNode(tmp->val);
						ptr->next = tmp_res->next;
						tmp_res->next = ptr;
						tmp = tmp->next;
						break;
					}
					tmp_res = tmp_res->next;
				}
				if (!tmp_res->next) {
					ListNode *ptr = new ListNode(tmp->val);  tmp_res->next = ptr; tmp = tmp->next;
				}
			}
		}
		return root;
	}
};
