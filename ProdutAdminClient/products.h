#pragma once
#include<Windows.h>
namespace product {
	class Product {
	protected:
		int id; //avtomatik
		string name;
		string description;
		int pieces;
		double price;
		double discount;
		double tax; //vergi faizi
		void copypraduct(string numstring, int num) {
			string buffer;
			fstream fin;
			int count = productlinesize();
			ofstream fin2;
			fin.open("Product.txt");
			fin2.open("Productcopy.txt", ios_base::trunc);
			while (fin.good() && count != 0)
			{
				fin >> buffer;
				fin2 << buffer << ' ';
				if (buffer == to_string(num))
				{
					int nums = stoi(numstring);
					nums--;
					for (size_t i = 0; i < 6; i++) {
						if (i == 3)
						{
							fin >> buffer; fin2 << to_string(nums) << ' ';
						}
						else
						{
							fin >> buffer;
							fin2 << buffer << ' ';
						}
					}
					fin2 << '\n';
					//info(num);
				}
				else if (fin.good()) {
					for (size_t i = 0; i < 6; i++) {
						fin >> buffer; fin2 << buffer << ' ';
					};
					fin2 << '\n';
				}
				count--;
			}
			fin.close();
			fin2.close();
			nocopypraduct();
		}
		void copydeleteproduct(string numstring) {
			string buffer;
			fstream fin;
			int count = productlinesize();
			ofstream fin2;
			fin.open("Product.txt");
			fin2.open("Productcopy.txt", ios_base::trunc);
			while (fin.good() && count != 0)
			{
				fin >> buffer;
				if (buffer == numstring) {

				}
				else fin2 << buffer << ' ';
				if (buffer == numstring)
				{

					for (size_t i = 0; i < 6; i++) {
						fin >> buffer;
					}
					//info(num);
				}
				else if (fin.good()) {
					for (size_t i = 0; i < 6; i++) {
						fin >> buffer; fin2 << buffer << ' ';
					};
					fin2 << '\n';
				}
				count--;
			}
			fin.close();
			fin2.close();
			nocopypraduct();
		}
		void nocopypraduct() {
			string buffer;
			ofstream fin;
			fstream fin2;
			int numsize = productlinesize2();
			fin2.open("Productcopy.txt");
			fin.open("Product.txt", ios_base::trunc);
			while (fin2.good() && numsize)
			{
				fin2 >> buffer;
				fin << buffer << ' ';
				for (size_t i = 0; i < 6; i++) {
					fin2 >> buffer;
					fin << buffer << ' ';
				}
				fin << '\n';
				numsize--;
			}
			fin2.close();
			fin.close();
		}
		int productlinesize() {
			ifstream file;
			int size = 0;
			string buffer;
			file.open("Product.txt");
			while (file.good())
			{
				for (size_t i = 0; i < 7; i++)
				{
					if (file.good())
					{
						file >> buffer;
						if (i == 6)size++;
					}
					else return size;
				}
			}
			return size;
		}
		int productlinesize2() {
			ifstream file;
			int size = 0;
			string buffer;
			file.open("Productcopy.txt");
			while (file.good())
			{
				for (size_t i = 0; i < 7; i++)
				{
					if (file.good())
					{
						file >> buffer;
						if (i == 6)size++;
					}
					else return size;
				}
			}
			return size;
		}
		int productendid() {
			int size = productlinesize();
			ifstream f;
			string buffer;
			f.open("Product.txt");
			for (size_t i = 0; i < size - 1; i++)
			{
				for (size_t i = 0; i < 7; i++) f >> buffer;
			}
			f >> buffer;
			int count = stoi(buffer);
			cout << count;
			f.close();
			return count;

		}
	public:
		void info(int num) {
			string buffer;
			ifstream fin;
			fin.open("Product.txt");
			while (fin.good())
			{
				fin >> buffer;
				if (buffer == to_string(num))
				{
					cout << "\n\tInfo" << endl;
					fin >> buffer;
					cout << "Name: " << buffer << endl; fin >> buffer;
					cout << "Description: " << buffer << endl;  fin >> buffer;
					cout << "Pieces: " << buffer << endl; fin >> buffer;
					cout << "Price: " << buffer << endl;  fin >> buffer;
					cout << "Discount: " << buffer << endl;  fin >> buffer;
					cout << "Tax: " << buffer << endl;
					fin.close();
					return;
				}
				else
				{
					for (size_t i = 0; i < 6; i++)fin >> buffer;
				}
			}
			throw false;
			cout << "Not fount";

		}
		void showProduct() {
			string buffer;
			ifstream fin;
			size_t count = productlinesize();
			fin.open("Product.txt");
			while (fin.good() && count != 0)
			{
				fin >> buffer;
				cout << "ID: " << buffer << endl; fin >> buffer;
				cout << "Name: " << buffer << endl; fin >> buffer;
				for (size_t i = 0; i < 4; i++) fin >> buffer;
				cout << endl;
				count--;
			}
			fin.close();
		}
		void buy() {
			int num = 0;
			string buffer, buffer1;
			cout << "enter id: "; cin >> num;
			fstream fin;
			fin.open("Product.txt");
			fin >> buffer;
			while (fin.good())
			{
				if (buffer == to_string(num))
				{
					string numstring;
					for (size_t i = 0; i < 4; i++) {
						if (i == 0)fin >> buffer1;
						else fin >> numstring;
					}
					if (numstring == "0")throw "Buffer";
					fin.close();
					ofstream file;
					file.open("hamper.txt", ios::app);
					file << '\n' << buffer1;
					file.close();
					copypraduct(numstring, num);
					cout << "Purchasing";
					/*	info(num)*/;
					return;
				}
				else if (fin.good()) for (size_t i = 0; i < 7; i++) fin >> buffer;
			}
			throw false;
			cout << "Not found";
			fin.close();
		}
		void fileproducts(string names, string des, int pieces, double proprice, double pro, double tax) {
			if (names.size() < 2 || des.size() < 2)throw "0";
			else if (pieces < 1)throw 1.09;
			else if (pro < 0) throw 1.1;
			else if (tax <= -1) throw 1.2;
			productendid();
			ofstream file;
			string buffer;
			int id = productendid(); id++;
			file.open("Product.txt", ios::app);
			file << '\n' << id << ' ' << names << ' ' << des << ' ' << pieces << ' ' << proprice << ' ' << pro << ' ' << tax;
			file.close();
		}
		void productadd() {
			string productname, prodescription;
			int  productpieces;
			double proprice, productdiscount, producttax;
			cout << "Enter Product name: "; cin >> productname;
			cout << "Enter Product description: "; cin >> prodescription;
			cout << "Enter Product pieces: "; cin >> productpieces;
			cout << "Enter Product price: "; cin >> proprice;
			cout << "Enter Product discount: "; cin >> productdiscount;
			cout << "Enter Product tax:"; cin >> producttax;
			fileproducts(productname, prodescription, productpieces, proprice, productdiscount, producttax);
			return;
		}
		void deleteproduct() {
			int num = 0;
			string buffer;
			cout << "enter id: "; cin >> num;
			fstream fin;
			fin.open("Product.txt");
			fin >> buffer;
			while (fin.good())
			{
				if (buffer == to_string(num))
				{
					fin.close();
					copydeleteproduct(to_string(num));
					return;
				}
				else if (fin.good()) for (size_t i = 0; i < 7; i++) fin >> buffer;
			}
			throw false;
			cout << "Not found";
			fin.close();
		}
	};
}