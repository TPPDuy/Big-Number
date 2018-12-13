#include"Function.h"

//X? LÝ CHU?I KÍ T?

// Chuy?n t? kí t? sang s?(t? 0 -> 9, vu?t giá tr? thì tr? v? - 1), hàm tr? v? 1 s? nguyên t? 0 d?n 9 tuong ?ng v?i kí t? chu?i truy?n vào
int CharToNum(char a)
{
	if (a >= '0' && a <= '9') {
		switch (a) {
		case '0': return 0; break;
		case '1': return 1; break;
		case '2': return 2; break;
		case '3': return 3; break;
		case '4': return 4; break;
		case '5': return 5; break;
		case '6': return 6; break;
		case '7': return 7; break;
		case '8': return 8; break;
		case '9': return 9; break;
		}
	}
	else return -1;
}

// Chuy?n t? s? sang kí t? (t? 0 -> 9), hàm tr? v? kí t? t? '0' d?n '9' v?i các s? tuong ?ng truy?n vào
char NumToChar(int n)
{
	if (n >= 0 && n <= 9) {
		switch (n) {
		case 0: return '0'; break;
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		}
	}
}

//Chia dôi chu?i s? l?n, tr? v? chu?i là k?t qu? c?a chu?i x chia cho 2 (chu?i tr? v? v? là chu?i nguyên)
string DivideStringBy2(string &x)
{
	int temp = 0;
	int i = 0, j = 0;
	string strXuat;
	if (x == "1") {
		strXuat = '0';
		return strXuat;
	}
	while (i != x.length()) {
		temp += CharToNum(x[i]);
		if (temp >= 2) {
			if (temp % 2 == 1) {
				temp--;
				strXuat.push_back(NumToChar(temp / 2));
				temp = 10;
				i++, j++;
			}
			else {
				strXuat.push_back(NumToChar(temp / 2));
				i++, j++;
				temp = 0;
			}
		}
		else {
			if (i != 0) {
				temp *= 10;
				strXuat.push_back('0');
				i++, j++;
			}
			else {
				temp *= 10;
				i++;
			}
		}
	}
	return strXuat;
}

//N?i 2 chu?i s1 và s2, tr? v? m?t chu?i k?t qu? t? 2 chu?i ban d?u
string ConnectStringsS1S2(string s1, string s2) {
	string s;
	int doDai = 2 * s1.length();
	int j = 0;
	for (int i = 0; i < doDai; i++)
	{
		if (i >= doDai - s1.length())
		{
			s.push_back(s2[j]);
			j++;
		}
		else
			s.push_back(s1[i]);
	}
	return s;
}

//Ð?o ngu?c chu?i
void ReverseString(string &s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		swap(s[i], s[s.length() - i - 1]);
	}
}

//Ðon gi?n chu?i Bits, lo?i b? các s? 0 không có ý nghia v? m?t giá tr? (tùy tru?ng h?p)
string SimplifyStringOfBits(string &a)
{
	int i;
	for (i = 0; i < a.length(); i++)
	{
		if (a[i] == '1') break;
	}
	if (i == a.length()) i--;
	a.erase(0, i);
	return a;
}

//CHUY?N Ð?I GI?A CÁC KI?U D? LI?U

//Int - String Of Bits
string IntToStringOfBits(int a)
{
	string s;
	for (int i = 0; i <= 31; i++) {
		bool bit = a & 1;
		s.push_back(bit + 48);
		a = a >> 1;
	}
	ReverseString(s);
	return s;
}

int StringOfBitsToInt(string s)
{
	int a = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int bit = s[s.length() - 1 - i] - 48;
		bit <<= i;
		a = a | bit;
	}
	return a;
}

//QInt - String Of QInt
string QIntToStringOfQInt(QInt x) // tr? ra s? nguyên l?n t? QInt
{
	string Bit = QIntToStringOfBits(x);
	string BigInt = "0";
	for (char i = Bit.length() - 1; i > 0; i--)
	{
		if (Bit[i] == '1')
		{
			BigInt = BigInt + TwoPower_k(Bit.length() - i - 1);
		}
	}
	if (Bit[0] == '1')
	{
		BigInt = BigInt - TwoPower_k(Bit.length() - 1);
	}
	return BigInt;
}

