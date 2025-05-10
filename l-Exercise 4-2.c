#include <stdio.h>
#include <ctype.h>

double atof(char s[]) {
    double val, power;
    int i, sign, exsign, exponent;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exsign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;

        for (exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');

        if (exsign == 1)
            while (exponent-- > 0)
                val *= 10.0;
        else
            while (exponent-- > 0)
                val /= 10.0;
    }

    return val;
}

int main(void) {
    printf("%g\n", atof("123.45e-6"));   
    printf("%g\n", atof("6.02E23"));     
    printf("%g\n", atof("-1.2e3"));      
    printf("%g\n", atof("0.1E-2"));     
}
