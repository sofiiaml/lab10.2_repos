#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void rewrite_info(string output, string input) {
	ifstream file(input);
	string line;
	bool isSpace = false;
	if (file.is_open()) {
		ofstream outfile(output);
		if (file.is_open()) {
			while (getline(file, line)) {
				for (int i = 0; i < line.size(); i++) {
					if (!isSpace) {
						if (line[i] >= 48 && line[i] <= 57 || line[i] >= 97 && line[i] <= 122) {
							outfile << line[i];
						}
						else if (line[i] >= 65 && line[i] <= 90) {
							outfile << char(line[i] + 32);
						}
						else if (line[i] == ' ') {
							outfile << line[i];
							isSpace = true;
						}
					}
					else {
						outfile << line[i];
					}
					
				}
			}
			outfile.close();
		}
		else {
			cout << "Error while opening output file" << endl;
		}
		file.close();
	}
	else {
		cout << "Error while opening input file" << endl;
	}
	
}

int main() {
	rewrite_info("output.txt", "text.txt");
	return 0;
}
