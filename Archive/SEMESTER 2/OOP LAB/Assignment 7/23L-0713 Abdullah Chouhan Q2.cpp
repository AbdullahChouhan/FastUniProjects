#include <iostream>

class Time {
    private:
        int hour;
        int minute;
        int second;
        void handleOverflow() {
            do {
            this->second -= 60;
            this->minute++;
            } while (this->second >= 60);
            do {
            this->minute -= 60;
            this->hour++;
            } while (this->minute >= 60);
        }
        void handleUnderflow() {
            do {
            this->second += 60;
            this->minute--;
            } while (this->second < 0);
            do {
            this->minute += 60;
            this->hour--;
            } while (this->minute < 0);
            if (this->hour < 0) {
                this->hour = 0;
            }
        }
    public:
        Time(int h, int m, int s) {
            this->hour = h;
            this->minute = m;
            this->second = s;
            handleOverflow();
            handleUnderflow();
        }
        void display() {
            std::cout << this->hour << ":" << this->minute << ":" << this->second << "\n";
        }
        Time operator+(const Time& other) {
            handleOverflow();
            return Time(this->hour + other.hour, this->minute + other.minute, this->second + other.second);
        }
        Time operator-(const Time& other) {
            handleUnderflow();
            return Time(this->hour - other.hour, this->minute - other.minute, this->second - other.second);
        }
        Time operator++() {
            return Time(this->hour, this->minute, this->second++);
            
        }
        Time operator--() {
            handleUnderflow();
            return Time(this->hour, this->minute, this->second--);
        }
        bool operator== (const Time& other) {
            return this->hour == other.hour && this->minute == other.minute && this->second == other.second;
        }
        bool operator!= (const Time& other) {
            return this->hour != other.hour || this->minute != other.minute || this->second != other.second;
        }
        friend std::ostream& operator<<(std::ostream& cout, const Time& t) {
            if (t.hour < 10) {
                cout << "0";
            }
            cout << t.hour << ":";
            if (t.minute < 10) {
                cout << "0";
            }
            cout << t.minute << ":";
            if (t.second < 10) {
                cout << "0";
            }
            cout << t.second;
            return cout;
        }
        friend std::istream& operator>>(std::istream& cin, Time& t) {
            std::cout << "Enter hour: ";
            cin >> t.hour;
            std::cout << "Enter minute: ";
            cin >> t.minute;
            std::cout << "Enter second: ";
            cin >> t.second;
            t.handleOverflow();
            t.handleUnderflow();
            return cin;
        }

};

int main() {
    Time t1(0, 0, 0);
    Time t2(0, 0, 0);
    std::cout << "Enter first time: ";
    std::cin >> t1;
    std::cout << "Enter second time: ";
    std::cin >> t2;

    Time t3 = t1 - t2;
    std::cout << "Difference = " << t3 << "\n";
    t3 = t1 + t2;
    std::cout << "Sum = " << t3 << "\n";
    ++t3;
    std::cout << "Incremented time = " << t3 << "\n";
    --t3;
    std::cout << "Decremented time = " << t3 << "\n";
    if (t1 == t2)
        std::cout << "Time 1 and Time 2 are equal\n";
    else if (t1 != t2) { // Using the operator for evaluation
        std::cout << "Time 1 and Time 2 are not equal\n";
    }
    return 0;
}