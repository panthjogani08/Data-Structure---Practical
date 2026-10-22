#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int V = 5;
vector<int> adj[V];
bool visited[V];

void DFS(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor])
            DFS(neighbor);
    }
}

void BFS(int start) {
    fill(visited, visited + V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2};

    fill(visited, visited + V, false);

    cout << "DFS Traversal: ";
    DFS(0);

    cout << "\nBFS Traversal: ";
    BFS(0);

    cout << endl;
    return 0;
}