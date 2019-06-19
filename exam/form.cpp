#include "form.h"
#include "ui_form.h"

#include "official.h"
#include "balancedTree/balancedtree.h"
#include "balancedTree/Splay/SplayTree.h"

Form::Form(EntityEnum entityType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    if (entityType == BalancedTreeType) entity = new SplayTree<QString, Official>();
}

Form::~Form()
{
    delete ui;
}
