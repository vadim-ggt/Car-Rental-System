
#include <iostream>
#include "CLASS_CAR_RENTAL_SYSTEM.h"
#include <windows.h>


void setBackgroundColor(int backgroundColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Установить цвет текста (7 - стандартный белый) + цвет фона
	SetConsoleTextAttribute(hConsole, 7 | (backgroundColor << 4));
}




// вход

int main() {
	setBackgroundColor(1);
	CarRentalSystem rer;
	rer.showMainMenu();
	return 0;
}

