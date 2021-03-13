#include "SummaryWindow.h"
#include "SummarySaveWindow.h"
#include <QMessageBox>

#include <QDebug>
//======================================================================================================
SummarySaveWindow::SummarySaveWindow(const QString& result, QWidget* parent)
    : QWidget{parent}, ui{new Ui_Form}, _file_dialog{nullptr}, _result{result}
{
    ui->setupUi(this);

    _file_dialog = new QFileDialog(this);
    _file_dialog->setWindowTitle(tr("Укажите директорию"));
    _file_dialog->setFileMode(QFileDialog::Directory);

    connect(ui->pushButtonFileDialog, SIGNAL(clicked()),
            this, SLOT(pushButtonFileDialog_clicked())
            );
    connect(ui->pushButtonConfirm, SIGNAL(clicked()),
            this, SLOT(pushButtonConfirm_clicked())
            );
    connect(_file_dialog, SIGNAL(urlSelected(const QUrl&)),
            this, SLOT(urlSelected(const QUrl&))
            );

    ui->pushButtonFileDialog->setIcon(QIcon("../Icons/Dir.png"));
    ui->pushButtonConfirm->setIcon(QIcon("../Icons/Confirm.png"));
    ui->pushButtonFileDialog->setIconSize(QSize(20, 30));
    ui->pushButtonConfirm->setIconSize(QSize(20, 30));
}
//======================================================================================================
void SummarySaveWindow::pushButtonFileDialog_clicked()
{
    _file_dialog->exec();
}
//======================================================================================================
void SummarySaveWindow::urlSelected(const QUrl& url)
{
    QString temp(url.path() + "/result" + ".txt");
    temp.remove(0, 1); // deleteing first '/'
    ui->lineEditPath->setText(temp);
}
//======================================================================================================
void SummarySaveWindow::pushButtonConfirm_clicked()
{
    if (ui->lineEditPath->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Ошибка"),
                             tr("Укажите для сохранения результатов вычислений."));
        return;
    }

    QFile file(ui->lineEditPath->text());
    if (QFile::exists(ui->lineEditPath->text()))
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Question); // sound?
        QPushButton* saveButton   = msgBox.addButton(tr("Сохранить"), QMessageBox::ActionRole);
        QPushButton* cancelButton = msgBox.addButton(QMessageBox::Abort); // почему нет конструктора с текстом??
        cancelButton->setText((tr("Отмена")));
        msgBox.setText(tr("Файл уже существует в указанной директории. Заменить?"));
        msgBox.setWindowTitle(tr("Сохранение"));
        msgBox.exec();

        if (msgBox.clickedButton() == saveButton)
        {
            if (!file.open((QIODevice::WriteOnly | QIODevice::Text)))
            {
                QMessageBox::warning(this, tr("Сохранение"),
                                     tr("Не удалось сохранить файл."));
                return;
            }
            else
            {
                QTextStream out(&file);
                out << _result;
                QMessageBox::information(this, tr("Сохранение"),
                                         tr("Файл успешно сохранён."));
                return;
            }
        }
        else if (msgBox.clickedButton() == cancelButton)
        {
            return;
        }
    }

    if (!file.open((QIODevice::WriteOnly | QIODevice::Text)))
    {
        QMessageBox::warning(this, tr("Сохранение"),
                             tr("Не удалось сохранить файл."));
        return;
    }
    else
    {
        QTextStream out(&file);
        out << _result;
        QMessageBox::information(this, tr("Сохранение"),
                             tr("Файл успешно сохранён."));
    }
}
//======================================================================================================
SummarySaveWindow::~SummarySaveWindow()
{
    delete ui;
}
