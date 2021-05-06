#include <stdio.h>

#define TEST 1000.0
#define MAXLINE 1000

int sum(int a, int b);
int test_constant_arg(int const);
int get_line(FILE *file, char line[], int limit_size);
void copy(char source[], char dest[]);
int get_char_from_file(FILE *file);
void print_lines_longer_than_eighty(int line_length, char line[]);

int main() {

  // Hello world
  printf("Hello world!\n");
  printf("---------\n\n");

  // Testing compiling
  // int c;
  // c = getchar();
  // putchar(c);
  // printf("\n");
  // printf("c: %d\n", c != EOF);
  printf("EOF: %d\n", EOF);
  printf("---------\n\n");

  // Arguments by value
  int a = 1, b = 3, s;
  printf("a = %d\n", a);
  s = sum(a, b);
  printf("a = %d\n", a);
  printf("sum: %d\n", s);

  test_constant_arg(TEST);
  printf("---------\n\n");

  // Get longest line from file
  int current_line_length, max_length_so_far;
  char line[MAXLINE], longest_line[MAXLINE];
  FILE *file = fopen("/Users/felipe/Projects/coding-interview-university/coding-interview-university/README.md","r");

  if(file == NULL) {
    perror("Error in opening file");
    return(-1);
  }

  max_length_so_far = 0;
  while((current_line_length = get_line(file, line, MAXLINE)) > 0) {
    if (current_line_length > max_length_so_far) {
      max_length_so_far = current_line_length;
      copy(line, longest_line);
    }
    // print_lines_longer_than_eighty(current_line_length, line);
  }
  if (max_length_so_far > 0) {
    printf("Max length: %d\n", max_length_so_far);
    printf("Longest line: %s\n", longest_line);
  }
  printf("---------\n\n");

  return 0;
}

int sum(int a, int b) {
  a = a+b;
  return a;
}

int test_constant_arg(int constant) {
  constant++;
  printf("const: %d\n", constant);
  return constant;
}

int get_line(FILE *file, char line[], int limit_size) {
  int character, i;
  for (i = 0; i < limit_size - 1 && (character = get_char_from_file(file)) != EOF && character != '\n'; i++) {
    line[i] = character;
  }
  if (character == '\n') {
    line[i] = character;
    i++;
  }
  line[i] = '\0';
  return i;
}

void copy(char source[], char dest[]) {
  int i;
  i = 0;
  while((dest[i] = source[i]) != '\0')
    i++;
}

int get_char_from_file(FILE *file) {
  char c = fgetc(file);
  return c;
}

void print_lines_longer_than_eighty(int line_length, char line[]) {
  if (line_length > 80) {
    printf("%s\n", line);
  }
}
