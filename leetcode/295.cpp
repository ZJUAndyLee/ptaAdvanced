//这个做一个流动数据中位数的一个类 为了降低时间复杂度 这个算法运用了两个优先队列也即一个最大一个最小每次插入的时候 
//都要保证插入结束之后两个队列的容量之差<=1
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {//插入时的三种情况 分别对应于哪一个队列更大
        if(bigque.empty()){bigque.push(num);}
        else if(bigque.size()==smallque.size()){
            if(bigque.top()<num){smallque.push(num);}
            else{ bigque.push(num);}
        }
        else if(bigque.size()>smallque.size()){
            if(bigque.top()<num){smallque.push(num);}
            else{ smallque.push(bigque.top());bigque.pop();bigque.push(num);}
        }
        else{
            if(smallque.top()>num){bigque.push(num);}
            else{ bigque.push(smallque.top());smallque.pop();smallque.push(num);}
        }
    }
    
    double findMedian() {//根据不同的size的情况中位数得到的情况也分为了三种
        if(bigque.size()==smallque.size()){return (double)(bigque.top()+smallque.top())/2;}
         if(bigque.size()>smallque.size()){return bigque.top();}
         if(bigque.size()<smallque.size()){return smallque.top();}
        return 0;
    }
private:
    priority_queue<int> bigque;
    priority_queue<int,vector<int>,greater<int>> smallque;
    
};

//而我用了一个链表来解决这个问题 这样的话插入和输出中位数就都是一个O(N)的时间复杂度的问题 效率很低而且程序也容易错。
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
		t_num = 0; root = NULL;
	}
	struct node {
		int val;
		node *next;
	};
	node *nptr(int val) {
		node *tmp = new node;
		tmp->val = val;
		tmp->next = NULL;
		return tmp;
	}
	void addNum(int num) {
		if (!root) {
			root = nptr(num);
		}
		else {
			node *tmp;
			if (num <= root->val) {
				tmp = nptr(num);
				tmp->next = root;
				root = tmp;
			}
			else {
				tmp = root;
				while (tmp->next) {
					if (tmp->next->val <= num) tmp = tmp->next;
					else break;
				}
				node *tmp_ptr = nptr(num);
				tmp_ptr->next = tmp->next;
				tmp->next = tmp_ptr;
			}
		}
		t_num++;
	}

	double findMedian() {
		int ct = 1, mid;
		node *tmp = root;
		if (t_num % 2) {
			mid = t_num / 2 + 1;
			while (ct < mid) {
				tmp = tmp->next;
				ct++;
			}
			return tmp->val;
		}
		else {
			mid = t_num / 2;
			while (ct < mid) {
				tmp = tmp->next;
				ct++;
			}
			return (tmp->val + tmp->next->val) / 2.0;
		}
	}
private:
	int t_num;
	node *root;
};
