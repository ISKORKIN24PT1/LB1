#include "modTableCipher.h"
#include <vector>
#include <string>
#include <algorithm>

modTableCipher::modTableCipher(int skey) : key(skey) {}

wchar_t modTableCipher::toUpper(wchar_t c) {
    if (c >= L'а' && c <= L'я') {
        return L'А' + (c - L'а');
    }
    if (c == L'ё') {
        return L'Ё';
    }
    return std::towupper(c);
}

std::wstring modTableCipher::prepareText(const std::wstring& text) {
    std::wstring result;
    for (wchar_t c : text) {
        wchar_t upperC = toUpper(c);
        if ((upperC >= L'А' && upperC <= L'Я') || upperC == L'Ё') {
            result += upperC;
        }
    }
    return result;
}

std::wstring modTableCipher::encryptImpl(const std::wstring& open_text) {
    std::wstring prepared_text = prepareText(open_text);
    int len = prepared_text.length();
    
    if (len == 0 || key <= 0) return L"";

    int rows = (len + key - 1) / key;
    int total_cells = rows * key;
    int pad_chars = total_cells - len;
    
    std::wstring text_with_pad = prepared_text;
    for (int i = 0; i < pad_chars; i++) {
        text_with_pad += L'X';
    }
    
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(key));
    
    int index = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < key; col++) {
            table[row][col] = text_with_pad[index++];
        }
    }

    std::wstring result;
    for (int col = key - 1; col >= 0; col--) {
        for (int row = 0; row < rows; row++) {
            result += table[row][col];
        }
    }

    return result;
}

std::wstring modTableCipher::decryptImpl(const std::wstring& cipher_text) {
    std::wstring text_to_process = cipher_text;
    int len = text_to_process.length();
    
    if (len == 0 || key <= 0) return L"";
    
    int rows = len / key; 
    
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(key));

    int index = 0;
    for (int col = key - 1; col >= 0; col--) {
        for (int row = 0; row < rows; row++) {
            table[row][col] = text_to_process[index++];
        }
    }

    std::wstring result_with_pad;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < key; col++) {
            result_with_pad += table[row][col];
        }
    }

    std::wstring result;
    for (wchar_t c : result_with_pad) {
        if (c != L'X') {
            result += c;
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
