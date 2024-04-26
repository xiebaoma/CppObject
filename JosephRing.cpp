#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <random>  
#include <ctime>  
#include <cstdlib>
#include <regex>
#include <cctype>
using namespace std;

void bubblesort(vector<int>& rank)
{
    int n = rank.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp;
            if (rank[j] < rank[j + 1])
            {
                temp = rank[j];
                rank[j] = rank[j + 1];
                rank[j + 1] = temp;
            }
        }
    }
}       //冒泡排序算法

class Player
{
private:
    const string name;
    string phone;
    string email;
    const string I_card;
    const string password;
public:
    const string player_id;
    int score;
    Player(string game_id, string name_string,
        string phone_string, string email_string,
        string idcard, string password_string,
        int get_score = 0)
        :
        player_id(game_id),
        name(name_string),
        phone(phone_string),
        email(email_string),
        I_card(idcard),
        password(password_string),
        score(get_score) {};
    string getID() const
    {
        return player_id;
    }   //需要的时候返回用户账号，保证不可修改性
    string getPassword() const
    {
        return password;
    }   //需要的时候返回密码，保证不可修改性
    string getName() const
    {
        return name;
    }   //需要的时候返回用户名字，保证不可修改性
    void personal_info();   //查看个人信息
    void modifyinfo();  //修改个人电话或者邮箱
};

void Player::personal_info()
{
    cout << "Account's Id is:" << " " << player_id << endl;
    cout << "Account's name is:" << " " << name << endl;
    cout << "Account's phone number is:" << " " << phone << endl;
    cout << "Account's email is:" << " " << email << endl;
    cout << "Your Identity Card is:" << " " << I_card << endl;
    //cout << "Account's password is:" << " " << password << endl;
    cout << "Now your score is:" << " " << score << endl;
    cout << "press any key to continue..." << endl;
    system("pause");
    system("cls");
}   //功能2（查看个人信息）的实现

void Player::modifyinfo()
{
    string answer;
    string new_phone;
    string new_email;
    cout << "You can only modify the phone or email.\n";
    cout << "Your phone is " << phone << ", " << "would you like to modify it? [Y/N]\n";
    cin >> answer;
    if (answer == "Y")
    {
        while (true)
        {
            cout << "Please enter phone number:" << endl;
            cin >> new_phone;
            bool valid = true;

            for (char c : new_phone)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                break;
            else
                cout << "Invalid input. Please enter a string containing only digits." << endl;
        }
        phone = new_phone;
        cout << "The modification is successful!\n" << endl;
    }
    else if (answer == "N")
        answer = "None";
    cout << "Your email is " << email << ", " << "would you like to modify it? [Y/N]\n";
    cin >> answer;
    if (answer == "Y")
    {
        regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

        while (true)
        {
            cout << "Please enter your email address:" << endl;
            cin >> new_email;

            if (regex_match(new_email, email_regex))
                break;
            else {
                cout << "Invalid email address. Please enter a valid email address." << endl;
            }
        }
        email = new_email;
        cout << "The modification is successful!\n" << endl;
    }
    else if (answer == "N")
        answer = "None";
    cout << "press any key to continue..." << endl;
    system("pause");
    system("cls");
}   //功能3（修改个人指定信息）的实现
struct ListNode
{
    Player data;
    ListNode* next;
    ListNode(Player player) :data(player), next(nullptr) {}
};

class Joseph
{
    friend class Player;
private:
    ListNode* head;
    string current_player_id;
    void add_player(string game_id, string name_string, string phone_string, string email_string, string idcard, string password_string, int score);
public:
    bool log_condition;
    Joseph()
    {
        head = nullptr;
        log_condition = false;
    }
    ListNode* find_player(string player_id);
    void interface_menu();
    //游戏启动器初始界面菜单
    void account_menu();
    //账户登陆后二次启动菜单
    void account_register();
    //账户注册
    int account_access();
    //账户登录及权限
    bool ID_check(string game_id);
    //检查账户是否重复
    void game_start();
    //启动游戏
    void easy_pattern(int n);
    //启动简单游戏模式
    void medium_pattern(int n);
    //启动中等游戏模式
    void delete_account(ListNode* flag);
    //删除账户
    void browse_account();
    //浏览所有人账户及信息
    void find_info();
    //查找特定用户信息
/*void set_challenge();*/
};

