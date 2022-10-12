#include <stdio.h>
#include <stdlib.h>

#define SIZE 1944

int main(int argc, char *argv[]) {
  unsigned char buffer[SIZE];
  FILE *in;
  FILE *out;

  in = fopen("./test/dungeon.o","rb");
  out = fopen("dungeon_mod.o","w+b");
  fread(buffer,sizeof(buffer),1,in);
  for(int i = 0; i < SIZE; i++){
    printf("%3d-", buffer[i]);
    if ( i % 15 == 0 && i != 0) {
      printf("\n"); 
    }
  }
  fwrite(buffer,sizeof(buffer),1,out);
  fclose(in);
  fclose(out);
  return 0;
}
