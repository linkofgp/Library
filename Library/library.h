#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>

struct Nod{
    QString Name;
    Nod *NextAddress;
};

namespace Ui {
class Library;
}

class Library : public QMainWindow
{
    Q_OBJECT

public:
    explicit Library(QWidget *parent = nullptr);
    ~Library();

private slots:
    void on_btnAddStart_clicked();

    void on_btnAddLast_clicked();

    void on_btnDeleteStart_clicked();

    void on_btnDeleteLast_clicked();

    void on_btnExit_clicked();

    void on_btnShowOfStart_clicked();

    void on_btnShowOfLast_clicked();

    void on_btnAddAfter_clicked();

    void on_btnDeleteBefore_clicked();

private:
    Ui::Library *ui;
    Nod *Start=nullptr;
        Nod *Last=nullptr;
};

#endif // LIBRARY_H
