/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 Lab_5
** Date: 02/06/2018
** Description: Menu class definition.
****************************************************/

#ifndef LAB_5_MENU_HPP
#define LAB_5_MENU_HPP

#include <iostream>
#include <string>
#include <vector>

class Menu {

    private:
        std::vector<std::string> menuItems;
        std::string promptText;

    public:
        Menu(std::vector<std::string> menuItems);
        Menu(std::string promptText, std::vector<std::string> menuItems);
        int showMenu();
        void setPromptText(std::string text);
        std::string getPromptText();
        void setMenuItems(std::vector<std::string> menuItems);
};


#endif //LAB_5_MENU_HPP
