#include<iostream>
#include<string>
using namespace std;
#include <fstream>
#include<sstream>

struct QInt
{
	int data[4] = { 0 };
	QInt& operator=(const QInt& a)
	{
		for (int i = 0; i < 4; i++) {
			QInt::data[i] = a.data[i];
		}
		return *this;
	}
	void clear() {
		for (int i = 0; i < 4; i++) {
			this->data[i] = 0;
		}
	}
};

//Xử lý chuỗi kí tự
int CharToNum(char a);
char NumToChar(int n);
string DivideStringBy2(string &x);
string ConnectStringsS1S2(string s1, string s2);
void ReverseString(string &s);
string SimplifyStringOfBits(string &a);

//Chuyển đổi giữa các kiểu dữ liệu
//Int - String Of Bits
string IntToStringOfBits(int a);
int StringOfBitsToInt(string s);
//QInt - String Of QInt
void StringOfQIntToQInt(QInt &x, string str);
string QIntToStringOfQInt(QInt);
//QInt - String Of Bits
string QIntToStringOfBits(QInt);
QInt StringOfBitsToQInt(string s);
//Bits (string) - Bools 
bool* StringOfBitsToArrayOfBools(string);


//Hàm xử lý trên QInt
void SetBitIntoQInt(QInt &x, bool a, int vt, int thuTu);
int SizeBitQInt(QInt a);
void ScanQInt(QInt &x);
QInt TwoSComplement(QInt a);
void PrintQIntAsBits(QInt a);

//Chuyển đổi giữa các hệ số
QInt BinToDec(bool *bit);
char FourbitToHex(int a[]);
bool* DecToBin(QInt a);
string BinToHex(bool *bit);
string DecToHex(QInt x);
QInt HexToQInt(string Hex);

// Xử lý BIT
int SizeOfBool(bool *a);
void PrintArrayOfBools(bool *a);

//Toán tử trên string

int Compare(string, string);
string operator+(string, string);
string operator-(string, string);
string operator*(string, string);
string TwoPower_k(int);
string SixteenPower_k(int k);
string ConvertNumberFromHexIntoDec(char c);

//Toán tử trên QINT
QInt operator &(QInt a, QInt b);
QInt operator |(QInt a, QInt b);
QInt operator~(QInt a);
QInt operator^(QInt a, QInt b);
QInt operator <<(QInt a, int k);
QInt operator >> (QInt a, int k);

QInt operator+(QInt a, QInt b);
QInt operator-(QInt a, QInt b);
QInt operator*(QInt M, QInt Q);	//Trả về string
QInt operator/(QInt Q, QInt M);
QInt operator%(QInt Q, QInt M);

//Xử lý FILE
bool CheckStr(string line);
void AnalyseStr(string line, int &format_I, int &format_O, string &data1, string &token, string &data2);
void WorkwithFILE(char *INPUTfilename, char *OUTPUTfilename);

//Chuỗi nhị phân

#pragma once

