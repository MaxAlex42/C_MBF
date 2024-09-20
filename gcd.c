#include "includes/gcd.h"

int geuclid (int a, int b) {
    if (a < 0 || b < 0) {
        return -1;
    }
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}