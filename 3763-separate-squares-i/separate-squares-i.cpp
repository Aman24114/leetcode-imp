class Solution {
public:
    double separateSquares(vector<vector<int>>& sq) {
     double a = 0;
        double l = 1e18, h = 0;
        for (auto &s : sq)
        {
            int y = s[1], l1 = s[2];
            a += (double)l1 * l1;
            l = min(l, (double)y);
            h = max(h, (double)y + l1);
        }
        double t = a / 2.0;
        for (int i1 = 0; i1 < 100; i1++)
        {
            double mid = (l + h) / 2.0;
            double s1 = 0;
            for (auto &s : sq)
            {
                double y = s[1], l1 = s[2];
                if (mid <= y) continue;
                else if (mid >= y + l1) s1 += l1 * l1;
                else s1 += (mid - y) * l1;
            }
            if (s1 < t)
            l = mid;
            else
            h = mid;
        }
        return h;
    }
};