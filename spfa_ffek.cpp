#define MAX 11234

typedef long long ll;
const ll oo = 2e15;
struct edge {
  int u, v;
  ll flow, cost;
  int prev;
  edge(int _u, int _v, ll _flow, ll _cost, int _prev)
      : u(_u), v(_v), flow(_flow), cost(_cost), prev(_prev) {}
};

vector<edge> edges;
int pos[MAX], p[MAX], cnt[MAX];  // TODO: inicializar pos com -1
ll dist[MAX];
bool inq[MAX];

void add_edge(int u, int v, ll flow, ll cost) {
  edges.emplace_back(u, v, flow, cost, pos[u]);
  pos[u] = edges.size() - 1;
}

ll spfa(int s, int t) {
  queue<int> q;
  fill(dist, dist + MAX, oo);
  memset(cnt, 0, sizeof(cnt));

  q.emplace(s);
  dist[s] = 0;
  inq[s] = true;
  cnt[s]++;
  p[s] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (int e = pos[u]; e != -1; e = edges[e].prev) {
      int v = edges[e].v;
      ll cost = edges[e].cost;
      ll flow = edges[e].flow;
      if (flow > 0 && dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        p[v] = e;
        if (!inq[v]) {
          inq[v] = true;
          q.emplace(v);
          cnt[v]++;
          if (cnt[v] > t + 1) {
            cout << "Ciclo negativo?\n";
            exit(0);
          }
        }
      }
    }
  }

  if (dist[t] == oo) return 0;
  ll bneck = oo;
  for (int e = p[t]; e != -1; e = p[edges[e].u]) {
    bneck = min(bneck, edges[e].flow);
  }
  return bneck;
}

pair<ll, ll> spfa_ffek(int s, int t) {
  ll flow, cost, bneck;
  flow = cost = bneck = 0;
  while ((bneck = spfa(s, t))) {
    for (int e = p[t]; e != -1; e = p[edges[e].u]) {
      edges[e].flow -= bneck;
      if ((e ^ 1) < (int)edges.size()) edges[e ^ 1].flow += bneck;
    }
    flow += bneck;
    cost += dist[t] * bneck;
  }
  return make_pair(flow, cost);
}
