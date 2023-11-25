#pragma once
namespace admin {
	class Admin {
	private:
		string username;
		string password;
	protected:
		void setpassword() {
			string password;
			char passwords[20];
			size_t i = 0;
			cout << "Enter password: ";
			while (true)
			{
				char symbol = _getch();
				if (symbol == 13)
				{
					passwords[i] = '\0';
					break;
				}
				passwords[i] = symbol;
				cout << '*';
				i++;
			}
			password = passwords;
			if (password.size() > 6) this->password = password;
			else throw 66;
		}
		void setusername() {
			string username;
			cout << "Enter username: ";
			cin >> username;
			if (username.size() > 2) this->username = username;
			else throw 22;
		}

	public:
		Admin() = default;
		void Admin123() {
			setusername();
			setpassword();
		}
		void gogo() {
			while (true)
			{
				size_t num;
				cout << "Login[1] Sign up[2] Exit[3]\nEnter: ";
				cin >> num;
				if (num == 1)
				{
					AmdinLogin();
					product::Product a;
					while (true)
					{
						size_t count;
						cout << "Add product[1] | Delete product[2] \n| Show Product[3] | Exit[4]\nEnter: ";
						cin >> count;
						if (count == 1)
						{
							a.productadd();
							system("cls");
						}
						else if (count == 2) {
							a.deleteproduct();
							system("cls");
						}
						else if (count == 4) exit(0);
						else if (count == 3) a.showProduct();
						else
						{
							system("cls");
							continue;
						}
					}
				}
				else if (num == 2) {
					newadmin();
					exit(0);
					break;
				}
				else if (num == 3) {
					exit(0);
					break;
				}
				else {
					if (num > 0)
					{
						system("cls");
						continue;
					}
					else throw 77;
				}
			}
		}
		void newadmin() {
			Admin123();
			ofstream file;
			file.open("N.txt", ios::app);
			file << '\n' << username << '\n' << password;
		}
		bool AmdinLogin() {
			Admin123();
			string usingname, password;
			ifstream fin;
			size_t count = 0;
			fin.open("N.txt");
			while (fin.good())
			{
				count++;
				fin >> usingname;
				if (usingname == this->username)
				{
					fin >> password;
					if (password == this->password)
					{
						cout << "Login successful" << endl;
						return true;
					}
				}
			}
			throw false;
			fin.close();
			return false;
		}
	};
}
