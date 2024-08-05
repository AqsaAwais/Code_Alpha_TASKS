#include <iostream>
#include <string>

using namespace std;

class User {
public:
    string name;
    int score;

    User() : name(""), score(0) {}
    User(string n) : name(n), score(0) {}
};

class Question {
public:
    string questionText;
    string options[4];
    int correctAnswer;

    Question() : questionText(""), correctAnswer(0) {}
    Question(string q, string opts[4], int ans) : questionText(q), correctAnswer(ans) {
        for (int i = 0; i < 4; ++i) {
            options[i] = opts[i];
        }
    }
};

class QuizGame {
private:
    Question* questions;
    User* users;
    int questionCount;
    int userCount;
    int maxQuestions;
    int maxUsers;

public:
    QuizGame(int mq, int mu) : questionCount(0), userCount(0), maxQuestions(mq), maxUsers(mu) {
        questions = new Question[maxQuestions];
        users = new User[maxUsers];
    }

    ~QuizGame() {
        delete[] questions;
        delete[] users;
    }

    void addQuestion(Question q) {
        if (questionCount < maxQuestions) {
            questions[questionCount++] = q;
        }
        else {
            cout << "Max questions reached!" << endl;
        }
    }

    void registerUser(string name) {
        if (userCount < maxUsers) {
            users[userCount++] = User(name);
        }
        else {
            cout << "Max users reached!" << endl;
        }
    }

    User* findUser(string userName) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].name == userName) {
                return &users[i];
            }
        }
        return nullptr;
    }

    void startQuiz(string userName) {
        User* user = findUser(userName);
        if (!user) {
            cout << "User not found! Please register first." << endl;
            return;
        }

        for (int i = 0; i < questionCount; ++i) {
            cout << questions[i].questionText << endl;
            for (int j = 0; j < 4; ++j) {
                cout << j + 1 << ". " << questions[i].options[j] << endl;
            }

            int answer;
            cout << "Your answer: ";
            cin >> answer;

            if (answer == questions[i].correctAnswer) {
                user->score++;
            }
        }

        cout << "Quiz finished!" << endl;
        cout << "Score: " << user->score << "/" << questionCount << endl;

        for (int i = 0; i < questionCount; ++i) {
            cout << "Question: " << questions[i].questionText << endl;
            cout << "Correct Answer: " << questions[i].options[questions[i].correctAnswer - 1] << endl;
        }
    }
};

int main() {
    int maxQuestions = 5;
    int maxUsers = 10;
    QuizGame game(maxQuestions, maxUsers);

    // Sample questions
    string options1[4] = { "Paris", "London", "Berlin", "Madrid" };
    game.addQuestion(Question("What is the capital of France?", options1, 1));

    string options2[4] = { "Earth", "Mars", "Jupiter", "Venus" };
    game.addQuestion(Question("Which planet is known as the Red Planet?", options2, 2));

    string options3[4] = { "1", "2", "3", "4" };
    game.addQuestion(Question("How many continents are there?", options3, 3));

    string options4[4] = { "China", "India", "USA", "Brazil" };
    game.addQuestion(Question("Which country has the largest population?", options4, 2));

    string options5[4] = { "Python", "C++", "Java", "JavaScript" };
    game.addQuestion(Question("Which programming language is known for its use in web development?", options5, 4));

    cout << " -----------------------------------------------------------------------------------------" << endl;
    cout << "|                                                                                         |" << endl;
    cout << "|                                                                                         |" << endl;
    cout << "|                                                                                         |" << endl;
    cout << "|                                   ONLINE QUIZ GAME                                      |" << endl;
    cout << "|                                                                                         |" << endl;
    cout << "|                                                                                         |" << endl;
    cout << "|                                                                                         |" << endl;
    cout << " -----------------------------------------------------------------------------------------" << endl;
    // User registration
    string userName;
    cout << "Enter your name to register: ";
    cin >> userName;
    game.registerUser(userName);

    // Start quiz
    game.startQuiz(userName);

    return 0;
}
