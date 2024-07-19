class MyStack {
    private:
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            int el=q.front();
            q.pop();
            q.push(el);
        }
    }
    
    int pop() {
        int el=q.front();
        q.pop();
        return el;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};
