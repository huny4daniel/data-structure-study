#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

void print_complex(Complex c, char *label) {
    if (c.imag >= 0)
        printf("%s = %.2f + %.2fi\n", label, c.real, c.imag);
    else
        printf("%s = %.2f - %.2fi\n", label, c.real, -c.imag);
}

Complex plus(Complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

Complex minus(Complex a, Complex b) {
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

Complex multi(Complex a, Complex b) {
    Complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

Complex conjugate(Complex a) {
    Complex c;
    c.real =  a.real;
    c.imag = -a.imag;
    return c;
}

int main(void) {
    Complex a = {3.0,  2.0};
    Complex b = {1.0, -4.0};

    print_complex(a, "A    ");
    print_complex(b, "B    ");
    printf("\n");

    print_complex(plus(a, b),    "A + B");
    print_complex(minus(a, b),    "A - B");
    print_complex(multi(a, b),    "A * B");
    print_complex(conjugate(a), "~A   ");
    print_complex(conjugate(b), "~B   ");

    return 0;
}
