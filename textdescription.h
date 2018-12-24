#ifndef TEXTDESCRIPTION_H
#define TEXTDESCRIPTION_H

#include <QObject>
#include <QPlainTextEdit>
#include <string>
#include <QScrollBar>

namespace description
{
class TextDescription : public QPlainTextEdit
{
    Q_OBJECT
public:
    TextDescription(QWidget* parent = nullptr);
    void initializeText();
public slots:
    void changeText(std::string desc);
};

}


#endif // TEXTDESCRIPTION_H
