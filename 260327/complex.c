#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

// 복소수 출력: a + bi 형식
void print_complex(Complex c, char *str) {
    if (c.imag >= 0)
        printf("%s = %.2f + %.2fi\n", str, c.real, c.imag);
    else
        printf("%s = %.2f - %.2fi\n", str, c.real, -c.imag);
}

// 켤레 복소수: a + bi -> a - bi
Complex conjugate(Complex a) {
    Complex result;
    result.real =  a.real;
    result.imag = -a.imag;
    return result;
}

// 덧셈: (a+bi) + (c+di) = (a+c) + (b+d)i
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// 뺄셈: (a+bi) - (c+di) = (a-c) + (b-d)i
Complex sub(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// 곱셈: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
Complex mul(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

int main(void) {
    Complex a = {3.0, 2.0};   // 3 + 2i
    Complex b = {1.0, -4.0};  // 1 - 4i

    print_complex(a, "A    ");
    print_complex(b, "B    ");
    printf("\n");

    print_complex(add(a, b),       "A + B");
    print_complex(sub(a, b),       "A - B");
    print_complex(mul(a, b),       "A * B");
    print_complex(conjugate(a),    "~A   ");
    print_complex(conjugate(b),    "~B   ");

    return 0;
}
