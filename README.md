Rock–Paper–Scissors Game 🎮

A simple C++ console-based implementation of the classic Rock–Paper–Scissors game.
The player competes against the computer for a number of rounds, and the game tracks wins, draws, and the overall winner.

🚀 Features

Play 1 to 10 rounds against the computer.

Choices:

1: Stone 🪨

2: Paper 📄

3: Scissors ✂️

Automatic computer choice using random number generation.

Round results printed after each game.

Colored output:

🟢 Green → Player wins.

🔴 Red (with beep sound) → Computer wins.

🟡 Yellow → Draw.

Final game summary with total scores.

Option to play again after finishing a game.

🛠️ Tech Stack

Language: C++ (C++11 or later recommended).

Platform: Console application (Windows; uses system("cls") and system("color")).

Randomization: rand() seeded with current time.

📂 Project Structure
├── main.cpp        # Source code
├── README.md       # Project documentation

▶️ How to Run

Clone the repository:

git clone https://github.com/your-username/rock-paper-scissors-cpp.git
cd rock-paper-scissors-cpp


Compile the code:

g++ main.cpp -o rps


Run the game:

./rps


⚠️ On Windows, compile using MinGW or MSVC.

🎯 Example Gameplay
How Many Rounds 1 to 10 ?
3

Round [1] begins:
Your choice: [1]:Stone, [2]:Paper, [3]:Scissors 1
Player Choice  : Stone
Computer Choice: Scissors
Round Winner   : Player


Final Results:

Game Rounds        : 3
Player won times   : 2
Computer won times : 0
Winner             : Player

📌 Future Improvements

Support multiplayer (Player vs Player).

Cross-platform compatibility (remove Windows system() dependencies).

GUI version with graphics.

<img width="1913" height="1069" alt="image" src="https://github.com/user-attachments/assets/0852418d-d512-4fc4-ac36-dd8ee28a0905" />
<img width="1919" height="1078" alt="image" src="https://github.com/user-attachments/assets/bab4a0f8-51f1-4ec4-8703-1f9ef206c98f" />
<img width="1832" height="994" alt="image" src="https://github.com/user-attachments/assets/bd7f1abc-2e16-4f7a-ae0e-5f1120103644" />

