#include <stdio.h>
#include <unistd.h>   // getpagesize()
#include <sys/mman.h> // mprotect()

void a();
void b();
void c();

int main(){
    int psize  = getpagesize();
    void *addr = c - ((long int)c % psize);

    if(mprotect(addr, psize, PROT_READ|PROT_WRITE|PROT_EXEC) == -1){
        perror("mprotect");
        return 1;
    }

    ((unsigned char *)c)[10] = 0xE1;

    c();

    return 0;
}

void a(){
    puts("Função A!");
}

void b(){
    puts("Esta é a função B!");
}

void c(){
    a();
}
