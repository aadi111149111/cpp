#include <iostream>
class CharStack {
private:
    char arr[100];
    int topIndex;

public:
    CharStack() { topIndex = -1; }
    bool push(char c) {
        if (topIndex >= 99) return false;
        arr[++topIndex] = c;
        return true;
    }
    char pop() {
        if (topIndex < 0) return '\0';
        return arr[topIndex--];
    }
    char peek() {
        if (topIndex < 0) return '\0';
        return arr[topIndex];
    }
    bool isEmpty() { return topIndex == -1; }
};

class IntStack {
private:
    int arr[100];
    int topIndex;

public:
    IntStack() { topIndex = -1; }
    bool push(int val) {
        if (topIndex >= 99) return false;
        arr[++topIndex] = val;
        return true;
    }
    int pop() {
        if (topIndex < 0) return 0;
        return arr[topIndex--];
    }
    bool isEmpty() { return topIndex == -1; }
};
class ExpressionParser {
public:
    static int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    static bool isOperand(char c) {
        return (c >= 'A' && c <= 'Z') || 
               (c >= 'a' && c <= 'z') || 
               (c >= '0' && c <= '9');
    }
};
void convertInfixToPostfix(const char* infix, char* postfix) {
    CharStack stack;
    int pIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (ExpressionParser::isOperand(c)) {
            postfix[pIndex++] = c;
        } 
        else if (c == '(') {
            stack.push(c);
        } 
        else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix[pIndex++] = stack.pop();
            }
            stack.pop(); // Remove '('
        } 
        else {
            while (!stack.isEmpty() && stack.peek() != '(' &&
                   (ExpressionParser::precedence(stack.peek()) >= ExpressionParser::precedence(c))) {
                if (c == '^' && stack.peek() == '^') {
                    break; // Right-associativity rule for exponentiation
                }
                postfix[pIndex++] = stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix[pIndex++] = stack.pop();
    }
    postfix[pIndex] = '\0';
}
int evaluatePostfix(const char* postfix) {
    IntStack stack;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            stack.push(c - '0');
        } 
        else {
            int op2 = stack.pop();
            int op1 = stack.pop();

            switch (c) {
                case '+': stack.push(op1 + op2); break;
                case '-': stack.push(op1 - op2); break;
                case '*': stack.push(op1 * op2); break;
                case '/': stack.push(op1 / op2); break;
            }
        }
    }

    return stack.pop();
}
class RecursionExamples {
public:
    static int factorial(int n) {
        if (n <= 1) {
            return 1; // Base case
        }
        return n * factorial(n - 1); // Inductive recursive call
    }

    static int fibonacci(int n) {
        if (n <= 0) return 0; // Base case 1
        if (n == 1) return 1; // Base case 2
        return fibonacci(n - 1) + fibonacci(n - 2); // Binary recursive call
    }
};
int main() {
    // 1. Infix to Postfix Verification
    const char* infixExpr = "A+B*(C-D)";
    char postfixExpr[100];
    convertInfixToPostfix(infixExpr, postfixExpr);

    std::cout << "Infix Expression:   " << infixExpr << "\n";
    std::cout << "Postfix Expression: " << postfixExpr << "\n\n";

    // 2. Postfix Evaluation Verification
    const char* numericPostfix = "53+82-*";
    int evaluationResult = evaluatePostfix(numericPostfix);
    std::cout << "Postfix Expression: " << numericPostfix << "\n";
    std::cout << "Evaluated Result:   " << evaluationResult << "\n\n";

    // 3. Recursion Verification
    int num = 4;
    std::cout << "Factorial(" << num << ")  = " 
              << RecursionExamples::factorial(num) << "\n";
    std::cout << "Fibonacci(" << num << ")  = " 
              << RecursionExamples::fibonacci(num) << "\n";

    return 0;
}