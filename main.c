#include <stdio.h>
#include <malloc.h>
struct foo{
  size_t test;
};

struct bar{
  unsigned int test;
  int padding;
};

int main() {

   struct foo *test_with_size = malloc(sizeof(struct foo));
   if (!test_with_size) {
      return -1;
   }
   struct bar *test_with_padding = malloc(sizeof(struct bar));
   if (!test_with_padding) {
      free(test_with_size);
      return -1;
   }
   test_with_size->test = 1234;
   test_with_padding->test = 1234;
   test_with_padding->padding = 0x555555;

   struct foo *padding_convert_to_size = (struct foo *)test_with_padding;

   printf("test_with_size test %zu\n", test_with_size->test);
   printf("test_with_padding test %u padding %d\n", test_with_padding->test, test_with_padding->padding);
   printf("tpadding_convert_to_size test %zu\n", padding_convert_to_size->test);


   free(test_with_size);
   free(test_with_padding);

   return 0;
}
