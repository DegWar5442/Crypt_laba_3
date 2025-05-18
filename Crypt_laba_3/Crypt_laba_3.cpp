#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <cstring>
#include <sstream>
typedef uint32_t uint32;
using namespace std;
//Пірсон
// Фіксована перестановка T 
const uint8_t T[256] = {
    98, 6, 85, 150, 36, 23, 112, 164, 135, 26, 66, 32, 113, 21, 4, 197,
    27, 112, 140, 163, 216, 198, 16, 56, 144, 43, 34, 182, 200, 35, 29, 57,
    25, 223, 241, 193, 14, 221, 1, 254, 2, 248, 246, 79, 229, 203, 67, 168,
    107, 84, 110, 177, 247, 58, 214, 207, 195, 115, 19, 37, 118, 6, 11, 152,
    41, 123, 171, 230, 231, 96, 193, 94, 13, 205, 108, 195, 17, 61, 54, 241,
    80, 76, 95, 125, 8, 126, 215, 179, 91, 209, 83, 93, 180, 190, 111, 166,
    7, 104, 109, 90, 81, 142, 138, 219, 76, 30, 88, 197, 99, 194, 149, 28,
    24, 12, 114, 50, 139, 106, 202, 164, 117, 31, 153, 3, 18, 86, 100, 220,
    210, 164, 40, 250, 120, 103, 178, 145, 227, 38, 130, 232, 174, 121, 49, 5,
    226, 192, 73, 191, 252, 148, 192, 184, 15, 151, 186, 53, 78, 92, 137, 132,
    176, 154, 243, 204, 171, 42, 77, 33, 91, 173, 127, 244, 158, 10, 22, 186,
    122, 236, 188, 20, 63, 147, 141, 82, 74, 222, 133, 183, 69, 143, 172, 65,
    39, 105, 240, 212, 87, 89, 185, 200, 70, 211, 59, 233, 102, 44, 134, 206,
    245, 213, 137, 169, 155, 157, 75, 60, 124, 187, 199, 239, 201, 101, 128, 71,
    175, 46, 55, 129, 161, 62, 116, 165, 156, 225, 167, 189, 97, 208, 255, 243,
    9, 143, 119, 224, 48, 68, 170, 196, 162, 238, 234, 181, 217, 251, 160, 221
};

// Пірсон геш-функція
vector<uint8_t> pirson_hash(const string& input, size_t n = 8) {
    vector<uint8_t> hash(n);
    for (size_t i = 0; i < n; ++i) {
        uint8_t h = T[(static_cast<uint8_t>(input[0]) + i) % 256];
        for (size_t j = 1; j < input.size(); ++j) {
            h = T[static_cast<uint8_t>(input[j]) ^ h];
        }
        hash[i] = h;
    }
    return hash;
}

// Допоміжна функція для виводу гешу в hex
void print_hash(const vector<uint8_t>& hash) {
    for (uint8_t byte : hash) {
        cout << hex << setw(2) << setfill('0') << +byte;
    }
    cout << dec << endl;
}



int main() {
        string input1, input2;
        // Test 1: Determinism
        cout << "-- Test on determinism --" << endl;
        cout << "First: ";
        getline(cin, input1);
        vector<uint8_t> hash1 = pirson_hash(input1);
        cout << "Hash 1: ";
        print_hash(hash1);

        cout << "Second: ";
        getline(cin, input2);
        vector<uint8_t> hash2 = pirson_hash(input2);
        cout << "Hash 2: ";
        print_hash(hash2);

        if (hash1 == hash2) {
            cout << "Test PASSED." << endl;
        }
        else {
            cout << "Test FAILED." << endl;
        }

        // Test 2: Different inputs
        cout << "\n-- Test on different inputs --" << endl;
        cout << "First: ";
        getline(cin, input1);
        cout << "Second: ";
        getline(cin, input2);
        hash1 = pirson_hash(input1);
        hash2 = pirson_hash(input2);

        cout << "Hash 1: ";
        print_hash(hash1);
        cout << "Hash 2: ";
        print_hash(hash2);

        if (hash1 != hash2) {
            cout << "Test PASSED." << endl;
        }
        else {
            cout << "Test FAILED." << endl;
        }

        // Test 3: Different size inputs
        cout << "\n-- Test on different size inputs --" << endl;
        cout << "First: ";
        getline(cin, input1);
        cout << "Second: ";
        getline(cin, input2);
        hash1 = pirson_hash(input1);
        hash2 = pirson_hash(input2);

        cout << "Hash 1: ";
        print_hash(hash1);
        cout << "Hash 2: ";
        print_hash(hash2);

        if (hash1 != hash2) {
            cout << "Test PASSED." << endl;
        }
        else {
            cout << "Test FAILED." << endl;
        }


        return 0;
}
