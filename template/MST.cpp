/// Name: MST
/// Guarantee: void prim(vector<vector<array<long long int,2>>> &adj) {

const int INF = 1000000000; // weight INF means there is no edge


ll prim(vector<vector<array<long long int,2>>> &adj) {

    int total_weight = 0;
    vector<array<long long int,2>> min_e(n);
    min_e[0][0] = 0;
    set<array<long long int,2>> q;
    q.insert({0, 0});
    vector<bool> selected(n, false);
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            //cout << "No MST!" << endl;
            //exit(0);
            return -1;
        }

        int v = q.begin()[1];
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        //if (min_e[v][1] != -1)
        //    cout << v << " " << min_e[v][1] << endl;

        for (auto e : adj[v]) {
            if (!selected[e[1]] && e[0] < min_e[e[1]][0]) {
                q.erase({min_e[e[1]][0], e[1]});
                min_e[e[1]] = {e[0], v};
                q.insert({e[0], e[1]});
            }
        }
    }

    return total_weight;
}
