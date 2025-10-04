#include <iostream>
#include <locale>
#include "modTableCipher.h"

using namespace std;

void test(const wstring& text, int key) {
    modTableCipher cipher(key);
    wstring encrypted = cipher.encrypt(text);
    wstring decrypted = cipher.decrypt(encrypted);
    
    wcout << L"Key: " << key << L" | Text: '" << text << L"'" << endl;
    wcout << L"Encrypted: '" << encrypted << L"'" << endl;
    wcout << L"Decrypted: '" << decrypted << L"'" << endl;
    wcout << endl;
  
}

int main() {
    setlocale(LC_ALL, "");
    
    test(L"Добрый вечер", 4);
    test(L"СЁМГА", 2);
    test(L"ПРИВЕТ мир", 3);
    test(L"АБВГД", 2);
    
    return 0;
}
