#include <iostream>
#include <vector>

#define INFINITY 1000000

void floydWarshall(std::vector<std::vector<int>> &dist) {
  int n = dist.size();
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != INFINITY &&
            dist[k][j] != INFINITY &&
            dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  // Detect negative cycles
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; dist[i][j] != -INFINITY && k < n; ++k) {
        if (dist[k][k] < 0 && dist[i][k] != INFINITY && dist[k][j] != INFINITY) {
          dist[i][j] = -INFINITY;
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, q, u, v, w;
  while (true) {
    std::cin >> n >> m >> q;
    if (n == 0 && m == 0 && q == 0) {
      break;
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INFINITY));
    for (int i = 0; i < n; ++i) {
      dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      std::cin >> u >> v >> w;
      dist[u][v] = w < dist[u][v] ? w : dist[u][v];
    }

    floydWarshall(dist);

    for (int i = 0; i < q; ++i) {
      std::cin >> u >> v;
      if (dist[u][v] == INFINITY) {
        std::cout << "Impossible" << std::endl;
      }
      else if (dist[u][v] == -INFINITY) {
        std::cout << "-Infinity" << std::endl;
      }
      else {
        std::cout << dist[u][v] << std::endl;
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
