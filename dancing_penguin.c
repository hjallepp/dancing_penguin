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

  // Dimensional variables
  int win_width, win_height;
  int x, y;
  int box_origin[2];
  int box_width = strlen(box_lid);
  int margin = (box_width - strlen(up_arms)) / 2;

  // Declare strings for drawing
  char str[box_width];
  char head[box_width];
  char body[box_width];
  char feet[box_width];

  // Cycling variables for cycling image
  int face_left = 0;
  int raise_arms = 0;

  // Declare variables for progress bar
  char progress_bar[box_width];
  int completed;

  int cycle = 1;
  while (cycle < run_time) {
    getmaxyx(stdscr, win_height, win_width);
    box_origin[0] = (win_width / 2) - (box_width / 2);
    box_origin[1] = (win_height / 2) - (box_height / 2);

    if (cycle % 4 == 0) face_left ^= 1;
    if (cycle % 1 == 0) raise_arms ^= 1;

    if (face_left) {
      sprintf(head, "%-*s%s%*s",margin, "|", left_facing, margin, "|");
      sprintf(feet, "%-*s%s%*s",margin, "|", step_left, margin, "|");
    } else {
      sprintf(head, "%-*s%s%*s",margin, "|", right_facing, margin, "|");
      sprintf(feet, "%-*s%s%*s",margin, "|", step_right, margin, "|");
    }

    if (raise_arms) {
      sprintf(body, "%-*s%s%*s",margin, "|", up_arms, margin, "|");
    } else {
      sprintf(body, "%-*s%s%*s",margin, "|", down_arms, margin, "|");
    }

    clear();


    // draw the lid and upper empty rows of the box above the penguins head
    x = box_origin[0];
    y = box_origin[1];
    sprintf(str, "%s", box_lid);
    mvprintw(y++, x, str);
    for (size_t i = 0; i < 2; i++) {
      sprintf(str, "%-*s|", box_width - 1, "|");
      mvprintw(y++, x, str);
    }

    // Draw the penguin
    mvprintw(y++, x, head);
    mvprintw(y++, x, body);
    mvprintw(y++, x, feet);

    // Draw bottom and lower empty rows beneath the penguins feet
    for (size_t i = 0; i < 2; i++) {
      sprintf(str, "%-*s|", box_width - 1, "|");
      mvprintw(y++, x, str);
    }
    sprintf(str, "%s", box_lid);
    mvprintw(y++, x, str);

    // Draw progress bar
    completed = (int)(((float)cycle/(float)(run_time - 1)) * (box_width - 2));
    sprintf(progress_bar, "%s", "");
    for (size_t j = 0; j < completed; j++) {
      sprintf(progress_bar, "%s#", progress_bar);
    }
    sprintf(str, "%s%-*s%s", "[", box_width - 2, progress_bar, "]");
    mvprintw(++y, x, str);

    refresh();

    cycle++;
    usleep(250000);
  }

  // Terminate curses library functions
  endwin();
  return 0;
}
