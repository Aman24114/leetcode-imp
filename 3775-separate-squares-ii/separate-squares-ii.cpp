class Solution {
public:
    struct evt 
    {
        long long y;
        int t;
        int a, b;
    };
    struct st
    {
        int n;
        vector<int> cnt;
        vector<double> len;
        vector<double> x;
        st(const vector<double>& x) : x(x)
        {
            n = x.size() - 1;
            cnt.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }
        void upd(int idx, int l, int r, int ql, int qr, int val)
        {
            if (qr < l || ql > r)
            return;
            if (ql <= l && r <= qr)
            cnt[idx] += val;
            else
            {
                int m = (l + r) / 2;
                upd(idx * 2, l, m, ql, qr, val);
                upd(idx * 2 + 1, m + 1, r, ql, qr, val);
            }

            if (cnt[idx] > 0)
            len[idx] = x[r + 1] - x[l];
            else
            len[idx] = (l == r) ? 0 : len[idx * 2] + len[idx * 2 + 1];
        }
        double query()
        {
          return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& s)
    {
        auto luntrivexi = s;
        int n = s.size();
        vector<evt> ev;
        ev.reserve(n * 2);
        vector<double> xs;
        xs.reserve(n * 2);
        for (auto &sq : s)
        {
            int x_val = sq[0], y_val = sq[1], l_val = sq[2];
            ev.push_back({(long long)y_val, 1, x_val, x_val + l_val});
            ev.push_back({(long long)(y_val + l_val), -1, x_val, x_val + l_val});
            xs.push_back(x_val);
            xs.push_back(x_val + l_val);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ev.begin(), ev.end(), [](const evt &a, const evt &b)
        {
            return a.y < b.y;
        });
        for (auto &e : ev)
        {
            e.a = int(lower_bound(xs.begin(), xs.end(), e.a) - xs.begin());
            e.b = int(lower_bound(xs.begin(), xs.end(), e.b) - xs.begin());
        }
        double total_area = 0;
        st seg(xs);
        long long prev = ev[0].y;
        int i = 0;
        while (i < ev.size())
        {
            long long cur = ev[i].y;
            double dy = double(cur - prev);
            total_area += seg.query() * dy;
            while (i < ev.size() && ev[i].y == cur)
            {
                seg.upd(1, 0, seg.n - 1, ev[i].a, ev[i].b - 1, ev[i].t);
                i++;
            }
            prev = cur;
        }
        double half_area = total_area / 2.0;
        st seg2(xs);
        double area_so_far = 0;
        prev = ev[0].y;
        i = 0;
        double ans = 0;
        while (i < ev.size())
        {
            long long cur = ev[i].y;
            double dy = double(cur - prev);
            double cur_union = seg2.query();
            double seg_area = cur_union * dy;
            if (area_so_far + seg_area >= half_area)
            {
                double rem = half_area - area_so_far;
                ans = (cur_union == 0) ? prev : prev + rem / cur_union;
                return ans;
            }
            area_so_far += seg_area;
            while (i < ev.size() && ev[i].y == cur)
            {
                seg2.upd(1, 0, seg2.n - 1, ev[i].a, ev[i].b - 1, ev[i].t);
                i++;
            }
            prev = cur;
        }
        return prev;
    }
};