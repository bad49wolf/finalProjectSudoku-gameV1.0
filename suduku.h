#ifndef SUDUKU_H
#define SUDUKU_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class suduku; }
QT_END_NAMESPACE

class suduku : public QWidget
{
    Q_OBJECT

public:
    suduku(QWidget *parent = nullptr);
    ~suduku();

private:
    Ui::suduku *ui;
    int matrix[9][9];

    void generateMatrix ();
    void matrixshow();
private slots:
    void matrixverify(int matrix[9][9]);
    void newgame() ;
    void reset();
    void on_pushButton_clicked();
};
#endif // SUDUKU_H
