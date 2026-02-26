#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void tsp(int n, int pre_city, int index, int cur_length, int *min_length, bool visited[n], int dist[n][n], int shortest_edge[n],int bound)
{
  if (*min_length != -1 && cur_length + bound >= *min_length) {
    return;
  }

  if (index == n) {
    if ((*min_length == -1) || (cur_length + dist[pre_city][0] < *min_length)) {
      *min_length = cur_length + dist[pre_city][0];
    }
    return;
  }

  for (int i = 1; i < n; i++) {
    if (visited[i]) {
      continue;
    }

    visited[i] = true;
    tsp(n, i, index + 1, cur_length + dist[pre_city][i], min_length, visited, dist, shortest_edge, bound - shortest_edge[i]);
    visited[i] = false;
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  bool visited[n];
  memset(visited, false, sizeof(visited));
  int distance[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &distance[i][j]);
    }
  }

  int shortest_edge[n];
  int bound = 0;
  for (int i = 0; i < n; i++) {
    int min_val = INT_MAX;
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (distance[i][j] < min_val) {
        min_val = distance[i][j];
      }
    }
    shortest_edge[i] = (min_val == INT_MAX) ? 0 : min_val;
    bound += shortest_edge[i];
  }

  int min_length = -1;
  visited[0]     = true;
  tsp(n, 0, 1, 0, &min_length, visited, distance, shortest_edge,bound - shortest_edge[0]);

  printf("%d", min_length);

  return 0;
}