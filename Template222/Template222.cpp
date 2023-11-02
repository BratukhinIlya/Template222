#include <stack>
#include <cmath>
#include <iostream>
#define EPS 1e-10
#pragma once

template <typename T>
class ImNumber {
private:
    T real;
    T im;
public:
    ImNumber<T>();
    ImNumber(T real, T im);
    double phi() const;
    ImNumber<T> operator+(const ImNumber<T>& num) const;
    ImNumber<T> operator-(const ImNumber<T>& num) const;
    ImNumber<T> operator*(const ImNumber<T>& num) const;
    ImNumber<T> operator/(const ImNumber<T>& num) const;
    ImNumber<T>& operator-=(const ImNumber<T>& num);
    ImNumber<T>& operator+=(const ImNumber<T>& num);
    ImNumber<T>& operator/=(const ImNumber<T>& num);
    ImNumber<T>& operator*=(const ImNumber<T>& num);
    ImNumber<T> operator!() const;
    bool operator==(const ImNumber<T>& num)const;
    bool operator!=(const ImNumber<T>& num)const;
    bool operator<(const ImNumber<T>& num)const;
    double operator()() const;

    template <typename M>
    friend std::ostream& operator<<(std::ostream& out, const ImNumber<M>& num);
};

template <typename T>
ImNumber<T>::ImNumber() : real(0.0), im(0.0) {}

template <typename T>
ImNumber<T>::ImNumber(T real, T im) : real(real), im(im) {}

template <typename T>
double ImNumber<T>::phi() const
{
    return atan2(im, real);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator+(const ImNumber<T>& num) const
{
    return ImNumber<T>(real + num.real, im + num.im);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator-(const ImNumber<T>& num) const
{
    return ImNumber<T>(real - num.real, im - num.im);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator*(const ImNumber<T>& num) const
{
    return ImNumber<T>(real * num.real - im * num.im, real * num.im + im * num.real);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator/(const ImNumber<T>& num) const
{
    double dm = num.real * num.real + num.im * num.im;
    return ImNumber<T>((real * num.real + im * num.im) / dm, (im * num.real - real * num.im) / dm);
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator+=(const ImNumber<T>& num)
{
    real += num.real;
    im += num.im;
    return *this;
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator-=(const ImNumber<T>& num)
{
    real -= num.real;
    im -= num.im;
    return *this;
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator*=(const ImNumber<T>& num)
{
    T new_real = real * num.real - im * num.im;
    T new_im = real * num.im + im * num.real;
    real = new_real;
    im = new_im;
    return *this;
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator/=(const ImNumber<T>& num)
{
    T dm = num.real * num.real + num.im * num.im;
    T new_real = (real * num.real + im * num.im) / dm;
    T new_im = (im * num.real - real * num.im) / dm;
    real = new_real;
    im = new_im;
    return *this;
}

template <typename T>
bool ImNumber<T>::operator==(const ImNumber<T>& num)const
{
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}

template <typename T>
bool ImNumber<T>::operator<(const ImNumber<T>& num) const
{
    return hypot(real, im) < hypot(num.real, num.im);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator!() const
{
    return ImNumber<T>(real, -im);
}

template <typename T>
double ImNumber<T>::operator()() const
{
    return hypot(real, im);
}

template <typename T>
bool ImNumber<T>::operator!=(const ImNumber<T>& num) const
{
    return !(*this == num);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ImNumber<T>& num)
{
    os << num.real;
    if (num.im >= 0)
    {
        os << "+i" << num.im;
    }
    else
    {
        os << "-i" << -num.im;
    }
    return os;
}

template <typename T>
int main() {

    ImNumber<T> one(2, 3);
    ImNumber<T> two(1, 2);

    ImNumber<T> Summa = one + two;
    std::cout << "" << Summa << std::endl;

    ImNumber<T> Raznost = one - two;
    std::cout << "" << Raznost << std::endl;

    ImNumber<T> Proizved = one * two;
    std::cout << "" << Proizved << std::endl;

    ImNumber<T> Delenie = one / two;
    std::cout << "" << Delenie << std::endl;

    std::cout << "|one|: " << one() << std::endl;

    ImNumber<T> Sopryzh = !one;
    std::cout << "Сопряженное num1: " << Sopryzh << std::endl;

    if (one == two)
        std::cout << "one = two" << std::endl;
    else
        std::cout << "one != two" << std::endl;

    if (one < two)
        std::cout << "|one| < |two|" << std::endl;
    else
        std::cout << "|one| >= |two|" << std::endl;

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
