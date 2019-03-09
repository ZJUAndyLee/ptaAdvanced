//最小栈 该问题非常简单

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stk.push_back(x);
	}

	void pop() {
		stk.pop_back();
	}

	int top() {
		return stk.back();
	}

	int getMin() {
		int min = stk[0];
		for (int i = 1; i < stk.size(); i++) {
			if (stk[i]<min) min = stk[i];
		}
		return min;
	}
private:
	vector<int> stk;
};

//提高算法的效率可以生成一个最小栈 然后每次调用pop函数的时候都判断一下是否与最小栈的第一个元素是否相等即可
class MinStack {
private:
    int min = INT_MAX;
public:
    //原始栈
    stack<int> st;
    //存放最小值的栈
    stack<int> minstack;
    /** initialize your data structure here. */
    MinStack() {
    }
    void push(int x) {
        //如果原始栈为空或者插入的值小于栈内最小值
        if(st.empty() || x <= min)
        {
            //先把数插入到原始栈
            st.push(x);
            //再把数插入到存放最小值的栈
            minstack.push(x);
            //标记最小值(这个最小值即为存放最小值栈的栈顶元素，也可以写min = minstack.top())
            min = x;
        }
        else
        {
            //如果插入的值大于最小值，直接入原始栈，最小值栈不必再入
            st.push(x);
        }
    }
    
    void pop() {
        //判断原始栈栈顶元素是否和最小值栈栈顶元素相同
        if(st.top() == minstack.top())
        {
            //如果相同，把原始栈和最小值栈栈顶元素一起删去
            st.pop();
            minstack.pop();
            //判断删除之后，栈内是否为空
            if(st.empty())
            {
                //如果为空则重新标记最小值
                min = INT_MAX;
            }
            else
                //如果不为空则最小值即为小最小值栈的栈顶元素
                min = minstack.top();
        }
        else
        {
            //如果不相同，直接删除原始栈的栈顶元素，最小值仍然不变
            st.pop();
        }
    }
    
    int top() {
        //由于原始栈么有改变，所以直接返回栈顶元素
        return st.top();
    }
    
    int getMin() {
        //最小值栈的栈顶元素即为最小值
        return minstack.top();
    }
};
