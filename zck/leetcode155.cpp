#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> min_st;    
    MinStack() {   
    }
    
    void push(int x) {
        st.push(x);
        if(min_st.empty())
            min_st.push(x);
        else
        {
            min_st.push(min(x, min_st.top()));
        }
        
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();        
    }
};
