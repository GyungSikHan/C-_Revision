#include <iostream>
using namespace std;

class Player
{
public:
	Player():name{},id(), team{}, score(){}
	~Player(){}

	void SetName(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	const char* GetName()const
	{
		return name;
	}
	void SetID(int id)
	{
		this->id = id;
	}
	const int GetID()const
	{
		return id;
	}
	void SetTeam(const char* team)
	{
		strcpy_s(this->team, sizeof(this->team), team);
	}
	const char* GetTeam() const
	{
		return team;
	}
	void SetScore(int score)
	{
		this->score = score;
	}
	const int GetScore() const
	{
		return score;
	}
	void PrintInfo()
	{
		cout << "- Player: " << name << " (Team " << team << ") Score: " << score << endl;
	}

private:
	char name[256];
	char team[256];
	int id;
	int score;
};

class ScoreBoard
{
public:
	ScoreBoard():players{}, playerLength() {}
	~ScoreBoard() {}

	void SetPlayer(Player* player)
	{
		players[playerLength] = *player;
		playerLength++;
	}

	void CalculationAverage()
	{
		int sum{};

		for (int i = 0; i < playerLength; ++i)
		{
			sum += players[i].GetScore();
		}

		average = (float)sum / playerLength;
	}

	void Print()
	{
		cout << "[ScoreBoard]" << endl;
		for (int i = 0; i < playerLength; ++i)
		{
			players[i].PrintInfo();
		}
		cout << "Average: " <<average << endl;
	}

private:
	Player players[10];
	int playerLength;
	float average;
};

int main()
{
	Player player1;
	player1.SetName("John");
	player1.SetTeam("A");
	player1.SetID(123);
	player1.SetScore(80);

	Player player2;
	player2.SetName("Mary");
	player2.SetTeam("B");
	player2.SetID(345);
	player2.SetScore(90);

	ScoreBoard board;

	board.SetPlayer(&player1);
	board.SetPlayer(&player2);
	board.CalculationAverage();
	board.Print();
}