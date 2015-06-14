#include "AboutWindow.h"
#include "ui_AboutWindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
}

void AboutWindow::on_okBtn_clicked(){
    this->close();
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
