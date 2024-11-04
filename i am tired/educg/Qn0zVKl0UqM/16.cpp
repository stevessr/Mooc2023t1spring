#include <iostream>
#include <vector>
#include <sstream>
#include <exception>
#include <map>
using namespace std;

class Term {
public:
    int coefficient;
    int exponent;

    Term(int coeff, int exp) : coefficient(coeff), exponent(exp) {}

    void output() const {
        cout << coefficient << " " << exponent << " ";
    }
};

class Polynomial {
public:
    map<int, int> terms; 

    void addTerm(int coefficient, int exponent) {
        if (coefficient != 0) {
            terms[exponent] += coefficient; 
        }
    }

    Polynomial operator*(const Polynomial &other) const {
        Polynomial result;
        for (const auto &term1 : terms) {
            for (const auto &term2 : other.terms) {
                int newCoeff = term1.second * term2.second;
                int newExp = term1.first + term2.first;
                result.addTerm(newCoeff, newExp); 
            }
        }
        return result;
    }

    void output() const {
        for (auto it = terms.rbegin(); it != terms.rend(); ++it) {
            if (it->second != 0) {
                cout << it->second << " " << it->first << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int n1, n2;
    cin >> n1;
    Polynomial poly1;
    for (int i = 0; i < n1; i++) {
        int coeff, exp;
        cin >> coeff >> exp;
        poly1.addTerm(coeff, exp);
    }
    cin >> n2;
    Polynomial poly2;
    for (int i = 0; i < n2; i++) {
        int coeff, exp;
        cin >> coeff >> exp;
        poly2.addTerm(coeff, exp);
    }

    Polynomial result = poly1 * poly2;
    
    result.output();

    return 0;
}
