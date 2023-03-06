#ifndef WEBENGIE_H
#define WEBENGIE_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
namespace Ui {
class webEngie;
}

class webEngie : public QWidget
{
    Q_OBJECT

public:
    explicit webEngie(QWidget *parent = nullptr);
    ~webEngie();

private:
    Ui::webEngie *ui;
};

#endif // WEBENGIE_H
