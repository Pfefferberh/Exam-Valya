#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// Option 2
/*
2. Написати програму «Автоматизована інформаційна система на залізничному вокзалі».
Інформаційна система містить дані про відправлення поїздів дальнього сполучення.
Для кожного потяга вказується:
номер потяга,
станція призначення,
час відправлення.
Програма повинна забезпечувати вибір за допомогою меню і виконання однієї наступних функцій:
 первісне введення даних в інформаційну систему (із клавіатури чи з файлу);
//                        виведення даних про всі потяги;
						  виведення даних пpо потяг з запитаним номером;
						  виведення даних про ті потяги, що слідують до запитаної станції призначення.
Збереження даних організувати з застосуванням контейнерного класу vector.
*/

template<typename T1, typename T2>
class Station
{
private:
	template <typename T1, typename T2>
	class Train
	{
	public:
		Train* nextTrain;
		T1 numberTrain;
		T2 destinationStation;
		T2 departureTime;
		Train() { };
		Train(T1 numberTrain, T2 destinationStation, T2 departureTime)
		{
			this->numberTrain = numberTrain;
			this->destinationStation = destinationStation;
			this->departureTime = departureTime;
		}
	};
	Train <T1, T2>* head;
	int size;

public:
	//Constructor Station
	Station()
	{
		this->size = 0;
		this->head = nullptr;
	}

	//Metor povernennia Size
	int GetSize()
	{
		return this->size;
	}

	//Metod stvorennia poizda na pochatok spyska
	void Push(T1 numberTrain, T2 destinationStation, T2 departureTime)
	{
		if (head == nullptr)
		{
			this->head = new Train<T1, T2>(numberTrain, destinationStation, departureTime);
		}
		else
		{
			Train<T1, T2>* tmp = this->head;
			while (tmp->nextTrain != nullptr)
			{
				tmp = tmp->nextTrain;
			}
			tmp->nextTrain = new Train <T1, T2>(numberTrain, destinationStation, departureTime);
		}
		this->size++;
	}

	//Metod dodavannia pershogo elementy
	void Pop(T1 numberTrain, T2 destinationStation, T2 departureTime)
	{
		head = new Train<T1, T2>(numberTrain, destinationStation, departureTime);
		this->size++;
	}

	//Vstavka elementa
	/*void InsertTrainByIndex()
	{
		T1 numberTrain;
		T2 destinationStation;
		T2 departureTime;
		int index;
		cout << "Enter number of Train for number: ";					cin >> numberTrain;
		cout << "Enter destination Station of Train: ";					cin >> destinationStation;
		cout << "Enter the departure time of Train: ";					cin >> departureTime;
		cout << " Enter the train train number to add: ";				cin >> index;
		if (index == 0)
		{
			Pop(numberTrain, destinationStation, departureTime);
		}
		else
		{
			Train<T1, T2, T2> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextTrain;
			}
			Train<T1, T2, T3> *newTrain = new Train<T1, T2, T3>(numberTrain, destinationStation, departureTime, prev->nextTrain);
			prev->nextTrain = newTrain;
			size++;
		}
	}*/


//Metod vydalennia pershogo elementa
	void DeleteFirst()
	{
		Train<T1, T2>* tmp = this->head;
		this->head = head->nextTrain;
		delete tmp;
		this->size--;
	}
	//Metod vydalyty za indeksom
	void RemoveByIndex()
	{
		int index;
		cout << "Enter the train serial number to be removed: "; cin >> index;
		if (index - 1 > size) {
			throw "index is more than size";
		}
		else{
			if (index == 0)
			{
				DeleteFirst();
			}
			else
			{
				Train<T1, T2>* prev = this->head;
				for (int i = 0; i < index - 1; i++)
				{
					prev = prev->nextTrain;
				}
				Train<T1, T2>* toDel = prev->nextTrain;
				prev->nextTrain = toDel->nextTrain;
				delete toDel;
				size--;
			}
			cout << "The train N" << index << " was removed from the database" << endl;
		}
	}

