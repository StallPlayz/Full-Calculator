#include <iostream>
#include <cmath>
#include <stdexcept>
#include <sstream>

using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Error: Division by zero");
        }
        return a / b;
    }

    double power(double base, double exponent) {
        return pow(base, exponent);
    }

    double squareRoot(double value) {
        if (value < 0) {
            throw invalid_argument("Error: Cannot take the square root of a negative number");
        }
        return sqrt(value);
    }

    double logBase10(double value) {
        if (value <= 0) {
            throw invalid_argument("Error: Logarithm of non-positive number");
        }
        return log10(value);
    }

    double sin(double angle) {
        return std::sin(degToRad(angle));
    }

    double cos(double angle) {
        return std::cos(degToRad(angle));
    }

    double tan(double angle) {
        return std::tan(degToRad(angle));
    }

private:
    double degToRad(double angle) {
        return angle * M_PI / 180.0;
    }
};

void showMenu() {
    cout << "\nComplex Calculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Power\n";
    cout << "6. Square Root\n";
    cout << "7. Logarithm (base 10)\n";
    cout << "8. Sine\n";
    cout << "9. Cosine\n";
    cout << "10. Tangent\n";
    cout << "11. Exit\n";
}

int main() {
    Calculator calc;
    int choice;
    string input;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        getline(cin, input);
        istringstream iss(input);
        if (!(iss >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (choice == 11) {
            break;
        }

        double a, b;

        switch (choice) {
            case 1: // Addition
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.add(a, b) << endl;
                break;
            case 2: // Subtraction
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.subtract(a, b) << endl;
                break;
            case 3: // Multiplication
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.multiply(a, b) << endl;
                break;
            case 4: // Division
                cout << "Enter two numbers: ";
                cin >> a >> b;
                try {
                    cout << "Result: " << calc.divide(a, b) << endl;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5: // Power
                cout << "Enter base and exponent: ";
                cin >> a >> b;
                cout << "Result: " << calc.power(a, b) << endl;
                break;
            case 6: // Square Root
                cout << "Enter a number: ";
                cin >> a;
                try {
                    cout << "Result: " << calc.squareRoot(a) << endl;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;
            case 7: // Logarithm
                cout << "Enter a number: ";
                cin >> a;
                try {
                    cout << "Result: " << calc.logBase10(a) << endl;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;
            case 8: // Sine
                cout << "Enter an angle (in degrees): ";
                cin >> a;
                cout << "Result: " << calc.sin(a) << endl;
                break;
            case 9: // Cosine
                cout << "Enter an angle (in degrees): ";
                cin >> a;
                cout << "Result: " << calc.cos(a) << endl;
                break;
            case 10: // Tangent
                cout << "Enter an angle (in degrees): ";
                cin >> a;
                cout << "Result: " << calc.tan(a) << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        cin.ignore(); // Clear the newline character from the buffer
    }

    return 0;
}

