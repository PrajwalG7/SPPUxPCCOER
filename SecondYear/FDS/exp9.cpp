#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

// Function to check whether a string is a palindrome using a stack
// Takes the string as input
bool isPalindrome(string s)
{
    // Create a stack to store the characters of the string
    stack<char> st;

    // Push the characters of the string onto the stack
    for (char c : s)
    {
        st.push(c);
    }

    // Compare the characters at the top of the stack with the characters at the corresponding position in the string
    for (char c : s)
    {
        // If the characters do not match, return false
        if (st.top() != c)
        {
            return false;
        }

        // Pop the top character from the stack
        st.pop();
    }

    // If all characters were matched, return true
    return true;
}

// Function to remove spaces and punctuation, convert all characters to lowercase, and check whether a string is a palindrome
// Takes the string as input
void checkPalindrome(string s)
{
    // Remove spaces and punctuation, and convert all characters to lowercase
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Check whether the string is a palindrome
    if (isPalindrome(s))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }
}

// Function to print a string in reverse order using a stack
// Takes the string as input
void printReverse(string s)
{
    // Create a stack to store the characters of the string
    stack<char> st;

    // Push the characters of the string onto the stack
    for (char c : s)
    {
        st.push(c);
    }

    // Pop the characters from the stack and print them
    cout << "The string in reverse order: ";
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    // Read a string from the user
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    // Remove spaces and punctuation, convert all characters to lowercase, and check whether the string is a palindrome
    checkPalindrome(s);

    // Print the string in reverse order using a stack
    printReverse(s);

    return 0;
}
