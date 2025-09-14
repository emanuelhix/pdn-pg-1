/*
Parker Hix
*/
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

// removed if-statements in favor of ternary assignments
void selectionSort(float numbers[], int count) {
  for (int outer = 0; outer < count - 1; outer++) {

    // Assume the current position holds
    // the minimum element
    int minIndex = outer;

    // Iterate through the unsorted portion
    // to find the actual minimum
    for (int inner = outer + 1; inner < count; inner++) {
      minIndex = numbers[inner] < numbers[minIndex] ? inner : minIndex;
    }

    // Move minimum element to its
    // correct position
    float swapTemp = numbers[outer];
    numbers[outer] = numbers[minIndex];
    numbers[minIndex] = swapTemp;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input filename> <output filename>\n", argv[0]);
    return 1;
  }

  const int NUM_VALUES = 4;

  FILE *infilename = fopen(argv[1], "r");
  if (infilename == NULL) {
    fprintf(stderr, "Error: could not open input file '%s'\n", argv[1]);
    return 1;
  }
  FILE *outfilename = fopen(argv[2], "w");

  float values[NUM_VALUES];

  for (int i = 0; i < NUM_VALUES; i++) {
    float value;
    if (fscanf(infilename, "%f", &value) != 1) {
      fprintf(stderr, "Error: failed to read float from input file\n");
      fclose(infilename);
      fclose(outfilename);
      return 1;
    }
    values[i] = value;
  }

  selectionSort(values, NUM_VALUES);
  
  for (int i = 0; i < NUM_VALUES; i++) {
    fprintf(outfilename, "%0.1f\n", values[i]);
  }

  fclose(infilename);
  fclose(outfilename);

  return 0;
}
