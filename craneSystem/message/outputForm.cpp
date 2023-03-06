#include "outputForm.h"
#include "ui_outputForm.h"

outputForm::outputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::outputForm)
{
    ui->setupUi(this);
    ui->textBrowser_output->document()->setMaximumBlockCount (100);
    connect(this,SIGNAL(AppendText(QString)),this,SLOT(SlotAppendText(QString)));
    QColor color;
    color.setRgb(255,0,0,255);
    ui->textBrowser_output->setTextColor(color);
    setFocusPolicy(Qt::NoFocus);
}

outputForm::~outputForm()
{
    delete ui;
}
void outputForm::showOutPut(const QString &text)
{
    emit AppendText(text);
}
void outputForm::SlotAppendText(const QString &text)
{
    ui->textBrowser_output->append(text);
}
