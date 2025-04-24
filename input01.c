char d;
int main()
{
	int a, b, c;
	a = 2;
	b = c = a;

	printint (a);
	printint (b);
	printint (c);
	printint (d);

	a = 20;
        d = a;

	printint (a);
	printint (d);
	return (0);
}
