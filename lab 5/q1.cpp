#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (next_permutation(s.begin(), s.end())) {
        cout << "Next permutation: " << s << endl;
    } else {
        cout << "No next permutation (already largest)." << endl;
    }

    return 0;
}
