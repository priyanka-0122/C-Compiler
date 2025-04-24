char c;
char d;
char p;
char q;
char r;
char *e;
char f;

int main()
{
        c = 10;
        d = 20;
        p = 30;
        q = 40;
        r = 50;
        print r;
        e = &c + 2;
        f = *e;
        printint(f);
        e = &p- 1;
        f = *e;
        printint(f);
        return(0);
}
