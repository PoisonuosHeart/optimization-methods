#pragma once

#include <iostream>
#include <string>

class Fraction {
    private:
        /* Числитель */
        int numerator;
        /* Знаменатель */
        int denominator;

        /* Поиск НОД алгоритмом Евклида */
        int gcd(int, int);
        /* Сократить дробь */
        // void reduce();

    public:
        void reduce();
        Fraction() {}
        Fraction(int);
        Fraction(int, int);
        // Fraction(double);
        // Fraction(float);
        // ~Fraction() {}

        // float toFloat();
        // double toDouble();

        // Fraction& operator+(const Fraction &term);
        // Fraction& operator-(const Fraction &term);
        // Fraction& operator*(const Fraction &term);
        // Fraction& operator/(const Fraction &term);

        friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
};

class FractionException {
    private:
        std::string m_error;

    public:
        FractionException(std::string error) : m_error(error) {}

        const char* getError() {return m_error.c_str();}
};
