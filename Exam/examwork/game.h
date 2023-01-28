#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>


// структура игрок
struct Person 
{
	std::string name;
	// золото
	int gold;
	// дерево
	int wood;
	// камень
	int stone;
	// кубик 1
	int dice1;
	// кубик 2
	int dice2;
	// кубик 3
	int dice3;
	// дополнительный кубик
	int additional_dice;
	// наличие советника
	std::string availability_advisor;
	// значение воинского реестра
	int military_register;
	// победные очки
	int victory_points;
	// постройки
	int buildings;
};

// структура советник
struct Advisor
{
	// имя советника
	std::string name;
	// имя игрока
	std::string player_name;
};

struct Enemy //к открытым членам можно обратится из дочерних, методов
{
	std::string name;
	// сила
	int power;
	// потери золота
	int lose_gold;
	// потери дерева
	int lose_wood;
	// потери камня
	int lose_stone;
	// выигрыш золота
	int win_gold;
	// выигрыш дерева
	int win_wood;
	// выигрыш камня
	int win_stone;
};

class Game
{
private:
	// список игроков
	std::list<Person> Players;
	// вектор советников
	std::vector<Advisor> Advisors;
	// год
	int year;
	// фаза
	int phase;
	// враг в текущем году
	Enemy current_enemy;

	// бросок кубика
	void roll_of_dice();
	// измение порядка ходов
	void changing_the_order_of_moves();
	// влияние на советников
	void influence_on_advisors();
	// возведение зданий
	void construction_of_buildings();
	// применение эффектов зданий
	void applying_building_effects();

public:
	// конструкторы и деструкторы
	// конструктор по умолчанию
	Game();
	// деструктор по умолчанию
	~Game();
	// конструктор с заданным количеством игроков
	Game(int number_of_players);


	// фазы
	// фаза 1
	void phase1();
	// фаза 2
	void phase3();
	// фаза 5
	void phase5();
	// фаза 7
	void phase7();
	// фаза 8
	void phase8();
	// функция применяющая результат боя к параметрам игрока
	void defense_level(const char* enemy_name, int king_help, Person& player);

	// функция описывающая фазы 2,4,6
	void phase246();
	// возведение зданий игроком
	void building(const char* building_name, Person person);
	// загрузка игры из файла
	bool load_game(const char* filename);
	// сохранение игры в файл
	bool save_game(const char* filename);
};

