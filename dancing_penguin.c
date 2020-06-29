#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const char left_facing[]  = "< 8      ";
const char right_facing[] = "      8 >";
const char up_arms[]      = "\\ ( U ) /";
const char down_arms[]    = "/ ( U ) \\";
const char step_left[]    = "_     _  ";
const char step_right[]   = "  _     _";
const char spaces[]       = "         ";
const char box_lid[]      = "+-------------------+";

const int offset = 13;

int main(int argc, char const *argv[]) {
  int run_time = 3;
  if (argc > 1) {
    run_time = atoi(argv[1]) + 1;
  }

  int box_width = strlen(box_lid);
  int margin = (box_width - strlen(up_arms)) / 2;

  int i = 1;
  while (i < run_time) {
    printf("%*s%s\n", offset, "", box_lid);
    printf("%*s%-*s|\n", offset, "", box_width - 1, "|");
    printf("%*s%-*s|\n", offset, "", box_width - 1, "|");
    if (i % 2 == 0) {
      printf("%*s%-*s%s%*s\n", offset, "", margin, "|", left_facing, margin, "|");
      printf("%*s%-*s%s%*s\n", offset, "", margin, "|", up_arms, margin, "|");
      printf("%*s%-*s%s%*s\n", offset, "", margin, "|", step_left, margin, "|");
    } else {
      printf("%*s%-*s%s%*s\n", offset, "", margin, "|", right_facing, margin, "|");
      printf("%*s%-*s%s%*s\n", offset, "", margin, "|", down_arms, margin, "|");
      printf("%*s%-*s%s%*s\n", offset, "", margin, "|", step_right, margin, "|");
    }
    printf("%*s%-*s|\n", offset, "", box_width - 1, "|");
    printf("%*s%-*s|\n", offset, "", box_width - 1, "|");
    printf("%*s%s\n", offset, "", box_lid);
    sleep(1);
    i++;
  }

  return 0;
}
