#include "library.h"
#include "ui_library.h"
#include<QMessageBox>

Library::Library(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Library)
{
    ui->setupUi(this);
}

Library::~Library()
{
    delete ui;
}

void Library::on_btnAddStart_clicked()
{
    QString str = ui->lineEdit->text();
            Nod *temp=nullptr;
            temp=new Nod;
            temp->Name=str;
            if (Start == nullptr) {
                        Start = temp;
                        Last = Start;
                        Last->NextAddress = nullptr;
                    }
                    else {
                        temp->NextAddress = Start;
                        Start = temp;
                    }
}

void Library::on_btnAddLast_clicked()
{
    QString str = ui->lineEdit->text();
            Nod *temp=nullptr;
            temp=new Nod;
            temp->Name=str;

        if (Start == nullptr) {
                    Start = temp;
                    Last = Start;
                    Last->NextAddress = nullptr;
                }
                else {
                    Last->NextAddress = temp;
                    temp->NextAddress=nullptr;
                    Last = temp;
                }
}

void Library::on_btnDeleteStart_clicked()
{
    QMessageBox msgBox;
        if (Start == nullptr)
        {
            msgBox.setText("The list is empty!");
             msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
        }
         else
             {
                Nod *x = Start;
                Start = x->NextAddress;
                delete x;
                x = nullptr;
                msgBox.setText("Delete was successfully!");
                msgBox.setIcon(QMessageBox::Information);
                msgBox.exec();
             }
}

void Library::on_btnDeleteLast_clicked()
{
    QMessageBox msgBox;
        if (Start == nullptr)
        {
            msgBox.setText("The list is empty!");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
        }
         else
            if(Start==Last)
            {
              Start=Last=nullptr;
              msgBox.setText("Delete was successfully!");
              msgBox.setIcon(QMessageBox::Information);
              msgBox.exec();
            }
            else
            {
                Nod *Previos = Start;
                for (; Previos->NextAddress != Last; Previos = Previos->NextAddress);
                Last = Previos;
                Last->NextAddress = nullptr;
                msgBox.setText("Delete was successfully!");
                msgBox.setIcon(QMessageBox::Information);
                msgBox.exec();
            }
}

void Library::on_btnExit_clicked()
{
    this->close();
}

void Library::on_btnShowOfStart_clicked()
{
    QMessageBox msgBox;
       if (Start == nullptr){
            msgBox.setIcon(QMessageBox::Warning);
           msgBox.setText("The list is empty!");
            msgBox.exec();
       }
       else
           {
            msgBox.setIcon(QMessageBox::Information);
              Nod *p = Start;
              for (; p->NextAddress != nullptr; p = p->NextAddress){
                  msgBox.setText(p->Name);
                   msgBox.exec();
              }
              msgBox.setText(p->Name);
               msgBox.exec();
            }
}

void Library::on_btnShowOfLast_clicked()
{
    Nod *first=Start;
        Nod *end=Last;
        QMessageBox msgBox;
        if(!first)
        {
             msgBox.setIcon(QMessageBox::Warning);
             msgBox.setText("The list is empty!");
             msgBox.exec();
        }
        else
        {
            msgBox.setIcon(QMessageBox::Information);
            while(first != end)
            {
            for(;first->NextAddress !=end;first=first->NextAddress);
            msgBox.setText(end->Name);
            msgBox.exec();
            end=first;
            first=Start;
            }
            msgBox.setText(first->Name);
            msgBox.exec();
        }
}

void Library::on_btnAddAfter_clicked()
{
    QMessageBox msgBox;
    if(Start==nullptr)
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("The list is empty");
        msgBox.exec();
    }
    else
        {
            Nod *New_Nod=new Nod;
            QString newstr=ui->lineEdit->text();
            QString str=ui->lineEdit_2->text();
            New_Nod->Name=newstr;
            Nod *p = Start;
            for (;  QString::compare(p->Name, str, Qt::CaseInsensitive) != 0; p = p->NextAddress);
            New_Nod->NextAddress = p->NextAddress;
            p->NextAddress = New_Nod;
              msgBox.setText("Add was successfully!");
              msgBox.setIcon(QMessageBox::Information);
              msgBox.exec();
        }
}

void Library::on_btnDeleteBefore_clicked()
{
    QMessageBox msgBox;
    if(Start==nullptr)
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("The list is empty");
        msgBox.exec();
    }
    else {
        QString str=ui->lineEdit_2->text();
        Nod *p = Start, *Pre, *PreDel;
        Pre = new Nod;
        PreDel = new Nod;
        for (int i = 1; (QString::compare(p->Name, str, Qt::CaseInsensitive)) != 0; p = p->NextAddress, i++)
         {
           if (i == 2) {
                 Pre = Start;
                  PreDel = p;
             }
               else {
                        Pre = Pre->NextAddress;
                        PreDel = p;
                    }
          }
           if (PreDel == Start)
             {
                 Start=p;
                 delete PreDel;
                 PreDel = nullptr;
                 msgBox.setText("Delete was successfully!");
                 msgBox.setIcon(QMessageBox::Information);
                 msgBox.exec();
              }
                else
                   {
                      Pre->NextAddress = p;
                      delete PreDel;
                      PreDel = nullptr;
                      msgBox.setText("Delete was successfully!");
                      msgBox.setIcon(QMessageBox::Information);
                      msgBox.exec();
                   }
    }

}
