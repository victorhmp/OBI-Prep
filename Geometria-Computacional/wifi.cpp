/*

Problema Wifi - OBI 2018 (Fase 2 - Nível 2)

    A solução desse problema envolve o algoritmo de Sweep-Line com eventos.

    Utilizamos <vector> e <map> da STL do C++.
    Vale notar que <map> é uma Self Balancing Binary Search Tree (Red-Black
    Tree).

*/

#include <bits/stdc++.h>
using namespace std;

struct event {
  int x;
  int ybot, ytop;
  int flag;  // 0 - inicio, 1 - final
};

bool compare_events(event e1, event e2) { return e1.x < e2.x; }

int N, res;
int xi, xf, ybot, ytop;

vector<event> all_events;
map<int, int> intersections;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> xi >> ytop >> xf >> ybot;
    all_events.push_back({xi, ybot, ytop, 0});
    all_events.push_back({xf, ybot, ytop, 1});
  }

  // Ordeno os eventos de acordo com o eixo x, orientado esquerda -> direita
  sort(all_events.begin(), all_events.end(), compare_events);

  for (int i = 0; i < all_events.size(); i++) {
    // Se o evento for de abertura, adiciono na BST
    if (all_events[i].flag == 0) {
      intersections[all_events[i].ybot] = 0;
      intersections[all_events[i].ytop] = 1;
    } else {
      // Verifica se o retângulo estava vazio
      if (intersections[all_events[i].ybot] == 0) res++;

      // Lembrar que as chaves do Map são ordenadas
      auto it = intersections.find(all_events[i].ybot);
      --it;

      // Marco o vizinho inferior para mostrar que tem um retângulo dentro
      it->second = 1;

      intersections.erase(all_events[i].ybot);
      intersections.erase(all_events[i].ytop);
    }
  }
  cout << res << endl;

  return 0;
}