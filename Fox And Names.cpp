#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>

using namespace std;

string foxAndNames(vector<string>& names) {
    // Build directed graph of character dependencies
    // Each node represents a letter 'a' to 'z'
    vector<vector<int>> graph(26);
    
    // Add edges to the graph by comparing adjacent names
    for (int i = 0; i < names.size() - 1; i++) {
        const string& name1 = names[i];
        const string& name2 = names[i + 1];
        
        // Find the first position where characters differ
        int pos = 0;
        while (pos < name1.size() && pos < name2.size() && name1[pos] == name2[pos]) {
            pos++;
        }
        
        // If name1 is a prefix of name2, they're already correctly ordered
        if (pos == name1.size()) {
            continue;
        }
        
        // If name2 is a prefix of name1, it's impossible (violates lexicographical order)
        if (pos == name2.size()) {
            return "Impossible";
        }
        
        // Add constraint: first differing character in name1 comes before character in name2
        graph[name1[pos] - 'a'].push_back(name2[pos] - 'a');
    }
    
    // Check for cycles using DFS
    auto hasCycle = [&]() -> bool {
        // State of each node: 0 = not visited, 1 = in current DFS path, 2 = fully processed
        vector<int> state(26, 0);
        
        // Recursive DFS function to detect cycles
        function<bool(int)> dfs = [&](int node) -> bool {
            if (state[node] == 1) return true;  // Found a back edge (cycle)
            if (state[node] == 2) return false; // Already processed this node
            
            state[node] = 1; // Mark as in current DFS path
            
            // Check all neighbors
            for (int neighbor : graph[node]) {
                if (dfs(neighbor)) {
                    return true; // Propagate cycle detection upward
                }
            }
            
            state[node] = 2; // Mark as fully processed
            return false;
        };
        
        // Start DFS from each unvisited node
        for (int i = 0; i < 26; i++) {
            if (state[i] == 0 && dfs(i)) {
                return true; // Cycle found
            }
        }
        
        return false; // No cycle found
    };
    
    // If there's a cycle, it's impossible to find a valid ordering
    if (hasCycle()) {
        return "Impossible";
    }
    
    // Perform topological sort using Kahn's algorithm
    vector<int> inDegree(26, 0);
    
    // Calculate in-degrees for all nodes
    for (int i = 0; i < 26; i++) {
        for (int neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }
    
    // Priority queue for nodes with 0 in-degree (for lexicographically smallest output)
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 26; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }
    
    // Perform topological sort
    string result;
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        result.push_back('a' + node); // Add this letter to our result
        
        // Remove this node from the graph and update in-degrees
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }
    
    // If we couldn't include all characters, there's a cycle
    if (result.size() != 26) {
        return "Impossible";
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    
    cout << foxAndNames(names) << endl;
    
    return 0;
}
