bool top_sort(unordered_map<char, unordered_set<char>>&g, vector<char>&order )
{
    unordered_map<char, int>indeg;
    for(auto &node: g)
    {
        if(indeg.find(node.F)==indeg.end())
            indeg[node.F]=0;
        // alternate way was to only write indeg[node.F];
        for(char neigh: node.S)
        {
            indeg[neigh]++;
        }
    }

    queue<char>q;
    for(const auto &node: g)
    {
        if (indeg[node.F]==0)
        {
            q.push(node.F);
        }
    }

    while(q.size())
    {
        char curr = q.front();
        q.pop();
        order.push_back(curr);
        for(char neigh: g[curr])
        {
            if(--indeg[neigh]==0)
            {
                q.push(neigh);
            }
        }
    }
    return order.size()==g.size();
}

void solve()
{
    int n;
    cin>>n;
    vector<string>s(n);
    read(s);
    vi rank(n);
    read(rank);

    unordered_map<char, unordered_set<char>>g;
    for(int i=1;i<n;i++)
    {
        string word1 = s[rank[i-1]-1];
        string word2 = s[rank[i]-1];
        int minLen = min(word1.size(), word2.size());
        for(int j=0;j<minLen;j++)
        {
            if(word1[j]!=word2[j])
            {
                g[word1[j]].insert(word2[j]);
                break;
            }
        }
    } 

    vector<char>order;
    if(!top_sort(g, order))
        {cn;}
    
    unordered_map<char, int>pos;
    for(int i=0;i<order.size();i++)
    {
        pos[order[i]] = i;
    }

    //Validating now
    for(int i=1;i<n;i++){

        string word1 = s[rank[i-1]-1];
        string word2 = s[rank[i]-1];
        bool valid = false;
        int len = min(word1.size(), word2.size());
        for(int j = 0;j<len;j++)
        {
            if(word1[j]!=word2[j])
            {
                if(pos[word1[j]]>pos[word2[j]])
                {
                    cn;
                }
                valid = true;
                break;
            }
        }
        if(!valid and word1.size()>word2.size())
        {
            cn;
        }
    }
    cy;



}
