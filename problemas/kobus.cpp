#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> are[1123];
int pd(int u, int p, int k, bool in);

vector<int> memoaux[1123][1123];

int pdaux(int u, int p, int i, int k){
    if (i == are[u].size()){
        if (k == 0) return 1;
        else return 0;
    }
    if (are[u][i] == p){
        return pdaux(u, p, i + 1, k);
    }
    int &resp = memoaux[u][k][i];
    if (resp == -1){
        resp = 0;
        for (int j=0; j <= k; j++){
            resp += pd(are[u][i], u, j, 1) * pdaux(u, p, i + 1, k - j);
            resp %= MOD;
        }
    }
    return resp;
}

int memo[1123][1123][2];

int pd(int u, int p, int k, bool in){
    if (k == 0) return 1;
    if (k < 0) return 0;
    int &resp = memo[u][k][in];
    if (resp == -1){
        resp = 0;
        if (in == 0){
            // caso 0, não preciso começar a subárvore aqui
            // posso não começar
            for (auto &x: are[u]){
                if (x != p){
                    resp += pd(x,u, k, 0);
                }
            }
        }
        // começo
        resp += pdaux(u, p,  0, k - 1);
    }
    return resp;
}

int main(){
    int n, k;
    cin >> n >> k;
    for (int i=0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        are[a].push_back(b);
        are[b].push_back(a);
    }
    for (int i=0; i < n; i++){
        for (int j=0; j <= k; j++){
            memo[i][j][0] = memo[i][j][1] = -1;
            memoaux[i][j] = vector<int>(are[i].size(), -1);
        }
    }
    cout << pd(0, 0, k, 0) << "\n";
}
