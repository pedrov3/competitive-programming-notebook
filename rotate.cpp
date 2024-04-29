// TODO: circular rotation?

int rotateLeft(int x, int d) { return (x << d) | (x >> (32 - d)) }

int rotateRight(int x, int d) { return (x >> d) | (x << (32 - d)) }
