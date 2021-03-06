#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	scanf_s("%d", &t);
	cin.ignore();

	while (t--) {
		string buf;
		getline(cin, buf);

		int start = 0;
		int end = 0;

		while (true) {
			if (buf[end] == ' ') {
				// 뒤집기
				int flip = end - 1;
				while (true) {
					if (flip <= start)
						break;

					int tmp = buf[start];
					buf[start] = buf[flip];
					buf[flip] = tmp;
					start++;
					flip--;
				}

				//
				start = end + 1;
			}
			else if (buf[end] == '\0') {
				// 뒤집기
				int flip = end - 1;
				while (true) {
					if (flip <= start)
						break;

					int tmp = buf[start];
					buf[start] = buf[flip];
					buf[flip] = tmp;
					start++;
					flip--;
				}
				break;
			}
			end++;
		}
		cout << buf << endl;
	}
	return 0;
}