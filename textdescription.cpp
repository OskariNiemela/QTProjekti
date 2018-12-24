#include "textdescription.h"

namespace description
{

TextDescription::TextDescription(QWidget *parent):
    QPlainTextEdit(parent)
{
    initializeText();
}

void TextDescription::initializeText()
{
    setFrameShadow(QFrame::Shadow::Sunken);
    setReadOnly(true);
    setPlainText("Welcome");
    setMaximumBlockCount(21);
}

void TextDescription::changeText(std::string desc)
{
    QString qPrevious = toPlainText();
    QString qDesc = QString::fromStdString(desc);
    QString qWhole = qPrevious+"\n"+qDesc;
    setPlainText(qWhole);
    QScrollBar* bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

}


