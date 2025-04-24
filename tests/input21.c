int printf(char *fmt);

int a[8];

void main()
{
        int c, d, e, f, g, h;
       	a[0] = 400;
	a[1] = 300;
        a[2] = 200;
	a[3] = 100;
	a[4] = 10;
	a[5] = 0;

	c = a[0];
        d = a[1];
        e = a[2];
	f = a[3];
	g = a[4];
	h = a[5];
        printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
	printf("%d\n", g);
	printf("%d\n", h);
}
