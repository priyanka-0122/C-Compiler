int printf(char *fmt);

int a [3];

void main()
{
        int b, c, d, e, f;
        a[2] = 300;
        a[1] = 200;
        a[0] = 100;

        b = a[2];
        c = a[1];
        d = a[0];

        printf("%d\n", b);
        printf("%d\n", c);
        printf("%d\n", d);
}
