class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange){
    int dr=numBottles;
    int emp=numBottles;
    while(emp>=numExchange)
    {
       emp-=numExchange;
       numExchange++;
       dr++;
       emp++;
    }  
    return dr;
    }
};