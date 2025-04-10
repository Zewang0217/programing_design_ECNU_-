#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Term {
    int coef;
    int exp;
};

vector<Term> addPolynomials(const vector<Term>& poly1, const vector<Term>& poly2) {
    vector<Term> result;
    int i = 0, j = 0;

    while (i < poly1.size() && j < poly2.size()) {
        if (poly1[i].exp > poly2[j].exp) {
            result.push_back(poly1[i++]);
        }
        else if (poly1[i].exp < poly2[j].exp) {
            result.push_back(poly2[j++]);
        }
        else {
            int sum = poly1[i].coef + poly2[j].coef;
            if (sum != 0) {
                result.push_back({ sum, poly1[i].exp });
            }
            i++;
            j++;
        }
    }
    while (i < poly1.size()) {
        result.push_back(poly1[i++]);
    }
    while (j < poly2.size()) {
        result.push_back(poly2[j++]);
    }

    return result;
}

vector<Term> subtractPolynomials(const vector<Term>& poly1, const vector<Term>& poly2) {
    vector<Term> result;
    int i = 0, j = 0;

    while (i < poly1.size() && j < poly2.size()) {
        if (poly1[i].exp > poly2[j].exp) {
            result.push_back(poly1[i++]);
        }
        else if (poly1[i].exp < poly2[j].exp) {
            result.push_back({ -poly2[j].coef, poly2[j].exp });
            j++;
        }
        else {
            int diff = poly1[i].coef - poly2[j].coef;
            if (diff != 0) {
                result.push_back({ diff, poly1[i].exp });
            }
            i++;
            j++;
        }
    }
    while (i < poly1.size()) {
        result.push_back(poly1[i++]);
    }
    while (j < poly2.size()) {
        result.push_back({ -poly2[j].coef, poly2[j].exp });
        j++;
    }

    return result;
}

vector<Term> multiplyPolynomials(const vector<Term>& poly1, const vector<Term>& poly2) {
    vector<Term> result;

    for (const auto& term1 : poly1) {
        for (const auto& term2 : poly2) {
            int coef = term1.coef * term2.coef;
            int exp = term1.exp + term2.exp;

            auto it = find_if(result.begin(), result.end(), [exp](const Term& t) {
                return t.exp == exp;
                });

            if (it != result.end()) {
                it->coef += coef;
            }
            else {
                result.push_back({ coef, exp });
            }
        }
    }

    return result;
}

void printPolynomial(const vector<Term>& poly) {
    bool firstTerm = true;
    for (const auto& term : poly) {
        if (!firstTerm) {
            if (term.coef > 0) {
                cout << "+";
            }
            else if (term.coef < 0) {
                cout << "-";
            }
        }
        if (abs(term.coef) != 1 || term.exp == 0) {
            cout << abs(term.coef);
        }
        if (term.exp > 0) {
            cout << "X";
            if (term.exp > 1) {
                cout << "^" << term.exp;
            }
        }
        firstTerm = false;
    }
}


vector<Term> readPolynomial() {
    vector<Term> poly;
    int coef, exp;

    while (true) {
        cin >> coef >> exp;
        if (coef == 0 && exp == 0) {
            break;
        }
        poly.push_back({ coef, exp });
    }

    return poly;
}

/*
int main() {
    char op;
    vector<Term> poly1, poly2, result;

    cin >> op;

    poly1 = readPolynomial();

    poly2 = readPolynomial();

    switch (op) {
    case '+':
        result = addPolynomials(poly1, poly2);
        break;
    case '-':
        result = subtractPolynomials(poly1, poly2);
        break;
    case '*':
        result = multiplyPolynomials(poly1, poly2);
        break;
    default:
        cout << "Unsupported operation!" << endl;
        return 1;
    }

    printPolynomial(result);
    cout << endl;

    return 0;
}
*/