// Devolve a quantidade de coordenadas inteiras entre dois pontos
// excluindo os próprios pontos
int extremos_inteiros(int ax, int ay, int bx, int by){
    if (ax == bx) return abs(ay - by) - 1;
    if (ay == by) return abs(ax - bx) - 1;
    return __gcd(abs(ax - bx), abs(ay - by)) - 1;
}
