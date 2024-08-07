vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict(B.begin(), B.end());
            vector<vector<string> > words(A.length() + 1, vector<string>(0));

            
            words[A.length()].push_back("");
            for(int i = A.length() - 1; i >= 0; i--) {
                vector<string> values;
                for(int j = i + 1; j <= A.length(); j++) {
                    if (dict.find(A.substr(i, j - i)) != dict.end()) {
                        for (int k = 0; k < words[j].size(); k++) {
                            values.push_back(A.substr(i, j - i) + (words[j][k].empty() ? "" : " ") + words[j][k]);
                        }
                    }
                }
                words[i] = values;
            }
            return words[0];
    
}
