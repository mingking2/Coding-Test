#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int t = 0; t < T; t++) {
        string crypt, origin;
        getline(cin, crypt);
        getline(cin, origin);

        int len_crypt = crypt.length();
        int len_origin = origin.length();
        int ord_a = 'a';

        vector<int> origin_list(26, 0);
        for (char n_o : origin) {
            origin_list[n_o - ord_a]++;
        }

        bool is_in = false;
        
        vector<int> crypt_list(26, 0);
        for (int i = 0; i < len_origin; i++) {
            crypt_list[crypt[i] - ord_a]++;
        }

		for (int i = len_origin; i < len_crypt; i++) {
			if (crypt_list == origin_list) {
				is_in = true;
				break;
			}

			crypt_list[crypt[i - len_origin] - ord_a]--;
			crypt_list[crypt[i] - ord_a]++;
		}

		if (crypt_list == origin_list) {
			is_in = true;
		}

		cout << (is_in ? "YES" : "NO") << endl;
    }

    return 0;
}
