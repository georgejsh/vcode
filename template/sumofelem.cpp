/// Name: sum of elements in range segtree(0,inf)
/// Guarantee: struct sumofelem{


struct sumofelem{
     ll left, right;
    ll sum = 0;
    sumofelem *left_child = nullptr, *right_child = nullptr;

    sumofelem(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new sumofelem(left, t);
            right_child = new sumofelem(t, right);
        }
    }

    void add(ll k, ll x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    ll get_sum(ll lq, ll rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};
