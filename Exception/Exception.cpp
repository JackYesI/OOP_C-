#include "Exception.h"
#include <vector>
#include <conio.h>

class User_Account
{
    std::string password = "None";
    std::string login = "None";
public:
    User_Account(const std::string& password, const std::string& login)
    {
        try
        {
            setPassword(password);
            setLogin(login);
        }
        catch (const WrongPasswordLengthException& ex)
        {
            ex.what();
            
        }
        catch (const FormatPasswordException& exc)
        {
            exc.what();
            
        }
        catch (...)
        {
            std::cout << "Error" << std::endl;
        }
        
    }
    std::string getLogin() const
    {
        return this->login;
    }
    std::string getPassword() const
    {
        return this->password;
    }
    void setPassword(const std::string& password)
    {
        if (password.length() < 7)
            throw WrongPasswordLengthException();
        else if (!(cheakPasswordNum(password) and cheakPasswordChar(password) and cheakPasswordBigChar(password)))
        {
            throw FormatPasswordException();
        }
        this->password = password;
        std::cout << "Password set\n";
    }
private:
    void setLogin(const std::string& login)
    {
        this->login = login;
    }
    bool cheakPasswordNum(const std::string& password) const
    {
        for (size_t i = 0; i < password.length(); i++)
        {
            if (48 <= static_cast<int>(password[i]) and static_cast<int>(password[i]) <= 57)
                return true;
        }
        return false;
    }
    bool cheakPasswordChar(const std::string& password) const
    {
        for (size_t i = 0; i < password.length(); i++)
        {
            if (97 <= static_cast<int>(password[i]) and static_cast<int>(password[i]) <= 122)
                return true;
        }
        return false;
    }
    bool cheakPasswordBigChar(const std::string& password) const
    {
        for (size_t i = 0; i < password.length(); i++)
        {
            if (65 <= static_cast<int>(password[i]) and static_cast<int>(password[i]) <= 90)
                return true;
        }
        return false;
    }
};

class SocialNetwork
{
    std::vector<User_Account> accounts;
public:
    SocialNetwork() = default;
    SocialNetwork(User_Account& acc)
    {
        accounts.push_back(acc);
    }
    void registr(const std::string& password, const std::string& login)
    {
        User_Account user(password, login);
        if (user.getPassword() == "None") return;
        for (auto& u : accounts)
        {
            if (u.getLogin() == login)
                throw ExistLogginException();
        }
        accounts.push_back(user);
        std::cout << "you are registr\n";
    }
    void login() const
    {
        std::string login, password;
        std::cout << "Enter login :: ";
        std::cin >> login;
        for (auto& u : accounts)
        {
            if (u.getLogin() == login)
            {
                std::cout << "Enter password :: ";
                std::cin >> password;
                if (u.getPassword() == password)
                {
                    std::cout << "you are login\n";
                    return;
                }
                else
                {
                    throw InvalidPasswordException();
                }
            }
        }
        throw InvalidLoginException();
    }
    void changePassword()
    {
        std::string login, password;
        std::cout << "Enter login :: ";
        std::cin >> login;
        for (auto& u : accounts)
        {
            if (u.getLogin() == login)
            {
                std::cout << "Enter password :: ";
                std::cin >> password;
                try
                {
                    u.setPassword(password);
                }
                catch (const WrongPasswordLengthException& ex)
                {
                    ex.what();
                    std::cout << "change password again :: \n";
                    
                }
                catch (const FormatPasswordException& ex)
                {
                    ex.what();
                    std::cout << "change password again :: \n";
                    
                }
                catch (...)
                {
                    std::cout << "Error" << std::endl;
                }
                return;
            }
        }
        throw InvalidLoginException();
    }
    void make()
    {
        std::cout << "\t q - registration;\t w - login;\t e - change Password;\t esc - exit;\n";
        char s;
        do {
            s = _getch();
            if (s == 113)
            {
                try
                {
                    std::string login, password;
                    std::cout << "Enter login :: ";
                    std::cin >> login;
                    std::cout << "Enter password :: ";
                    std::cin >> password;
                    this->registr(password, login);
                }
                catch (const ExistLogginException& ex)
                {
                    ex.what();
                    
                    std::cout << "Try set registr again!\n";
                    
                }
            }
            else if (s == 119)
            {
                try
                {
                    login();
                }
                catch (const InvalidLoginException& ex)
                {
                    ex.what();
                    std::cout << "Try login again\n";
                    
                }
                catch (const InvalidPasswordException& ex)
                {
                    ex.what();
                    std::cout << "Try login again\n";
                    
                }
            }
            else if (s == 101)
            {
                try
                {
                    changePassword();
                }
                catch (const InvalidLoginException& ex)
                {
                    ex.what();
                    std::cout << "Try change password again\n";
                }
            }
        } while (s != 27);
    }
};

int main()
{
    /*User_Account ua("den", "edaaa");*/

    SocialNetwork sn;
    sn.make();
    
}


