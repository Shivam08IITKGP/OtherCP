class DisjointSetUnion {
public:
    void initialize(int numberOfElements) {
        parent.resize(numberOfElements);
        for (int i = 0; i < numberOfElements; ++i)
            parent[i] = i;
    }

    int findRoot(int element) {
        if (parent[element] != element)
            parent[element] = findRoot(parent[element]);
        return parent[element];
    }

    void unite(int element1, int element2) {
        int root1 = findRoot(element1);
        int root2 = findRoot(element2);
        if (root1 != root2)
            parent[root1] = root2;
    }

private:
    vector<int> parent;
};

string solve(vector<string>& words) {
    int wordCount = words.size();

    DisjointSetUnion dsu;
    dsu.initialize(26);
    vector<int> inDegrees(26, 0);
    vector<int> outDegrees(26, 0);
    vector<bool> isConnected(26, false);

    string result;
    for (int k = 0; k < wordCount; ++k) {
        int start = words[k][0] - 'a';
        int end = words[k].back() - 'a';
        outDegrees[start]++;
        inDegrees[end]++;
        dsu.unite(start, end);
        isConnected[start] = isConnected[end] = true;

        int root = dsu.findRoot(start);
        unordered_set<int> roots;
        for (int i = 0; i < 26; ++i) {
            if (isConnected[i] && (inDegrees[i] > 0 || outDegrees[i] > 0))
                roots.insert(dsu.findRoot(i));
        }

        if (roots.size() > 1) {
            result.push_back('0');
            continue;
        }

        vector<int> differences;
        for (int i = 0; i < 26; ++i) {
            if (isConnected[i] && (inDegrees[i] > 0 || outDegrees[i] > 0))
                differences.push_back(outDegrees[i] - inDegrees[i]);
        }

        if (!differences.empty()) {
            int maxDifference = *max_element(differences.begin(), differences.end());
            int minDifference = *min_element(differences.begin(), differences.end());
            if (!((maxDifference == 0 && minDifference == 0) || (maxDifference == 1 && minDifference == -1 && count(differences.begin(), differences.end(), 1) == 1 && count(differences.begin(), differences.end(), -1) == 1))) {
                result.push_back('0');
                continue;
            }
        }

        result.push_back('1');
    }

    return result;
}
