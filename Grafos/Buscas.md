# Buscas em grafos

Existem dois algoritmos de busca muito utilizados para percorrer os vértices de um grafo: a Busca em Profundidade e a Busca em Largura.

## Busca em profundidade (DFS)

Vamos começar pela busca em profundidade (Depth-first search ou DFS). A ideia é que, dado um vértice inicial para a busca, vamos percorrer seus vizinhos de maneira que, para cada um deles, vamos "afundando" pela profundidade do grafo.

```c++
vector<int> adj[N];
bool visited[N];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u: adj[s]) {
        dfs(u);
    }
}
```

## Busca em largura (BFS)

Diferente da DFS, na busca em largura (Breadth-first search ou BFS) percorremos cada profundidade do grafo de uma vez. Ou seja, a diferença entre os dois algoritmos de busca se resume à ordem em que percorremos os vértices do grafo.

```c++
queue<int> q;
bool visited[N];
int distance[N];

void bfs(int x) {
    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s]+1;
            q.push(u);
        }
    }
}
```

### Exercícios

- https://br.spoj.com/problems/ENERGIA/ (Transmissão de Energia)
- http://www.codcad.com/problem/175 (Familia Real)
- http://www.codcad.com/problem/119 (Gincana PJ)
- https://br.spoj.com/problems/CARTOG11/ (Desafio Cartográfico)
- https://www.spoj.com/problems/PT07Z/ (Longest path in a tree)
- http://www.codcad.com/problem/103 (Móbile)
- http://www.codcad.com/problem/115 (Ladrilhos)
