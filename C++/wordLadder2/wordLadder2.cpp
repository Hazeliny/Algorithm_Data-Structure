/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordLadder2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:26:36 by linyao            #+#    #+#             */
/*   Updated: 2024/10/12 11:26:39 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

class Solution {
    public:
    bool valid(string s, string t) {
        int c = 0;
        for (int i = 0; i < s.length(); i++)
            c += (s[i] != t[i]);
        return (c == 1);
    }
    // Breadth-First Search. To find the shortest path in unweighted graph
    // or for exploring all nodes in a level-wise manner
    // g is the adjacency list structure of the graph. 
    // g[x] stores the indices of all the adjacent nodes of node x
    // parent[] stores the procursor node of every node
    // i.e. to store those nodes which we must go through to reach this node on the opimal path
    // start is the beginning node
    // end is the final node
    void    bfs(vector<vector<int>> &g, vector<int> parent[], int n, int start, int end) {
        vector <int> dist(n, 1005);
        queue <int> q;
        q.push(start); // push the beginning node into queue
        parent[start] = {-1}; // -1 shows it hasn't parent node
        dist[start] = 0; // distance of the beginning node is set 0
        while (!q.empty()) {
            // In each iteration, a node x is taken from the front of the queue q, 
            // and then all its adjacent nodes u are visited
            int x = q.front();
            q.pop();
            for (int u : g[x]) {
                //  equivalent to u=g[x][i] in for loop
                if (dist[u] > dist[x] + 1) {
                    // this if means the path from beginning to node u found before
                    // is not the shortest
                    // now the optimal path is the one from beginning to u through x
                    dist[u] = dist[x] + 1;
                    q.push(u); // push u into queue, then take u as beginning and continue BFS
                    parent[u].clear(); // the parents nodes of u before now is invalid, so clear them
                    parent[u].push_back(x); 
                    // take x as the parent of u
                    // showing the optimal path for the moment is from x
                }
                // this indicates that we have found another equally shortest path
                else if (dist[u] == dist[x] + 1)
                    parent[u].push_back(x); // add x into the parents nodes
            }
        }
    }

    // produce all the possible shortest paths to store into paths by recursive backtrack
    // store all the shortest paths into paths
    // every path is vector<int>, in which all the nodes gone through in the shortest path are included
    // path is the one which is currently constructing and is updated instantly during backtracking
    // parent[i] is a vector, presenting all the parent nodes of node i
    // node is the node being backtracked currently  
    void    shortestPaths (vector<vector<int>> &paths, vector<int> &path, vector<int> parent[], int node) {
        // as parent of start is -1, we've finished backtrack
        // this is the condition of recurse termination
        // the current path has been completed constructing
        if (node == -1) {
            paths.push_back(path);
            return ;
        }
        // every time we recursively call, add the current parent node u into path
        // then continue to backtrack the parent nodes with recursive call until reach start
        for (auto u : parent[node]) {
            path.push_back(u);
            shortestPaths(paths, path, parent, u);
            // After finish recurse, remove all the nodes stored in path just now
            // recover path to original status
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), start = -1, end = -1;
        vector<vector<string>> ANS;

        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord)
                start = i;
            if (wordList[i] == endWord)
                end = i;
        }
        // if endWord doesn't exist, return empty list
        if (end == -1)
            return (ANS);
        // if beginWord doesn't exist, add it in start of wordList
        if (start == -1) {
            wordList.emplace(wordList.begin(), beginWord);
            start = 0;
            end++;
            n++;
        }
        // construct the structure list of adjacent nodes
        // at the same time declare another variable paths
        vector<vector<int>> g(n, vector<int>()), paths;

        vector<vector<int>> parent[n], path;

        // when each adjacent pair of words in the wordList differs 
        // by only one letter, establish a bidirectional edge
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; i < n; j++) {
                if (valid(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        // to iterate the graph by call bfs and record the shortest
        // path of every word, parent will be updated
        bfs(g, parent, n, start, end);

        // backtrack to construct the shortest paths
        shortestPaths(paths, path, parent, end);

        // convert the numerical path into word path
        // attention: what were stored in paths are indices of words
        for (auto u : paths) {
            vector<string> now;
            // transform indices into words one by one
            for (int i = 0; i < u.size() - 1; i++)
                now.push_back(wordList[u[i]]);
            // attention: we started to backtrack from end
            // so it is necessaty to reverse the path 'now'
            reverse(now.begin(), now.end());
            now.push_back(wordList[end]);
            ANS.push_back(now);
        }
        return (ANS);
    }
};
