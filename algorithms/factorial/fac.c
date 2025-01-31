int it(int f)
{
    int c = 1, i = 1;
    for (; c <= f; i*=c++);
    return i;
}

int rec(int f)
{
    if (f == 1) return 1;
    else {
        return f*rec(f-1);
    }
}
