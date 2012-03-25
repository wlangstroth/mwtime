#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int convert_watt_seconds(int recipe_w, int recipe_s, int target_w);
int convert_watt_time(int recipe_w, time_t recipe_time, int target_w);

int
main(int argc, char *argv[])
{
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <recipe-watts> <recipe-time> <target-watts>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int recipe_watts = atoi(argv[1]);
  int recipe_time = atoi(argv[2]);
  int target_watts = atoi(argv[3]);

  int answer = convert_watt_seconds(recipe_watts, recipe_time, target_watts);

  printf("Your cooking time should be %d seconds\n", answer);

  exit(EXIT_SUCCESS);
}

// -----------------------------------------------------------------------------
int
convert_watt_time(int recipe_w, int target_w, time_t recipe_s) {
  return 0;
}

// -----------------------------------------------------------------------------
int
convert_watt_seconds(int recipe_w, int recipe_s, int target_w)
{
  int target_s;

  // For the trivial case
  if (recipe_w == target_w)
    return recipe_s;

  // User fail
  if (recipe_w <= 0 || recipe_s <=0 || target_w <= 0  ||
      recipe_w > 5000 || recipe_s > 32000 || target_w > 5000)
    return 0;

  target_s = (float) recipe_w / target_w * recipe_s;

  return target_s;
}
