#include "/Users/orlandoshamlou/Documents/Coding/CPP_CLion/PPP/PPP_support/PPPheaders.h"

// Calculate operations left-to-right, not considering order of operations
int main() {
    // Prompt
    cout << "Enter an expression (we support '+', '-', '*', '/', and '%'), terminating with '=': ";
    // Get input
    // Calculate

    // Get first operand
    double lval;
    cin >> lval;
    // Calculate operations
    while(true)
    {
        // Get operator-operand pairs or terminating character
        char op = '0';
        cin >> op;
        // User terminates with '='
        if (op == '=')
        {
            break;
        }
        double rval;
        cin >> rval;
        // Check operator and calculate
        switch(op)
        {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            case '%':
                lval = fmod(lval, rval); // % is int only
                break;
            default:
                error("Unrecognised operator");
        }
    }
    // Output
    cout << "Result: " << lval << endl;
}