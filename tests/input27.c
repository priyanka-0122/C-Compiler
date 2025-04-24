char *str;
char *str1;
char *str2;

int main() {
  for (str= "Hello\n"; *str != 0; str = str + 1) {
    printchar(*str);
  }
  for (str1= "Welcome"; *str1 != 0; str1 = str1 + 1) {
    printchar(*str1);
  }
  for (str2= " Peers!!\n"; *str2 != 0; str2 = str2 + 1) {
    printchar(*str2);
  }
  return(0);
}
