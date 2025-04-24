char b;
char c;
char d;
char *e;
char f;

int main() {
	b = 10;
  	c = 12;
	d = 14;
	printint(d);
	e = &b;
	printint(e);
	e = &b + 2;
	printint(e);
	f = *e;
	printint(f);
	e = &f - 1;
	printint(e);
  	return(0);
}
