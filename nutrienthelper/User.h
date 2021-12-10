#pragma once
//#include "Graph.h"
#include<vector>
#include<string>
using namespace std;

//struct node {
//	string name;
//	int ID;
//	float protien;
//	float fat;
//	float carb;
//};

class User
{ //need to add activity level to calculation
private:
	struct node {
		string name;
		int ID;
		float protien;
		float fat;
		float carb;
	};

	float maxCarbs;
	float maxProt;
	float maxFat;
	float currCarb = 0;
	float currProt = 0;
	float currFat = 0;
	int age;
	int activityLevel;

	float weight;
	float height;
	float BMR;

public:
	vector<node> userStore;
	void addFood(int ID, string name, float protien, float fat, float carb);
	void removeFood(int ID);
	float calculateBMR(int AGE, int actLev, float WEIGHT, float HEIGHT);
	float giveMaxCarb();
	float giveMaxProt();
	float giveMaxFat();
	float giveCurCarb();
	float giveCurProt();
	float giveCurFat();
	User(int AGE, int actLev, float WEIGHT, float HEIGHT) {
		this->age = AGE;
		this->activityLevel = actLev;
		this->weight = WEIGHT;
		this->height = HEIGHT;
		this->BMR = calculateBMR(this->age, this->activityLevel, this->weight, this->height);
		this->currCarb = 0.0f;
		this->currProt = 0.0f;
		this->currFat = 0.0f;

		this->maxCarbs = (this->BMR) * 0.4f;
		this->maxProt = (this->BMR) * 0.4f;
		this->maxFat = (this->BMR) * 0.2f;
	}
};