class ZeroEvenOdd{
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
public:
    int i;
    ZeroEvenOdd(int n){
    this->n = n;
    turn=0;
    i=1;
    }
    void zero(function<void(int)> printNumber){
    while(i<=n)
    {
        unique_lock<mutex>lock(m);
        while(turn!=0 && i<=n)
        {
            cv.wait(lock);
        }
        if(i>n)
        break;
        printNumber(0);
        turn=i%2==0?2:1;
        cv.notify_all();
    }
    }

    void even(function<void(int)> printNumber){
    while(i<=n)
    {
        unique_lock<mutex>lock(m);
        while(turn!=2 && i<=n)
        {
            cv.wait(lock);
        }
            if(i>n)
            break;
        printNumber(i++);
        turn=0;
        cv.notify_all();
    }   
    }
    void odd(function<void(int)> printNumber){
    while(i<=n)
    {
        unique_lock<mutex>lock(m);
        if(i>n)
        break;
        while(turn!=1 && i<=n)
        {
            cv.wait(lock);
        }
        if(i>n)
        return;
        printNumber(i++);
        turn=0;
        cv.notify_all();
    }        
    }
};