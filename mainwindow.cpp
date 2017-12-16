#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QTextEdit>
#include<QMdiSubWindow>
#include<QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage(tr("欢迎使用多文档编辑器"),2000);

    //永久信息
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.ihewro.com");
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mdiArea_destroyed()
{

}

void MainWindow::on_action_new_triggered()
{
    //新建文本编辑器部件

    QTextEdit *edit = new QTextEdit(this);
    QMdiSubWindow * child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle (tr("多文档编辑器子窗口"));
    child->show();

}

void MainWindow::on_action_showTool_triggered()
{
    ui->dockWidget->show();
}
