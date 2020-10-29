#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{//Exit

    destroy();

}

void MainWindow::on_pushButton_clicked()
{
    //connect

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("ramki");

    if(db.open())
    {
        QMessageBox::information(this, "Connection", "Baza podłączona");
        QString name = ui->lineEdit->text();
        QString name1 = ui->lineEdit_2->text();


        QSqlQuery qry;
        qry.prepare("USE ramki");
        qry.prepare("CREATE TABLE IF NOT EXISTS tasks (task_id INT AUTO_INCREMENT,title VARCHAR(255) NOT NULL, start_date DATE, due_date DATE, priority TINYINT NOT NULL DEFAULT 3 ,description TEXT, PRIMARY KEY (task_id));");
        //qry.prepare("INSERT INTO zamiana (idzamiana) VALUES (imie Jego)");

        //qry.bindValue(":name", name);

        if(qry.exec())
        {
            QMessageBox::information(this, "Connection", "sukces");
        }
        else{
            QMessageBox::information(this, "Connection", "brak wpisu");
        }
    }
    else
    {
        QMessageBox::information(this, "Connection", "BRAK POLACZENIA");

    }





}

void MainWindow::on_pushButton_3_clicked()
{


}