void StringOfQIntToQInt(QInt &x, string str)
{
	if (str[0] != '-') {
		int thuTu = 3;
		int viTriBit = 0;
		int temp;
		bool bit;
		while (str != "0") {
			temp = CharToNum(str[str.length() - 1]);
			if (temp % 2 == 1) {
				bit = 1;
			}
			else {
				bit = 0;
			}
			str = DivideStringBy2(str);
			SetBitIntoQInt(x, bit, viTriBit, thuTu);
			viTriBit++;
			if (viTriBit == 32) {
				viTriBit = 0;
				thuTu--;
			}
		}
	}
	else {
		QInt a;
		string str1;
		for (int i = 1; i < str.length(); i++) {// copy l?i chu?i str vào chu?i str1 nhung không copy d?u "-", vd: str = "-10" ==> str1 = "10"
			str1.push_back(str[i]);
		}

		int thuTu = 3;
		int viTriBit = 0;
		int temp;
		bool bit;
		while (str1 != "0") {
			temp = CharToNum(str1[str1.length() - 1]);
			if (temp % 2 == 1) {
				bit = 1;
			}
			else {
				bit = 0;
			}
			str1 = DivideStringBy2(str1);
			SetBitIntoQInt(a, bit, viTriBit, thuTu);
			viTriBit++;
			if (viTriBit == 32) {
				viTriBit = 0;
				thuTu--;
			}
		}
		// << str1 << endl;
		x = TwoSComplement(a);
	}
}

//QInt - String Of Bits
string QIntToStringOfBits(QInt a) // xu?t dãy bit t? QInt sang chu?i
{
	string ChuoiBit = "";
	for (int i = 3; i >= 0; i--)
	{
		int temp = 1;
		for (int j = 1; j <= 32; j++) //d?ch ph?i 32 l?n d? l?y h?t bit trong data[i]
		{
			bool bit = a.data[i] & temp;
			//chèn bit vô ChuoiBit
			ChuoiBit.push_back(bit + 48);
			temp <<= 1;
		}
	}
	ReverseString(ChuoiBit);
	return ChuoiBit;
}

QInt StringOfBitsToQInt(string s)
{
	QInt a;
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j <= 31; j++)
		{
			if (s.length() > 0) {
				bool x = ((s[s.length() - 1]) - 48) & 1;
				s.pop_back();
				SetBitIntoQInt(a, x, j, i);
			}
			else {
				return a;
			}
		}
	}
	return a;
}

//Bits (string) - Bools 
bool* StringOfBitsToArrayOfBools(string a)
{
	bool* s = new bool[128];
	int i, j;
	for (i = 0; i < 128; i++)
		s[i] = 0;
	for (i = 127, j = a.length() - 1; i >=0 && j >= 0; i--,j--) {
		s[i] = CharToNum(a[j]);
	}
	return s;
}

//HÀM X? LÝ TRÊN QINT

// Ðua bit có giá tr? a vào v? trí bit th? vt trong x.data[thuTu].
void SetBitIntoQInt(QInt &x, bool a, int vt, int thuTu)
{
	x.data[thuTu] = (a << vt) | x.data[thuTu];
}

// Tr? v? s? lu?ng bit c?a a
int SizeBitQInt(QInt a)
{
	int size = 0;
	int i = 31, thuTu = 0;
	bool temp = (a.data[0] >> 31) & 1;
	while (temp == false) {
		size++, i--;
		if (i == -1) {
			i = 31;
			thuTu++;
		}
		temp = (a.data[thuTu] >> i) & 1;
	}
	return 128 - size;
}

void ScanQInt(QInt &x)
{
	string a;
	cout << "Nhap chuoi so nguyen lon: ";
	getline(cin, a);
	StringOfQIntToQInt(x, a);
}

//N?u s? nh?p vào là s? âm thì chuy?n nó qua bù 2
QInt TwoSComplement(QInt a)
{
	a = ~a;// Ð?o bit => bù1
	QInt b;
	b.data[3] = 1;
	return (a + b);// bù1 + 1 = bù2
}

//Xu?t chu?i bit trong QInt
void PrintQIntAsBits(QInt a)
{
	int dem = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 32; i++) {
			cout << ((a.data[j] >> (31 - i)) & 1);
			dem++;
			if (dem == 32) {
				dem = 0;
				cout << " ";
			}
		}
	}
}

