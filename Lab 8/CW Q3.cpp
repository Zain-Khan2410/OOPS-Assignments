#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInteger {
    private:
        std::vector<int> digits;
        bool isNegative;

        void trim() {
            while (digits.size() > 1 && digits.back() == 0) {
                digits.pop_back();
            }
            if (digits.size() == 1 && digits[0] == 0) {
                isNegative = false;
            }
        }

    public:
        BigInteger() : isNegative(false) {
            digits.push_back(0);
        }

        BigInteger(const std::string &str) {
            isNegative = (str[0] == '-');
            int start = isNegative ? 1 : 0;
            for (int i = str.size() - 1; i >= start; --i) {
                digits.push_back(str[i] - '0');
            }
            trim();
        }

        BigInteger operator+(const BigInteger &other) const {
            if (isNegative == other.isNegative) {
                BigInteger result;
                result.isNegative = isNegative;
                int carry = 0;
                size_t size = std::max(digits.size(), other.digits.size());
                for (size_t i = 0; i < size || carry; ++i) {
                    int sum = carry;
                    if (i < digits.size()) sum += digits[i];
                    if (i < other.digits.size()) sum += other.digits[i];
                    carry = sum / 10;
                    result.digits.push_back(sum % 10);
                }
                result.trim();
                return result;
            }
            if (isNegative) {
                BigInteger temp = *this;
                temp.isNegative = false;
                return other - temp;
            }
            BigInteger temp = other;
            temp.isNegative = false;
            return *this - temp;
        }

        BigInteger operator-(const BigInteger &other) const {
            if (isNegative != other.isNegative) {
                BigInteger temp = other;
                temp.isNegative = !temp.isNegative;
                return *this + temp;
            }
            bool resultNeg = false;
            const BigInteger *larger = this;
            const BigInteger *smaller = &other;
            if (digits.size() < other.digits.size() || (digits.size() == other.digits.size() && digits.back() < other.digits.back())) {
                larger = &other;
                smaller = this;
                resultNeg = true;
            }
            BigInteger result;
            result.isNegative = resultNeg;
            int borrow = 0;
            for (size_t i = 0; i < larger->digits.size(); ++i) {
                int diff = larger->digits[i] - borrow;
                if (i < smaller->digits.size()) {
                    diff -= smaller->digits[i];
                }
                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                result.digits.push_back(diff);
            }
            result.trim();
            return result;
        }

        bool operator==(const BigInteger &other) const {
            return isNegative == other.isNegative && digits == other.digits;
        }

        bool operator!=(const BigInteger &other) const {
            return !(*this == other);
        }

        bool operator<(const BigInteger &other) const {
            if (isNegative != other.isNegative) {
                return isNegative;
            }
            if (digits.size() != other.digits.size()) {
                return (digits.size() < other.digits.size()) != isNegative;
            }
            for (int i = digits.size() - 1; i >= 0; --i) {
                if (digits[i] != other.digits[i]) {
                    return (digits[i] < other.digits[i]) != isNegative;
                }
            }
            return false;
        }

        bool operator>(const BigInteger &other) const {
            return other < *this;
        }

        friend std::ostream& operator<<(std::ostream &out, const BigInteger &num) {
            if (num.isNegative && !(num.digits.size() == 1 && num.digits[0] == 0)) {
                out << '-';
            }
            for (int i = num.digits.size() - 1; i >= 0; --i) {
                out << num.digits[i];
            }
            return out;
        }

        friend std::istream& operator>>(std::istream &in, BigInteger &num) {
            std::string str;
            in >> str;
            num = BigInteger(str);
            return in;
        }
};

int main() {
    BigInteger a("12345678901237897890");
    BigInteger b("-45678901237865435690");
    BigInteger c = a + b;
    BigInteger d = a - b;

    std::cout << "a + b = " << c << std::endl;
    std::cout << "a - b = " << d << std::endl;
    std::cout << "a == b? " << (a == b ? "Yes" : "No") << std::endl;
    std::cout << "a < b? " << (a < b ? "Yes" : "No") << std::endl;
}
