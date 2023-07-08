#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Function to check the strength of a password
int checkPasswordStrength(const string& password) {
    int score = 0;

    // Check length
    if (password.length() >= 8)
        score++;

    // Check for character types using regular expressions
    regex uppercase("[A-Z]");
    regex lowercase("[a-z]");
    regex numbers("[0-9]");
    regex special("[^a-zA-Z0-9]");

    if (regex_search(password, uppercase))
        score++;
    if (regex_search(password, lowercase))
        score++;
    if (regex_search(password, numbers))
        score++;
    if (regex_search(password, special))
        score++;

    // Check for common patterns
    if (!regex_search(password, regex("(.)\\1{2,}")))
        score++;

    return score;
}

// Function to provide feedback based on password strength
void provideFeedback(int score) {
    string strength;

    switch (score) {
        case 0:
            strength = "Very Weak";
            break;
        case 1:
            strength = "Very Weak";
            break;
        case 2:
            strength = "Weak";
            break;
        case 3:
            strength = "Weak";
            break;
        case 4:
            strength = "Moderate";
            break;
        case 5:
            strength = "Moderately Strong"; 
            break;
        default:
            strength = "Strong"; // We always prefer the level strong for any password.
            break;
    }

    cout<<"Score: "<<score<<endl;
    cout << "Password strength: " << strength << endl;

    if (score < 3)
        cout << "Consider using a longer password with a mix of uppercase and lowercase letters, numbers, and special characters." << endl;
}

int main() {
    string password;

    cout << "Enter a password to check its strength: ";
    cin >> password;

    int score = checkPasswordStrength(password);

    provideFeedback(score);

    return 0;
}
