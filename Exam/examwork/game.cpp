#include "game.h"

void Game::roll_of_dice()
{
	// функция-заглушка
}

void Game::changing_the_order_of_moves()
{
	// функция-заглушка
}

void Game::influence_on_advisors()
{
	// функция-заглушка
}

void Game::construction_of_buildings()
{
	// функция-заглушка
}

void Game::applying_building_effects()
{
	// функция-заглушка
}


Game::Game()
{
	this->year = 0;
	this->phase = 1;
}

Game::~Game()
{
	// очистка данных об игроках
	this->Players.clear();
	// очистить данные о советниках
	this->Advisors.clear();
}

Game::Game(int number_of_players)
{
	// цикл содания и добавления игроков (одна итерация - один игрок)
	for (int i = 0; i < number_of_players; i++) {
		// создание игрока
		Person player;
		std::cout << "\nВведите имя игрока : ";
		std::cin >> player.name;
		player.gold = 0;// определение ресурсов игрока
		player.wood = 0;
		player.stone = 0;
		player.dice1 = true; // бросок первого кубика 
		player.dice2 = true; // второго 
		player.dice3 = true; // 
		player.buildings = 0;
		player.additional_dice = false;
		player.availability_advisor = "";
		player.military_register = 0;
		player.victory_points = 0;
		// добавление созданного игрока в список
		this->Players.push_back(player);
	}
	this->year = 0;
	this->phase = 1;
}

void Game::phase1()
{
	this->year += 1;
	this->phase = 1;
	std::cout << "\n\n\n";
	std::cout << "Год " << this->year << " фаза " << this->phase;
	// если это начало игры, то первая фаза пропускается
	if (this->year == 1) {
		// заглушка (пропуск фазы)
	}
	else {
		// минимальное количество ресурсов
		int min_resources = 99999999;
		// имя игрока с минимальным количеством ресурсов
		std::string min_name;//имя игрока
		for (Person person : this->Players) {
			int current_resources = 0;
			current_resources += person.gold;
			current_resources += person.wood;
			current_resources += person.stone;
			current_resources += person.buildings;
			if (current_resources < min_resources)
				min_name = person.name;// Тот кто расчитывает на помощь короля
		}
		for (Person person : this->Players) { // цикл вывода с игрока с мин. ресурсами 
			if (person.name == min_name)
				std::cout << "\nИгрок с минимальным количеством ресурсов >>> " << person.name;
			person.additional_dice = true;
		}
	}
	this->phase += 1; // сдвиг по фазе
}

void Game::phase3()
{
	std::cout << "\n\n\n";
	std::cout << "Год " << this->year << " фаза " << this->phase;
	int max_buildings = 0;// Максимальное количество построек 
	std::string max_name;// имя игрока с максимальным количеством зданий
	for (Person person : this->Players) {
		if (person.buildings > max_buildings) // сравнение построек с пустой переменной
			max_buildings = person.buildings; //запись в память
	}
	for (Person person : this->Players) {
		if (person.name == max_name) // проверка победителя фазы
			person.victory_points += 1; // добавление очков 
	}
	this->phase += 1; // сдвиг по фазе 
}

void Game::phase5()
{
}

void Game::phase7()
{
	std::cout << "\n\n\n";
	std::cout << "Год " << this->year << " фаза " << this->phase;
	for (Person person : this->Players) {
		bool condition = true; 
		while (condition) {// пока не наберёт нужное колличество воинов
			std::cout << "\nВ вашем распоряжении:\n"
				<< "Золото: " << person.gold << "шт.\n"
				<< "Дерево: " << person.wood << "шт.\n"
				<< "Камень: " << person.stone << "шт.\n";
			std::cout << "\nВыберите пункт меню:\n"
				<< "1. Купить воина за золото.\n"
				<< "2. Купить воина за дерево.\n"
				<< "3. Купить воина за камень.\n";
			int choice;
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				if (person.gold >= 2) { // проверка золота
					person.gold -= 2; // покупка за золото 
					person.military_register += 1; // добавление война 
				}
				break;

			case 2:
				if (person.wood >= 2) {
					person.wood -= 2;
					person.military_register += 1;
				}
				break;

			case 3:
				if (person.stone >= 2) {
					person.stone -= 2;
					person.military_register += 1;
				}
				break;

			case 50:// больше наролить невозможно 
				condition = false; //завершение хода
				break;

			default:
				break;
			}
		}
	}
	this->phase += 1;
}

void Game::phase8()
{
	std::cout << "\n\n\n";
	std::cout << "Год " << this->year << " фаза " << this->phase;
	for (Person person : this->Players) { // проход по элементам массива
		defense_level("enemy_name", 1, person);
	}
	this->phase += 1;
}

