#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define TRAPPED "Trapped!"
#define ESCAPED "Escaped in %d minute(s)."
#define START 'S'
#define BLOCK '#'
#define EXIT 'E'

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<int> dx = {-1, 0, 1, 0};
  std::vector<int> dy = {0, -1, 0, 1};
  std::vector<int> dz = {-1, 0, 1};

  do {
    int L, R, C;
    std::cin >> L >> R >> C;
    if (L == 0 || R == 0 || C == 0) {
      break;
    }

    std::vector<std::vector<std::vector<char>>> dungeon =
        std::vector<std::vector<std::vector<char>>>(L, std::vector<std::vector<char>>(R, std::vector<char>(C, ' ')));
    std::vector<std::vector<std::vector<bool>>> visited =
        std::vector<std::vector<std::vector<bool>>>(L, std::vector<std::vector<bool>>(R, std::vector<bool>(C, false)));

    std::tuple<int, int, int> start;
    for (int z = 0; z < L; ++z) {
      for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
          std::cin >> dungeon[z][y][x];
          if (dungeon[z][y][x] == START) {
            start = std::make_tuple(z, y, x);
          }
        }
      }
    }

    int x, y, z;
    int nodesNext = 0;
    int nodesRemain = 1;
    int time = 0;
    std::queue<std::tuple<int, int, int>> queue;
    queue.push(start);
    std::tie(z, y, x) = start;
    visited[z][y][x] = true;
    bool canEscape = false;
    while(!queue.empty()) {
      std::tie(z, y, x) = queue.front();
      queue.pop();

      if (dungeon[z][y][x] == EXIT) {
        canEscape = true;
        break;
      }
      
      for (auto deltaZ: dz) {
        if (z + deltaZ >= 0 &&
            z + deltaZ < L &&
            !visited[z + deltaZ][y][x] &&
            dungeon[z + deltaZ][y][x] != BLOCK) {
          queue.push(std::make_tuple(z + deltaZ, y, x));
          visited[z + deltaZ][y][x] = true;
          ++nodesNext;
        }
      }
      for (auto deltaY: dy) {
        if (y + deltaY >= 0 &&
            y + deltaY < R &&
            !visited[z][y + deltaY][x] &&
            dungeon[z][y + deltaY][x] != BLOCK) {
          queue.push(std::make_tuple(z, y + deltaY, x));
          visited[z][y + deltaY][x] = true;
          ++nodesNext;
        }
      }
      for (auto deltaX: dx) {
        if (x + deltaX >= 0 &&
            x + deltaX < C &&
            !visited[z][y][x + deltaX] &&
            dungeon[z][y][x + deltaX] != BLOCK) {
          queue.push(std::make_tuple(z, y, x + deltaX));
          visited[z][y][x + deltaX] = true;
          ++nodesNext;
        }
      }

      --nodesRemain;
      if (nodesRemain == 0) {
        nodesRemain = nodesNext;
        nodesNext = 0;
        ++time;
      }
    }

    if (canEscape) {
      char buffer[256];
      std::sprintf(buffer, ESCAPED, time);
      std::cout << buffer << std::endl;
    }
    else {
      std::cout << TRAPPED << std::endl;
    }
  }
  while (true);
  
  return 0;
}