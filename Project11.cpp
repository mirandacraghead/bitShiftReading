// Project11.cpp : Defines the entry point for the console application.
//
#include<fstream>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include"Color.h"
using namespace std;






int main()
{
	Color colorObj; 
	vector<string> colors;
	vector<int> red;
	vector<int> green;
	vector<int> blue;
	vector<string> redHex;
	vector<string> greenHex;
	vector<string> blueHex;
	map<string, string> redColoring;
	map<string, string> greenColoring;
	map<string, string> blueColoring;
	map<string, int> redDec;
	map<string, int> greenDec;
	map<string, int> blueDec;
	string Hex1;
	string Hex2;
	string line;
	//convert to hexidecimal 
	int index = 0;
	int indexG = 0;
	int indexB = 0;

	cout << "1. Load colors1.txt" << endl;
	cout << "2. Load colors2.txt" << endl;
	cout << "3. Load colors3.txt" << endl;
	cout << "4. Load all 3 files.txt" << endl;
	int option;
	cin >> option;

	if (option == 1) {
		ifstream file("colors1.txt");
		while (getline(file, line, '\n')) {
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ' ') {
					colors.push_back(line.substr(0, i));
					string numbers = line.substr(i + 1, line.size() - i - 1);
					//cout << numbers << "\n" << endl;
					int binary = stoi(numbers);
					vector<int> binaryValues;
					for (int i = 0; i < 24; i++) {
						binaryValues.push_back(0);
					}
					int count = 23;
					binaryValues.at(count) = binary % 2;
					while (binary / 2 > 0) {
						count--;
						binary /= 2;
						binaryValues.at(count) = binary % 2;
					}
					//cout << "red" << endl;
					for (int i = 0; i < 8; i++) {
						//cout << binaryValues.at(i);
						red.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "green" << endl;
					for (int i = 8; i <16; i++) {
						//cout << binaryValues.at(i);
						green.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "blue" << endl;
					for (int i = 16; i < 24; i++) {
						//cout << binaryValues.at(i);
						blue.push_back(binaryValues.at(i));
					}
					//cout << endl;

					string hexiConversion = to_string(red.at(index));
					for (int i = index + 1; i < index + 8; i++) {
						hexiConversion += to_string(red.at(i));
					}
					//red hexidecimal conversion 
					index += 8;
					Hex1 = hexiConversion.substr(0, 4);
					Hex2 = hexiConversion.substr(4, 4);
					//cout << "red " << Hex1 << endl;
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "redH: " << Hex1 + Hex2 << endl;
					redHex.push_back(Hex1 + Hex2);
					//green hexidecimal conversion 
					hexiConversion = to_string(green.at(indexG));
					for (int i = indexG + 1; i < indexG + 8; i++) {
						hexiConversion += to_string(green.at(i));
					}
					indexG += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "green " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "greenH: " << Hex1 + Hex2 << endl;
					greenHex.push_back(Hex1 + Hex2);
					//blue hexidecimal conversion
					hexiConversion = to_string(blue.at(indexB));
					for (int i = indexB + 1; i < indexB + 8; i++) {
						hexiConversion += to_string(blue.at(i));
					}
					indexB += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "blue " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					blueHex.push_back(Hex1 + Hex2);

				}
			}
		}
		for (unsigned int i = 0; i < colors.size(); i++) {
			redColoring.emplace(colors.at(i), redHex.at(i));
			greenColoring.emplace(colors.at(i), greenHex.at(i));
			blueColoring.emplace(colors.at(i), blueHex.at(i));
			//convert to integer representation 
			redDec.emplace(colors.at(i), colorObj.HextoDecimal(redHex.at(i)));
			greenDec.emplace(colors.at(i), colorObj.HextoDecimal(greenHex.at(i)));
			blueDec.emplace(colors.at(i), colorObj.HextoDecimal(blueHex.at(i)));

		}
		
		sort(colors.begin(), colors.end());
		for (unsigned int i = 0; i < colors.size(); i++) {
			if (colors.at(i).size() <= 7) {
				cout << colors.at(i) << '\t' << '\t'<<'\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else if (colors.at(i).size() >= 16) {
				cout << colors.at(i) << '\t' <<  "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else {
				cout << colors.at(i) << '\t' << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			}
		cout << "Number of colors: " << colors.size() << endl;
	}
	else if (option == 2) {
		ifstream file2("colors2.txt");
		while (getline(file2, line, '\n')) {
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ' ') {
					colors.push_back(line.substr(0, i));
					string numbers = line.substr(i + 1, line.size() - i - 1);
					//cout << numbers << "\n" << endl;
					int binary = stoi(numbers);
					vector<int> binaryValues;
					for (int i = 0; i < 24; i++) {
						binaryValues.push_back(0);
					}
					int count = 23;
					binaryValues.at(count) = binary % 2;
					while (binary / 2 > 0) {
						count--;
						binary /= 2;
						binaryValues.at(count) = binary % 2;
					}
					//cout << "red" << endl;
					for (int i = 0; i < 8; i++) {
						//cout << binaryValues.at(i);
						red.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "green" << endl;
					for (int i = 8; i <16; i++) {
						//cout << binaryValues.at(i);
						green.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "blue" << endl;
					for (int i = 16; i < 24; i++) {
						//cout << binaryValues.at(i);
						blue.push_back(binaryValues.at(i));
					}
					//cout << endl;

					string hexiConversion = to_string(red.at(index));
					for (int i = index + 1; i < index + 8; i++) {
						hexiConversion += to_string(red.at(i));
					}
					//red hexidecimal conversion 
					index += 8;
					Hex1 = hexiConversion.substr(0, 4);
					Hex2 = hexiConversion.substr(4, 4);
					//cout << "red " << Hex1 << endl;
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "redH: " << Hex1 + Hex2 << endl;
					redHex.push_back(Hex1 + Hex2);
					//green hexidecimal conversion 
					hexiConversion = to_string(green.at(indexG));
					for (int i = indexG + 1; i < indexG + 8; i++) {
						hexiConversion += to_string(green.at(i));
					}
					indexG += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "green " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "greenH: " << Hex1 + Hex2 << endl;
					greenHex.push_back(Hex1 + Hex2);
					//blue hexidecimal conversion
					hexiConversion = to_string(blue.at(indexB));
					for (int i = indexB + 1; i < indexB + 8; i++) {
						hexiConversion += to_string(blue.at(i));
					}
					indexB += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "blue " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					blueHex.push_back(Hex1 + Hex2);

				}
			}
		}
		for (unsigned int i = 0; i < colors.size(); i++) {
			redColoring.emplace(colors.at(i), redHex.at(i));
			greenColoring.emplace(colors.at(i), greenHex.at(i));
			blueColoring.emplace(colors.at(i), blueHex.at(i));
			//convert to integer representation 
			redDec.emplace(colors.at(i), colorObj.HextoDecimal(redHex.at(i)));
			greenDec.emplace(colors.at(i), colorObj.HextoDecimal(greenHex.at(i)));
			blueDec.emplace(colors.at(i), colorObj.HextoDecimal(blueHex.at(i)));

		}

		sort(colors.begin(), colors.end());
		for (unsigned int i = 0; i < colors.size(); i++) {
			if (colors.at(i).size() <= 7) {
				cout << colors.at(i) << '\t' << '\t' << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else if (colors.at(i).size() >= 16) {
				cout << colors.at(i) << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else {
				cout << colors.at(i) << '\t' << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
		}
		cout << "Number of colors: " << colors.size() << endl;
	}
	else if (option == 3) {
		ifstream file3("colors3.txt");
		while (getline(file3, line, '\n')) {
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ' ') {
					colors.push_back(line.substr(0, i));
					string numbers = line.substr(i + 1, line.size() - i - 1);
					//cout << numbers << "\n" << endl;
					int binary = stoi(numbers);
					vector<int> binaryValues;
					for (int i = 0; i < 24; i++) {
						binaryValues.push_back(0);
					}
					int count = 23;
					binaryValues.at(count) = binary % 2;
					while (binary / 2 > 0) {
						count--;
						binary /= 2;
						binaryValues.at(count) = binary % 2;
					}
					//cout << "red" << endl;
					for (int i = 0; i < 8; i++) {
						//cout << binaryValues.at(i);
						red.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "green" << endl;
					for (int i = 8; i <16; i++) {
						//cout << binaryValues.at(i);
						green.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "blue" << endl;
					for (int i = 16; i < 24; i++) {
						//cout << binaryValues.at(i);
						blue.push_back(binaryValues.at(i));
					}
					//cout << endl;

					string hexiConversion = to_string(red.at(index));
					for (int i = index + 1; i < index + 8; i++) {
						hexiConversion += to_string(red.at(i));
					}
					//red hexidecimal conversion 
					index += 8;
					Hex1 = hexiConversion.substr(0, 4);
					Hex2 = hexiConversion.substr(4, 4);
					//cout << "red " << Hex1 << endl;
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "redH: " << Hex1 + Hex2 << endl;
					redHex.push_back(Hex1 + Hex2);
					//green hexidecimal conversion 
					hexiConversion = to_string(green.at(indexG));
					for (int i = indexG + 1; i < indexG + 8; i++) {
						hexiConversion += to_string(green.at(i));
					}
					indexG += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "green " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "greenH: " << Hex1 + Hex2 << endl;
					greenHex.push_back(Hex1 + Hex2);
					//blue hexidecimal conversion
					hexiConversion = to_string(blue.at(indexB));
					for (int i = indexB + 1; i < indexB + 8; i++) {
						hexiConversion += to_string(blue.at(i));
					}
					indexB += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "blue " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					blueHex.push_back(Hex1 + Hex2);

				}
			}
		}
		for (unsigned int i = 0; i < colors.size(); i++) {
			redColoring.emplace(colors.at(i), redHex.at(i));
			greenColoring.emplace(colors.at(i), greenHex.at(i));
			blueColoring.emplace(colors.at(i), blueHex.at(i));
			//convert to integer representation 
			redDec.emplace(colors.at(i), colorObj.HextoDecimal(redHex.at(i)));
			greenDec.emplace(colors.at(i), colorObj.HextoDecimal(greenHex.at(i)));
			blueDec.emplace(colors.at(i), colorObj.HextoDecimal(blueHex.at(i)));

		}
		sort(colors.begin(), colors.end());
		for (unsigned int i = 0; i < colors.size(); i++) {
			if (colors.at(i).size() <= 7) {
				cout << colors.at(i) << '\t' << '\t' << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else if (colors.at(i).size() >= 16) {
				cout << colors.at(i) << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else {
				cout << colors.at(i) << '\t' << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
		}
		cout << "Number of colors: " << colors.size() << endl;
	}
	else if (option == 4) {
		ifstream file("colors1.txt");
		ifstream file2("colors2.txt");
		ifstream file3("colors3.txt");
		while (getline(file, line, '\n')) {
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ' ') {
					colors.push_back(line.substr(0, i));
					string numbers = line.substr(i + 1, line.size() - i - 1);
					//cout << numbers << "\n" << endl;
					int binary = stoi(numbers);
					vector<int> binaryValues;
					for (int i = 0; i < 24; i++) {
						binaryValues.push_back(0);
					}
					int count = 23;
					binaryValues.at(count) = binary % 2;
					while (binary / 2 > 0) {
						count--;
						binary /= 2;
						binaryValues.at(count) = binary % 2;
					}
					//cout << "red" << endl;
					for (int i = 0; i < 8; i++) {
						//cout << binaryValues.at(i);
						red.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "green" << endl;
					for (int i = 8; i <16; i++) {
						//cout << binaryValues.at(i);
						green.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "blue" << endl;
					for (int i = 16; i < 24; i++) {
						//cout << binaryValues.at(i);
						blue.push_back(binaryValues.at(i));
					}
					//cout << endl;

					string hexiConversion = to_string(red.at(index));
					for (int i = index + 1; i < index + 8; i++) {
						hexiConversion += to_string(red.at(i));
					}
					//red hexidecimal conversion 
					index += 8;
					Hex1 = hexiConversion.substr(0, 4);
					Hex2 = hexiConversion.substr(4, 4);
					//cout << "red " << Hex1 << endl;
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "redH: " << Hex1 + Hex2 << endl;
					redHex.push_back(Hex1 + Hex2);
					//green hexidecimal conversion 
					hexiConversion = to_string(green.at(indexG));
					for (int i = indexG + 1; i < indexG + 8; i++) {
						hexiConversion += to_string(green.at(i));
					}
					indexG += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "green " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "greenH: " << Hex1 + Hex2 << endl;
					greenHex.push_back(Hex1 + Hex2);
					//blue hexidecimal conversion
					hexiConversion = to_string(blue.at(indexB));
					for (int i = indexB + 1; i < indexB + 8; i++) {
						hexiConversion += to_string(blue.at(i));
					}
					indexB += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "blue " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					blueHex.push_back(Hex1 + Hex2);

				}
			}
		}while (getline(file2, line, '\n')) {
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ' ') {
					colors.push_back(line.substr(0, i));
					string numbers = line.substr(i + 1, line.size() - i - 1);
					//cout << numbers << "\n" << endl;
					int binary = stoi(numbers);
					vector<int> binaryValues;
					for (int i = 0; i < 24; i++) {
						binaryValues.push_back(0);
					}
					int count = 23;
					binaryValues.at(count) = binary % 2;
					while (binary / 2 > 0) {
						count--;
						binary /= 2;
						binaryValues.at(count) = binary % 2;
					}
					//cout << "red" << endl;
					for (int i = 0; i < 8; i++) {
						//cout << binaryValues.at(i);
						red.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "green" << endl;
					for (int i = 8; i <16; i++) {
						//cout << binaryValues.at(i);
						green.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "blue" << endl;
					for (int i = 16; i < 24; i++) {
						//cout << binaryValues.at(i);
						blue.push_back(binaryValues.at(i));
					}
					//cout << endl;

					string hexiConversion = to_string(red.at(index));
					for (int i = index + 1; i < index + 8; i++) {
						hexiConversion += to_string(red.at(i));
					}
					//red hexidecimal conversion 
					index += 8;
					Hex1 = hexiConversion.substr(0, 4);
					Hex2 = hexiConversion.substr(4, 4);
					//cout << "red " << Hex1 << endl;
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "redH: " << Hex1 + Hex2 << endl;
					redHex.push_back(Hex1 + Hex2);
					//green hexidecimal conversion 
					hexiConversion = to_string(green.at(indexG));
					for (int i = indexG + 1; i < indexG + 8; i++) {
						hexiConversion += to_string(green.at(i));
					}
					indexG += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "green " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "greenH: " << Hex1 + Hex2 << endl;
					greenHex.push_back(Hex1 + Hex2);
					//blue hexidecimal conversion
					hexiConversion = to_string(blue.at(indexB));
					for (int i = indexB + 1; i < indexB + 8; i++) {
						hexiConversion += to_string(blue.at(i));
					}
					indexB += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "blue " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					blueHex.push_back(Hex1 + Hex2);

				}
			}
		}while (getline(file3, line, '\n')) {
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line.at(i) == ' ') {
					colors.push_back(line.substr(0, i));
					string numbers = line.substr(i + 1, line.size() - i - 1);
					//cout << numbers << "\n" << endl;
					int binary = stoi(numbers);
					vector<int> binaryValues;
					for (int i = 0; i < 24; i++) {
						binaryValues.push_back(0);
					}
					int count = 23;
					binaryValues.at(count) = binary % 2;
					while (binary / 2 > 0) {
						count--;
						binary /= 2;
						binaryValues.at(count) = binary % 2;
					}
					//cout << "red" << endl;
					for (int i = 0; i < 8; i++) {
						//cout << binaryValues.at(i);
						red.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "green" << endl;
					for (int i = 8; i <16; i++) {
						//cout << binaryValues.at(i);
						green.push_back(binaryValues.at(i));
					}
					//cout << endl;
					//cout << "blue" << endl;
					for (int i = 16; i < 24; i++) {
						//cout << binaryValues.at(i);
						blue.push_back(binaryValues.at(i));
					}
					//cout << endl;

					string hexiConversion = to_string(red.at(index));
					for (int i = index + 1; i < index + 8; i++) {
						hexiConversion += to_string(red.at(i));
					}
					//red hexidecimal conversion 
					index += 8;
					Hex1 = hexiConversion.substr(0, 4);
					Hex2 = hexiConversion.substr(4, 4);
					//cout << "red " << Hex1 << endl;
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "redH: " << Hex1 + Hex2 << endl;
					redHex.push_back(Hex1 + Hex2);
					//green hexidecimal conversion 
					hexiConversion = to_string(green.at(indexG));
					for (int i = indexG + 1; i < indexG + 8; i++) {
						hexiConversion += to_string(green.at(i));
					}
					indexG += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "green " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					//cout << "greenH: " << Hex1 + Hex2 << endl;
					greenHex.push_back(Hex1 + Hex2);
					//blue hexidecimal conversion
					hexiConversion = to_string(blue.at(indexB));
					for (int i = indexB + 1; i < indexB + 8; i++) {
						hexiConversion += to_string(blue.at(i));
					}
					indexB += 8;
					Hex1 = hexiConversion.substr(0, 4);
					//cout << "blue " << Hex1 << endl;
					Hex2 = hexiConversion.substr(4, 4);
					Hex1 = colorObj.HexiComparison(Hex1);
					Hex2 = colorObj.HexiComparison(Hex2);
					blueHex.push_back(Hex1 + Hex2);

				}
			}
		}
		for (unsigned int i = 0; i < colors.size(); i++) {
			redColoring.emplace(colors.at(i), redHex.at(i));
			greenColoring.emplace(colors.at(i), greenHex.at(i));
			blueColoring.emplace(colors.at(i), blueHex.at(i));
			//convert to integer representation 
			redDec.emplace(colors.at(i), colorObj.HextoDecimal(redHex.at(i)));
			greenDec.emplace(colors.at(i), colorObj.HextoDecimal(greenHex.at(i)));
			blueDec.emplace(colors.at(i), colorObj.HextoDecimal(blueHex.at(i)));

		}
		sort(colors.begin(), colors.end());
		for (unsigned int i = 0; i < colors.size(); i++) {
			if (colors.at(i).size() <= 7) {
				cout << colors.at(i) << '\t' << '\t' << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else if (colors.at(i).size() >= 16) {
				cout << colors.at(i) << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
			else {
				cout << colors.at(i) << '\t' << '\t' << "0x" << redColoring.at(colors.at(i)) << greenColoring.at(colors.at(i)) << blueColoring.at(colors.at(i));
				cout << '\t' << redDec.at(colors.at(i)) << "," << greenDec.at(colors.at(i)) << "," << blueDec.at(colors.at(i)) << endl;
			}
		}
		cout << "Number of colors: " << colors.size() << endl;
	}
	else{}

	
	return 0;
}
