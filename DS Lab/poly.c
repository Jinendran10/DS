
#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

int main() {
    int i, j, row1, row2, r = 0;
    printf("Enter the degree of polynomial 1: ");
    scanf("%d", &row1);
    printf("Enter the degree of polynomial 2: ");
    scanf("%d", &row2);

    struct poly A[row1 + 1], B[row2 + 1], sum[row1 + row2 + 1];

    for (i = row1; i >= 0; i--) {
        printf("Enter the coefficient of X^%d of polynomial 1: ", i);
        scanf("%d", &A[i].coeff);
        A[i].exp = i;
    }

    for (i = row2; i >= 0; i--) {
        printf("Enter the coefficient of X^%d of polynomial 2: ", i);
        scanf("%d", &B[i].coeff);
        B[i].exp = i;
    }

    i = row1;
    j = row2;

    while (i >= 0 || j >= 0) {
        if (i >= 0 && j >= 0) {
            if (A[i].exp == B[j].exp) {
                sum[r].coeff = A[i].coeff + B[j].coeff;
                sum[r].exp = A[i].exp;
                r++;
                i--;
                j--;
            } else if (A[i].exp > B[j].exp) {
                sum[r].coeff = A[i].coeff;
                sum[r].exp = A[i].exp;
                r++;
                i--;
            } else {
                sum[r].coeff = B[j].coeff;
                sum[r].exp = B[j].exp;
                r++;
                j--;
            }
        } else if (i >= 0) {
            sum[r].coeff = A[i].coeff;
            sum[r].exp = A[i].exp;
            r++;
            i--;
        } else {
            sum[r].coeff = B[j].coeff;
            sum[r].exp = B[j].exp;
            r++;
            j--;
        }
    }

    printf("The sum of polynomial is: ");
    for (i = r - 1; i >= 0; i--) {
        printf("%dX^%d + ", sum[i].coeff, sum[i].exp);
    }

    return 0;
}

