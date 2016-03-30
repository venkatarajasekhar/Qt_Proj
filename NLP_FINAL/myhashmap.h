#include <QCoreApplication>
#include <QThread>
#include <QHash>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>
#include <QTime>
#include <QStringList>


//QTextStream cin(stdin, QIODevice::ReadOnly);
//QTextStream cout(stdout, QIODevice::WriteOnly);
static bool threadExit=false;

class QMyHashMap : public QThread
{
    //Q_OBJECT
private:
public:
    QMyHashMap(){threadExit=false;}
    virtual ~QMyHashMap(){;}
    inline QString findWord(QString word);
    QStringList correctWord(QString wordtofind);
    int LevenshteinDistance(QString a, QString b);
    inline int minimum(int a, int b, int c);
    QList<int> correctSentence(QString s, int &startpos);
public slots:
    void loadThreadExited();
protected:
    QHash<QString, QString> dic;
    void run();
};

/*
 * Input:   None
 * Return:  None
 * Explain:    A thread to load dictionary into a map<string, string> from "diclarge.txt"
 */
void QMyHashMap::run()
{
    QTime time;
    time.start();
    QFile file("diclarge.txt");
    QRegExp keyrx("(.*)\\[E\\]");
    QRegExp serx("(\\[L\\].*)");
    QRegExp exrx("(\\[E\\].*)");
    if(file.open(QFile::ReadOnly))
    {
        QTextStream fs(&file);
        QString key="", ex="",se="", line="";
        while(!fs.atEnd())
        {
            line=fs.readLine();
            //keyword
            int pos = keyrx.indexIn(line);
            if(pos>-1)
            {
                key=keyrx.cap(1);
            }
            //sentence
            pos = serx.indexIn(line);
            if(pos>-1)
            {
                se=serx.cap(1);
                line.resize(pos);
            }
            //explain
            pos = exrx.indexIn(line);
            if(pos>-1)
            {
                ex=exrx.cap(1);
            }
            dic[key]=ex+"\n"+se;
            key=""; ex="";se=""; line="";
        }
    }
//    cout<<"Time used: "<<time.elapsed()<<endl;
    emit loadThreadExited();
}

/*
 * Input:   A English word
 * Return:  The translation of the word or NULL if the word not found.
 */
QString QMyHashMap::findWord(QString word)
{
    QHash<QString, QString>::iterator it=dic.find(word);
    if(it==dic.end())
        return "";
    return it.value();
}

/*
 * Input:   A uncorrect English word
 * Return:  A list of strings represent 5 words which may replace the input word.
 */
QStringList QMyHashMap::correctWord(QString wordtofind)
{
    int len=wordtofind.length();
    QStringList candidate, best;
    QHash<QString, QString>::iterator it=dic.begin();
    //find all candidate
    for(; it!=dic.end(); it++)
    {
        int l=it.key().length();
        if(l>=len-1 && l<=len+1)
            candidate.append(it.key());
    }
    //for all candidates, calculate their edit distance
    int max=4, midmax=3, mid=2, midmin=1, min=0;
    struct dis{int distance;QString word;}minidis[5]={{96,""},{97,""},{98,""},{99,""},{100,""}};
    for(int i=0; i<candidate.size(); i++)
    {
        if(wordtofind==candidate.at(i))
            continue;
        int curdis=LevenshteinDistance(wordtofind, candidate.at(i));
        if(curdis<minidis[min].distance)
        {
            minidis[max].distance=curdis;
            minidis[max].word=candidate.at(i);
            int tmp=max;
            max=midmax;
            midmax=mid;
            mid=midmin;
            midmin=min;
            min=tmp;
        }
        else if(curdis<minidis[midmin].distance)
        {
            minidis[max].distance=curdis;
            minidis[max].word=candidate.at(i);
            int tmp=max;
            max=midmax;
            midmax=mid;
            mid=midmin;
            midmin=tmp;
        }
        else if(curdis<minidis[mid].distance)
        {
            minidis[max].distance=curdis;
            minidis[max].word=candidate.at(i);
            int tmp=max;
            max=midmax;
            midmax=mid;
            mid=tmp;
        }else if(curdis<minidis[midmax].distance)
        {
            minidis[max].distance=curdis;
            minidis[max].word=candidate.at(i);
            int tmp=max;
            max=midmax;
            midmax=tmp;
        }else if(curdis<minidis[max].distance)
        {
            minidis[max].distance=curdis;
            minidis[max].word=candidate.at(i);
        }
    }
    return best;
}

/*
 * Input:   A English sentence and the position it takes in the artical
 * Return:  A list of integers represent all uncorrect words
 * Mark:    Your sentence should not contains any punctuation
 */
QList<int> QMyHashMap::correctSentence(QString s, int &startpos)
{
    QList<int> pos;
    int curpos=startpos;
    if(s.length()==0)
        return pos;
    QTextStream ts(&s,QIODevice::ReadOnly);
    QString wordstofind;
    while(!ts.atEnd())
    {
        ts>>wordstofind;
        //qDebug()<<wordstofind<<" --->";
        if(findWord(wordstofind)=="")
        {
            correctWord(wordstofind);
            pos.push_back(curpos);
        }
        // +1 because the space was ingnore by the stream
        curpos+=wordstofind.length()+1;
    }
    //qDebug()<<pos;
    return pos;
}

/*
 * Input:   3 integer
 * Return:  The minimum of the 3
 */
int QMyHashMap::minimum(int a, int b, int c)
{
    int tmp=a>b?b:a;
    return tmp>c?c:tmp;
}

/*
 * Input:   2 English words
 * Return:  The Levenshtein distance of the 2 input words
 */
int QMyHashMap::LevenshteinDistance(QString a, QString b)
{
    int i = a.length()+1;
    int j = b.length()+1;
    if(i==1||j==1)
        return 65535;
    int **matrix=new int*[i];
    for(int m=0; m<i; m++)
    {
        matrix[m]=new int[j];
    }
    //initialize matrix
    for(int m=0; m<i; m++)
        matrix[m][0]=m;
    for(int m=0; m<j; m++)
        matrix[0][m]=m;
    //fill in the matrix
    for(int m=1; m<i; m++)
    {
        for(int n=1; n<j; n++)
        {
            int dmn= matrix[m-1][n-1];
            if(a.at(m-1)!=b.at(n-1))
            {
                dmn+=2;
            }
            matrix[m][n]=minimum(matrix[m-1][n]+1, matrix[m][n-1]+1, dmn);
            //qDebug()<<matrix[m][n];
        }
        //qDebug()<<endl;
    }
    //qDebug()<<matrix[i-1][j-1];
    return matrix[i-1][j-1];
}

