#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>


// ��������� �����
struct Person 
{
	std::string name;
	// ������
	int gold;
	// ������
	int wood;
	// ������
	int stone;
	// ����� 1
	int dice1;
	// ����� 2
	int dice2;
	// ����� 3
	int dice3;
	// �������������� �����
	int additional_dice;
	// ������� ���������
	std::string availability_advisor;
	// �������� ��������� �������
	int military_register;
	// �������� ����
	int victory_points;
	// ���������
	int buildings;
};

// ��������� ��������
struct Advisor
{
	// ��� ���������
	std::string name;
	// ��� ������
	std::string player_name;
};

struct Enemy //� �������� ������ ����� ��������� �� ��������, �������
{
	std::string name;
	// ����
	int power;
	// ������ ������
	int lose_gold;
	// ������ ������
	int lose_wood;
	// ������ �����
	int lose_stone;
	// ������� ������
	int win_gold;
	// ������� ������
	int win_wood;
	// ������� �����
	int win_stone;
};

class Game
{
private:
	// ������ �������
	std::list<Person> Players;
	// ������ ����������
	std::vector<Advisor> Advisors;
	// ���
	int year;
	// ����
	int phase;
	// ���� � ������� ����
	Enemy current_enemy;

	// ������ ������
	void roll_of_dice();
	// ������� ������� �����
	void changing_the_order_of_moves();
	// ������� �� ����������
	void influence_on_advisors();
	// ���������� ������
	void construction_of_buildings();
	// ���������� �������� ������
	void applying_building_effects();

public:
	// ������������ � �����������
	// ����������� �� ���������
	Game();
	// ���������� �� ���������
	~Game();
	// ����������� � �������� ����������� �������
	Game(int number_of_players);


	// ����
	// ���� 1
	void phase1();
	// ���� 2
	void phase3();
	// ���� 5
	void phase5();
	// ���� 7
	void phase7();
	// ���� 8
	void phase8();
	// ������� ����������� ��������� ��� � ���������� ������
	void defense_level(const char* enemy_name, int king_help, Person& player);

	// ������� ����������� ���� 2,4,6
	void phase246();
	// ���������� ������ �������
	void building(const char* building_name, Person person);
	// �������� ���� �� �����
	bool load_game(const char* filename);
	// ���������� ���� � ����
	bool save_game(const char* filename);
};

