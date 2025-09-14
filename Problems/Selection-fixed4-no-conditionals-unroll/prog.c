/*
Parker Hix
*/
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

// removed if-statements in favor of ternary assignments
void selectionSort(float numbers[], int count) {
  // Unroll outer loop for count = 4 (NUM_VALUES = 4)
  // outer = 0
  int minIndex = 0;
  minIndex = numbers[1] < numbers[minIndex] ? 1 : minIndex;
  minIndex = numbers[2] < numbers[minIndex] ? 2 : minIndex;
  minIndex = numbers[3] < numbers[minIndex] ? 3 : minIndex;
  float swapTemp = numbers[0];
  numbers[0] = numbers[minIndex];
  numbers[minIndex] = swapTemp;

  // outer = 1
  minIndex = 1;
  // Unroll inner loop for outer = 1: inner = 2, 3
  minIndex = numbers[2] < numbers[minIndex] ? 2 : minIndex;
  minIndex = numbers[3] < numbers[minIndex] ? 3 : minIndex;
  swapTemp = numbers[1];
  numbers[1] = numbers[minIndex];
  numbers[minIndex] = swapTemp;

  // outer = 2
  minIndex = 2;
  // Unroll inner loop for outer = 2: inner = 3
  minIndex = numbers[3] < numbers[minIndex] ? 3 : minIndex;
  swapTemp = numbers[2];
  numbers[2] = numbers[minIndex];
  numbers[minIndex] = swapTemp;

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

  float values[NUM_VALUES];

  for (int i = 0; i < NUM_VALUES; i++) {
    float value;
    if (fscanf(infilename, "%f", &value) != 1) {
      fprintf(stderr, "Error: failed to read float from input file\n");
      fclose(infilename);
      return 1;
    }
    values[i] = value;
  }

  fclose(infilename);

  selectionSort(values, NUM_VALUES);

  FILE *outfilename = fopen(argv[2], "w");
  if (outfilename == NULL) {
    fprintf(stderr, "Error: could not open output file '%s'\n", argv[2]);
    return 1;
  }
  
  for (int i = 0; i < NUM_VALUES; i++) {
    fprintf(outfilename, "%0.1f\n", values[i]);
  }

  fclose(outfilename);

  return 0;
}
