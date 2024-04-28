/// Name: permutation cycles
/// Guarantee: struct permute{

vector<vector<int>> cycles;
// Find cycles in the permutation
for (int i = 1; i <= n; i++) {
    if (a[i] == i) {
        // If element is already in correct position, mark it as visited
        continue;
    }
    int tmp = i;
    vector<int> v;
    do {
        v.push_back(tmp);
        tmp = a[tmp];
    }while (tmp!=i)
    cycles.push_back(v);
}


