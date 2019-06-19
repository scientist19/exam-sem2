#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

class Controller;

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private:
    Ui::MainMenu *ui;

    friend Controller;
};

#endif // MAINMENU_H
