/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include "lottery.h"
#include "general.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UUID_LEN 40
#define MAX_TIP_LEN 17
#define MAX_LINE_LEN (UUID_LEN + 1 + MAX_TIP_LEN + 1)

typedef struct FileInfo* FInfo;
struct FileInfo
{
  FILE* fd;
  char csv_separator;
};

FInfo file_info = (FInfo) malloc(sizeof(struct FileInfo));

bool init_lottery(const char *csv_file, char csv_separator)
{
  // Close file if opened before
  if(file_info->fd != 0)
  {
    fclose(file_info->fd);
  }

  file_info->fd = fopen(csv_file, "r");
  file_info->csv_separator = csv_separator;
  return file_info->fd != 0;
}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{
  if(tip_number >= 0)
  {
    char current_line[MAX_LINE_LEN];
    // Reset to position 0
    fseek(file_info->fd, 0, SEEK_SET);

    // Go to line
    for(int i = 0; i <= tip_number; i++)
    {
      if(fgets(current_line, MAX_LINE_LEN, file_info->fd) == 0)
      {
        return false;
      }
    }

    // Split lines with separator
    char* delimited = strtok(current_line, &file_info->csv_separator);
    int counter = 0;

    while(delimited != 0)
    {
      delimited = strtok(0, &file_info->csv_separator);

      // Only if not NULL
      if(delimited != 0)
      {
        tip[counter] = atoi(delimited);
        counter++;
      }
    }

    return true;
  }
  else
  {
    // Invalid tip
    return false;
  }
}

bool set_drawing(int drawing_numbers[TIP_SIZE])
{
  return false;
}

int get_tip_result(int tip_number)
{
  return 0;
}

int get_right_tips_count(int right_digits_count)
{
  return 0;
}
