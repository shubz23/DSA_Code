// #include <iostream>
// using namespace std;    
// void func(char * str) {
//     int len = 0;
//     while (str[len] != '\0'){
//         len++;
//     }
//     for(int i=0 ; i<len/2; i++){
//             char temp = str[i];
//             str[i] = str[len-i-1];
//             str[len-i-1] = temp;
//     }
// }

#include <iostream>
using namespace std;

void func(char *str) {
    int len = 0;
    while (str[len] != '\0'){
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    func(str);
    cout << "Reversed string: " << str << endl;
    return 0;
}