	//Metod vyvodu na ekran
	void ShowInfo()
	{
		Train<T1, T2>* tmp = head;
		int counter = 0;
		while (tmp != nullptr)
		{
			counter++;
			cout << "Train N " << counter << ": " << endl;
			cout << "Train's number: " << tmp->numberTrain << "\tDestination station\t: " << tmp->destinationStation << "\tTime: " << tmp->departureTime << endl;
			tmp = tmp->nextTrain;

		}
		//cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
	}
	//Metod peregruzky operatora []
	T1& operator[](const int index)
	{
		int counter = 0;
		Train<T1, T2>* train = this->head;
		while (train != nullptr)
		{
			if (train == index)
			{
				return train->numberTrain;
			}
			train = train->nextBus;
			counter++;
		}
	}
	//Metod vyvodu na ekran 
	void ShowInfoByIndex()
	{
		int index;
		Train<T1, T2>* tmp = head;
		int counter = 0;
		bool isIndex = false;
		cout << "Enter the train number: "; cin >> index;
		index--;
			while (tmp != nullptr)
			{
				if (index == counter)
				{
					cout << "Counter = " << counter << endl;
					cout << "Index = " << index << endl;

					cout << "Train's number: " << tmp->numberTrain << "\tDestination station\t: " << tmp->destinationStation << "\tTime: " << tmp->departureTime << endl;
					isIndex = true;
				}
				tmp = tmp->nextTrain;
				counter++;

			}
			if (!isIndex)
			{
				cout << "Please check that you are correct" << endl;
			}
	}
	//Metod poshuku za vidstany
	void FindByDestination()
	{
		string index;
		Train<T1, T2>* tmp = head;
		int counter = 0;
		bool isIndex = false;
		cout << "Enter the destination station: "; cin >> index;
		while (tmp != nullptr)
		{
			if (index == tmp->destinationStation)
			{
				cout << "Train's number: " << tmp->numberTrain << "\tDestination station\t: " << tmp->destinationStation << "\tTime: " << tmp->departureTime << endl;
				isIndex = true;
			}
			tmp = tmp->nextTrain;
			counter++;
		}
		if (!isIndex)
		{
			cout << "Please check that you are correct" << endl;
		}
	}
	//metod zapusy y fayl
	void WriteFile() {
		Train<T1, T2>* tmp = head;
		string path = "TrainDB.txt";

		ofstream writeFile;

		writeFile.open(path);

		if (!writeFile.is_open()) {
			cout << "Cant open file" << endl;
		}
		else {
			while (tmp != nullptr)
			{
				
				writeFile << tmp->numberTrain<<endl;
				writeFile << tmp->destinationStation << endl;
				writeFile << tmp->departureTime << endl;
				tmp = tmp->nextTrain;
			}
		}
		writeFile.close();
	}
	//metod zchutyvanya
	void ReadFile() {
		T1 MembNumberTrain;
		T2 MembDestinationStation;
		T2 MembDepartureTime;

		string path = "TrainDB.txt";

		ifstream readFile;

		readFile.open(path);

		if (!readFile.is_open()) {
			cout << "Cant open file" << endl;
		}
		else {
			while (!readFile.eof()) {
				char tmpChar[255];

				readFile.getline(tmpChar, 255);
				MembNumberTrain=atoi(tmpChar);
				readFile.getline(tmpChar, 255);
				MembDestinationStation =tmpChar;
				readFile.getline(tmpChar, 255);
				MembDepartureTime=tmpChar;
				Push(MembNumberTrain, MembDestinationStation, MembDepartureTime);
				
			}
		}

		readFile.close();
	}

};



void Menu()
{
	Station<int, string> station;
	bool exit = false;
	int menu = 0;
	int numberOfTrain = 0;
	int numberTrain;
	string description;
	string time;

	while (!exit)
	{
		system("cls");
		cout << " =================     MENU   ==============================:\n";
		cout << "  (1)Create Station:\n"; // Ввід бази даних
		cout << "        11.From keyboard\n";
		cout << "        12.From File\n";
		cout << "  2.Showing the database:\n"; //Перегляд бази даних
		cout << "  (3)Editing the database:\n"; //Редагування бази даних
		cout << "        31.Delete by Index Train\n";
		cout << "        32.Add new Train\n";
		cout << "  (4)Data search:\n";//Пошук
		cout << "        41.By Trains number\n";
		cout << "        42.By destination Station\n";
		cout << "  5.Database output(Save):\n"; // Запис бази даних в файл
		cout << "  0.Exit\n\n";

		cout << "Select menu item: ";
		cin >> menu;
		switch (menu)
		{
		case 12: // Створити базу даних з файлу
		{
			system("cls");
			station.ReadFile();
			cout << "Done!\n";
			system("pause");
			break;
		}
		case 11: // Ввести потяг з клавіатури
		{
			system("cls");
			cout << "Enter the number of trains: ";	 cin >> numberOfTrain;
			cout << "======================================" << endl;
			for (int i = 0; i < numberOfTrain; i++)
			{
				cout << "====================================================" << endl;
				cout << "Add information about Train N [" << i+1 << "]" << endl;
				cout << "Enter number of Train for number: ";					cin >> numberTrain;
				cout << "Enter destination Station of Train: ";					cin >> description;
				cout << "Enter the departure time of Train: ";					cin >> time;

				station.Push(numberTrain, description, time);
			}
			system("pause");
			break;
		}
		case 2: //Перегляд бази даних
		{
			system("cls");
			station.ShowInfo();
			system("pause");
			break;
		}

		case 31:
		{
			system("cls");
			station.RemoveByIndex();
			system("pause");
			break;
		}
		case 32:
		{
			system("cls");
			cout << "====================================================" << endl;
			cout << "Add information about Train N [" << station.GetSize() + 1 << "]" << endl;
			cout << "Enter number of Train for number: ";					cin >> numberTrain;
			cout << "Enter destination Station of Train: ";					cin >> description;
			cout << "Enter the departure time of Train: ";					cin >> time;
			station.Push(numberTrain, description, time);
			system("pause");
			break;
		}
		case 41:
		{
			system("cls");
			station.ShowInfoByIndex();
			system("pause");
			break;
		}
		case 42:
		{
			system("cls");
			station.FindByDestination();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			station.WriteFile();
			cout << "Done!\n";
			system("pause");
			break;
		}
		case 0:
		{
			exit = true;
			break;

		}
		default:
		{
			cout << "ERROR! \n\n";
			menu = 8;
		}
		}
	}
}

