//这是递归合并的方法

class Solution {
public:
	ListNode* newp(ListNode*ptr) {
		void *raw = operator new (sizeof(ListNode));
		ListNode *tmp = static_cast<ListNode *>(raw);
    //ListNode* x = (ListNode*):: operator new (sizeof(ListNode)); 可以先申请内存再调用构造函数
    //new(x) ListNode(2);
		tmp->val = ptr->val;
		tmp->next = NULL;
		return tmp;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int sz = lists.size();
		if (lists.empty()) return NULL;
		if (sz == 1) return lists[0];
		if (sz == 2)
		{
			ListNode *tmp1 = lists[0];
			ListNode *tmp2 = lists[1];
			if (tmp1 && tmp2) {
				ListNode *ptr;
				if (tmp1->val > tmp2->val) { ptr = newp(tmp2);  tmp2 = tmp2->next; }
				else { ptr = newp(tmp1); tmp1 = tmp1->next; }
				ListNode*tmp_ptr = ptr;
				while (tmp1 && tmp2) {
					if (tmp1->val > tmp2->val) {
						tmp_ptr->next = newp(tmp2);
						//cout << tmp2->val << endl;
						tmp_ptr = tmp_ptr->next;
						tmp2 = tmp2->next;
					}
					else {
						tmp_ptr->next = newp(tmp1);
						//cout << tmp1->val << endl;
						tmp_ptr = tmp_ptr->next;
						tmp1 = tmp1->next;
					}
				}
				while (tmp1) { tmp_ptr->next = newp(tmp1); tmp1 = tmp1->next; }
				while (tmp2) { tmp_ptr->next = newp(tmp2); tmp2 = tmp2->next; }
				return ptr;
			}
			else if (tmp1)return tmp1;
			else if (tmp2)return tmp2;
			else return NULL;

		}
		else {
			ListNode *ptr1;
			ListNode *ptr2;
			ListNode *res;
			vector<ListNode *> lt1;
			vector<ListNode *> lt2;
			vector<ListNode *> lt3;
			lt1.insert(lt1.end(), lists.begin(), lists.begin() + sz / 2 );
			lt2.insert(lt2.end(), lists.begin() + sz / 2, lists.end());
			ptr1 = mergeKLists(lt1);
			ptr2 = mergeKLists(lt2);
			lt3.push_back(ptr1); lt3.push_back(ptr2);
			res = mergeKLists(lt3);
			return res;
		}
	}
};
