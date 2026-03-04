#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count_n(int *board, int width, int height, int x, int y)
{
    int n = 0;
    int dx;
    int dy;
    int nx;
    int ny;

    dy = -1;
    while (dy <= 1)
    {
        dx = -1;
        while (dx <= 1)
        {
            if (!(dx == 0 && dy == 0))
            {
                nx = dx + x;
                ny = dy + y;
                if (nx >= 0 && nx < width && ny >= 0 && ny <height)
                    n += board[ny * width + nx];
            }
            dx++;
        }
        dy++;
    }
    return n;
}

void print(int *board, int width, int height)
{
    int x;
    int y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (board[y * width + x])
                putchar('O');
            else
                putchar(' ');
            x++;
        }
        putchar('\n');
        y++;
    }
    
}

int main(int argc, char **argv)
{
    int width;
    int height;
    int iterations;
    int x = 0;
    int y = 0;
    int pen;
    int n;
    int *board;
    int *newboard;
    char c;

    if (argc != 4)
        return (1);
    width = atoi(argv[1]);
    height = atoi(argv[2]);
    iterations = atoi(argv[3]);
    if (width <= 0 || height <=0 || iterations < 0)
        return (1);
    board = calloc(width * height, sizeof(int));
    if (!board)
        return (1);
    while (read(0, &c, 1))
    {
        if (c == 'a')
            x--;
        else if (c == 'd')
            x++;
        else if (c == 'w')
            y--;
        else if (c == 's')
            y++;
        else if (c == 'x')
            pen = !pen;
        if (pen && x >= 0 && x < width && y >= 0 && y < height)
            board[y * width + x] = 1;
    }
    while (iterations--)
    {
        newboard = calloc(width * height, sizeof(int));
        if (!newboard)
            return (1);
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                n = count_n(board, width, height, x, y);
                if (board[y * width + x])
                    newboard[y * width + x] = (n == 2 || n == 3);
                else
                    newboard[y * width + x] = (n == 3);
                x++;
            }
            y++;
        }
        free(board);
        board = newboard;
    }
    
    print(board, width, height);
    free(board);
    return (0);
}