bool Joseph::ID_check(string game_id)
{
    bool flag = false;
    ListNode* repeat_finding = head;
    while (repeat_finding)
    {
        if (repeat_finding->data.player_id == game_id)
        {
            flag = true;
            break;
        }
        repeat_finding = repeat_finding->next;
    }
    return flag;
}

ListNode* Joseph::find_player(string player_id)
{
    return nullptr;
}

void Joseph::interface_menu()
{
    cout << "===== Joseph Game Simulator =====" << endl;
    cout << "1. Sign Up.\n";
    cout << "2. Sign In.\n";
    cout << "3. Quit.\n";
    cout << "Please enter your choice:\n";
}

void Joseph::account_register()
{
    cout << "How many accounts would you like to have?\n";
    int number = 0;
    int length = 6;   //密码串长度为6
    char ch_range[] =
    {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z',
        '@', '$', '%', '&', '*', '#'
    };  //密码串字符取模
    srand(time(NULL));
    cin >> number;
    cout << "press any key to continue..." << endl;
    system("pause");
    system("cls");
    while (number <= 0 || cin.fail())
    {
        cout << "Wrong signal! Please input again!\n";
        cin.clear(); // 非法输入处理
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> number;
    }
    string game_id, name_string, phone_string, email_string, idcard, password_string;
    int score = 0;
    for (int i = 0; i < number; i++)
    {
        cout << endl;

        while (true)
        {
            cout << "Please enter game id:" << endl;
            cin >> game_id;
            bool valid = true;
            for (char c : game_id)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter a string containing only digits." << endl;
            }
        }
        while (ID_check(game_id))
        {
            cout << "The account has been created, use another name please.\n";
            cin >> game_id;
        }

        while (true)
        {
            cout << "Please enter your name:" << endl;
            cin >> name_string;
            bool valid = true;

            for (char c : name_string)
            {
                if (!isalpha(c))
                {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter a string containing only alphabetic characters." << endl;
            }
        }

        while (true)
        {
            cout << "Please enter phone number:" << endl;
            cin >> phone_string;
            bool valid = true;

            for (char c : phone_string)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter a string containing only digits." << endl;
            }
        }


        regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

        while (true)
        {
            cout << "Please enter your email address:" << endl;
            cin >> email_string;

            if (regex_match(email_string, email_regex)) {
                break;
            }
            else {
                cout << "Invalid email address. Please enter a valid email address." << endl;
            }
        }

        while (true)
        {
            cout << "Please enter ID_card:" << endl;
            cin >> idcard;
            bool valid = true;

            for (char c : idcard)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter a string containing only digits." << endl;
            }
        }

        for (int j = 0; j < length; j++)
        {
            int idx = rand() % 68;
            password_string.append(1, ch_range[idx]);
        }
        cout << "Please remember your password,It will only be displayed once:" << password_string << endl;
        add_player(game_id, name_string, phone_string, email_string, idcard, password_string, score);
        password_string.clear();
        cout << "press any key to continue..." << endl;
        system("pause");
        system("cls");
    }
}

void Joseph::add_player(string game_id, string name_string, string phone_string, string email_string, string idcard, string password_string, int score)
{
    Player newplayer(game_id, name_string, phone_string, email_string, idcard, password_string, score);
    ListNode* newnode = new ListNode(newplayer);
    if (!head)
    {
        head = newnode;
        head->next = nullptr;
    }
    else
    {
        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = nullptr;
    }
    cout << "Your account/accounts has/have been created!\nHave fun!\n";
    cout << endl;
}

int Joseph::account_access()
{
    int nextchoice;
    int choice = 1;
    bool flag = false;
    bool ingame = true;
    string entered_id;
    cout << "Please enter you id:\n";
    cin >> entered_id;
    ListNode* current = head;
    while (current)
    {
        if (current->data.getID() == entered_id)
        {
            flag = true;
            break;
        }
        else {
            current = current->next;
        }
    }
    if (flag) {
        system("cls");
        cout << "Find your account.\n";
    }
    else {
        ingame = false;
        cout << "----------------------------------------------------" << endl;
        cout << "Your account doesn't existed, please come back to sign up first.\n";
    }
    while (ingame)
    {
        account_menu();
        cin >> nextchoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (nextchoice == 1)
            current->data.personal_info();
        if (nextchoice == 2)
            current->data.modifyinfo();
        if (nextchoice == 3)
            game_start();
        //ingame = false;
        if (nextchoice == 4)
            delete_account(current);
        if (nextchoice == 5)
            browse_account();
        if (nextchoice == 6)
            find_info();
        if (nextchoice == 7)
        {
            ingame = false;
            choice = 3;
        }
        /*if (nextchoice==8)*/
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
        {
            while (true)
            {
                cout << "Wrong signal! Please try it again!\n";
                cin >> nextchoice;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7)
                    break;
            }
        }
    }
    return choice;
}

