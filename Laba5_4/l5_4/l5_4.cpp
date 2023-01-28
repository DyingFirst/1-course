// lab 5.4

#include <iostream>
class position // позиция
{
public:
    int x, y;

    position() {
        this->x = 0;
        this->y = 0;
        std::cout << "1\n";
    }

    position(int a, int b) {
        this->x = a;
        this->y = b;
    }

    void set_location(int a, int b) {
        this->x = a;
        this->y = b;
    }

    void print_location() {
        std::cout << "X: " << x << "\nY: " << y << '\n';
    }
};

class circumference : public virtual position  // окружность
{
public:
    int rad;
    circumference() {
        this->x = 0;
        this->y = 0;
    }

    circumference(int c) {
        this->rad = c / 2;
    }

    double c_per() {
        return 2 * 3.14 * this->rad;
    }

    double c_array() {
        return 3.14 * this->rad * this->rad;
    }
};

class square : public virtual position  // квдрат
{
public:
    int len; // длина одной стороны
    square() {
        this->x = 0;
        this->y = 0;
    }

    square(int c) {
        this->len = c;
    }

    int s_per() {
        return 4 * this->len;
    }

    int s_array() {
        return this->len * this->len;
    }
};

class circumferenceINsquare : public virtual circumference, public virtual square
{
public:
    circumferenceINsquare() {}
    circumferenceINsquare(int a) {
        this->len = a;
        this->rad = a / 2;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    circumferenceINsquare data(8);
    std::cout << "Площадь круга: " << data.c_array()
        << "\nПлощадь квадрата: " << data.s_array()
        << "\nПериметр круга: " << data.c_per()
        << "\nПериметр квадрата: " << data.s_per()
        << "\nСторона квадрата: " << data.len
        << "\nРадиус круга: " << data.rad << '\n';
}