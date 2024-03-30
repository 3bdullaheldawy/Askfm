#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define dd double

using namespace std;

struct user {
    int id;
    string password;
};

struct question {
    int id;
    int from;
    int to;
    string text;
};

struct answer {
    int id;
    int from;
    int to;
    int q_id;
    string text;
};

void sign_up();
bool login();

fstream u_file("Users.txt");
fstream q_file("Questions.txt");
fstream a_file("Answers.txt");

vector<user>u;
vector<question>q;
vector<answer>a;

class User {
protected:
    user x;
public:
    void add_user(user y) {
        ofstream u_file("Users.txt", ios::app);
        if (u_file.is_open()) {
            x.id = y.id; u_file << x.id << " ";
            x.password = y.id; u_file << x.password << endl;
            u.push_back(x);
            u_file.close();
        }
        else {
            cout << "Error";
        }
    }
    void user_file() {
        ifstream u_file("Users.txt");
        if (u_file.is_open()) {
            user z;
            while (u_file >> z.id ) {
                a_file.ignore();
                getline(u_file, z.password);
                u.push_back(z);
            }
            a_file.close();
        }
        else {
            cout << "Error";
        }
    }
};

class Question {
protected:
    question x;
public:
    void add_question(question y) {
        ofstream q_file("Questions.txt", ios::app);
        if (q_file.is_open()) {
            x.id = y.id; q_file << x.id << " ";
            x.from = y.from; q_file << x.from << " ";
            x.to = y.to; q_file << x.to << " ";
            x.text = y.text; q_file << x.text << endl;
            q.push_back(x);
            q_file.close();
        }
        else {
            cout << "Error";
        }
    }
    void question_file() {
        ifstream q_file("Questions.txt");
        if (q_file.is_open()) {
            question z;
            while (q_file >> z.id >> z.from >> z.to) {
                q_file.ignore();
                getline(q_file, z.text);
                q.push_back(z);
            }
            q_file.close();
        }
        else {
            cout << "Error";
        }
    }
};

class Answer{
protected:
    answer x;
public:
    void add_answer(answer y) {
        ofstream a_file("Answers.txt", ios::app);
        if (a_file.is_open()) {
            x.q_id = y.q_id; a_file << x.q_id << " ";
            x.id = y.id; a_file << x.id << " ";
            x.from = y.from; a_file << x.from << " ";
            x.to = y.to; a_file << x.to << " ";
            x.text = y.text; a_file << x.text << endl;
            a.push_back(x);
            a_file.close();
        }
        else {
            cout << "Error";
        }
    }
    void answer_file() {
        ifstream a_file("Answers.txt");
        if (a_file.is_open()) {
            answer z;
            while (a_file >> z.q_id >> z.id >> z.from >> z.to) {
                a_file.ignore();
                getline(a_file, z.text);
                a.push_back(z);
            }
            a_file.close();
        }
        else {
            cout << "Error";
        }
    }
};

void display_questions();

void display_answers();

int main()
{
    IOS;
    User U;
    Question Q;
    Answer A;
    cout << "Sign up Press 1\n" << "Login press 2\n";
    int x; cin >> x;
    if (x == 1) {
        cout << "Sign up\n"; sign_up();
    }
    else if (x == 2) {
        cout << "Login\n"; login();
    }
    else {
        cout << "Invalid number\n";
    }
    cout << "Show questions press 1\n" << "Answers press 2\n";
    int y; cin >> y;
    if (y == 1) {
        display_questions();
    }
    else if (y == 2) {
        display_answers();
    }
    else {
        cout << "Invalid number\n";
    }
    return 0;
}

void sign_up() {
    user x;
    x.id++;
    cin >> x.password;
    u_file << x.id << " " << x.password << endl;
}

bool login() {
    user x;
    cin >> x.id >> x.password;
    for (auto u1 : u) {
        if ((x.id == u1.id) && (x.password == u1.password)) {
            return true;
        }
    }
}

void display_answers() {
    while (1) {
        question q1;
        cin >> q1.from;
        for (int i = 0; i < q.size(); i++) {
            if (q1.id == q[i].id) {
                cout << q[i].text << " ?\n";
                for (int j = 0; j < a.size(); j++) {
                    if (q[i].id == a[j].q_id) {
                        cout << "Answer of Q : " << q[i].id << endl
                            << "Answer_id : " << a[j].id << endl
                            << "Answer : " << a[j].text << endl
                            << "Answer from : " << a[j].from << endl;
                    }
                    else {
                        cout << "No Answer\n";
                    }
                }
            }
        }
    }
}

void display_questions() {
    question q1;
    cout << "Questions :\n";
    int k = 1;
    for (int i = 0; i < q.size(); i++) {
        cout << k << " - " << q1.text << endl
            << "ID : " << q1.id << endl
            << "From : " << q1.from << endl
            << "To : " << q1.to << endl;
    }
} 