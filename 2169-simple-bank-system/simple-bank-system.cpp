#define ll long long 
class Bank {
public:
    int n;
    vector<ll>b;
    Bank(vector<ll>& b){
    this->b=b;
    n=b.size();
    }
    
    bool transfer(int acc1, int acc2, ll m) {
    if(acc1>n || acc2>n || b[acc1-1]<m)
    return 0;
    b[acc1-1]-=m;
    b[acc2-1]+=m;
    return 1;
    }
    
    bool deposit(int acc, ll m) {
    if(acc>n)
    return 0;
    b[acc-1]+=m;
    return 1;
    }
    
    bool withdraw(int acc, ll m) {
    if(acc>n || b[acc-1]<m)
    return 0;
    b[acc-1]-=m;
    return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */