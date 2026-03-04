#include <stdio.h>
#include <stdlib.h>

int error_msg()
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
    return error_msg();
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
    int **dp = NULL;
    int best_size = 0, best_r = 0, best_x = 0;
    char empty, obstacle, full;
    char **map = NULL;
    size_t len = 0;
    if (fscanf(f, "%d %c %c %c\n", &rows, &empty, &obstacle, &full) != 4)
        return error_msg();
    map = malloc(rows * sizeof(char*));
    if (!map)
        return error_msg();
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
        } else
            return ext_err(map, dp, rows);       
        if (i == 0)
            cols = read;
        else if (cols != read)
            return ext_err(map, dp, rows);
    }
    dp = malloc(rows * sizeof(int*));
    if (!dp)
        return ext_err(map, dp, rows);
    for (int r = 0; r < rows; r++)
    {
        dp[r] = calloc(cols, sizeof(int));
        if (!dp[r])
            return ext_err(map, dp, rows);
        for (int x = 0; x < cols; x++)
        {
            char c = map[r][x];
            if (c != empty && c != obstacle)
                return ext_err(map, dp, rows);
            if (c == obstacle)
                dp[r][x] = 0;
            else if (r == 0 || x == 0)
                dp[r][x] = 1;
            else
                dp[r][x] = 1 + min(dp[r - 1][x], dp[r -1][x - 1], dp[r][x - 1]);
            if (dp[r][x] > best_size)
            {
                best_size = dp[r][x];
                best_r = r;
                best_x = x;
            }
        }
    }
    for (int r = best_r - best_size + 1; r <= best_r; r++)
    {
        for (int x = best_x - best_size + 1; x <= best_x; x++)
            map[r][x] = full;
    }
    for (int r = 0; r < rows; r++)
    {
        for (int x = 0; x < cols; x++)
            putchar(map[r][x]);
        putchar('\n');
    }
    free_all(map, dp, rows);
    return 0;
}

int main(int argc, char **argv)
{
    FILE *f;
    int r;
    if (argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            f = fopen(argv[i], "r");
            if (!f)
                return error_msg();
            r = bsq(f);
            fclose(f);
            if (i < argc -1)
                fprintf(stdout, "\n");
        }
    }
    else
        r = bsq(stdin);
    
    return (r);
}