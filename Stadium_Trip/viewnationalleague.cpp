
#include "mainwindow.h"

void MainWindow::on_viewNationalLeagueBtn_clicked()
{
    int index;
    int row;
    int size = 0;
//    int column;
    QTableWidgetItem*   tableItem;
    QStringList         horizontalHeaderList;
    QStringList         verticalHeaderList;
//    QString             longestHeader;

    //Set the headers for each column
    horizontalHeaderList.append("Stadium Name");
    horizontalHeaderList.append("Team Name");
    horizontalHeaderList.append("Address");
    horizontalHeaderList.append("Phone Number");
    horizontalHeaderList.append("Date Opened");
    horizontalHeaderList.append("Seating Capacity");

    //The header for each row will be empty

    foreach(Stadium stadium, stadiumMap)
    {
        if(stadium.getLeague() == 'N')
            size ++;
    }
    for(index = 0; index < size; index++)
    {
        verticalHeaderList.append("");
    }

    ui->viewNationalLeagueTable->setColumnCount(6);
    ui->viewNationalLeagueTable->setRowCount(size);
    ui->viewNationalLeagueTable->setHorizontalHeaderLabels(horizontalHeaderList);
    ui->viewNationalLeagueTable->setVerticalHeaderLabels(verticalHeaderList);

//    longestHeader = "American or National League";

//    //For loop - Set column width
//    for(column = 0; column < 7; column++)
//    {
//        ui->viewMajorLeagueTable->setColumnWidth(column, longestHeader.size() * 6.5);
//    }

    //Set column width for columns
    ui->viewNationalLeagueTable->setColumnWidth(0, 180);
    ui->viewNationalLeagueTable->setColumnWidth(1, 200);
    ui->viewNationalLeagueTable->setColumnWidth(2, 280);
    ui->viewNationalLeagueTable->setColumnWidth(3, 120);
    ui->viewNationalLeagueTable->setColumnWidth(4, 120);
    ui->viewNationalLeagueTable->setColumnWidth(5, 250);

    //Set the # of rows for the table
    row = 0;
    foreach(Stadium stadium, stadiumMap)
    {
        if(stadium.getLeague() == 'N')
        {
            //Show stadium name
            //Dynamically create a "cell" of the table
            tableItem = new QTableWidgetItem();
            //Set stadium name to the tableItem
            tableItem->setText(stadium.getStadiumName());
            //Place the tableItem in the desired location in the table
            ui->viewNationalLeagueTable->setItem(row, 0, tableItem);

            //Show team name
            tableItem = new QTableWidgetItem();
            tableItem->setText(stadium.getTeamName());
            ui->viewNationalLeagueTable->setItem(row, 1, tableItem);

            //Show Street Address
            tableItem = new QTableWidgetItem();
            tableItem->setText(stadium.getAddress());
            ui->viewNationalLeagueTable->setItem(row, 2, tableItem);

            //Show Phone Number
            tableItem = new QTableWidgetItem();
            tableItem->setText(stadium.getPhoneNumber());
            ui->viewNationalLeagueTable->setItem(row, 3, tableItem);

            //Show DateOpened
            tableItem = new QTableWidgetItem();
            tableItem->setText(stadium.getDateOpened().toString());
            ui->viewNationalLeagueTable->setItem(row, 4, tableItem);

            //Show Seating Capacity
            tableItem = new QTableWidgetItem();
            tableItem->setText(stadium.getCapacity());
            ui->viewNationalLeagueTable->setItem(row, 5, tableItem);

            row++;

        }
    }

    ui->viewNATLeaguePage->show();
    ui->viewStadiumsPage->hide();
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->viewNATLeaguePage->hide();
    ui->viewStadiumsPage->show();
}
