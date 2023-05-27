#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

class Checkerboard : public QWidget {
public:
    Checkerboard(QWidget *parent = nullptr) : QWidget(parent) {
        // Инициализация игрового поля
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                board[row][col] = nullptr;
                if ((row + col) % 2 == 0) {
                    QPushButton *button = new QPushButton(this);
                    button->setFixedSize(50, 50);
                    button->setStyleSheet("background-color: lightgray");

                    // Обработка нажатия на кнопку
                    connect(button, &QPushButton::clicked, [=]() {
                        buttonClicked(row, col);
                    });

                    board[row][col] = button;
                }
            }
        }

        // Расположение кнопок в сетке
        QGridLayout *gridLayout = new QGridLayout(this);
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col]) {
                    gridLayout->addWidget(board[row][col], row, col);
                }
            }
        }

        setLayout(gridLayout);
    }

private:
    QPushButton *board[8][8];

    void buttonClicked(int row, int col) {
        // Вывод сообщения о выбранной позиции
        QString message = "Выбрана позиция: " + QString::number(row) + ", " + QString::number(col);
        QMessageBox::information(this, "Выбранная позиция", message);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Checkerboard checkerboard;
    checkerboard.setWindowTitle("Шашки");
    checkerboard.show();

    return app.exec();
}
