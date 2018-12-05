#ifndef MAINMENU_H
#define MAINMENU_H

#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QImage>
#include <QLabel>
#include <QPixMap>
#include <QColor>

namespace menu
{
class MainMenu : public QWidget
{
public:
    MainMenu();
public slots:
    void GoToGame();
    void Exit();

private:
    void InitializeMenu();

    QLabel* title_;
    QPushButton* startGame_;
    QPushButton* exitGame_;
    QVBoxLayout* layout_;
};
}


#endif // MAINMENU_H
