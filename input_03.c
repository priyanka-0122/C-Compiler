int func(int b) {
	b = foo(b) + 2 ;
	return (b);
}

int foo(int a) {
	return (a + 2);
}

int main() {
	int i;
	i = 10;
	printint(i);
	i = foo(i);
	printint(i);
	i = func(i);
	printint(i);
	return (0);
}
