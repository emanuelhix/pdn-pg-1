/*
Parker Hix
*/
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

void selectionSort(float numbers[], int count) {
  int minIndex;
  float swapTemp;

  // outer = 0
  minIndex = 0;
  if (numbers[1] < numbers[minIndex]) minIndex = 1;
  if (numbers[2] < numbers[minIndex]) minIndex = 2;
  if (numbers[3] < numbers[minIndex]) minIndex = 3;
  swapTemp = numbers[0];
  numbers[0] = numbers[minIndex];
  numbers[minIndex] = swapTemp;

  // outer = 1
  minIndex = 1;
  if (numbers[2] < numbers[minIndex]) minIndex = 2;
  if (numbers[3] < numbers[minIndex]) minIndex = 3;
  swapTemp = numbers[1];
  numbers[1] = numbers[minIndex];
  numbers[minIndex] = swapTemp;

  // outer = 2
  minIndex = 2;
  if (numbers[3] < numbers[minIndex]) minIndex = 3;
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
