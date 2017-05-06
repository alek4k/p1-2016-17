#include <iostream>
#include "rational.h"

using namespace std;

namespace Numbers {
    // Inserire il codice che implementa le funzioni definite in "rational.h"   
    Rational::Rational (int num, int den) {
        if (num == 0 && den != 0) {
            numerator = 0;
            denominator = 1;
        }
        else if (den == 0) {
            numerator = 0;
            denominator = 0;
        }
        else if (den < 0) {
            denominator = -1 * denominator;
            numerator = -1 * numerator;
        }
        else {
            numerator = num;
            denominator = den;
        }
    }
    
    Rational add(Rational a, Rational b) {
        Rational x (0, 0);
        if ((a.numerator == 0 && a.denominator == 0) || (b.numerator == 0 && b.numerator == 0))
            return x;

        int temp1 = a.denominator * b.denominator;
        int temp2 = temp1 / a.denominator * a.numerator + temp1 / b.denominator * b.numerator;
        Rational c (temp2, temp1);
        
        return reduce (c);
    }

    Rational sub(Rational a, Rational b) {
        Rational x (0, 0);
        if ((a.numerator == 0 && a.denominator == 0) || (b.numerator == 0 && b.numerator == 0))
            return x;
            
        int temp1 = a.denominator * b.denominator;
        int temp2 = temp1 / a.denominator * a.numerator - temp1 / b.denominator * b.numerator;
        Rational c(temp2,temp1);
        
        return reduce (c);
    }

    Rational mul(Rational a, Rational b) {
        Rational c (a.numerator * b.numerator, a.denominator * b.denominator);
        return reduce (c);
    }

    Rational div(Rational a, Rational b) {
        int new_num = a.numerator * b.denominator;
        int new_den = a.denominator * b.numerator;
        if (new_den < 0) {
            new_den = -1 * new_den;
            new_num = -1 * new_num;
        }
        Rational c (new_num, new_den);
        
        return reduce (c);
    }

    Rational reduce(Rational a) {
        if (a.numerator == 0 || a.denominator <= 0)
            return a;
        else if (a.numerator == a.denominator) {
            a.numerator=1;
            a.denominator=1;
        }
        else {
            int big=0, small=0;
            bool neg=false;
            if(a.numerator<0)//numeratore deve essere positivo per il teorema
            {
                a.numerator=a.numerator*-1;
                neg=true;
            }
            if(a.numerator>a.denominator)
            {
                big=a.numerator;
                small=a.denominator;
            }
            else
            {
                big=a.denominator;
                small=a.numerator;
            }
            //big conterrà il valore assoluto più grande tra num e den, small il più piccolo
            //TEOREMA DI EULERO: cerco l'MCD tra big e small
            int q=big/small;//q serve a dire quante volte small è contenuto in big
            int resto=big%small;//il modulo, contiene la differenza tra big e q*small
            //ottengo che big = small*q + resto, small arriverà a valere l'MCD tra big e small, cioè tra num e den.
            while(resto!=0)//R=(resto>=0) && (big = small*q + resto)
            {
                big=small;
                small=resto;
                q=big/small;
                resto=big%small;
            }
            if(neg)//se il numeratore era negativo, lo faccio ritornare tale
            {
                a.numerator=a.numerator*-1;
            }
            a.numerator=a.numerator/small;
            a.denominator=a.denominator/small;
        }
        return a;
    }

    std::ostream & operator<<(std::ostream & s, Rational & r) {
        s << r.numerator << "/" << r.denominator << endl;
        return s;
    }
}

