#include "mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(QString::fromUtf8("Checkable QPushButton Example"));
    resize(200,800);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    QLabel* lblCreateFonts = new QLabel("Create Fonts");
    layout->addWidget(lblCreateFonts);

    QGridLayout* gridLayout = new QGridLayout();
    layout->addLayout(gridLayout);

    btnCreate = new QPushButton("Create Code");
    layout->addWidget(btnCreate);

    btnClear = new QPushButton("Clear");
    layout->addWidget(btnClear);

    txtBox = new QTextEdit("");
    layout->addWidget(txtBox);

    int i, j;
    for(j = 0; j<8; j++)
    {
        for(i = 7; i>=0; i--)
        {
            //QString temptext;
            //temptext.append("Button");
            //temptext.append(QString::number((j*8)+i));

            buttons[(j*8)+i] = new QPushButton("*");
            buttons[(j*8)+i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            buttons[(j*8)+i]->setCheckable(true);
            //layout->addWidget(buttons[(j*8)+i]);
            gridLayout->addWidget(buttons[(j*8)+i],i,j);
        }
    }


    setCentralWidget(centralWidget);
    connect(btnCreate, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(clearButton()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::handleButton()
{
    short TempBuffer;
    QString strTempOutput;

    strTempOutput.append("{");
    char tempstr[6];

    int i, j;
    for(j = 0; j<8; j++)
    {
        TempBuffer = 0x00;
        for(i = 7; i>=0; i--)
        {
            TempBuffer|=buttons[(j*8)+i]->isChecked()<<7-i;
        }
        sprintf(tempstr,"%p",TempBuffer);
        strTempOutput.append(tempstr);
        if(j<7)strTempOutput.append(", ");
    }
    strTempOutput.append("},");
    txtBox->setText(strTempOutput);
}
void MainWindow::clearButton()
{
    int j;
    for(j = 0; j<64; j++)
    {
        buttons[j]->setChecked(false);
    }
}