//CHUY?N Ð?I GI?A CÁC H? S?

QInt BinToDec(bool *bit)
{
	QInt a;
	int j = 127;
	/*int i = SizeOfBool(bit) - 1;*/
	int i = 127;
	int viTriBit = 0, thuTu = 3;
	while (i >= SizeOfBool(bit) - 1) {
		SetBitIntoQInt(a, bit[i], viTriBit, thuTu);
		i--;
		viTriBit++;
		if (viTriBit == 32) {
			viTriBit = 0;
			thuTu--;
		}
	}
	return a;
}

char FourbitToHex(int a[])
{
	int temp = a[0] * 8 + a[1] * 4 + a[2] * 2 + a[3] * 1;
	switch (temp) {
	case 0: return '0'; break;
	case 1: return '1'; break;
	case 2: return '2'; break;
	case 3: return '3'; break;
	case 4: return '4'; break;
	case 5: return '5'; break;
	case 6: return '6'; break;
	case 7: return '7'; break;
	case 8: return '8'; break;
	case 9: return '9'; break;
	case 10: return 'A'; break;
	case 11: return 'B'; break;
	case 12: return 'C'; break;
	case 13: return 'D'; break;
	case 14: return 'E'; break;
	case 15: return 'F'; break;
	}
}

bool* DecToBin(QInt a)
{
	//int size = SizeBitQInt(a);
	//bool *Bin = new bool[size];
	bool *Bin = new bool[128];
	int thuTu = 3;
	int viTriBit = 0;
	for (int i = 127; i >= 0; i--) {
		if (viTriBit == 32) {
			viTriBit = 0;
			thuTu--;
		}
		Bin[i] = ((a.data[thuTu] >> viTriBit) & 1);
		viTriBit++;
	}
	return Bin;
}

string BinToHex(bool *bit)
{
	int i = 128 - SizeOfBool(bit); // chỉ số của mảng bit
	int a[4] = { 0 };
	int mod = SizeOfBool(bit) % 4;
	if (mod != 0) {
		string Hex;
		int k = 0; //Chỉ số của mảng Hex
		for (int j = 4 - mod; j < 4; j++) {
			a[j] = bit[i];
			i++;
		}
		Hex.push_back(FourbitToHex(a));
		k++;
		while (k < ((SizeOfBool(bit) / 4) + 1)) {
			for (int j = 0; j < 4; j++) {
				a[j] = bit[i];
				i++;
			}
			Hex.push_back(FourbitToHex(a));
			k++;
		}
		return Hex;
	}
	else {
		string Hex;
		int k = 0; //Chỉ số của mảng Hex
		while (k < (SizeOfBool(bit) / 4)) {
			for (int j = 0; j < 4; j++) {
				a[j] = bit[i];
				i++;
			}
			//Hex[k] = FourbitToHex(a);
			Hex.push_back(FourbitToHex(a));
			k++;
		}
		return Hex;
	}
}

string DecToHex(QInt x)
{
	bool* bit = new bool[SizeBitQInt(x)];
	bit = DecToBin(x);
	string Hex = BinToHex(bit);
	return Hex;
}

QInt HexToQInt(string Hex) //chuy?n t? h? 16 qua QInt
{
	QInt a;
	string BigInt = "0";
	for (int i = Hex.length() - 1; i >= 0; i--)
	{
		BigInt = BigInt + ConvertNumberFromHexIntoDec(Hex[i])*SixteenPower_k(Hex.length() - 1 - i);
	}
	StringOfQIntToQInt(a, BigInt);
	return a;
}

//X? LÝ BITs

// tr? v? s? bit trong m?ng bool
int SizeOfBool(bool *a)
{
	int dem = 0;
	int i = 0;
	while (a[i] != 1) {
		dem++, i++;
	}
	return 128 - dem;
}

//Xu?t m?ng bool*
void PrintArrayOfBools(bool *a)
{
	int mod = SizeOfBool(a) % 4;
	int i = 128 - SizeOfBool(a);
	if (mod != 0) {
		for (int j = 1; j <= mod; j++, i++) {
			cout << a[i];
		}
		cout << " "; // t?o kho?ng cách cho nh?ng bit l? d?u tiên
	}
	int dem = 0;
	for (i; i < 128; i++) {
		cout << a[i];
		dem++;
		if (dem == 4) {
			dem = 0;
			cout << " ";
		}
	}
}


