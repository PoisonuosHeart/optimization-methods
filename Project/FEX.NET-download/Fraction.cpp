#include "Fraction.hpp"

bool Fraction::operator==(const Fraction& scnd) {
    if ((this->numerator == scnd.numerator) && (this->denominator == scnd.denominator))
        return true;
    return false;
}

Fraction& Fraction::prepareFraction(const Fraction& subFr) {
    Fraction tmp(subFr.numerator, subFr.denominator);
    long int _gcm = gcm(this->denominator, tmp.denominator);
    double k = _gcm / this->denominator;
    this->numerator *= k; this->denominator *= k;
    k = _gcm / tmp.denominator;
    tmp.numerator *= k; tmp.denominator *= k;
    return tmp;
}

int Fraction::gcm(int a, int b) {
    return (a * b / gcd(a, b));
}

int Fraction::gcd(int a, int b) {
    if (a == b) {
        return a;
    }

    a = std::abs(a);
    if (a < b) {
        std::swap(a, b);
    }
    
    int mod = a % b;
    while (mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

void Fraction::reduce() {
    int numerator, denominator;
    int gcd = this->gcd(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
}

Fraction::Fraction(int value) {
    this->numerator = value;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    try {
        if (!denominator) {
            throw FractionException("Знаменатель дроби не можен быть равен 0.");
        }

        this->numerator = numerator;
        this->denominator = denominator;
    }
    catch(FractionException &exception) {
        std::cout << exception.getError() << std::endl;
        exit(1);
    }
}

std::ostream& operator<<(std::ostream &out, const Fraction& fraction) {
    out << fraction.numerator;

    if (fraction.denominator != 1) {
        out << "/" << fraction.denominator;
    }

    return out;
}
