#include <iostream>
#include <vector>
#include <tuple>

#define INFINITY 20000000

std::vector<int> bellmanFord(int n, int s, const std::vector<std::tuple<int, int, int>>& edges) {
  std::vector<int> dist(n, INFINITY);
  dist[s] = 0;
  for (int i = 0; i < (n - 1) * 2; ++i) {
    for (auto& edge: edges) {
      int u, v, w;
      std::tie(u, v, w) = edge;
      if (dist[u] != INFINITY && dist[v] > dist[u] + w) {
        dist[v] = i >= n - 1 ? -INFINITY : dist[u] + w;
      }
    }
  }

  return dist;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, q, s, e, u, v, w;
  while (true) {
    std::cin >> n >> m >> q >> s;
    if (n == 0 && m == 0 && q == 0 && s == 0) {
      break;
    }

    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
      std::cin >> u >> v >> w;
      edges.push_back(std::make_tuple(u, v, w));
    }

    auto dist = bellmanFord(n, s, edges);

    for (int i = 0; i < q; ++i) {
      std::cin >> e;
      if (e >= n || dist[e] == INFINITY) {
        std::cout << "Impossible" << std::endl;
      }
      else if (dist[e] == -INFINITY) {
        std::cout << "-Infinity" << std::endl;
      }
      else {
        std::cout << dist[e] << std::endl;
      }
    }
    std::cout << std::endl;
  }

  return 0;
}