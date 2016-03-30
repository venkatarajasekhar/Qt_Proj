#include "qmyhashthread.h"

QMyHashThread::QMyHashThread(QObject *parent) :
    QThread(parent)
{
    userFile=NULL;
    userTs=NULL;
}

QMyHashThread::~QMyHashThread()
{
    if(userFile->isOpen())
        userFile->close();
    delete userFile;
    delete userTs;
}

/*
 * Input:   None
 * Return:  None
 * Explain:    A thread to load dictionary into a map<string, string> from "diclarge.txt" and "user.txt"
 */
void QMyHashThread::run()
{
    QTime time;
    time.start();
    QFile file[2];
    file[0].setFileName("systemdic.txt");    //system dictionary
    file[1].setFileName("userdic.txt");      //user dictionary
    QRegExp keyrx("(.*)\\[E\\]");
    QRegExp serx("(\\[L\\].*)");
    QRegExp exrx("(\\[E\\].*)");
    for(int i=0; i<2; i++)
    {
        if(file[i].open(QIODevice::ReadOnly| QIODevice::Text))
        {
            QTextStream fs(&file[i]);
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
        file[i].close();
    }
    userFile=new QFile("userdic.txt");
    userFile->open(QFile::Append);
    userTs=new QTextStream(userFile);
//    cout<<"Time used: "<<time.elapsed()<<endl;
    emit loadThreadExited(time.elapsed());
}

/*
 * Input:   A English word
 * Return:  The translation of the word or NULL if the word not found.
 */
QString QMyHashThread::findWord(QString word)
{
    QHash<QString, QString>::iterator it=dic.find(word);
    if(it==dic.end())
        return "";
    return it.value();
}

/*
 * Input:   A uncorrect English word
 * Return:  A list of strings (5 words) which may be able to replace the input word.
 */
QStringList QMyHashThread::correctWord(QString wordtofind)
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
    //qDebug()<<candidate<<candidate.size();
    //for all candidates, calculate their edit distance
    int max=4, midmax=3, mid=2, midmin=1, min=0;
    struct dis{int distance;QString word;}minidis[5]={{96,""},{97,""},{98,""},{99,""},{100,""}};
    for(int i=0; i<candidate.size(); i++)
    {
        if(wordtofind==candidate.at(i))
            continue;
        int curdis=LevenshteinDistance(wordtofind, candidate.at(i));
        //qDebug()<<candidate[i]<<curdis;
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
    best.append(minidis[min].word);
    best.append(minidis[midmin].word);
    best.append(minidis[mid].word);
    best.append(minidis[midmax].word);
    best.append(minidis[max].word);
    //qDebug()<<best;
    return best;
}

/*
 * Input:   A English sentence and the position of the word in the artical
 * Return:  A list of integers represent all uncorrect words
 * Mark:    Your sentence should not contains any punctuation
 */
QVector<int> QMyHashThread::correctSentence(QString s, int startpos)
{
    QVector<int> pos;
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
 * Input:   a string list contains the new word and its explaination
 * Function: add a new word to the dic
 */
void QMyHashThread::addNewWords(QStringList list)
{
    //It might never be empty, though...
    if(list.empty())
        return;
    if(findWord(list.at(0))!="")
        return;
    dic[list.at(0)]=list.at(1)+"\n"+list.at(2);
    *userTs<<list.at(0)<<list.at(1)<<list.at(2)<<"\n";
    userTs->flush();
}

/*
 * Return a pointer of the text stream which is used to write usetdic.txt
 */
QTextStream *QMyHashThread::getUserTs()
{
    if(userTs!=NULL)
        return userTs;
    else
        return NULL;
}
/*
 * Return a pointer of the dictionary which is used to hold all words.
 */
QHash<QString, QString> *QMyHashThread::getDicPointer()
{
    return &dic;
}
/*
 * Same as getUserTs()
 */
QTextStream *QMyHashThread::getTextStreamPointer()
{
    return userTs;
}

/*
 * Input:   3 integer
 * Return:  The minimum of the 3
 */
int QMyHashThread::minimum(int a, int b, int c)
{
    int tmp=a>b?b:a;
    return tmp>c?c:tmp;
}

/*
 * Input:   2 English words
 * Return:  The Levenshtein distance between the 2 input words
 */
int QMyHashThread::LevenshteinDistance(QString a, QString b)
{
    int i = a.length()+1;
    int j = b.length()+1;
    if(i==1||j==1)
        return 65535;
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



