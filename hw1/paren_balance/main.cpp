#include <iostream>
#include <string>

using namespace std;

// Implement below
bool are_paren_balanced(const string& expression);

// We have suggested a helper method, but feel free to write whatever you see fit
bool are_paren_balanced(const string& expression, size_t& i, char expected_closing);

// Do not change this method
int main(int argc, char* argv[]) {

    // Check if an expression has been passed to the program
    if (argc != 2) {
        cerr << "error: expected expression to check!" << endl;
        return -1;
    }

    // The second argument is the expression string in the format specified and
    // promised in the assignment page. You do not need to do any error checking
    // except for checking the parentheses.
    string expression(argv[1]);
    if (are_paren_balanced(expression)) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }

    return 0;
}

// Some notes:
// - This method must be implemented recursively.
// - When debugging, make sure to output to cerr rather than cout. This will
//   prevent any leftover debug statements from confusing the automated
//   grading and will make sure output is guaranteed to be written to the
//   terminal in case your program crashes.
bool are_paren_balanced(const string& expression) {
    // TODO: your code here
    //initialize values
    static int l_b = 0; //left bracket sum
    static int r_b = 0; //right bracket sum
    static int l_p = 0; //left paren sum
    static int r_p = 0; //right paren sum
    static int tester = 0;
    static string p_b_holder = "";
    string paren_comparer = "()";
    string brack_comparer = "[]";
    string expressionCopy = expression;
    int i = expressionCopy.length();
    // if (base case), then return true:
    //  if parens and bracks equal to their respective partners
    //   and if right brackets aren't zero (as in it hasn't iterated yet)
    if(i <= 0)
    {
        if(((l_p == r_p) && (l_b == r_b)))
        {
            string prev = "";
            prev[0] = p_b_holder[p_b_holder.size()];
            for(int i = 1; i <= p_b_holder.size(); i++)
            {
                prev += p_b_holder[p_b_holder.size() - i];
            }
            for(int p = 0; p <= prev.size(); p++)
            {
                //check for each possible opposite,
                // replace with char 'X' if pair found
                // prev ( and holder )
                if(prev[p] == '(' && p_b_holder[p] == ')')
                {
                    prev[p] = 'X';
                    p_b_holder[p] = 'X';
                }
                // prev [ and holder ]
                else if(prev[p] == '[' && p_b_holder[p] == ']')
                {
                    prev[p] = 'X';
                    p_b_holder[p] = 'X';
                }
                //prev ] and holder [
                else if(prev[p] == ']' && p_b_holder[p] == '[')
                {
                    prev[p] = 'X';
                    p_b_holder[p] = 'X';
                }
                //prev ) and holder (
                else if(prev[p] == ')' && p_b_holder[p] == '(')
                {
                    prev[p] = 'X';
                    p_b_holder[p] = 'X';
                }
                //now, check all indices of string have been replaced with X char
            }
            for(int m = 0; m < p_b_holder.length(); m++)
            {
                if(p_b_holder[m] != 'X')
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    // else, continue searching for missing paren pair
    //  moving RTL and popping back after checked index
    else if(i > 0)
    {
        //check if current index is a paren or bracket
        if(expressionCopy[i-1] == paren_comparer[0])
        {
            l_p++;
            p_b_holder += paren_comparer[0];
        }
        else if(expressionCopy[i-1] == brack_comparer[0])
        {
            l_b++;
            p_b_holder += brack_comparer[0];
        }
        else if(expressionCopy[i-1] == paren_comparer[1])
        {
            r_p++;
            p_b_holder += paren_comparer[1];
        }
        else if(expressionCopy[i-1] == brack_comparer[1])
        {
            r_b++;
            p_b_holder += brack_comparer[1];
        }
        else
        {
            tester++;
        }
        
        //decrement index for next iteration
        i--;
        //pop back of copied expression
        expressionCopy.pop_back();
        return are_paren_balanced(expressionCopy);
    }
    else
    {
        return false;
    }
    
    
}

// Add any additional function implementations here.
//


// If you want to use the suggested helper method, you'll have to write its
// definition here.
