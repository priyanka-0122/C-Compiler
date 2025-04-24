int a;

int add()
{
	int c;
	c = 10;
	c = c + a;
	printint(c);
	return(c);
}

int main() {
	int b;
	b = 3;
	a = 5;
	b = b + a;
	printint(b);
	b = add(b) + b;
	printint(b);
	printint(a);
	return (0);
}
