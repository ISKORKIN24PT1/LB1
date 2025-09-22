#include <iostream>
#include <locale>
#include "modAlphaCipher.h"

using namespace std;

void check(const wstring& Text, const wstring& key) {
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout << L"key=" << key << endl;
    wcout << L"Original: " << Text << endl;
    wcout << L"Encrypted: " << cipherText << endl;
    wcout << L"Decrypted: " << decryptedText << endl;
    if (Text == decryptedText)
        wcout << L"Ok\n";
    else
        wcout << L"Err\n";
    wcout << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    check(L"ПРИВЕТ", L"МИР");        
    check(L"привет", L"мир");        
    check(L"ПрИвЕт", L"Мир");        
    
    return 0;
}