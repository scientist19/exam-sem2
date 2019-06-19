#include "form.h"
#include "ui_form.h"

#include "official.h"
#include "balancedTree/balancedtree.h"
#include "balancedTree/Splay/SplayTree.h"

#include <QDebug>

Form::Form(EntityEnum entityType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    ui->console->setText(">");
    QTextCursor cursor = ui->console->textCursor();
    cursor.setPosition(1);
    ui->console->setTextCursor(cursor);

    if (entityType == BalancedTreeType) entity = new SplayTree<QString, Official>();
    ui->helpMe->setText(entity->help());
}

Form::~Form()
{
    delete ui;
}

void Form::displayEntity()
{
    ui->display->setText(entity->print());
}

void Form::slotParseConsole()
{
    QString text = ui->console->toPlainText();

    QString debug = QString("in slotParseConsole " + QString(text[text.length() - 1]));
    qDebug(debug.toStdString().c_str());
    if (text[text.length() - 1] != '\n') return;

    QStringList commands = text.split('\n');
    QString command = commands[commands.length()-2];

    if (command.length() == 0 || command[0] != ">") return;
    command.remove(0,1);
    QString result = entity->parse(command);
    text += result + '>';
    ui->console->setText(text);

    QTextCursor cursor = ui->console->textCursor();
    cursor.setPosition(text.length());
    ui->console->setTextCursor(cursor);

    displayEntity();
}
