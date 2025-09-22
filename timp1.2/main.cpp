#include <iostream>
#include <locale>
#include "modTableCipher.h"

using namespace std;

void check(const wstring& Text, int key) {
    wstring cipherText;
    wstring decryptedText;
    modTableCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout << L"key=" << key << endl;
    wcout << Text << endl;
    wcout << cipherText << endl;
    wcout << decryptedText << endl;
    if (Text == decryptedText)
        wcout << L"Ok\n";
    else
        wcout << L"Err\n";
}

int main() {
    setlocale(LC_ALL, "");
    check(L"ПРИВЕТ", 3);
    return 0;
}