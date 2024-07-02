/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if (!node) {
        return NULL;
    }
    
    // Map to store the original nodes and their corresponding cloned nodes
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
    
    // Create the clone of the first node
    UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
    nodeMap[node] = cloneNode;
    
    // Queue for BFS traversal
    queue<UndirectedGraphNode*> toVisit;
    toVisit.push(node);
    
    while (!toVisit.empty()) {
        // Get the current node
        UndirectedGraphNode* currentNode = toVisit.front();
        toVisit.pop();
        
        // Iterate through all the neighbors of the current node
        for (UndirectedGraphNode* neighbor : currentNode->neighbors) {
            // If this neighbor hasn't been cloned yet
            if (nodeMap.find(neighbor) == nodeMap.end()) {
                // Create the clone for the neighbor
                UndirectedGraphNode* cloneNeighbor = new UndirectedGraphNode(neighbor->label);
                nodeMap[neighbor] = cloneNeighbor;
                toVisit.push(neighbor);
            }
            // Add this neighbor to the neighbors of the clone node
            nodeMap[currentNode]->neighbors.push_back(nodeMap[neighbor]);
        }
    }
    
    return cloneNode;

}
