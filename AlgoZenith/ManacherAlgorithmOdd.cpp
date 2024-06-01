string manacherOddLength(const string &s) {
    // Transform s into new string with sentinel characters '#' to handle even length palindromes
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";
    int n = t.length();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    
    for (int i = 1; i < n - 1; ++i) {
        if (i < right) {
            p[i] = min(right - i, p[2 * center - i]);
        }
        // Attempt to expand palindrome centered at i
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }
        // If palindrome centered at i expands past right,
        // adjust center and right boundary
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    
    // Find the maximum element in p
    int max_len = 0;
    int center_index = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (p[i] > max_len) {
            max_len = p[i];
            center_index = i;
        }
    }
    
    // Extract the longest palindrome from the original string
    int start = (center_index - max_len) / 2;
    return s.substr(start, max_len);
}
