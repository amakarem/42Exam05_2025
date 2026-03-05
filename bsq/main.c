#include <stdio.h>
#include <stdlib.h>

int err_msg()
{
    fprintf(stderr, "map error\n");
    return (1);
}

void free_all(char **map, int **dp, int rows)
{
    if (map)
    {
        for (int i = 0; i < rows; i++)
            free(map[i]);
        free(map);
    }
    if (dp)
    {
        for (int i = 0; i < rows; i++)
            free(dp[i]);
        free(dp);
    }
}

int ext_err(char **map, int **dp, int rows)
{
    free_all(map, dp, rows);
    return err_msg();
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

int bsq(FILE *f)
{
    int rows;
    int cols = 0;
    int read;
    int best_size = 0, best_y = 0, best_x = 0;
    int **dp = NULL;
    size_t len = 0;
    char empty, obstacle, full;
    char **map = NULL;
    if (fscanf(f, "%d %c %c %c\n", &rows, &empty, &obstacle, &full) != 4)
        return err_msg();
    if (rows <= 0 || empty == obstacle || empty == full || obstacle == full)
        return err_msg();
    map = calloc(rows, sizeof(char *));
    if (!map)
        return err_msg();
    for (int i = 0; i < rows; i++)
    {
        map[i] = NULL;
        read = getline(&map[i], &len, f);
        if (read <= 0)
            return ext_err(map, dp, rows);
        if (map[i][read - 1] == '\n' || map[i][read - 1] == '\r')
        {
            map[i][read - 1] = '\0';
            read--;
        }
        else
            return ext_err(map, dp, rows);
        if (i == 0)
            cols = read;
        else if (cols != read)
            return ext_err(map, dp, rows);
    }
    dp = calloc(rows, sizeof(int *));
    if (!dp)
        return ext_err(map, dp, rows);
    for (int y = 0; y < rows; y++)
    {
        dp[y] = calloc(cols, sizeof(int));
        if (!dp[y])
            return ext_err(map, dp, rows);
        for (int x = 0; x < cols; x++)
        {
            char c = map[y][x];
            if (c != empty && c != obstacle)
                return ext_err(map, dp, rows);
            if (c == obstacle)
                dp[y][x] = 0;
            else if (y == 0 || x == 0)
                dp[y][x] = 1;
            else
                dp[y][x] = 1 + min(dp[y - 1][x], dp[y - 1][x - 1], dp[y][x - 1]);
            if (dp[y][x] > best_size)
            {
                best_size = dp[y][x];
                best_y = y;
                best_x = x;
            }
        }
    }
    for (int y = best_y - best_size + 1; y <= best_y; y++)
    {
        for (int x = best_x - best_size + 1; x <= best_x; x++)
            map[y][x] = full;
    }
    for (int y = 0; y < rows; y++)
        fprintf(stdout, "%s\n", map[y]);
    free_all(map, dp, rows);
    return (0);
}

void next_map(int argc, int i)
{
    if (i < argc - 1)
        fprintf(stdout, "\n");
}

int main(int argc, char **argv)
{
    FILE *f;
    int r;
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            f = fopen(argv[i], "r");
            if (!f)
            {
                r = err_msg();
                next_map(argc, i);
                continue;
            }
            r = bsq(f);
            fclose(f);
            next_map(argc, i);
        }
    }
    else
        r = bsq(stdin);
    return (r);
}
