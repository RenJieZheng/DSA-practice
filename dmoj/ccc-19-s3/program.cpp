
#include <bits/stdc++.h>

using namespace std;

const int X = -1000001;

void fill_row(int matrix[3][3], int row, int vals[3]) {
    for (int i = 0; i < 3; i++) {
        matrix[row][i] = vals[i];
    }
}

void fill_col(int matrix[3][3], int col, int vals[3]) {
    for (int i = 0; i < 3; i++) {
        matrix[i][col] = vals[i];
    }
}

void fill_row_auto(int matrix[3][3], int row) {
    if (matrix[row][0] != X && matrix[row][2] != X) {
        matrix[row][1] = matrix[row][0] + ((matrix[row][2] - matrix[row][0]) / 2);
    } else if (matrix[row][0] != X && matrix[row][1] != X) {
        matrix[row][2] = matrix[row][1] + (matrix[row][1] - matrix[row][0]);
    } else if (matrix[row][1] != X && matrix[row][2] != X) {
        matrix[row][0] = matrix[row][1] - (matrix[row][2] - matrix[row][1]);
    } 
}

void fill_col_auto(int matrix[3][3], int col) {
    if (matrix[0][col] != X && matrix[2][col] != X) {
        matrix[1][col] = matrix[0][col] + ((matrix[2][col] - matrix[0][col]) / 2);
    } else if (matrix[0][col] != X && matrix[1][col] != X) {
        matrix[2][col] = matrix[1][col] + (matrix[1][col] - matrix[0][col]);
    } else if (matrix[1][col] != X && matrix[2][col] != X) {
        matrix[0][col] = matrix[1][col] - ((matrix[2][col] - matrix[1][col]));
    }
}

void find_single_element_in_col(int matrix[3][3], int col, int &el, int &el_r) {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][col] != X) {
            el = matrix[i][col];
            el_r = i;
        }
    }
}

void fill_easily_solvable_positions(int matrix[3][3], bool row_full[3], bool col_full[3]) {
    bool filled = false;
    do {
        filled = false;
        for (int i = 0; i < 3; i++) {
            // Check and Fill Row
            if (!row_full[i]) {
                int num_x = 0;
                for (int j = 0; j < 3; j++) {
                    if (matrix[i][j] == X) {
                        num_x++;
                    }
                }
                if (num_x == 1) {
                    fill_row_auto(matrix, i);
                    row_full[i] = true;
                    filled = true;
                } else if (num_x == 0) {
                    row_full[i] = true;
                }
            }

            // Check and Fill Column
            if (!col_full[i]) {
                int num_x = 0;
                for (int j = 0; j < 3; j++) {
                    if (matrix[j][i] == X) {
                        num_x++;
                    }
                }
                if (num_x == 1) {
                    fill_col_auto(matrix, i);
                    col_full[i] = true;
                    filled = true;
                } else if (num_x == 0) {
                    col_full[i] = true;
                }
            }
        }
    } while (filled);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int matrix[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string s;
            cin >> s;

            if (s == "X") {
                matrix[i][j] = X;
            } else {
                matrix[i][j] = stoi(s);
            }
        }
    }

    bool row_full[3] = {false, false, false};
    bool col_full[3] = {false, false, false};
    fill_easily_solvable_positions(matrix, row_full, col_full);

    if (row_full[0] || row_full[1] || row_full[2]) {
        if (!(row_full[0] && row_full[1] && row_full[2])) {
            // Only 1 row is full, and there are at most 1 column full, 
            // otherwise, the fill_easily_solvable_positions would've been able to fill in each cell

            int full_row = -1;
            for (int i = 0; i < 3; i++) if (row_full[i]) full_row = i;

            int full_col = -1;
            for (int i = 0; i < 3; i++) if (col_full[i]) full_col = i;

            if (full_col != -1) {
                // 1 row and 1 column is full, in all cases we can fill in 1 more square and let
                // fill_easily_solvable_positions fill in the rest

                if (full_row == 0) {
                    if (full_col == 1) {
                        matrix[1][0] = matrix[0][0];
                    } else {
                        matrix[1][1] = matrix[0][1];
                    }
                } else if (full_row == 1) {
                    if (full_col == 1) {
                        matrix[0][0] = matrix[1][0];
                    } else {
                        matrix[0][1] = matrix[1][1];
                    }
                } else {
                    if (full_col == 1) {
                        matrix[1][0] = matrix[2][0];
                    } else {
                        matrix[1][1] = matrix[2][1];
                    }
                }
                fill_easily_solvable_positions(matrix, row_full, col_full);
            } else {
                // Only 1 row is full, we can just duplicate it
                fill_row(matrix, 0, matrix[full_row]);
                fill_row(matrix, 1, matrix[full_row]);
                fill_row(matrix, 2, matrix[full_row]);
            }
        }
    } else if (col_full[0] || col_full[1] || col_full[2]) {
        // None of the rows are full, which means each only has 1 element, and thus only 1 column is full
        // We can simply duplicate this column
        int full_c;
        for (int i = 0; i < 3; i++) if (col_full[i]) full_c = i;

        int vals[3] = {matrix[0][full_c], matrix[1][full_c], matrix[2][full_c]};
        for (int i = 0; i < 3; i++) if (!col_full[i]) fill_col(matrix, i, vals);
    } else {
        // No rows or columns are full but we have at most 1 item in each row col pair
        // These elements can just be duplciated. 
        // From the problem restrictions there are at least 2 non X elements

        int num_non_x = 0;
        int a = X, a_r = -1;
        find_single_element_in_col(matrix, 0, a, a_r);
        if (a != X) num_non_x++;
        int b = X, b_r = -1;
        find_single_element_in_col(matrix, 1, b, b_r);
        if (b != X) num_non_x++;
        int c = X, c_r = -1;
        find_single_element_in_col(matrix, 2, c, c_r);
        if (c != X) num_non_x++;

        if (num_non_x == 0) {
            a = 1;
            b = 1;
            c = 1;
        } else if (num_non_x == 1) {
            if (a != X) b = a;
            else if (b != X) a = b;
            else if (c != X) b = c;
        }

        if (a == X) {
            a = b - (c - b);
        } else if (b == X) {
            // This case could be difficult if c - a is not even and are on opposite corners
            b = a + ((c - a) / 2);
        } else if (c == X) {
            c = b + (b - a);
        }

        int vals[3] = {a, b, c};
        fill_row(matrix, 0, vals);
        fill_row(matrix, 1, vals);
        fill_row(matrix, 2, vals);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j];
            if (j != 2) cout << " ";
        }
        cout << endl;
    }
}