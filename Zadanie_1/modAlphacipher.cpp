#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "modAlphaCipher.h"
using namespace std;
std::wstring numAlpha = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";//алфавит по порядку
std::map <wchar_t, int> alphaNum; //ассоциативный массив "номер по символу"

modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{
    wcout << L"modAlphaCipher constructor: " << skey <<endl;
    for (int i = 0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    } 
    key = convert(skey);
}
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text)
{
    std::vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
    std::vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline std::vector<int> modAlphaCipher::convert(const std::wstring& str)
{
    std::vector<int> result;
    for(auto c:str) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
    std::wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}