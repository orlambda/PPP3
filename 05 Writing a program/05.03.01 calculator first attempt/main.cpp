#include "/Users/orlandoshamlou/Documents/Coding/CPP_CLion/PPP/PPP_support/PPPheaders.h"

// calculates operations left-to-right, does not consider order of operations
int main() {
    // prompt
    cout << "Enter an expression (we support '+', '-', '*', '/', and '%'), terminating with '=': ";
    // get input
    // calculate
    double lval;
    cin >> lval;
    while(true)
    {
        char op = '0';
        cin >> op;
        if (op == '=')
        {
            break;
        }
        double rval;
        cin >> rval;
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
                lval = fmod(lval, rval);
                break;
            default:
                error("Unrecognised operator");
        }
    }
    // output
    cout << "Result: " << lval << endl;
}