#pragma once

namespace Guest {
	class Guest {
		string fullname;
		string connected_date; //tarix saat
		bool Guestname(string name) {
			string buffer;
			ifstream file;
			file.open("Clinetguset.txt");
			while (file.good())
			{
				file >> buffer;
				if (buffer == name)return true;
			}
			return false;
		}
		void addguest(string name) {
			ofstream file;
			file.open("Clinetguset.txt", ios::app);
			file << '\n' << name;
			file.close();
			return;
		}
		void hamper() {
			ifstream file;
			string buffer;
			file.open("hamper.txt");
			while (file.good()) {
				file >> buffer;
				cout << "Name: " << buffer << endl;
			}
		}
		void go() {
			product::Product products;
			size_t nuberc;
			size_t numberr;
			while (true)
			{
				products.showProduct();
				cout << "Buy[1] Info[2] Exit[3]\nEnter: ";
				cin >> nuberc;
				if (nuberc == 1)
				{
					products.buy();
					for (size_t i = 0; i < 3; i++)
					{
						cout << '.';
						Sleep(1000);
					}
					while (true)
					{
						cout << endl << "Back[1] | Hamper[2]\nEnter: ";
						cin >> numberr;
						if (numberr == 1)
						{
							break;
						}
						else if (numberr == 2) {
							hamper();
							Sleep(3000);
							break;
						}
						else {
							if (numberr > 0)
							{
								system("cls");
								continue;
							}
							else throw 77;
						};

					}
				}
				else if (nuberc == 2) {
					size_t nums;
					cout << "Enter ID: ";
					cin >> nums;
					products.info(nums);
					Sleep(3000);
					system("cls");
				}
				else if (nuberc == 3) {
					system("cls");
					exit(0);
					break;
				}
				else
				{
					if (nuberc > 0)
					{
						system("cls");
						continue;
					}
					else throw 77;
				}
			}
		}
	public:
		Guest() { setfullname(); }
		void setfullname() {
			string name;
			cout << "Enter name: ";
			cin >> name;
			if (name.size() <= 2)throw 22;
			if (Guestname(name))cout << "Welcome back\n";
			else addguest(name);
			go();



		}
	};
}

