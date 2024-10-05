
void build() {
  fat[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fat[i] = (fat[i - 1] * i) % P;
  }

  invfat[MAX - 1] = expbin(fat[MAX - 1], P - 2);
  for (int i = MAX - 1; i >= 1; i--) {
    invfat[i - 1] = (invfat[i] * (i)) % P;
  }
}