void Game::defense_level(const char* enemy_name, int king_help, Person& person)
{
	int power = person.military_register; // военный потанцевал игрока
	if (power > this->current_enemy.power) { // проверка потанцевала игроков
		std::cout << "\nПобеда для игрока " << person.name;
		person.gold += this->current_enemy.win_gold; // лутание золота
		person.wood += this->current_enemy.win_wood; // лутание дерева  при победе
		person.stone += this->current_enemy.win_stone; // лутание камня 
	}
	if (power == this->current_enemy.power) {
		std::cout << "\nНичья для игрока " << person.name; // миру мир 
	}
	else {
		std::cout << "\nПоражение для игрока " << person.name;
		person.gold -= this->current_enemy.lose_gold;
		person.wood -= this->current_enemy.lose_gold;
		person.stone -= this->current_enemy.lose_gold;
	}
}


void Game::phase246() // действия во время фарм фаз 
{
	for (Person person : this->Players) {
		// бросок кубика
		roll_of_dice();
		// измение порядка ходов
		changing_the_order_of_moves();
		// влияние на советников
		influence_on_advisors();
		// возведение зданий
		construction_of_buildings();
		// применение эффектов зданий
		applying_building_effects();
	}
}

void Game::building(const char* building_name, Person person)
{
	if (building_name == "Собор") {
		int sum = 0;
		sum += person.gold
			+ person.wood
			+ person.stone;
		sum /= 2; // сумма всех ресурсов, делить на 2 = ПО
		person.victory_points += sum;
	}
	if (building_name == "Фермы") {
		person.military_register -= 1; // потеря военного потанцевала
	}
	if (building_name == "Торговая гильдия") {
		person.gold += 1; // фарм золота 
	}
	if (building_name == "Казармы") { // фарм военных 
		std::cout << "\nЧто хотите отдать:\n"
			<< "1. золото (в наличии " << person.gold << "шт.)\n"
			<< "2. дерево (в наличии " << person.wood << "шт.)\n"
			<< "3. камень (в наличии " << person.stone << "шт.)\n";
		int choice;
		std::cout << "\nВаш выбор: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			person.gold -= 3;
			break;
		case 2:
			person.wood -= 3;
			break;
		case 3:
			person.stone -= 3;
			break;
		default:
			break;
		};
		person.military_register += 1;
	}
	else {
		std::cout << "\nЗдание с таким названием не найдено...";
	}
}


bool Game::load_game(const char* filename)
{
	// поток для чтения из файла
	std::fstream streamin;
	// задание пути к файлу
	std::string filePath;
	std::cout << "\nВведите путь к файлу: ";
	std::cin >> filePath;
	// открытие файла на чтение
	streamin.open(filePath, std::fstream::in);
	// проверка на наличие файла
	if (!streamin) {
		std::cout << "error! file not found...";
		// возврат ошибки
		return false;
	}
	else {
		while (!streamin.eof()) {
			std::string person = "";
			for (Person person : this->Players) {
				std::string line;
				std::getline(streamin, line);
				person.name = line;
				std::getline(streamin, line);
				person.gold = stoi(line);
				std::getline(streamin, line);
				person.wood = stoi(line);
				std::getline(streamin, line);
				person.stone = stoi(line);
				std::getline(streamin, line);
				person.dice1 = stoi(line);
				std::getline(streamin, line);
				person.dice2 = stoi(line);
				std::getline(streamin, line);
				person.dice3 = stoi(line);
				std::getline(streamin, line);
				person.buildings = stoi(line);
				std::getline(streamin, line);
				person.additional_dice = stoi(line);
				std::getline(streamin, line);
				person.availability_advisor = line;
				std::getline(streamin, line);
				person.military_register = stoi(line);
				std::getline(streamin, line);
				person.victory_points = stoi(line);
			}
		}
		streamin.close();
	}
	return true;
}

bool Game::save_game(const char* filename)
{
	// поток для записи в файл
	std::fstream streamout;
	// задание пути к файлу
	std::string filePath;
	std::cout << "\nВведите путь к файлу: ";
	std::cin >> filePath;
	// открытие файла на запись с перезаписыванием файла
	streamout.open(filePath, std::fstream::out | std::fstream::trunc);
	// проверка на наличие файла
	if (!streamout) {
		std::cout << "error! file not found...";
		// возврат ошибки
		return false;
	}
	else {
		for (Person person : this->Players) {
			std::string data_person;
			data_person += person.name + "\n";
			data_person += person.gold + "\n";
			data_person += person.wood + "\n";
			data_person += person.stone + "\n";
			data_person += person.dice1 + "\n";
			data_person += person.dice2 + "\n";
			data_person += person.dice3 + "\n";
			data_person += person.buildings + "\n";
			data_person += person.additional_dice + "\n";
			data_person += person.availability_advisor + "\n";
			data_person += person.military_register + "\n";
			data_person += person.victory_points + "\n";
			streamout << data_person;
		}
		streamout.close();
	}
	return true;
}


