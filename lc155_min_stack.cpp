class MinStack {
public:
    vector<int> arr;
    MinStack() {
        
        
    }
    
    void push(int val) {
        arr.push_back(val);
        
    }
    
    void pop() {
        arr.pop_back();
        
    }
    
    int top() {
        int top = arr[arr.size() - 1];
        return top;
        
    }
    
    int getMin() {
        return *min_element(arr.begin(),arr.end());
        
    }
};
