class MyQueue {
public:
    vector<int> ans;
    MyQueue() {
        
    }
    
    void push(int x) {
        ans.push_back(x);
        
    }
    
    int pop() {
        int num = ans[0];
        ans.erase(ans.begin());
        return num;
        
    }
    
    int peek() {
        return ans[0];
        
    }
    
    bool empty() {
        if(ans.size() != 0){
            return false;
        }
        return true;
        
    }
};
