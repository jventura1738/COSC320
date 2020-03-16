#include <iostream>

int main () {

    std::string msg = "ATTACKATDAWN";
    int size = msg.length();
    std::string msg2 = "************";

    // basic loop
    int i = 0, j = 0;
    while (j < size) {
        if (i % 2 == 0) {
            int temp = i;
            while (i < size) {
                msg2[j] = msg[i];
                i += 4;
                j++;
            }
            i = temp;
        }
        else {
            int temp = i;
            while (i < size) {
                msg2[j] = msg[i];
                i += 2;
                j++;
            }
            i = temp;
        }
        i++;
    }

    std::cout << msg2 << "\n";

    return 0;
}