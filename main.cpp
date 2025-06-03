#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

class temp
{
    string username, email, password, re_check_password;
    fstream file;

public:
    void Log_In();
    void Sign_Up();
    void Forgotten_Password();
    void Update_password();
    void exit();
    string gethiddenpasswordinput();
};

int main()
{
    ofstream clearFile("logindata.txt", ios::out); // This clears the file
    clearFile.close();
    int choice;

    cout << "\n 1.) Sign Up ";
    cout << "\n 2.) Log In ";
    cout << "\n 3.) Forgot Password ";
    cout << "\n 4.) Update Password";
    cout << "\n 5.) Exit ";

    cout << "\n Enter your choice::-> ";
    cin >> choice;
    cout << endl;
    while (choice != 5)
    {
        if (choice == 1)
        {
            temp obj;
            obj.Sign_Up();
        }
        else if (choice == 2)
        {
            temp obj;
            obj.Log_In();
        }
        else if (choice == 3)
        {
            temp obj;
            obj.Forgotten_Password();
        }
        else if (choice == 4)
        {
            temp obj;
            obj.Update_password();
        }
        // else if (choice == 4)
        // {
        //     temp obj;
        //     obj.exit();
        // }
        else
        {
            cout << "Invalid Choice" << endl;
        }
        cout << "\n Enter other choice::-> ";
        cin >> choice;
        cout << endl;
    }
    if (choice == 5)
    {
        temp obj;
        obj.exit();
    }
}

void temp ::Sign_Up()
{

    cout << "------- SIGN UP --------" << endl;
    cout << endl;

    cout << "enter your username: ";
    cin >> username;
    cout << endl;
    bool exists = false;
    file.open("logindata.txt", ios::in);
    string unname, mail, pass;
    while (getline(file, unname, '*') &&
           getline(file, mail, '*') &&
           getline(file, pass, '\n'))
    {
        if (username == unname)
        {
            exists = true;
            break;
        }
    }
    file.close();
    if (exists)
    {
        cout << "Username already exists. Please try a different one." << endl;
        return;
    }

    cout << "enter your email address: ";
    cin >> email;
    cout << endl;
    bool exist = false;
    file.open("logindata.txt", ios::in);
    // string unname, mail, pass;
    while (getline(file, unname, '*') &&
           getline(file, mail, '*') &&
           getline(file, pass, '\n'))
    {
        if (email == mail)
        {
            exist = true;
            break;
        }
    }
    file.close();
    if (exist)
    {
        cout << "email already exists. Please try a different one." << endl;
        return;
    }
    cout << "enter a strong password: ";
    password = gethiddenpasswordinput();
    cout << endl;
    cout << "Enter password for Confirmation: ";
    re_check_password = gethiddenpasswordinput();
    cout << endl;
    if (password == re_check_password)
    {
        cout << "Successfully Sign UP..";
        cout << endl;
    }
    else
    {
        cout << "confirmational Password is not same as original Password";
        cout << endl;
    }
    fstream file;
    file.open("logindata.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << '\n';
    file.close();
}

void temp ::Log_In()
{
    cout << "------- LOG IN --------" << endl;
    cout << endl;
    string searchname, searchpassword;

    cout << "enter your username: ";
    cin >> searchname;
    cout << endl;
    cout << "enter Your password: ";
    searchpassword = gethiddenpasswordinput();
    cout << endl;
    file.open("logindata.txt", ios ::in);
    bool found = false;
    // string username, email, password;

    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password, '\n'))
    {
        if (searchname == username && searchpassword == password)
        {
            cout << "Your Account is Successfully Log In" << endl;
            cout << "Email: " << email << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Invalid username OR password" << endl;
    }
    file.close();
}

void temp ::Forgotten_Password()
{
    cout << "------- Forgotten_Password --------" << endl;
    cout << endl;
    string searchname, searchmail;

    cout << "Enter your username: ";
    cin >> searchname;
    cout << endl;
    cout << "enter your email address: ";
    cin >> searchmail;
    cout << endl;
    file.open("logindata.txt", ios::in);
    bool found = false;
    // string username, email, password;

    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password, '\n'))
    {
        if (searchname == username && searchmail == email)
        {
            cout << "Your Password is safe." << endl;
            cout << "password: " << password << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Invalid username OR mail" << endl;
    }
    file.close();
}

void temp ::Update_password()
{
    cout << "------- Update_Password --------" << endl;
    cout << endl;

    string searchname, searchpassword, new_password;

    cout << "Enter your username: ";
    cin >> searchname;
    cout << endl;
    cout << "enter your old password: ";
    searchpassword = gethiddenpasswordinput();
    cout << endl;
    file.open("logindata.txt", ios::in);
    ofstream tempfile("temp.txt");
    bool found = false;
    // string username, email, password;

    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password, '\n'))
    {
        if (searchname == username && searchpassword == password && !found)
        {

            cout << "enter your new password: ";
            new_password = gethiddenpasswordinput();
            cout << endl;
            cout << "Updated Successfully.." << endl;
            tempfile << username << "*" << email << "*" << new_password << '\n';
            found = true;
            // break;
        }
        else
        {
            tempfile << username << "*" << email << "*" << password << '\n';
        }
    }
    if (!found)
    {
        cout << "Invalid username OR mail" << endl;
    }
    file.close();
    tempfile.close();
    remove("logindata.txt");
    rename("temp.txt", "logindata.txt");
}

void temp ::exit()
{
    cout << "Successfully Exit ";
}

string temp ::gethiddenpasswordinput()
{
    string input = "";
    char ch;
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b')
        {
            if (!input.empty())
            {
                cout << "\b \b";
                input.pop_back();
            }
        }
        else
        {
            input.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;
    return input;
}