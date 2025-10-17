class MyStack {
public:
    vector<int> arr;
    MyStack() {
        
    }
    
    void push(int x) {
        arr.push_back(x);
        
    }
    
    int pop() {
        int val = arr[arr.size() - 1];
        arr.pop_back();
        return val;
        
    }
    
    int top() {
        int n = arr.size();
        return arr[n - 1];
        
    }
    
    bool empty() {
        if(arr.size() == 0){
            return true;
        }
        else{
            return false;
        }
        
    }
};
