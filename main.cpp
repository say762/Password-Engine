#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

// for output formatting in the terminal
const int BOX_WIDTH = 58;

void printBorder(char corner = '+', char line = '-')
{
    cout << corner << string(BOX_WIDTH - 2, line) << corner << endl;
}

void printCenteredLine(const string &text)
{
    int padding = (BOX_WIDTH - 2 - text.length()) / 2;
    int extra = (BOX_WIDTH - 2 - text.length()) % 2;
    cout << "| " << string(max(0, padding - 1), ' ')
         << text
         << string(max(0, padding - 1 + extra), ' ') << " |" << endl;
}

void printLeftLine(const string &text)
{
    int content_space = BOX_WIDTH - 4;
    string padded_text = text;
    if ((int)padded_text.length() > content_space)
    {
        padded_text = padded_text.substr(0, content_space);
    }
    else
    {
        padded_text.append(content_space - padded_text.length(), ' ');
    }
    cout << "| " << padded_text << " |" << endl;
}

// program logic
void Score(int score)
{
    printBorder('+', '-');
    if (score == 40)
    {
        cout << "PASSWORD RATING: VERY STRONG " << endl;
    }

    else if (score >= 20)
    {
        cout << "PASSWORD RATING: WEAK" << endl;
    }

    else
    {
        cout << "PASSWORD RATING: VERY WEAK (NEEDS TO BE CHANGED)" << endl;
    }
    printBorder('+', '-');
}

bool check_dictionary(const string &password)
{
    ifstream common_file("common-passwords.txt", ios::in);

    if (!common_file)
    {
        throw runtime_error("common-passwords.txt couldnt be opened!");
    }

    string common_pass;
    while (common_file >> common_pass)
    {
        if (password == common_pass)
        {
            return true;
        }
    }
    return false;
}

void PasswordStrength(const string &password)
{

    bool upper = false;
    bool digit = false;
    bool symbol = false;
    int score = 0;

    printBorder('+', '-');
    printCenteredLine("CHECKING PASSWORD STRENGTH");
    printBorder('+', '-');

    if (password.length() < 8)
    {
        printLeftLine("\n Length of the password is less than 8 characters");
    }
    else
    {
        printLeftLine("Password is 8 or 8+ characters");
        score += 10;
    }

    for (char c : password)
    {
        if (isupper(c))
        {
            upper = true;
        }

        if (isdigit(c))
        {
            digit = true;
        }

        if (ispunct(c))
        {
            symbol = true;
        }
    }

    if (!upper)
    {
        printLeftLine("Password does not have any uppercase characters.");
    }
    else
    {
        printLeftLine("Password has uppercase characters");
        score += 10;
    }

    if (!digit)
    {
        printLeftLine("Password does not have any digits");
    }
    else
    {
        printLeftLine("Password has digits");
        score += 10;
    }

    if (!symbol)
    {
        printLeftLine("Password does not have any symbols");
    }
    else
    {
        printLeftLine("Password has symbols");
        score += 10;
    }

    printBorder('+', '-');
    printLeftLine("SCORE:" + to_string(score) + "/40");

    Score(score);
}

int main()
{

    try
    {
        string user_input, pass_input, choice_input;
        do
        {

            ofstream user_file("passwords.txt", ios::app);

            if (!user_file)
            {
                throw runtime_error("Error! Couldn't write to 'password.txt' file");
            }

            cout << endl;
            printBorder('=', '=');
            printCenteredLine("PASSWORD ENGINE");
            printBorder('=', '=');

            cout << "ENTER USERNAME:";
            cin >> user_input;
            cout << endl;

            cout << "ENTER PASSWORD:";
            cin >> pass_input;

            user_file << setw(10) << user_input << " " << setw(10) << pass_input << endl;
            user_file.close();

            cout << endl;
            printBorder('+', '=');
            printLeftLine("USERNAME:" + user_input);
            printLeftLine("PASSWORD:" + pass_input);
            printBorder('+', '=');

            if (check_dictionary(pass_input))
            {
                printBorder('+', '-');
                cout << "\n WEAK PASSWORD (found in the common password list)" << endl;
                printBorder('+', '-');
            }
            else
            {
                cout << "\n Password not found in the common password list" << endl;
                PasswordStrength(pass_input);
            }

            cout << "Write 'yes', to recheck your password or anything else to quit" << endl;
            cin >> choice_input;

            for (char &c : choice_input)
            {
                c = tolower(c);
            }

        } while (choice_input == "yes");
    }

    catch (const exception &e)
    {
        cerr << "Ensure that the 'common_passwords.txt' exists in the same directory" << endl;
        return 1;
    }
    cout << endl;
    printBorder('=', '=');
    printCenteredLine("Exiting the password engine");
    printBorder('=', '=');
    cout << endl;

    return 0;
}
