#include "controller.h"

#include "ui_mainmenu.h"
#include "ui_form.h"


Controller::Controller(QWidget *parent) : QWidget(parent)
{
    mainMenu = new MainMenu();
    mainMenu->show();
    connect(mainMenu->ui->startButton, SIGNAL(clicked()), this, SLOT(slotCreateForm()));
}

void Controller::slotCreateForm()
{
    form = new Form(BalancedTreeType);
    form->show();
    mainMenu->hide();
}
