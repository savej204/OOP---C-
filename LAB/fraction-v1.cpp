#include <iostream>
using namespace std;

class Fraction {
    private:
        double numerator;
        double denominator;  
    public:
        Fraction() {
            double numerator = 0.0;
            double denominator = 0.0;
        }

        Fraction(double nu, double de) {
            this -> numerator = nu; this -> denominator = de;
        }

        ~Fraction(){}

        double getNumerator() {
            return numerator;
        }

        double getDenominator() {
            return denominator;
        }

        void setNumerator(double nu) {
            this -> numerator = nu;
        }

        void setDenominator(double de) {
            this -> denominator = de;
        }

        Fraction operator+(Fraction const &obj) {
            Fraction a;
            a.numerator = (numerator * obj.denominator) + (denominator * obj.numerator);
            a.denominator = denominator * obj.denominator;
            return a.optimize();
        }

        Fraction operator-(Fraction const &obj) {
            Fraction b;
            b.numerator = (numerator * obj.denominator) - (denominator * obj.numerator);
            b.denominator = denominator * obj.denominator;
            return b.optimize();
        }

        Fraction operator*(Fraction const &obj) {
            Fraction c;
            c.numerator = numerator * obj.numerator;
            c.denominator = denominator * obj.denominator;
            return c.optimize(); 
        }

        Fraction operator/(Fraction const &obj) {
            Fraction d;
            d.numerator = numerator * obj.denominator;
            d.denominator = denominator * obj.numerator;
            return d.optimize();
        }   
        
        bool operator>(Fraction const &obj) {
            double a,b;
            a = numerator / denominator;
            b = obj.numerator / obj.denominator;
            return a > b;
        }
        bool operator<(Fraction const &obj) {
            double a,b;
            a = numerator / denominator;
            b = obj.numerator / obj.denominator;
            return a < b;
        }

        bool operator==(Fraction const &obj) {
            double a,b;
            a = numerator / denominator;
            b = obj.numerator / obj.denominator;
            return a == b;
        }
    
        bool operator>=(Fraction const &obj) {
            double a,b;
            a = numerator / denominator;
            b = obj.numerator / obj.denominator;
            return a >= b;
        }

        bool operator<=(Fraction const &obj) {
            double a,b;
            a = numerator / denominator;
            b = obj.numerator / obj.denominator;
            return a <= b;
        }
        
        int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        Fraction optimize() {
            Fraction result;
            this -> numerator = numerator; this -> denominator = denominator;
            
            if(numerator == 0) {
                result.numerator = 0;
                result.denominator = 1;
                return result;
            }
    
            else if(numerator != 0) {
                double c = gcd(abs(numerator), abs(denominator));
                numerator /= c;
                denominator /= c;
            }

            if(denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
            result.numerator = numerator;
            result.denominator = denominator;
            return result;
        }
        
        friend istream& operator>>(istream& cin, Fraction& obj) { 
           cin >> obj.numerator >> obj.denominator;
           while(obj.denominator == 0) {
                cout << "ERROR: "; cin >> obj.numerator >> obj.denominator; 
           } 
           return cin; 
        }

        friend ostream& operator<<(ostream&, Fraction& obj) { 
		    cout << obj.numerator << "/" << obj.denominator; 
		    return cout; 
	    }
};

int main()
{
    Fraction c1,c2;
    Fraction hl(0.0, 0.0);
    cin >> c1;
    cin >> c2;
    Fraction c3 = c1 + c2;
    Fraction c4 = c1 - c2;
    Fraction c5 = c1 * c2;
    Fraction c6 = c1 / c2;
    cout << "(+) -> " << c3 << endl;
    cout << "(-) -> " << c4 << endl;
    cout << "(*) -> " << c5 << endl;
    cout << "(/) -> " << c6 << endl;
    if(c1 > c2) { cout << c1 << " > " << c2 << endl; }
    else if(c1 < c2) { cout << c1 << " < " << c2 << endl; }
    if(c1 >= c2) { cout << c1 << " >= " << c2 << endl; }
    else if(c1 <= c2) { cout << c1 << " <= " << c2 << endl; }
    if(c1 == c2) { cout << c1 << " = " << c2 << endl; }
}
