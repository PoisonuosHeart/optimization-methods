#pragma once

#include <iostream>
#include <string>

class Fraction {
        /* Числитель */ /* Знаменатель */
        int numerator,  denominator;

        /* Поиск НОД алгоритмом Евклида */
        int gcd(int, int);
        int gcm(int, int); //   НОК
        Fraction& prepareFraction(const Fraction& subFr); // Приводит num и denum к нужному виду для операции + || - и возвращает Fraction для этой операции другого числа
        /* Сократить дробь */
        // void reduce();

    public:
        void reduce();
        Fraction() {}
        Fraction(int);
        Fraction(int, int);
        Fraction(const Fraction& _fr) { this->numerator = _fr.numerator; this->denominator = _fr.denominator; }
        // Fraction(double);
        // Fraction(float);
        // ~Fraction() {}

        // float toFloat();
        // double toDouble();

        // Fraction& operator+(const Fraction &term);
        // Fraction& operator-(const Fraction &term);
        // Fraction& operator*(const Fraction &term);
        // Fraction& operator/(const Fraction &term);

        bool operator==(const Fraction& scnd);

        friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
        /**/
        friend Fraction;

        //@ Удалить функции что есть здесь(это для отладки сейчас)!!!!!!!!!!!!!!!!!!!!!!!!!!!
        void add(const Fraction& fr) {
            Fraction a(fr);
            this->reduce(); a.reduce();
            a = prepareFraction(a);
            std::cout << "left fraction: " << *this << "\n";
            std::cout << "right fraction: " << a << "\n";
            this->numerator += a.numerator; 
        }
};

class FractionException {
    private:
        std::string m_error;

    public:
        FractionException(std::string error) : m_error(error) {}

        const char* getError() {return m_error.c_str();}
};
