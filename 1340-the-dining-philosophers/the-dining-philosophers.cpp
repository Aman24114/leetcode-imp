class DiningPhilosophers {
public:
    int n;
    vector<mutex>locks;
    DiningPhilosophers() {
    n=5;
    locks=vector<mutex>(n);    
    }

    void wantsToEat(int philosopher,function<void()> pickLeftFork, function<void()> pickRightFork,function<void()> eat, function<void()> putLeftFork,function<void()> putRightFork){
int leftid= philosopher%n;
int rightid=(philosopher+1)%n;
if(philosopher%n==1)
{
    locks[rightid].lock();
    locks[leftid].lock();
    pickRightFork();
    pickLeftFork();
    eat();
    putRightFork();
    putLeftFork();
    locks[rightid].unlock();
    locks[leftid].unlock();
}
else
{
    locks[leftid].lock();
    locks[rightid].lock();
    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();
    locks[leftid].unlock();
    locks[rightid].unlock();
}
}
};