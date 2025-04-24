long c;
long d;
long *e;
long f;
int main()
{
        c = 12;
        d = 20;
        e = &c + 1;
        f = *e;
        printint(f);
        e = &d - 1;
        f = *e;
        printint(f);
        return(0);
}
