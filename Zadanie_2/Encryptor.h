#pragma once
#include <string>
using namespace std;
class Encryptor {
public:
	string encrypt(string in, const int key);
	string decrypt(string in, const int key);
};