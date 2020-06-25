#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char left_facing[]  = "< 8      ";
  char right_facing[] = "      8 >";
  char up_arms[]      = "\\ ( U ) /";
  char down_arms[]    = "/ ( U ) \\";
  char step_left[]    = "_     _  ";
  char step_right[]   = "  _     _";
  char spaces[]       = "         ";
  char box_lid[]      = "---------------";

  int i = 1;
  while (i < 3) {
    if (i % 2 == 0) {
      printf("%13s%s%s%s\n", "", "+", box_lid, "+");
      printf("%13s%-4s%s%4s\n", "", "|", spaces, "|");
      printf("%13s%-4s%s%4s\n", "", "|", left_facing, "|");
      printf("%13s%-4s%s%4s\n", "", "|", up_arms, "|");
      printf("%13s%-4s%s%4s\n", "", "|", step_left, "|");
      printf("%13s%-4s%s%4s\n", "", "|", spaces, "|");
      printf("%13s%s%s%s\n", "", "+", box_lid, "+");
    } else {
      printf("%13s%s%s%s\n", "", "+", box_lid, "+");
      printf("%13s%-4s%s%4s\n", "", "|", spaces, "|");
      printf("%13s%-4s%s%4s\n", "", "|", right_facing, "|");
      printf("%13s%-4s%s%4s\n", "", "|", down_arms, "|");
      printf("%13s%-4s%s%4s\n", "", "|", step_right, "|");
      printf("%13s%-4s%s%4s\n", "", "|", spaces, "|");
      printf("%13s%s%s%s\n", "", "+", box_lid, "+");
    }
    printf("%s\n", "");
    sleep(1);
    i++;
  }

  return 0;
}
