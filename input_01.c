int foo(int a) {
	return (a);
}

int func(int b) {
	return (b);
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
