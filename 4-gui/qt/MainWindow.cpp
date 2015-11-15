#include "MainWindow.h"

#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
    setWindowTitle("Example");

    QPushButton* button = new QPushButton("Press me");

    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    setCentralWidget(button);
}

void MainWindow::buttonClicked()
{
    QMessageBox::information(this, "Wow!", "Hello world!");
}
