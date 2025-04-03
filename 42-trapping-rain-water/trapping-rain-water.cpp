class Solution {
public:
    int trap(vector<int>& h) {
    int n= h.size();
    int w=0;
    vector<int>leftmax(n);
    vector<int>rightmax(n);
    leftmax[0]=h[0];
    rightmax[n-1]=h[n-1];
    for(int i=1;i<n;i++)
    {
        leftmax[i]=max(leftmax[i-1],h[i]);
    } 
    for(int i=n-2;i>=0;i--)
    {
        rightmax[i]=max(rightmax[i+1],h[i]);
    }
    for(int i=1;i<n-1;i++)
    {
        w+=min(leftmax[i],rightmax[i])-h[i];
    }
    return w;
    }
};