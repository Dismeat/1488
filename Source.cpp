using std::cout;
using std::cin;
using std::endl;

int main() {
	String str;//Прописать в h u cpp
	Keeper kpr;
	int ch;
	bool flag = true;
	setlocale(LC_ALL, "Russian");

	while (flag) {

		cout << "1. Добавить" << endl;
		cout << "2. Удалить" << endl;
		cout << "3. Вывести на экран" << endl;
		cout << "4. Вывести на экран по нужному времени" << endl;
		cout << "5. Выход" << endl;

		cout << "Выберете пункт: ";
		cin >> ch;
		cin.get();
		cout << endl;

		switch (ch) {
		case 1:
			try {
				TRAIN tmp;

				cin >> tmp;

				kpr += tmp;

			}
			catch () {
				cout << () << endl;//Через исключения выведем о переполеннии списка при всех 8
			}
			break;
		case 2:
			cout << kpr;
			if (kpr.GetSize()) {
				cout << "Выберете удаляемую запись: ";
				cin >> ch;
				cin.get();
				try {
					kpr.remove(--ch);
				}
				catch () {
					cout <<  << endl;//Вывод об отсутствии оной
				}
			}
			break;
		case 3:
			cout << kpr;
			break;
		case 4: {

			size_t t_H;
			size_t t_M;

			cout << "Введите время:" << std::endl;
			cout << "\tЧасы: ";

			cin >> t_H;

			if (t_H > 23) {

				cout << "Ошибка ввода!" << endl;

				break;

			}

			cout << "\tМинуты: ";

			cin >> t_M;

			if (t_M > 59) {

				cout << "Ошибка ввода!" << endl;

				break;

			}

			cout << endl;

			try {
				kpr.print(t_H, t_M);
			}
			catch () {
				cout <<  << endl;// Исключение - ошибка - отсутсвие рейсов
			}
		}
			break;
		case 5:
			flag = false;
			break;
		default:
			cout << "Был выбран неверный пункт." << endl;
		}
		cout << endl;
	}

	return 0;
}
