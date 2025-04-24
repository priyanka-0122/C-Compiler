int a;

int add()
{
	int b;
	b = 10;
	printint(a);
	b = b + a;
	a = a * 2;
	printint(a);
	printint(b);
	return(b);
}

int main() {
	int b, c;
	b = 3;
	a = 5;
	printint(b);
	b = b + a;
	printint(b);
	b = add(b) + b;
	printint(a);
	printint(b);
	printint(c);
	return (0);
}
