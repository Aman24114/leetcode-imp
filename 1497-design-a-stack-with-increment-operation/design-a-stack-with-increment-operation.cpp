class CustomStack {
public:
    vector<int>stack;
    int maxi;
    CustomStack(int maxi)
    {
        this->maxi=maxi;
    }
    
    void push(int x) {
    if(stack.size()<maxi)
    {
        stack.push_back(x);
    }
    }
    int pop() {
    if(stack.empty())
    {
        return -1;
    }
    int value=stack.back();
    stack.pop_back();
    return value;
    }
    void increment(int k, int val) {
    int size= stack.size();
    for(int i=0;i<min(k,size);i++)
    {
        stack[i]+=val;
    }   
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */