#include <iostream>
#include <queue>
#include <vector>

#define MAXN 10001

using namespace std;

vector<int> graph[MAXN];
int visited[MAXN];
int dist[MAXN];
int N, starting_position, destination;
queue<int> adj_nodes_queue;

int bfs(int source, int destination) {
  visited[source] = true;
  dist[source] = 0;
  adj_nodes_queue.push(source);

  while (!adj_nodes_queue.empty()) {
    int current = adj_nodes_queue.front();
    adj_nodes_queue.pop();

    for (auto node : graph[current]) {
      if (visited[node]) continue;

      visited[node] = true;

      dist[node] = dist[current] + 1;

      adj_nodes_queue.push(node);
    }
  }

  return dist[destination];
}

int main() {
  int p = 0;
  int q = 0;

  cin >> N >> starting_position >> destination;

  for (int i = 1; i <= N - 1; i++) {
    cin >> p >> q;
    graph[p].push_back(q);
    graph[q].push_back(p);
  }

  int answer = bfs(starting_position, destination);
  cout << answer << endl;

  return 0;
}
