#include "modAlphaCipher.h"
#include <cctype>
#include <algorithm>

modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    for (size_t i = 0; i < numAlpha.size(); ++i) {
        alphaNum[numAlpha[i]] = static_cast<int>(i);
    }
    std::wstring upperKey = skey;
    std::transform(upperKey.begin(), upperKey.end(), upperKey.begin(), toUpper);
    key = convert(upperKey);
}
wchar_t modAlphaCipher::toUpper(wchar_t c) {
    if (c >= L'а' && c <= L'я') {
        return L'А' + (c - L'а');
    }
    if (c == L'ё') {
        return L'Е'; 
    }
    return std::towupper(c);
}

std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        wchar_t upperC = toUpper(c);
        if (alphaNum.find(upperC) != alphaNum.end()) {
            result.push_back(alphaNum[upperC]);
        }
    }
    return result;
}
std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (auto i : v) {
        if (i >= 0 && i < static_cast<int>(numAlpha.size())) {
            result.push_back(numAlpha[i]);
        }
    }
    return result;
}

std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    std::vector<int> work = convert(open_text);
    if (work.empty() || key.empty()) {
        return L"";
    }
    for (size_t i = 0; i < work.size(); ++i) {
        work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    std::vector<int> work = convert(cipher_text);
    if (work.empty() || key.empty()) {
        return L"";
    }
    for (size_t i = 0; i < work.size(); ++i) {
        work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}