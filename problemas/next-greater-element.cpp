stack<ii> stk;
vi nxt_greater(vi &vet){
    int n = vet.size();
    vi nxt(n);
    for (int i=0; i < n; i++){
        while (!stk.empty() && stk.top().first < vet[i]){
            nxt[stk.top().second] = i;
            stk.pop();
        }
        stk.emplace(vet[i], i);
    }
    while (!stk.empty()){
        nxt[stk.top().second] = n;
        stk.pop();
    }
    return nxt;
}
