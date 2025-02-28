#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

// Structures section
struct Race
{
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[20];
    char firstPlaceRaceCarColor[20];
};

struct RaceCar
{
    char driverName[20];
    char raceCarColor[20];
    int totalLapTime;
};

// Print functions section
void printIntro(void)
{
    printf("Welcome to our main event digital race fans!\n");
    printf("I hope everybody has their snacks because we are about to begin!\n");
};

void printCountDown(void)
{
    Sleep(3000);
    printf("Racers Ready! In...\n");
    Sleep(1000);
    printf("5\n");
    Sleep(1000);
    printf("4\n");
    Sleep(1000);
    printf("3\n");
    Sleep(1000);
    printf("2\n");
    Sleep(1000);
    printf("1\n");
    Sleep(1500);
    printf("Race!\n\n");
};

void printFirstPlaceAfterLap(struct Race race)
{
    Sleep(1500);
    printf("After lap number %d:\n", race.currentLap);
    printf("First Place Is: %s in the %s race car!\n\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
};

void printCongratulation(struct Race race)
{
    Sleep(1500);
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    Sleep(500);
    printf("It truly was a great race and everybody have a goodnight!\n");
};

// Logic functions section
int calculateTimeToCompleteLap(void)
{
    int speed = rand() % 3 + 1;
    int acceleration = rand() % 3 + 1;
    int nerves = rand() % 3 + 1;
    return speed + acceleration + nerves;
};

void updateRaceCar(struct RaceCar *raceCarPtr)
{
    raceCarPtr->totalLapTime += calculateTimeToCompleteLap();
};

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2)
{
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime)
    {
        strcpy(race->firstPlaceDriverName, raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
    }
    else
    {
        strcpy(race->firstPlaceDriverName, raceCar2->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
    }
};

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2)
{
    struct Race race = {5, 1, "", ""};
    for (int i = race.currentLap; i <= race.numberOfLaps; i++)
    {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        printFirstPlaceAfterLap(race);
        race.currentLap++;
    };
    printCongratulation(race);
};

int main()
{
    struct RaceCar raceCar1 = {"Burt", "Black"};
    struct RaceCar raceCar2 = {"Bert", "Blue"};
    srand(time(0));
    printIntro();
    printCountDown();
    startRace(&raceCar1, &raceCar2);
};