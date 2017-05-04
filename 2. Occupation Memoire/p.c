#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main() {
        int i, *p;
        for(i = 0; i < 8192; i++) {
                p = malloc(8*(1024*1024));
                (void *)memset(p, '\0', (8*(1024*1024)));
        }
        return 0;
}