void Joseph::account_menu()
{
    cout << "-----------------------" << endl;
    cout << "Please choose again!" << endl;
    cout << "1. Search my account.\n";
    cout << "2. Modify my account.\n";
    cout << "3. Start to play.\n";
    cout << "4. Delete my account.\n";
    cout << "5. Browse the ranking list.\n";
    cout << "6. Finding someone's account.\n";
    cout << "7. Exit the game" << endl;
    //cout << "7. Start to challenge.\n";
    cout << "-----------------------" << endl;
    cout << "Please enter your choice:\n";
}
void Joseph::easy_pattern(int n)
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head;

    int size = 1;
    current = head;
    while (current->next != head)
    {
        current = current->next;
        ++size;
    }

    if (n >= size)
    {
        cout << "Invalid value of n." << endl;
        return;
    }

    while (current->next != current)
    {
        for (int i = 1; i < n; ++i) {
            current = current->next;
        }

        ListNode* temp = current->next;
        current->next = temp->next;
        //cout << "Player " << temp->data.getID() << " is eliminated." << endl;
        delete temp;

        current = current->next;
    }

    cout << "Winner is " << current->data.getName() << endl;
    current->data.score++;
    cout << "Press any key to continue" << endl;
    system("pause");
    system("cls");
}


void Joseph::medium_pattern(int n) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // Convert the singly linked list to a circular linked list
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head;

    // Check if the list contains only one node
    if (head->next == head) {
        cout << "Winner is " << head->data.getID() << endl;
        return;
    }

    int k = n;
    char direction = 'r';

    // Check if k is valid
    if (k <= 0)
    {
        cout << "Invalid value of k." << endl;
        return;
    }

    // Traverse the list to find its length
    int listLength = 1;
    current = head;
    while (current->next != head)
    {
        current = current->next;
        listLength++;
    }

    // Check if k is greater than the length of the list
    if (k > listLength)
    {
        cout << "Value of k is greater than the number of players." << endl;
        return;
    }

    // Initialize current and pre pointers
    current = head;
    ListNode* pre = nullptr;

    // Loop through the list
    while (head->next != head)
    {
        // Find the (k-1)th node
        for (int i = 0; i < k - 1; i++)
        {
            pre = current;
            current = current->next;
        }

        // Modify direction
        if (current->data.getPassword() == "r") {
            direction = 'r';
        }
        else if (current->data.getPassword() == "l") {
            direction = 'l';
        }

        // Delete the kth node
        if (pre == nullptr) {
            head = current->next;
        }
        else {
            pre->next = current->next;
        }
        ListNode* temp = current;
        current = current->next;
        delete temp;

        // Move to the next node based on direction
        if (direction == 'r') {
            current = (pre == nullptr) ? head : pre->next;
        }
        else if (direction == 'l')
        {
            // Find the previous node of current starting from head
            pre = nullptr;
            ListNode* temp = head;
            while (temp->next != current) {
                temp = temp->next;
            }
            pre = temp;
            current = pre;
        }
        // Update head pointer
        head = current;
    }
    cout << "Winner is " << head->data.getID() << endl;
    cout << "Press any key to continue..." << endl;
    system("pause");
    system("cls");
}



void Joseph::game_start()
{
    char pattern_choice;
    bool isValidInput = false;
    cout << "Welcome to Joseph Ring!\n";
    cout << "Please choose the game level:\na. Easy.     b. Medium.   [a/b]\n";
    while (!isValidInput)
    {
        cin >> pattern_choice;

        if (tolower(pattern_choice) == 'a')
        {
            cout << "Please enter how many people report the count every other time:" << endl;
            int n;
            cin >> n;
            easy_pattern(n);
            isValidInput = true;
        }
        else if (tolower(pattern_choice) == 'b')
        {
            cout << "Please enter how many people report the count every other time:" << endl;
            int n;
            cin >> n;
            medium_pattern(n);
            isValidInput = true;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong! Please choose again!\n";
            cout << "Please choose the game level:\na. Easy.     b. Medium.   [a/b]\n";
        }
    }
}

