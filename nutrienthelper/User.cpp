#include "User.h"

float User::calculateBMR(int AGE, int actLev, float WEIGHT, float HEIGHT) {
	float BMR = 655.0f + (4.35f * (float)WEIGHT) + (4.7f * (float)HEIGHT) - (4.7f * (float)AGE);
	switch (actLev)
	{
	case 0: //low activity
		BMR *= 1.2f;
		break;
	case 1: //1-3 times per week
		BMR *= 1.375f;
		break;
	case 2: //3-5 times per week
		BMR *= 1.55f;
		break;
	case 3: //6-7 times per week
		BMR *= 1.725f;
		break;
	}
	return BMR;
}

float User::giveMaxCarb() {
	return this->maxCarbs;
}

float User::giveMaxProt() {
	return this->maxProt;
}

float User::giveMaxFat() {
	return this->maxFat;
}

float User::giveCurCarb() {
	return this->currCarb;
}

float User::giveCurProt() {
	return this->currProt;
}

float User::giveCurFat() {
	return this->currFat;
}

void User::addFood(int ID, string name, float protien, float fat, float carb) {
	node temp;
	temp.ID = ID;
	temp.name = name;
	temp.protien = protien;
	temp.fat = fat;
	temp.carb = carb;

	this->currProt += protien;
	this->currFat += fat;
	this->currCarb += carb;

	userStore.push_back(temp);
}

void User::removeFood(int ID) {
	for (int i = 0; i < userStore.size(); i++) {
		if (userStore.at(i).ID == ID) {
			this->currProt -= userStore.at(i).protien;
			this->currFat -= userStore.at(i).fat;
			this->currCarb -= userStore.at(i).carb;
			userStore.erase(userStore.begin() + i);
		}
	}
}