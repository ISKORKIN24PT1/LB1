#include "modTableCipher.h"
#include <vector>
#include <string>

modTableCipher::modTableCipher(int skey) : key(skey) {}

std::wstring modTableCipher::encryptImpl(const std::wstring& open_text) {
    int len = open_text.length();
    int rows = (len + key - 1) / key; // Округление вверх
    
    // Создаем таблицу и заполняем её
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(key, L' '));
    
    for (int i = 0; i < len; i++) {
        int row = i / key;
        int col = i % key;
        table[row][col] = open_text[i];
    }

    // Читаем по столбцам справа налево
    std::wstring result;
    for (int col = key - 1; col >= 0; col--) {
        for (int row = 0; row < rows; row++) {
            result += table[row][col];
        }
    }

    return result;
}

std::wstring modTableCipher::decryptImpl(const std::wstring& cipher_text) {
    int len = cipher_text.length();
    int rows = (len + key - 1) / key; // Округление вверх
    
    // Создаем пустую таблицу
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(key, L' '));

    // Заполняем таблицу по столбцам справа налево
    int index = 0;
    for (int col = key - 1; col >= 0; col--) {
        for (int row = 0; row < rows; row++) {
            if (index < len) {
                table[row][col] = cipher_text[index++];
            }
        }
    }

    // Читаем по строкам слева направо
    std::wstring result;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < key; col++) {
            result += table[row][col];
        }
    }

    return result;
}

std::wstring modTableCipher::encrypt(const std::wstring& open_text) {
    return encryptImpl(open_text);
}

std::wstring modTableCipher::decrypt(const std::wstring& cipher_text) {
    return decryptImpl(cipher_text);
}