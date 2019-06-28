#include iostream
#include roottimp_1timp_1_1modAlphaCipher.h
using namespace std;

void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcoutLkey=  key endl;
    wcoutTextendl;
    wcoutcipherTextendl;
    wcoutdecryptedTextendl;
    if (Text == decryptedText)
        wcoutLOkn;
    else
        wcoutLErrn;
}

int main(int argc, char argv)
{
    locale loc(ru_RU.UTF-8);
    localeglobal(loc);
    check(LДЖОРДЖОРУЭЛЛ,LАБВГД);
    check(LАТЛАНТРАСПРАВИЛПЛЕЧИ,LАЙНРЭНД);
    check(LДЖЕКЛОНДОН,LИДЕН);
    return 0;
}