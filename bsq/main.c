#include <stdio.h>
#include <stdlib.h>

void free_arr(char **arr, int **d, int rows)
{
    if (arr)
    {
        int i = 0;
        while (i < rows)
        {
            free(arr[i]);
            i++;
        }
        free(arr);
    }
    if (d)
    {
        int i = 0;
        while (i < rows)
        {
            free(d[i]);
            i++;
        }
        free(d);
    }
}

int ext_error(char **map, int **dp, int rows)
{
    if (rows > 0)
        free_arr(map, dp, rows);
    fprintf(stderr, "map error\n");
    return (1);
}

int min(int a, int b, int c)
{
    int m = a;
    if (b < m)
        m = b;
    if (c < m)
        m = c;
    return m;
}

int bsq(int input, char **argv)
{
    int rows;
    int cols = 0;
    char empty, obstacle, full;
    char **map = NULL;
    int **dp = NULL;
    int best_size = 0, best_x = 0, best_y = 0;
    FILE *f;
    if (input > 0)
        f = fopen(argv[input], "r");
    else
        f = stdin;
    if (!f)
        return ext_error(map, dp, 0);
    if (fscanf(f, "%d %c %c %c\n", &rows, &empty, &obstacle, &full) != 4)
        return ext_error(map, dp, 0);
    map = malloc(rows * sizeof(char*));
    if (!map)
        return ext_error(map, dp, 0);
    size_t len = 0;
    int read;
    for (int i = 0; i < rows; i++)
    {
        map[i] = NULL;
        read = getline(&map[i], &len, f);
        if (read <= 0)
            return ext_error(map, dp, rows);
        if(map[i][read - 1] == '\n' || map[i][read - 1] == '\r')
        {
            map[i][read - 1] = '\0';
			read--;
        }
        else
            return ext_error(map, dp, rows);
        if (i == 0)
            cols = read;
        else if (read != cols)
            return ext_error(map, dp, rows);
    }
    if (input > 0)
        fclose(f);
    dp = malloc(rows * sizeof(int*));
    if (!dp)
        return ext_error(map, dp, rows);
    for (int i =0; i < rows; i++)
    {
        dp[i] = calloc(cols, sizeof(int));
        if (!dp[i])
            return ext_error(map, dp, rows);
        for (int j = 0; j < cols; j++)
        {
            char c = map[i][j];
            if (c != empty && c != obstacle)
                return ext_error(map, dp, rows);
            if (c == obstacle)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            if (dp[i][j] > best_size)
            {
                best_size = dp[i][j];
                best_x = i;
                best_y = j;
            }
        }
    }
    for (int i = best_x - best_size + 1; i <= best_x; i++)
    {
        for (int j = best_y - best_size + 1; j <= best_y; j++)
            map[i][j] = full;
    }
    for (int i =0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            putchar(map[i][j]);
        putchar('\n');
    }
    free_arr(map, dp, rows);
    return 0;
}

int main(int argc, char **argv)
{
    int r = 0;
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            r = bsq(i, argv);
            if (i < argc - 1)
                fprintf(stdout, "\n");
        }
    } else
        r = bsq(0, argv);
    return r;
}