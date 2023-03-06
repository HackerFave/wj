#include "webEngie.h"
#include "ui_webEngie.h"
#include <QSharedPointer>
#include <QUrl>
#include <QtDebug>
webEngie::webEngie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::webEngie)
{
    ui->setupUi(this);
//    QScopedPointer<QWebEngineView> view(new QWebEngineView(this));
    QWebEngineView *view = new QWebEngineView(parent);
    QUrl url = QUrl::fromUserInput("http://baidu.com");
    view->load(url);
    ui->gridLayout->addWidget(view);

}

webEngie::~webEngie()
{
    delete ui;
}

