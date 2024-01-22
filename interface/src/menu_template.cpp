// #include "menu_template.h"

// Menu::Menu(std::shared_ptr<Menu> parent) : highlight(0), parent(parent) {
//     initscr();
//     noecho();
//     curs_set(FALSE);
//     keypad(stdscr, TRUE);
// }

// Menu::~Menu() {
//     endwin();
// }

// void Menu::addMenuItem(const std::string& item, std::function<void()> action) {
//     choices.push_back(item);
//     actions.push_back(action);
// }

// void Menu::run() {
//     while(1) {
//         for(int i = 0; i < choices.size(); i++) {
//             if(i == highlight)
//                 attron(A_REVERSE);
//             mvprintw(6+i, 6, choices[i].c_str());
//             attroff(A_REVERSE);
//         }
//         int choice = getch();

//         switch(choice) {
//             case KEY_UP:
//                 highlight--;
//                 if(highlight == -1)
//                     highlight = 0;
//                 break;
//             case KEY_DOWN:
//                 highlight++;
//                 if(highlight == choices.size())
//                     highlight = choices.size() - 1;
//                 break;
//             default:
//                 break;
//         }
//         if(choice == 10) { 
//             actions[highlight]();
//             break;
//         }
//     }
// }