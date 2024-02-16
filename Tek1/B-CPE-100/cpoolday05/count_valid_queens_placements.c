/*
** EPITECH PROJECT, 2022
** count_valid_queens_placements.c
** File description:
** Implementation of count_valid_queens_placements
*/

static char can_place_queen(int *queen_column_in_rows, int row, int column)
{
    for (int i = 0; i < row; i++) {
        if (queen_column_in_rows[i] == column)
            return 0;
        if (queen_column_in_rows[i] == column - (row - i))
            return 0;
        if (queen_column_in_rows[i] == column + (row - i))
            return 0;
    }
    return 1;
}

static int place_queen(int n, int *queen_column_in_rows, int row)
{
    int count = 0;

    if (row == n)
        return 1;
    for (int column = 0; column < n; column++) {
        if (can_place_queen(queen_column_in_rows, row, column)) {
            queen_column_in_rows[row] = column;
            count += place_queen(n, queen_column_in_rows, row + 1);
        }
    }
    return count;
}

static int count(int n)
{
    int queen_column_in_rows[n];

    return place_queen(n, queen_column_in_rows, 0);
}

int count_valid_queens_placements(int n)
{
    if (n <= 0)
        return 0;
    return count(n);
}
