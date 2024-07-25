class MyQueue {
private:
stack<int>st1,st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        //S1->S2
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        //
        st1.push(x);
        //S2->S1
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int topElement=st1.top();
        st1.pop();
        return topElement;
    }
    
    int peek() {
     return st1.top();
    }
    
    bool empty() {
        return st1.size()==0;
    }
};
// *******************************************

class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty())
        {
            int el=s2.top();
            s2.pop();
            return el;
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int el=s2.top();
            s2.pop();
            return el;
        }

    }
    
    int peek() {
        if(!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s2.size()+s1.size()==0;
    }
};
