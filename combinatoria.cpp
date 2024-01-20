fat[0] = 1;
for (int i = 1; i < p; i++) {
  fat[i] = fat[i - 1] * i;
}

invfat[p - 1] = mint(1) / fat[p - 1];
for (int i = p - 1; i >= 1; i--) {
  invfat[i - 1] = invfat[i] * (i);
}
