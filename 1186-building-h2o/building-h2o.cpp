class H2O
{
    private:
    mutex mtx;
    condition_variable cv;
    int hcnt=0;
    public:
        H2O() {}

    void hydrogen(function < void() > releaseHydrogen)
    {
        unique_lock<mutex>lock(mtx);
        while(hcnt>=2)
        {
            cv.wait(lock);
        }
        hcnt++;
        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function < void() > releaseOxygen)
    {
       unique_lock<mutex>lock(mtx);
       while(hcnt<2)
       {
          cv.wait(lock);
       }
       releaseOxygen();
       hcnt=0;
       cv.notify_all();
    }
};