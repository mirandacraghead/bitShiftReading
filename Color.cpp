#include "Color.h"

string Color::HexiComparison(string apple) {
	if (apple == "0000") {
		return "0";
	}
	else if (apple == "0001") {
		return "1";
	}
	else if (apple == "0010") {
		return "2";
	}
	else if (apple == "0011") {
		return"3";
	}
	else if (apple == "0100") {
		return "4";
	}
	else if (apple == "0101") {
		return "5";
	}
	else if (apple == "0110") {
		return "6";
	}
	else if (apple == "0111") {
		return "7";
	}
	else if (apple == "1000") {
		return "8";
	}
	else if (apple == "1001") {
		return "9";
	}
	else if (apple == "1010") {
		return "A";
	}
	else if (apple == "1011") {
		return "B";
	}
	else if (apple == "1100") {
		return "C";
	}
	else if (apple == "1101") {
		return "D";
	}
	else if (apple == "1110") {
		return "E";
	}
	else if (apple == "1111") {
		return "F";
	}
	else {
		return "";
	}
}
int Color::HextoDecimalHelper(char one) {
	if (one == '0') {
		return 0;
	}
	else if (one == '1') {
		return 1;
	}
	else if (one == '2') {
		return 2;
	}
	else if (one == '3') {
		return 3;
	}
	else if (one == '4') {
		return 4;
	}
	else if (one == '5') {
		return 5;
	}
	else if (one == '6') {
		return 6;
	}
	else if (one == '7') {
		return 7;
	}
	else if (one == '8') {
		return 8;
	}
	else if (one == '9') {
		return 9;
	}
	else if (one == 'A') {
		return 10;
	}
	else if (one == 'B') {
		return 11;
	}
	else if (one == 'C') {
		return 12;
	}
	else if (one == 'D') {
		return 13;
	}
	else if (one == 'E') {
		return 14;
	}
	else if (one == 'F') {
		return 15;
	}
	else {
		return 0;
	}
}
int Color::HextoDecimal(string a) {
	char one = a.at(0);
	char two = a.at(1);
	int decimalConversion = HextoDecimalHelper(one) * 16 + HextoDecimalHelper(two);
	return decimalConversion;
}



