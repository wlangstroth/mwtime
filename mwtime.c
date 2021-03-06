/*
 * mwtime.c
 *
 * Get the amount of time you should cook something in the microwave, if your
 * microwave is a different wattage than specified in the recipe.
 *
 * Will Langstroth
 *
 * MIT License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ANSWER_SIZE 64

int convert_watt_seconds(int, int, int);
char *seconds_to_time(int);

int
main(int argc, char *argv[])
{
  if (argc < 3 || argc > 4) {
    fprintf(stderr, "Usage: %s <recipe-watts> <recipe-time> [target-watts]\n", argv[0]);
    fprintf(stderr, "If target-watts is omitted, 900 is assumed");
    exit(EXIT_FAILURE);
  }

  int recipe_watts = atoi(argv[1]);
  int recipe_time = atoi(argv[2]);

  int target_watts = 900;
  if (argc == 4) {
    target_watts = atoi(argv[3]);
  }

  int answer = convert_watt_seconds(recipe_watts, recipe_time, target_watts);

  if (answer <= 0) {
    fprintf(stderr, "Values must be greater than zero.\n");
    exit(EXIT_FAILURE);
  }

  printf("Your cooking time should be %s.\n", seconds_to_time(answer));

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
// recipe_w -> recipe watts
// recipe_s -> recipe seconds
int
convert_watt_seconds(int recipe_w, int recipe_s, int target_w)
{
  int target_s;

  // Respond to user foolishness
  if (recipe_w <= 0 || recipe_s <=0 || target_w <= 0  ||
      recipe_w > 5000 || recipe_s > 32000 || target_w > 5000)
    return 0;

  target_s = (float) recipe_w / target_w * recipe_s;

  return target_s;
}

// -----------------------------------------------------------------------------
char *
seconds_to_time(int seconds) {
  int h, m, s;
  static char buff[ANSWER_SIZE];

  if (seconds > 0) {
    m = seconds / 60;
    s = seconds % 60;
    h = m / 60;
    m = m % 60;
  } else {
    return "0h 0m 0s";
  }

  sprintf(buff, "%dh %dm %ds", h, m, s);

  return buff;
}
