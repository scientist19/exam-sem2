#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>

#include "mainmenu.h"
#include "form.h"

class Controller : public QWidget
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = nullptr);

signals:

public slots:
    void slotCreateForm();

private:
    MainMenu* mainMenu;
    Form* form;
};

#endif // CONTROLLER_H