//TOÁN T? TRÊN STRING

int Compare(string a, string b) // So sánh 2 chu?i s?
{
	if (a.length() > b.length()) return 1;
	else if (a.length() < b.length()) return -1;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] < b[i]) return -1;
		}
		return 0;
	}
}

string operator+(string a, string b) // c?ng 2 chu?i s? l?n l?i v?i nhau
{
	string S = "";
	//chon ra chuoi ngan va chuoi dai hon de tinh
	string c, d;
	if (Compare(a, b) >= 0)
	{
		c = a;
		d = b;
	}
	else
	{
		c = b;
		d = a;
	}
	char nho = 0;
	for (int i = d.length() - 1, j = c.length() - 1; i >= 0; i--, j--)
	{
		int temp = (c[j] - 48) + (d[i] - 48) + nho;
		S.push_back(temp % 10 + 48);
		if (temp >= 10) nho = 1;
		else nho = 0;
	}
	int index = c.length() - d.length() - 1;
	while (index >= 0)
	{
		if (nho > 0)
		{
			int temp = c[index] - 48 + nho;
			if (temp < 10)
			{
				S.push_back(temp + 48);
				nho = 0;
			}
			else
			{
				S.push_back(temp - 10 + 48);
				nho = 1;
			}
		}
		else
			S.push_back(c[index]);
		index--;
	}
	if (nho == 1) S.push_back(nho + 48);
	ReverseString(S);
	return S;
}

string operator-(string a, string b) // tr? hai chu?i l?n v?i nhau
{
	string S = "";
	//chon ra chuoi ngan va chuoi dai hon de tinh, v?n l?y chu?i dài hon tr? chu?i ng?n hon
	string c, d;
	int sign = 0; //d? dánh d?u 2 s? tr? nhau là âm hay duong 0: duong, 1: âm
	if (Compare(a, b) >= 0)
	{
		c = a;
		d = b;
	}
	else
	{
		c = b;
		d = a;
		sign = 1;
	}
	int nho = 0;
	for (int i = d.length() - 1, j = c.length() - 1; i >= 0; i--, j--)
	{
		int temp = (c[j] - 48) - (d[i] - 48) - nho;
		if (temp < 0)
		{
			temp += 10;
			S.push_back(temp % 10 + 48);
			nho = 1;
		}
		else
		{
			S.push_back(temp % 10 + 48);
			nho = 0;
		}
	}
	int index = c.length() - d.length() - 1;
	while (index >= 0)
	{
		if (nho > 0)
		{
			int temp = c[index] - 48 - nho;
			if (temp >= 0)
			{
				S.push_back(temp + 48);
				nho = 0;
			}
			else
			{
				S.push_back(temp + 10 + 48);
				nho = 1;
			}
		}
		else
			S.push_back(c[index]);
		index--;
	}
	while (S[S.length() - 1] == '0' && S.length()>1) S.pop_back();
	if (sign == 1) S.push_back('-');
	ReverseString(S);
	return S;
}

string operator*(string a, string b) // nhân 2 chu?i s?
{
	string T = "0";
	string c, d;
	if (a.length() >= b.length())
	{
		c = a;
		d = b;
	}
	else
	{
		c = b;
		d = a;
	}
	for (int i = d.length() - 1; i >= 0; i--)
	{
		int nho = 0;
		string S = "";
		for (int j = c.length() - 1; j >= 0; j--)
		{
			int temp = (d[i] - 48)*(c[j] - 48) + nho;
			nho = temp / 10;
			S.push_back(temp % 10 + 48);
		}
		if (nho != 0) S.push_back(nho + 48);
		ReverseString(S);
		for (int k = d.length() - 1; k > i; k--)
			S.push_back('0');
		T = T + S;
	}
	return T;
}

string TwoPower_k(int k) // tính 2^k
{
	string a, b = "2";
	if (k == 0) a = "1";
	else a = "2";
	for (int i = 1; i < k; i++)
	{
		a = a*b;
	}
	return a;
}

