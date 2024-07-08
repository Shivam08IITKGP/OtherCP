vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    int n = A.size();  // Assuming A and B are of the same size
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Max heap to store (sum, index of A, index of B)
    priority_queue<tuple<int, int, int>> maxHeap;
    set<pair<int, int>> visited;

    // Initialize the max heap with the largest possible sum
    maxHeap.emplace(A[0] + B[0], 0, 0);
    visited.insert({0, 0});

    vector<int> result;

    while (result.size() < n) 
    {
        auto [sum, i, j] = maxHeap.top();
        maxHeap.pop();
        result.push_back(sum);

        // Push the next possible pairs into the heap if they haven't been considered
        if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) 
        {
            maxHeap.emplace(A[i + 1] + B[j], i + 1, j);
            visited.insert({i + 1, j});
        }
        if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) 
        {
            maxHeap.emplace(A[i] + B[j + 1], i, j + 1);
            visited.insert({i, j + 1});
        }
    }

    return result;
}
