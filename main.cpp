#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    ifstream secretList("secret_list.txt");
    string secret;
    string guess;

    // TODO: random selection
    secretList >> secret;
    cout << secret;

    for(;;) {
        cout << "Input: ";
        cin >> guess;

        if (guess.size() != 4) {
            cout << "Need 4 Numbers!" << endl;
            continue;
        }

        if (secret.compare(guess) == 0) {
            cout << "You Win" << endl;
            break;
        }

        int bulls = 0;
        int cows = 0;

        for (int i = 0; i < 4; ++i) {
            size_t found = secret.find(guess[i]);

            if (found != string::npos) {
                if (found == i) {
                    ++bulls;
                } else {
                    ++cows;
                }
            }
        }

        cout << bulls << " bulls and " << cows << " cows" << endl;
    }
    
    return 0;
}