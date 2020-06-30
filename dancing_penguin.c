#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

// ASCII art strings
const char left_facing[]  = "< 8      ";
const char right_facing[] = "      8 >";
const char up_arms[]      = "\\ ( U ) /";
const char down_arms[]    = "/ ( U ) \\";
const char step_left[]    = "_     _  ";
const char step_right[]   = "  _     _";
const char spaces[]       = "         ";
const char box_lid[]      = "+-------------------+";

const int box_height = 7;

int main(int argc, char const *argv[]) {

  // Extract Arguements
  int run_time = 3;
  if (argc > 1) {
    run_time = atoi(argv[1]) * 4;
  } else {
    printf("%s\n", "Usage: <executable name> [seconds of dance]\n");
    exit(0);
  }

  // Initialize curses library functions
  initscr();
  noecho();
  curs_set(FALSE);

  // Set dimentional variables
  int win_width, win_height;
  getmaxyx(stdscr, win_height, win_width);

  int box_width = strlen(box_lid);
  int margin = (box_width - strlen(up_arms)) / 2;
  int box_origin[] = {(win_width / 2) - (box_width / 2), (win_height / 2) - (box_height / 2)};

  char str[box_width];
  char head[box_width];
  char body[box_width];
  char feet[box_width];
  char progress[box_width];

  int x, y;
  int face_left = 0;
  int raise_arms = 0;

  int i = 0;
  while (i < run_time) {

    if (i % 4 == 0) face_left ^= 1;
    if (i % 1 == 0) raise_arms ^= 1;

    if (face_left) {
      sprintf(head, "%-*s%s%*s\n",margin, "|", left_facing, margin, "|");
      sprintf(feet, "%-*s%s%*s\n",margin, "|", step_left, margin, "|");
    } else {
      sprintf(head, "%-*s%s%*s\n",margin, "|", right_facing, margin, "|");
      sprintf(feet, "%-*s%s%*s\n",margin, "|", step_right, margin, "|");
    }

    if (raise_arms) {
      sprintf(body, "%-*s%s%*s\n",margin, "|", up_arms, margin, "|");
    } else {
      sprintf(body, "%-*s%s%*s\n",margin, "|", down_arms, margin, "|");
    }

    clear();


    // draw the lid and upper empty rows of the box above the penguins head
    x = box_origin[0];
    y = box_origin[1];
    sprintf(str, "%s", box_lid);
    mvprintw(y++, x, str);
    for (size_t i = 0; i < 2; i++) {
      sprintf(str, "%-*s|\n", box_width - 1, "|");
      mvprintw(y++, x, str);
    }

    // Draw the penguin
    mvprintw(y++, x, head);
    mvprintw(y++, x, body);
    mvprintw(y++, x, feet);

    // Draw bottom and lower empty rows beneath the penguins feet
    for (size_t i = 0; i < 2; i++) {
      sprintf(str, "%-*s|\n", box_width - 1, "|");
      mvprintw(y++, x, str);
    }
    sprintf(str, "%s", box_lid);
    mvprintw(y, x, str);

    refresh();

    i++;
    usleep(250000);
  }

  // Terminate curses library functions
  endwin();
  return 0;
}