string SixteenPower_k(int k) //tính 16^k
{
	string a, b = "16";
	if (k == 0) a = "1";
	else a = "16";
	for (int i = 1; i < k; i++)
	{
		a = a*b;
	}
	return a;
}

string ConvertNumberFromHexIntoDec(char c) //Chuy?n 1 s? h?ng t? h? 16 sang h? 10
{
	switch (c)
	{
	case '0':return "0";
	case '1': return "1";
	case '2': return "2";
	case '3': return "3";
	case '4': return "4";
	case '5': return "5";
	case '6': return "6";
	case '7': return "7";
	case '8': return "8";
	case '9': return "9";
	case 'A': return "10";
	case 'B': return "11";
	case 'C': return "12";
	case 'D': return "13";
	case 'E': return "14";
	case 'F': return "15";
	}
}

//TOÁN T? TRÊN QINT

//Operator &: Phép AND
QInt operator &(QInt a, QInt b)
{
	QInt c;
	for (int i = 3; i >= 0; i--)
	{
		c.data[i] = a.data[i] & b.data[i];
	}
	return c;
}

//Operator |: Phép OR
QInt operator |(QInt a, QInt b)
{
	QInt c;
	for (int i = 3; i >= 0; i--)
	{
		c.data[i] = a.data[i] | b.data[i];
	}
	return c;
}

//Operator ~ : Phép NOT
QInt operator~(QInt a)
{
	QInt c;
	for (int i = 3; i >= 0; i--)
	{
		c.data[i] = ~a.data[i];
	}
	return c;
}

//Operator ^: Phép XOR
QInt operator^(QInt a, QInt b)
{
	QInt c;
	for (int i = 3; i >= 0; i--) {
		c.data[i] = a.data[i] ^ b.data[i];
	}
	return c;
}

//Operator <<: Phép d?ch trái
QInt operator <<(QInt a, int k)
{
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			//D?ch trái 1 bit th?ng Data[j]
			a.data[j] <<= 1;
			// Xét nh?ng th?ng n?m bên ph?i Data[j], gl pdata
			if (j + 1 <= 3) {
				//L?y ra bit d?u (bit trái nh?t) c?a pdata dó
				int temp = a.data[j + 1] >> 31;
				bool bit = temp & 1;
				//Sau dó OR v?i data <=> d?ch sang trái trong khuôn kh? data[j]
				a.data[j] = a.data[j] | bit;
			}

		}
	}
	return a;
}

//Operator >>: Phép d?ch ph?i
QInt operator >> (QInt a, int k)
{
	for (int i = 1; i <= k; i++)
	{

		for (int j = 3; j >= 0; j--)
		{
			bool bit;
			if (j == 0)
			{
				bit = a.data[0] >> 127 & 1;
			}
			//D?ch ph?i 1 bit trong data[j]
			a.data[j] >>= 1;
			//Thao tác b?t bit n?u QInt có d?u
			if (j == 0)
			{
				if (bit == 1) {
					int temp = pow(2, 31);
					a.data[0] = a.data[0] | temp;
				}
			}
			//Xét nh?ng th n?m bên trái data[j], gl tdata
			if (j - 1 >= 0)
			{
				// L?y ra bit cu?i cùng c?a tdata dó
				bit = a.data[j - 1] & 1;
				string s = IntToStringOfBits(a.data[j]);
				s[0] = bit + 48;
				a.data[j] = StringOfBitsToInt(s);
			}
		}
	}
	return a;
}

// Các phép toán + - * / % QInt
QInt operator+(QInt a, QInt b)
{
	string s1 = QIntToStringOfBits(a);
	string s2 = QIntToStringOfBits(b);
	string s;
	bool nho = 0;
	for (int i = 127; i >= 0; i--)
	{
		// Th?c hi?n d?i ký t? sang s? -> C?ng
		char temp = (s1[i] - 48) + (s2[i] - 48) + nho;
		if (temp < 2)
		{
			//Sau dó cho d?i kq sang chu?i-> cho vào chu?i
			s.push_back(temp + 48);
			nho = 0;
		}
		// N?u temp > 2, xét d?n tru?ng h?p overflow
		else
		{
			s.push_back(temp - 2 + 48);// Chèn 0 ho?c 1 tùy vào nh?
			nho++;
		}
	}
	ReverseString(s);
	QInt kq;
	kq = StringOfBitsToQInt(s);
	return kq;
}

