#include <stdio.h>

void printhello(void)
{
    printf("hello\n");
}

int main(void)
{
    printhello();
    void *vp;
    int x = 0xDEADBEEF;
    int *ip = &x;
    vp = ip;
    *ip = 0xCAFFE14E;
    printf("vp:%p hex vp:%x \n", vp, *(int *)vp);
    printf("ip:%p hex ip:%x \n", ip, *ip);
    printf("sizeof vp: %lu\n", sizeof(vp));
    printf("sizeof ip: %lu\n", sizeof(ip));
    // the size of pointers on your machine is 8
    // why would you ever use void pointers?
    //      when you don't care about the type information
    //      also realise that malloc returns a void pointer.
    //      memcpy also deals with void *'s. they don't care
    //      about the var types.
    
}
