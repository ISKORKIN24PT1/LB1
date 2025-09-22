#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>

class modTableCipher {
private:
    std::wstring numAlpha = L"ААБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    int key;

    std::wstring encryptImpl(const std::wstring& open_text);
    std::wstring decryptImpl(const std::wstring& cipher_text);
public:
    modTableCipher() = delete;
    modTableCipher(int skey);
    std::wstring encrypt(const std::wstring& open_text);
    std::wstring decrypt(const std::wstring& cipher_text);
};