void Joseph::delete_account(ListNode* flag)
{
    ListNode* current = head;
    ListNode* pre = nullptr;
    while (current != flag && current)
    {
        pre = current;
        current = current->next;
        if (current == flag) {
            break;
        }
    }
    ListNode* re = new ListNode(pre->data);
    delete current;
    cout << "Delete successful" << endl;
    cout << "press any key to continue" << endl;
    system("pause");
    system("cls");
}

void Joseph::browse_account()
{
    int total_number = 0;
    vector<int> rank_list;
    ListNode* current = head;
    while (current)
    {
        rank_list.push_back(current->data.score);
        current = current->next;
    }
    bubblesort(rank_list);
    total_number = rank_list.size();
    cout << "The number of the player is " << total_number << ".\n";
    for (int i = 0; i < total_number; i++)
    {
        cout << "The score rank list is:\n";
        cout << rank_list[i] << endl;
    }
    cout << "press any key to continue..." << endl;
    system("pause");
    system("cls");
}

void Joseph::find_info()
{
    bool flag = false;
    string entered_id;
    int entered_score;
    int number;
    cout << "Please choose the way you'd like to use to find someone's account:\n";
    cout << "1. Account's ID\n2. Account's score\n";
    cin >> number;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (number != 1 && number != 2)
    {
        cout << "Wrong!\nPlease input again!";
        cin >> number;
    }
    if (number == 1)
    {
        cout << "Please enter the id you want:\n";
        cin >> entered_id;
    }
    else if (number == 2)
    {
        cout << "Please enter the score you want:\n";
        cin >> entered_score;
    }
    ListNode* current = head;
    while (current)
    {
        if (number == 1)
        {
            if (current->data.player_id == entered_id)
            {
                flag = true;
                break;
            }
        }
        if (number == 2)
        {
            if (current->data.score == entered_score)
            {
                flag = true;
                break;
            }
        }
        current = current->next;
    }
    if (flag) {
        cout << "Founded...\nThe account's ID is " << current->data.player_id << ".\n" << "It has got " << current->data.score << " score(s).\n";
    }
    else {
        cout << "The account doesn't existed.\n";
    }
    cout << "press any key to continue..." << endl;
    system("pause");
    system("cls");
}

void Outgame()
{
    cout << "Exiting program...If needed, please relogin!\n";
    cout << "Bye!\n";
}

int main()
{
    string game_id, name_string, phone_string, email_string, idcard, password_string;
    int score = 0;
    int choice;
    int signal;
    Joseph interface;
    interface.interface_menu();
    bool isrunning = true;  //布尔类型运行变量，用于控制中止
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (isrunning)
    {
        if (choice == 1)
        {
            interface.account_register();
            cout << "Which choice are you going to? [2/3].\n";
            cout << "2. Sign In.\n";
            cout << "3. Quit.\n";
            cin >> signal;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (signal == 2) {
                choice = (interface.account_access());
            }
            else if (signal == 3)
            {
                Outgame();
                isrunning = false;
            }
            else if (cin.fail() || (signal != 2) && (signal != 3)) {
                cout << "Wrong, try it again!\n";
            }
        }
        else if (choice == 2)
        {
            choice = interface.account_access();
            if (choice == 1) {
                interface.log_condition = true;
            }
            if (!interface.log_condition)
            {
                cout << "Which choice are you going to?     [2/3].\n";
                cout << "2. Sign In.\n";
                cout << "3. Quit.\n";
                cin >> signal;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (signal == 2) {
                    interface.account_access();
                }
                else if (signal == 3)
                {
                    Outgame();
                    isrunning = false;
                }
                else if (cin.fail() || (signal != 2) && (signal != 3)) {
                    cout << "Wrong, try it again!\n";
                }
            }
            else
            {
                interface.account_register();
                choice = 2;
            }
        }

        else if (choice == 3)
        {
            Outgame();
            isrunning = false;
        }
        else
        {
            while (true)
            {
                cout << "Wrong signal, Please try again!\n";
                cin >> choice;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (choice == 1 || choice == 2 || choice == 3)
                    break;
            }
        }
    }
    return 0;
}