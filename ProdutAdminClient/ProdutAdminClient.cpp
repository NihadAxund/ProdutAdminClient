#include<iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include <sys/stat.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include "products.h"
#include "admin.h"
#include"Guest.h"

void start() {
	ofstream file;
	file.open("hamper.txt", ios_base::trunc);
	file.close();
	try
	{
		while (true)
		{
			size_t selction;
			cout << "Guest[1]\nAdmin[2]\nExit [3]\nEnter: ";
			cin >> selction;
			if (selction == 2)
			{
				admin::Admin admin;
				admin.gogo();
			}
			else if (selction == 1) {
				Guest::Guest guest;
				guest.setfullname();
			}
			else if (selction == 3)
			{
				exit(0);
				break;
			}
			else
			{
				if (selction > 0)
				{
					system("cls");
					continue;
				}
				else throw 77;
			}
		}
	}
	catch (bool isokay)
	{
		if (isokay == false)cout << "\nError: id not found\n";

	}
	catch (double number) {
		if (number == 1.09)cout << "\nError: pieces\n";
		else if (number == 1.1)cout << "\nError: discount\n";
		else if (number == 1.2)cout << "\nError Tax\n";
	}
	catch (string name) {
		if (name == "0")cout << "\nError: String size>2\n";
		else if (name == "Buffer")cout << "\nError: this product is over\n";
	}
	catch (int number1) {
		if (number1 == 666)cout << "\nError: Password size" << endl;
		else if (number1 == 22)cout << "\n Error: Username size" << endl;
		else if (number1 == 77)cout << "\nError: just numbers!" << endl;
	}


}

int main() {
	start();
}