QInt operator-(QInt a, QInt b)
{
	return a + TwoSComplement(b);
}

//Ch? phép nhân xu?t ra string, vì có d?n 256bit, ko xu?t data du?c:
QInt operator*(QInt M, QInt Q)
{
	QInt A; // Ðã du?c kh?i t?o toàn bit 0
	int k = 128;
	bool Q1 = 0;
	while (k>0) {
		bool Q0 = Q.data[3] & 1;// L?y ra bit cu?i cùng c?a Q: bit 0 ho?c bit 1
		if (Q0 == 1 && Q1 == 0) {
			A = A - M;
		}
		if (Q0 == 0 && Q1 == 1) {
			A = A + M;

		}
		// Xoay pha? A & Q
		//=> TH 11 ,00
		Q1 = Q0;
		Q = Q >> 1;
		bool bit = A.data[3] & 1;
		A = A >> 1;
		string s = QIntToStringOfBits(Q);
		s[0] = bit + 48;
		Q = StringOfBitsToQInt(s);
		k--;
	}
	string s1 = QIntToStringOfBits(A);
	string s2 = QIntToStringOfBits(Q);
	string kq = ConnectStringsS1S2(s1, s2);// Chua lo?i bit 0 ? d?u 
	ReverseString(kq);
	while (kq.length() > 128) kq.pop_back();
	ReverseString(kq);
	return StringOfBitsToQInt(kq);
}

QInt operator/(QInt Q, QInt M)
{
	int k = 128;
	QInt A;
	//L?y ra bit d?u c?a Q d? xét Q<0 hay Q>0
	bool bit = (Q.data[0] >> 31) & 1;
	//TH1: Q < 0
	if (bit == 1)
	{
		//Lúc này A toàn bit 1
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 127; j++)
			{
				SetBitIntoQInt(A, true, j, i);
			}
		}
	}
	//TH2: Q > 0 
	// Lúc này A toàn bit 0

	while (k > 0)
	{
		//Dich xoay vòng [A, Q], L?y bit d?u c?a Q th? vô bit cu?i c?a A
		bool bit = (Q.data[0] >> 31) & 1;
		Q = Q << 1;
		A = A << 1;
		//Th?
		string sa = QIntToStringOfBits(A);
		int n = sa.length() - 1;
		sa[n] = bit + 48;
		A = StringOfBitsToQInt(sa);

		//So sánh M v?i 0:
		bool sign = (M.data[0] >> 31) & 1;
		if (sign == 0)
			A = A - M;
		else
			A = A + M;
		//L?y bit dau tien c?a A, so sánh A vs 0
		bool bit1 = (A.data[0] >> 31) & 1;
		string sq = QIntToStringOfBits(Q);
		int nsq = sq.length() - 1;
		//A<0
		if (bit1 == 1) {
			sq[nsq] = '0';
			if (sign == 0)
				A = A + M;
			else
				A = A - M;
		}
		//A>0
		else {
			sq[nsq] = '1';
		}
		Q = StringOfBitsToQInt(sq);
		k--;
	}
	return Q;
}

QInt operator%(QInt Q, QInt M) {
	int k = 128;
	QInt A;
	//L?y ra bit d?u c?a Q d? xét Q<0 hay Q>0
	bool bit = (Q.data[0] >> 31) & 1;
	//TH1: Q < 0
	if (bit == 1)
	{
		//Lúc này A toàn bit 1
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 127; j++)
			{
				SetBitIntoQInt(A, true, j, i);
			}
		}
	}
	//TH2: Q > 0 
	// Lúc này A toàn bit 0

	while (k > 0)
	{
		//Dich xoay vòng [A, Q], L?y bit d?u c?a Q th? vô bit cu?i c?a A
		bool bit = (Q.data[0] >> 31) & 1;
		Q = Q << 1;
		A = A << 1;
		//Th?
		string sa = QIntToStringOfBits(A);
		int n = sa.length() - 1;
		sa[n] = bit + 48;
		A = StringOfBitsToQInt(sa);

		//So sánh M v?i 0:
		bool sign = (M.data[0] >> 31) & 1;
		if (sign == 0)
			A = A - M;
		else
			A = A + M;
		//L?y bit dau tien c?a A, so sánh A vs 0
		bool bit1 = (A.data[0] >> 31) & 1;
		string sq = QIntToStringOfBits(Q);
		int nsq = sq.length() - 1;
		//A<0
		if (bit1 == 1) {
			sq[nsq] = '0';
			if (sign == 0)
				A = A + M;
			else
				A = A - M;
		}
		//A>0
		else {
			sq[nsq] = '1';
		}
		Q = StringOfBitsToQInt(sq);
		k--;
	}
	return A;
}

