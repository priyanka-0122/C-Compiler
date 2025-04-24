int fred(char a, int b, int c);

int fred(char a, int b, int c) {
        return(a+b+c);
}

int main() {
        int x;
        x = fred(2, 3, 4);
        printint(x);
        return(0);
}
