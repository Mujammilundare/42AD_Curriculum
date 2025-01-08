
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt",O_RDONLY | O_CREAT);
    while (fd > 0)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        printf("%s",line);
        free(line);
    }
    return (0);
}