//X? LÝ FILE

bool CheckStr(string line) {
	for (int i = 0; i < line.length(); i++) {
		if ((line[i]<'0' || (line[i]>'9'&&line[i]<'A') || line[i]>'Z') && line[i] != ' ')
			return false;
	}
	return true;
}

void AnalyseStr(string line, int &format_I, int &format_O, string &data1, string &token, string &data2)
{
	istringstream iss(line);
	if (!CheckStr(line)) {
		iss >> format_I >> data1 >> token;
		if (token != "<<"&&token != ">>") {
			iss >> data2;
			format_O = 0;
		}
		else if (token != "~")
			iss >> format_O;
	}
	else {
		iss >> format_I >> format_O >> data1;
	}
}

void WorkwithFILE(char *INPUTfilename, char *OUTPUTfilename)
{
	ifstream input(INPUTfilename);
	if (!input.is_open()) {
		cout << "Loi doc FILE!\n ";
		return;
	}
	ofstream output(OUTPUTfilename);

	int format_I, format_O;
	string line, data1, data2, token;
	QInt x, y, z;
	while (!input.eof()) {
		x.clear();
		y.clear();
		z.clear();
		getline(input, line);
		if (line == "\n" || line == "") break;
		AnalyseStr(line, format_I, format_O, data1, token, data2);
		if (!CheckStr(line)) {
			switch (format_I) {
			case 2: x = StringOfBitsToQInt(data1); if (token != "<<"&&token != ">>"&&token != "~") y = StringOfBitsToQInt(data2); break;
			case 10:StringOfQIntToQInt(x, data1); if (token != "<<"&&token != ">>"&&token != "~") StringOfQIntToQInt(y, data2); break;
			case 16: x = HexToQInt(data1); if (token != "<<"&&token != ">>"&&token != "~") y = HexToQInt(data2); break;
			}
			//Tinh toan du lieu
			if (token == "+") z = x + y;
			else if (token == "-") z = x - y;
			else if (token == "*") z = x*y;
			else if (token == "/") z = x / y;
			else if (token == "%") z = x%y;
			else if (token == "<<") z = x << format_O;
			else if (token == ">>") z = x >> format_O;
			else if (token == "&") z = x&y;
			else if (token == "|") z = x | y;
			else if (token == "^") z = x^y;
			else if (token == "~") z = ~x;
			//Ghi du lieu
			switch (format_I) {
			case 2: output << SimplifyStringOfBits(QIntToStringOfBits(z)) << endl; break;
			case 10: output << QIntToStringOfQInt(z) << endl; break;
			case 16: output << DecToHex(z) << endl; break;
			}
		}
		else {
			switch (format_I) {
			case 2: {
				switch (format_O) {
				case 10:output << QIntToStringOfQInt(StringOfBitsToQInt(data1)) << endl; break;
				case 16:bool *BITs = StringOfBitsToArrayOfBools(data1); output << BinToHex(BITs) << endl; break;
				}
				break;
			}
			case 10: {
				StringOfQIntToQInt(z, data1);
				switch (format_O) {
				case 2: output << SimplifyStringOfBits(QIntToStringOfBits(z)) << endl; break;
				case 16: output << DecToHex(z) << endl; break;
				}
				break;
			}
			case 16: {
				switch (format_O) {
				case 2: output << SimplifyStringOfBits(QIntToStringOfBits(HexToQInt(data1))) << endl; break;
				case 10: output << QIntToStringOfQInt(HexToQInt(data1)) << endl; break;
				}
				break;
			}
			}
		}

	}
	input.close();
	output.close();
}

