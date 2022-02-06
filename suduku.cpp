#include "suduku.h"
#include "ui_suduku.h"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "Sodukus.cpp"
using namespace std;
suduku::suduku(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::suduku)
{
    ui->setupUi(this);
    generateMatrix();
    matrixshow();

}

suduku::~suduku()
{
    delete ui;
}

bool isinRange(int board[9][9])
{

    // Traverse board[][] array
    for (int i = 0; i < 9;
         i++) {
        for (int j = 0; j < 9;
             j++) {

            // Check if board[i][j]
            // lies in the range
            if (board[i][j] <= 0 || board[i][j] > 9) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the solution
// of sudoku puzzle is valid or not
bool isValidSudoku(int board[][9])
{
    // Check if all elements of board[][]
    // stores value in the range[1, 9]
    if (isinRange(board)
        == false) {
        return false;
    }

    // Stores unique value
    // from 1 to N
    bool unique[9 + 1];

    // Traverse each row of
    // the given array
    for (int i = 0; i < 9; i++) {

        // Initialize unique[]
        // array to false
        memset(unique, false,
               sizeof(unique));

        // Traverse each column
        // of current row
        for (int j = 0; j < 9;
             j++) {

            // Stores the value
            // of board[i][j]
            int Z = board[i][j];

            // Check if current row
            // stores duplicate value
            if (unique[Z]) {
                return false;
            }
            unique[Z] = true;
        }
    }

    // Traverse each column of
    // the given array
    for (int i = 0; i < 9; i++) {

        // Initialize unique[]
        // array to false
        memset(unique, false,
               sizeof(unique));

        // Traverse each row
        // of current column
        for (int j = 0; j < 9;
             j++) {

            // Stores the value
            // of board[j][i]
            int Z = board[j][i];

            // Check if current column
            // stores duplicate value
            if (unique[Z]) {
                return false;
            }
            unique[Z] = true;
        }
    }

    // Traverse each block of
    // size 3 * 3 in board[][] array
    for (int i = 0; i < 9 - 2;
         i += 3) {

        // j stores first column of
        // each 3 * 3 block
        for (int j = 0; j < 9 - 2;
             j += 3) {

            // Initialize unique[]
            // array to false
            memset(unique, false,
                   sizeof(unique));

            // Traverse current block
            for (int k = 0; k < 3;
                 k++) {

                for (int l = 0; l < 3;
                     l++) {

                    // Stores row number
                    // of current block
                    int X = i + k;

                    // Stores column number
                    // of current block
                    int Y = j + l;

                    // Stores the value
                    // of board[X][Y]
                    int Z = board[X][Y];

                    // Check if current block
                    // stores duplicate value
                    if (unique[Z]) {
                        return false;
                    }
                    unique[Z] = true;
                }
            }
        }
    }

    // If all conditions satisfied
    return true;
}
void suduku::matrixverify(int matrix[9][9]) {
    if(isValidSudoku(matrix)) {
    QMessageBox::information(this, "congrats","you won");
    }
    else {
     QMessageBox::information(this, "Surprise!","you lost , try again");
    }

}
void suduku::generateMatrix(){
    Sudoku *x = new Sudoku();
   x->createSeed();

      // Generating the puzzle
      x->genPuzzle();

      // Calculating difficulty of puzzle
     x->calculateDifficulty();
    for (int i=0;i<9 ;i++ ) {
        for (int j=0;j<9 ;j++ ) {
   matrix[i][j] = x->getGrd(i, j);
}
    }

}
void suduku::newgame() {
    generateMatrix();
    matrixshow();
}
void suduku::reset(){
    matrixshow();
}
void suduku::matrixshow() {


    for (int i=0;i<9 ;i++ ) {
        for (int j=0;j<9 ;j++ ) {
if (matrix[i][j]==0) {
      auto xd = new QTableWidgetItem("");

      ui->suduku_2->setItem(i,j,xd);
}
        else {
            auto xd = new QTableWidgetItem(QString::number(matrix[i][j]));
            ui->suduku_2->setItem(i,j,xd);
             xd->setBackground(Qt::gray);
             xd->setFlags(xd->flags() ^ Qt::ItemIsEditable);
}


        }
    }
}


void suduku::on_pushButton_clicked()
{
    int xd[9][9];
    for (int i=0;i<9 ;i++ ) {
        for (int j=0;j<9 ;j++ ) {
           auto hi =  ui->suduku_2->item(i,j)->text().toInt();
           xd[i][j] = hi;
        }
        }
    matrixverify(xd);
}

