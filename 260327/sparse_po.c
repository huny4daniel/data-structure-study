#include <stdio.h>
#include <math.h>

#define MAX_TERMS 100

typedef struct {
    int exp; // 지수
    float coef; // 계수
} Term;

typedef struct {
    int nTerms; // 다항식의 항의 개수
    Term term[MAX_TERMS]; // 다항식의 항들을 저장하는 배열
} SparsePoly;

// 다항식에 x값 대입
float evaluate(SparsePoly a, float x) {
    float result = 0.f;

    for (int i = 0; i < a.nTerms; i++) {
        result += (float)(a.term[i].coef * pow(x, a.term[i].exp)); // 계수 * x^지수
    }
    return result;
}

// 다항식 덧셈
SparsePoly add(SparsePoly a, SparsePoly b) {
    SparsePoly c;

    c.nTerms = 0;
    for (int i = 0, j = 0; i < a.nTerms || j < b.nTerms;) {
        if (i == a.nTerms || a.term[i].exp < b.term[j].exp) {
            c.term[c.nTerms++] = b.term[j++];
        }
        else if (j == b.nTerms || a.term[i].exp > b.term[j].exp) {
            c.term[c.nTerms++] = a.term[i++];
        }
        else {
            c.term[c.nTerms] = a.term[i++];
            c.term[c.nTerms++].coef += b.term[j++].coef;
        }
    }

    return c;
}

// 다항식 출력
void print_spoly(SparsePoly p, char str[]) {
    printf("%s = ", str);

    for (int i = 0; i < p.nTerms; i++) {
        printf("%5.1f", p.term[i].coef);

        if (p.term[i].exp > 0) {
            printf(" x^%d ", p.term[i].exp);

            if (i < p.nTerms - 1) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

void main(void) {
    SparsePoly a = {2, {{100, 10.0f}, {0, 6.0f}}};
    SparsePoly b = {2, {{50, 1.1f}, {3, 2.0f}}};
    SparsePoly c = add(a, b);

    print_spoly(a, " A = ");
    print_spoly(b, " B = ");
    print_spoly(c, " A + B = ");

    printf("A(1) = %f\n", evaluate(a, 1.0f));
    printf("B(2) = %f\n", evaluate(b, 2.0f));
}