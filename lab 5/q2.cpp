#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, r;
    cout << "Enter total elements (n): ";
    cin >> n;
    cout << "Enter number to choose (r): ";
    cin >> r;

    vector<int> a(n);
    cout << "Enter " << n << " elements in increasing order:\n";
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<bool> mask(n);
    fill(mask.begin(), mask.begin() + r, true); // first r elements = true

    // First combination
    do {
        for (int i = 0; i < n; ++i)
            if (mask[i])
                cout << a[i] << " ";
        cout << endl;
    } while (prev_permutation(mask.begin(), mask.end()));

    return 0;
}
