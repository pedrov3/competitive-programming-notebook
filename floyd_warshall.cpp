// TODO: inicializar dist[i][j] = oo pras arestas que não existem
//             dist[i][j] = w(u, v) se a aresta existe
//             dist[i][i] = 0
void floyd_warshall() {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
