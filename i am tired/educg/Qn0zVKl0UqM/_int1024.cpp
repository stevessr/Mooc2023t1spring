#include <iostream>
#include <array>
#include <cstring>
#include <stdexcept>
#include <vector>

class _int1024 {
public:
    static const size_t SIZE = 128; // 1024 bits = 128 bytes
    std::array<uint8_t, SIZE> data;

    _int1024() {
        std::memset(data.data(), 0, SIZE);
    }

    _int1024(uint64_t value) {
        std::memset(data.data(), 0, SIZE);
        for (size_t i = 0; i < sizeof(value); ++i) {
            data[i] = (value >> (8 * i)) & 0xFF;
        }
    }

    _int1024 operator+(const _int1024& other) const {
        _int1024 result;
        uint16_t carry = 0;
        for (size_t i = 0; i < SIZE; ++i) {
            uint16_t sum = static_cast<uint16_t>(data[i]) + static_cast<uint16_t>(other.data[i]) + carry;
            result.data[i] = static_cast<uint8_t>(sum & 0xFF);
            carry = sum >> 8;
        }
        return result;
    }

    _int1024 operator-(const _int1024& other) const {
        _int1024 result;
        int16_t borrow = 0;
        for (size_t i = 0; i < SIZE; ++i) {
            int16_t diff = static_cast<int16_t>(data[i]) - static_cast<int16_t>(other.data[i]) - borrow;
            if (diff < 0) {
                diff += 256;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.data[i] = static_cast<uint8_t>(diff & 0xFF);
        }
        return result;
    }

    _int1024 operator*(const _int1024& other) const {
        _int1024 result;
        for (size_t i = 0; i < SIZE; ++i) {
            if (data[i] == 0) continue;
            uint16_t carry = 0;
            for (size_t j = 0; j < SIZE - i; ++j) {
                uint16_t product = (static_cast<uint16_t>(data[i]) * static_cast<uint16_t>(other.data[j])) + static_cast<uint16_t>(result.data[i + j]) + carry;
                result.data[i + j] = static_cast<uint8_t>(product & 0xFF);
                carry = product >> 8;
            }
        }
        return result;
    }

    std::pair<_int1024, _int1024> divide(const _int1024& divisor) const {
        if (divisor == _int1024(0)) {
            throw std::runtime_error("Division by zero");
        }

        _int1024 quotient;
        _int1024 remainder = *this;

        for (int i = SIZE * 8 - 1; i >= 0; --i) {
            remainder = remainder << 1;
            if (remainder >= divisor) {
                remainder = remainder - divisor;
                quotient.data[i / 8] |= (1 << (i % 8));
            }
        }

        return {quotient, remainder};
    }

    _int1024 operator/(const _int1024& other) const {
        auto result = divide(other);
        return result.first;
    }

    _int1024 operator%(const _int1024& other) const {
        auto result = divide(other);
        return result.second;
    }

    _int1024 operator&(const _int1024& other) const {
        _int1024 result;
        for (size_t i = 0; i < SIZE; ++i) {
            result.data[i] = data[i] & other.data[i];
        }
        return result;
    }

    _int1024 operator<<(size_t shift) const {
        _int1024 result;
        size_t byteShift = shift / 8;
        size_t bitShift = shift % 8;

        for (size_t i = SIZE; i > byteShift; --i) {
            result.data[i - 1] = static_cast<uint8_t>(data[i - 1 - byteShift] << bitShift);
            if (i - byteShift > 1) {
                result.data[i - 1] |= static_cast<uint8_t>((data[i - 2 - byteShift] >> (8 - bitShift)) & 0xFF);
            }
        }
        return result;
    }

    _int1024 operator>>(size_t shift) const {
        _int1024 result;
        size_t byteShift = shift / 8;
        size_t bitShift = shift % 8;

        for (size_t i = 0; i < SIZE; ++i) {
            if (i + byteShift < SIZE) {
                result.data[i] = static_cast<uint8_t>(data[i + byteShift] >> bitShift);
                if (i + byteShift + 1 < SIZE) {
                    result.data[i] |= static_cast<uint8_t>((data[i + byteShift + 1] << (8 - bitShift)) & 0xFF);
                }
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const _int1024& num) {
        bool leading_zero = true;
        for (size_t i = SIZE; i > 0; --i) {
            if (num.data[i - 1] != 0) leading_zero = false;
            if (!leading_zero) {
                os << static_cast<int>(num.data[i - 1]);
                if (i > 1) os << " ";
            }
        }
        if (leading_zero) {
            os << "0"; // 处理0的情况
        }
        return os;
    }

    bool operator==(const _int1024& other) const {
        return data == other.data;
    }

    bool operator>=(const _int1024& other) const {
        for (int i = SIZE - 1; i >= 0; --i) {
            if (data[i] > other.data[i]) return true;
            if (data[i] < other.data[i]) return false;
        }
        return true;
    }
};

int main() {
    _int1024 num1(123456789);
    _int1024 num2(987654321);

    _int1024 sum = num1 + num2;
    _int1024 diff = num1 - num2;
    _int1024 prod = num1 * num2;
    _int1024 div = num1 / num2;
    _int1024 mod = num1 % num2;
    _int1024 and_op = num1 & num2;
    _int1024 left_shift = num1 << 1;
    _int1024 right_shift = num1 >> 1;

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "sum: " << sum << std::endl;
    std::cout << "diff: " << diff << std::endl;
    std::cout << "prod: " << prod << std::endl;
    std::cout << "div: " << div << std::endl;
    std::cout << "mod: " << mod << std::endl;
    std::cout << "and: " << and_op << std::endl;
    std::cout << "left shift: " << left_shift << std::endl;
    std::cout << "right shift: " << right_shift << std::endl;

    return 0;
}
