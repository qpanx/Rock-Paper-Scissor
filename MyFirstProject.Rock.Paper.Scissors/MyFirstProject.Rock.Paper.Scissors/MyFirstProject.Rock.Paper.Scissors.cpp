#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3};
enum enWinner {Player = 1, Computer = 2, Draw =3};

struct stRoundInfo {
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults {
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Player", "Computer" , "Draw" };
    return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice) {
        return enWinner::Draw;
    }

    switch (RoundInfo.PlayerChoice) {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
            if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            {
                return enWinner::Computer;
            }break;
    }
    return enWinner::Player;
    
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes) {
    if (PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else if (ComputerWinTimes > PlayerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short PlayerWinTimes, short GomputerWinTimes, short DrawTimes) {
    stGameResults GameResults;

    GameResults.GameRounds = GameRounds;
    GameResults.PlayerWinTimes = PlayerWinTimes;
    GameResults.ComputerWinTimes = GomputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, GomputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}

string ChoiceName(enGameChoice Choice) {
    string arrGameChoices[3] = { "Stone", "Paper" ,"Scissors" };

    return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner) {
    switch (Winner) {
    case enWinner::Player:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");
        break;
    }
    
}

void PrintRoundResults(stRoundInfo RoundInfo) {

    cout << "\n_____________Round [" << RoundInfo.RoundNumber << "] _________\n\n";
    cout << "Player Choice  : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : " << RoundInfo.WinnerName << "] \n";
    cout << "____________________________________________\n" << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}

enGameChoice ReadPlayerChoice() {
    short Choice = 1;

    do {
        cout << "\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds) {
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player) {
            PlayerWinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer)
        {
            ComputerWinTimes++;
        }
        else {
            DrawTimes++;
        }
        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

short ReadHowManyRounds() {
    short GameRounds = 1;

    do {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    
    return GameRounds;
    
}

string Tabs(short NumberOfTabs) {
    string t = "";

    for (int i = 1; i < NumberOfTabs; i++) {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void ShowGameOverScreen() {

    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout << Tabs(2) << "                     +++ G A M E - O V E R +++\n            ";
    cout << Tabs(2) << "__________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults) {

    cout << Tabs(2) << "__________________ [Game Results] ________________\n\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player won times   : " << GameResults.PlayerWinTimes << endl;
    cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Winner        : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "__________________________________________________\n\n";

    SetWinnerScreenColor(GameResults.GameWinner);
}

void ResetScreen() {
    system("cls");
    system("color 0F");
}

void StartGame() {
    char PlayAgain = 'Y';

    do {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);
        
        cout << endl << Tabs(3) << "Do you want to play again ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}