int main()
{
	cout << " **** Option 2 ****" << endl;
	try
	{
		Menu();
	}
	catch (const exception & error)
	{
		cout << error.what() << endl;
	}
	
	catch (...) {
		cout << "Internal server error" << endl;
	}





	system("pause");
	return 0;
}





















//class Station
//{
//protected:
//	class Train
//	{
//
//		int numberTrain;
//		string destinationStation;
//		string departureTime;
//	public:
//		Train() { cout << "Default constructor Bus " << this << endl; };
//		Train(int numberTrain, string destinationStation, string departureTime)
//		{
//			this->numberTrain = numberTrain;
//			this->destinationStation = destinationStation;
//			this->departureTime = departureTime;
//			cout << "Overload constructor Train " << this << endl;
//		}
//		void Show() {
//			cout << "Train's number: " << this->numberTrain << "\tDestination station\t: " << this->destinationStation << "\tTime: " << this->departureTime << endl;
//		}
//		string GetDestinationStation() { return this->destinationStation; }
//		int GetNumberTrain() { return this->numberTrain; }
//	};
//	
//public:
//	vector<Train> train;
//	//Constructor Station
//	Station()
//	{
//		cout << "Default constructor Station " << this << endl;
//	}
//	//Metod stvorennia poizda   
//	void Push(int numberTrain, string destinationStation, string departureTime)
//	{
//		this->train.push_back(Train( numberTrain,  destinationStation,  departureTime));
//	}
//	//Metod vydalennia elementa
//	void RemoveByIndex( )
//	{
//		int index;
//		cout << "Enter the train serial number to be removed: "; cin >> index;
//		this->train.erase(train.begin()+ index);
//	}
//	//Metod vyvodu na ekran
//	void ShowInfo()
//	{
//		int counter = 0;
//		while (! train.size() )
//		{
//			cout << "Train N " << counter << ": " << endl;
//			train.at(counter).Show();
//			counter++;
//		}
//		//cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
//	}
//
//	//Metod vyvodu na ekran 
//	void ShowInfoByIndex()
//	{
//		int index;
//		cout << "Enter the train number: "; cin >> index;
//		index--;
//		train.at(index).Show();
//	}
//
//	void FindByDestination()
//	{
//		string index;
//		bool trust = false;
//		int counter = 0;
//		cout << "Enter the destination station: "; cin >> index;
//		while (!train.size())
//		{
//			if (index == train.at(counter).GetDestinationStation())
//			{
//				train.at(counter).Show();
//				trust = true;
//			}
//			counter++;
//		}
//		if (trust == false) {
//			cout << "Sory but we haven`t this train \n" ;
//		}
//	}
//	void FindByNumberTrain()
//	{
//		int index;
//		bool trust = false;
//		int counter = 0;
//		cout << "Enter the name station: "; cin >> index;
//		while (!train.size())
//		{
//			if (index == train.at(counter).GetNumberTrain())
//			{
//				train.at(counter).Show();
//				trust = true;
//			}
//			counter++;
//		}
//		if (trust == false) {
//			cout << "Sory but we haven`t this train \n";
//		}
//	}
//};
