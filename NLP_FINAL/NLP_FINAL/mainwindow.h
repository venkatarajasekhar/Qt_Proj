#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "qmyhashthread.h"
#include <QDesktopWidget>
#include <QToolTip>
#include <dialog.h>
#include <QVector>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMessageBox>
#include "inputdialog.h"
#include "qaddfilethread.h"

namespace Ui {
class MainWindow;
}
typedef struct{
   int psgLen;
   int newpsgLen;
   int insertPos;
}MyLen;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ReplaceWords(int pos, int wordslen, QString newwords, int newcolor);
    bool isPosValid(int pos);
    void markAllWrongWord();
public slots:
    void enableAction(int timeused);
    void replyFinished(QNetworkReply *reply);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    bool eventFilter(QObject *obj, QEvent *e);
    void timerEvent(QTimerEvent *e);
private slots:
    void on_btnCheck_clicked();
    void on_btnTran_clicked();
    void showCandidateDlg();
    void getTextEditClickPos(QPoint point);
    void autoReplaceWord(QString str);
    void on_btnOpenFile_clicked();
    void addNewWords(QStringList list);
    void addNewFile(int all, int added);

    void on_btnChooseFile_clicked();

    void on_tabArtical_tabBarClicked(int);

    void on_radioFile_clicked();

    void on_radioSingle_clicked();

    void on_btnAddNew_clicked();

    void on_lineEditNewWord_textChanged(const QString &);

    void on_btnSave_clicked();

    void on_btnLink_clicked();

private:
    Ui::MainWindow *ui;
    bool m_drag;
    QPoint m_dragPosition;
    QPoint m_dlgPos;
    QMyHashThread *myThread;
    QString color[5];
    enum mycolor{red, yellow, green, wathet, blue};
    QStringList candidate;
    int curPos;
    QVector<int> allPos;
    QHash<QString, int> allWrongWord;
    QString psgOld;
    Dialog *dlg;
    MyLen mylen;
    int getArticalTimerId;
    InputDialog *inputDlg;
    QString wordUnderCursor;
    QAddFileThread *add;
    QString fileName;
    QString fname;
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H
