#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int count;
    cin >> count;

    vector<int> data(count);
    int output[4] = {0, 0, 0, 0};

    for(int i = 0; i < count; i++) {
        cin >> data[i];
        if(data[i] < 19) {
            output[0]++;
        } else if (data[i] < 36) {
            output[1]++;
        } else if (data[i] < 61) {
            output[2]++;
        } else {
            output[3]++;
        }
    }

    cout << fixed << setprecision(2);
    for(int i = 0; i < 4; i++) {
        cout << (output[i] / double(count) * 100) << "%" << endl;
    }

    return 0;
}
