int a;

int add()
{
	int b;
	b = 10;
	b = b + a;
	printint(b);
	return(b);
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
