#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int WHITEBALLSSIZE = 69; 
const int WHITECHOSEN = 5;
const int REDBALLS = 26;
const int LOWERBOUNDQTYOFGAMES = 0;

int qtyOfGames();
void playWhite();
void packWhiteBalls(int[], int, int&);
void sortWhitePicks(int[], int);
void redballFunction();


int main() {
	int qtyOfGames1 = qtyOfGames();

	unsigned int seed = time(0);
	srand(seed);

	for (int i = 0; i < qtyOfGames1; i++) {
		playWhite();
		redballFunction();
	}

	return 0;
}

int qtyOfGames() {
	int qty;
	cout << "How many games would you like to play? ";
	cin >> qty;
	cout << endl;
	
	while (qty <= LOWERBOUNDQTYOFGAMES) {
		cout << "How many games would you like to play? ";
		cin >> qty;
		cout << endl;
	}
	return qty;
}

void packWhiteBalls(int num[], int d, int& size)
{
	for (int i = d; i < size - 1; i++)
	{
		num[i] = num[i + 1];
	}

	size -= 1;
}

void playWhite()
{

	int sizeOfWhiteBalls = WHITEBALLSSIZE;


	int whiteBallsCage[WHITEBALLSSIZE];

	for (int i = 0; i < WHITEBALLSSIZE; i++)
	{
		int j = i + 1;
		whiteBallsCage[i] = j;
	}

	int whitePicksArray[WHITECHOSEN];
	int* whitePicksArrayPtr = whitePicksArray;
	int sizeOfWhitePicksArray = WHITECHOSEN;

	for (int i = 0; i < WHITECHOSEN; i++)
	{
		int randomWhiteBall = rand() % sizeOfWhiteBalls;
		*(whitePicksArrayPtr + i) = whiteBallsCage[randomWhiteBall];

		packWhiteBalls(whiteBallsCage, randomWhiteBall, sizeOfWhiteBalls);
	}

	sortWhitePicks(whitePicksArray, sizeOfWhitePicksArray);

	cout << "White balls are: ";
	for (int i = 0; i < sizeOfWhitePicksArray; i++) {
		cout << whitePicksArray[i] << " ";
	}
}

//Selection sort
void sortWhitePicks(int array[], int size)
{

	int minIndex, minValue;


	for (int start = 0; start < (size - 1); start++)
	{

		minIndex = start;
		minValue = array[start];

		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}

		swap(array[minIndex], array[start]);
	}
}


void redballFunction() {
	int randRed = (rand() % REDBALLS) + 1;
	cout << "Power ball is: " << randRed << endl;
}


