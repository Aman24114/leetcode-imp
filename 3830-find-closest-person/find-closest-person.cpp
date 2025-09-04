class Solution {
public:
    int findClosest(int x, int y, int z) {
    int x1=abs(x-z);
    int y1=abs(y-z);
    if(x1==y1)
    return 0;
    if(x1>y1)
    return 2;
    return 1; 
    }
};