#include "game.h"

void Game::roll_of_dice()
{
	// �������-��������
}

void Game::changing_the_order_of_moves()
{
	// �������-��������
}

void Game::influence_on_advisors()
{
	// �������-��������
}

void Game::construction_of_buildings()
{
	// �������-��������
}

void Game::applying_building_effects()
{
	// �������-��������
}


Game::Game()
{
	this->year = 0;
	this->phase = 1;
}

Game::~Game()
{
	// ������� ������ �� �������
	this->Players.clear();
	// �������� ������ � ����������
	this->Advisors.clear();
}

Game::Game(int number_of_players)
{
	// ���� ������� � ���������� ������� (���� �������� - ���� �����)
	for (int i = 0; i < number_of_players; i++) {
		// �������� ������
		Person player;
		std::cout << "\n������� ��� ������ : ";
		std::cin >> player.name;
		player.gold = 0;// ����������� �������� ������
		player.wood = 0;
		player.stone = 0;
		player.dice1 = true; // ������ ������� ������ 
		player.dice2 = true; // ������� 
		player.dice3 = true; // 
		player.buildings = 0;
		player.additional_dice = false;
		player.availability_advisor = "";
		player.military_register = 0;
		player.victory_points = 0;
		// ���������� ���������� ������ � ������
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
	std::cout << "��� " << this->year << " ���� " << this->phase;
	// ���� ��� ������ ����, �� ������ ���� ������������
	if (this->year == 1) {
		// �������� (������� ����)
	}
	else {
		// ����������� ���������� ��������
		int min_resources = 99999999;
		// ��� ������ � ����������� ����������� ��������
		std::string min_name;//��� ������
		for (Person person : this->Players) {
			int current_resources = 0;
			current_resources += person.gold;
			current_resources += person.wood;
			current_resources += person.stone;
			current_resources += person.buildings;
			if (current_resources < min_resources)
				min_name = person.name;// ��� ��� ����������� �� ������ ������
		}
		for (Person person : this->Players) { // ���� ������ � ������ � ���. ��������� 
			if (person.name == min_name)
				std::cout << "\n����� � ����������� ����������� �������� >>> " << person.name;
			person.additional_dice = true;
		}
	}
	this->phase += 1; // ����� �� ����
}

void Game::phase3()
{
	std::cout << "\n\n\n";
	std::cout << "��� " << this->year << " ���� " << this->phase;
	int max_buildings = 0;// ������������ ���������� �������� 
	std::string max_name;// ��� ������ � ������������ ����������� ������
	for (Person person : this->Players) {
		if (person.buildings > max_buildings) // ��������� �������� � ������ ����������
			max_buildings = person.buildings; //������ � ������
	}
	for (Person person : this->Players) {
		if (person.name == max_name) // �������� ���������� ����
			person.victory_points += 1; // ���������� ����� 
	}
	this->phase += 1; // ����� �� ���� 
}

void Game::phase5()
{
}

void Game::phase7()
{
	std::cout << "\n\n\n";
	std::cout << "��� " << this->year << " ���� " << this->phase;
	for (Person person : this->Players) {
		bool condition = true; 
		while (condition) {// ���� �� ������ ������ ����������� ������
			std::cout << "\n� ����� ������������:\n"
				<< "������: " << person.gold << "��.\n"
				<< "������: " << person.wood << "��.\n"
				<< "������: " << person.stone << "��.\n";
			std::cout << "\n�������� ����� ����:\n"
				<< "1. ������ ����� �� ������.\n"
				<< "2. ������ ����� �� ������.\n"
				<< "3. ������ ����� �� ������.\n";
			int choice;
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				if (person.gold >= 2) { // �������� ������
					person.gold -= 2; // ������� �� ������ 
					person.military_register += 1; // ���������� ����� 
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

			case 50:// ������ �������� ���������� 
				condition = false; //���������� ����
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
	std::cout << "��� " << this->year << " ���� " << this->phase;
	for (Person person : this->Players) { // ������ �� ��������� �������
		defense_level("enemy_name", 1, person);
	}
	this->phase += 1;
}

void Game::defense_level(const char* enemy_name, int king_help, Person& person)
{
	int power = person.military_register; // ������� ���������� ������
	if (power > this->current_enemy.power) { // �������� ����������� �������
		std::cout << "\n������ ��� ������ " << person.name;
		person.gold += this->current_enemy.win_gold; // ������� ������
		person.wood += this->current_enemy.win_wood; // ������� ������  ��� ������
		person.stone += this->current_enemy.win_stone; // ������� ����� 
	}
	if (power == this->current_enemy.power) {
		std::cout << "\n����� ��� ������ " << person.name; // ���� ��� 
	}
	else {
		std::cout << "\n��������� ��� ������ " << person.name;
		person.gold -= this->current_enemy.lose_gold;
		person.wood -= this->current_enemy.lose_gold;
		person.stone -= this->current_enemy.lose_gold;
	}
}


void Game::phase246() // �������� �� ����� ���� ��� 
{
	for (Person person : this->Players) {
		// ������ ������
		roll_of_dice();
		// ������� ������� �����
		changing_the_order_of_moves();
		// ������� �� ����������
		influence_on_advisors();
		// ���������� ������
		construction_of_buildings();
		// ���������� �������� ������
		applying_building_effects();
	}
}

void Game::building(const char* building_name, Person person)
{
	if (building_name == "�����") {
		int sum = 0;
		sum += person.gold
			+ person.wood
			+ person.stone;
		sum /= 2; // ����� ���� ��������, ������ �� 2 = ��
		person.victory_points += sum;
	}
	if (building_name == "�����") {
		person.military_register -= 1; // ������ �������� �����������
	}
	if (building_name == "�������� �������") {
		person.gold += 1; // ���� ������ 
	}
	if (building_name == "�������") { // ���� ������� 
		std::cout << "\n��� ������ ������:\n"
			<< "1. ������ (� ������� " << person.gold << "��.)\n"
			<< "2. ������ (� ������� " << person.wood << "��.)\n"
			<< "3. ������ (� ������� " << person.stone << "��.)\n";
		int choice;
		std::cout << "\n��� �����: ";
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
		std::cout << "\n������ � ����� ��������� �� �������...";
	}
}


bool Game::load_game(const char* filename)
{
	// ����� ��� ������ �� �����
	std::fstream streamin;
	// ������� ���� � �����
	std::string filePath;
	std::cout << "\n������� ���� � �����: ";
	std::cin >> filePath;
	// �������� ����� �� ������
	streamin.open(filePath, std::fstream::in);
	// �������� �� ������� �����
	if (!streamin) {
		std::cout << "error! file not found...";
		// ������� ������
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
	// ����� ��� ������ � ����
	std::fstream streamout;
	// ������� ���� � �����
	std::string filePath;
	std::cout << "\n������� ���� � �����: ";
	std::cin >> filePath;
	// �������� ����� �� ������ � ���������������� �����
	streamout.open(filePath, std::fstream::out | std::fstream::trunc);
	// �������� �� ������� �����
	if (!streamout) {
		std::cout << "error! file not found...";
		// ������� ������
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


