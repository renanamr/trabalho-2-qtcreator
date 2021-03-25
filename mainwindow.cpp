#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,130,30, ui->speed_trem1->value());
    trem2 = new Trem(2,330,30, ui->speed_trem2->value());
    trem3 = new Trem(3,530,30, ui->speed_trem3->value());
    trem4 = new Trem(4,230,150, ui->speed_trem4->value());
    trem5 = new Trem(5,430,150, ui->speed_trem5->value());

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_pushButton_clicked()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked()
{
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();
}


void MainWindow::on_speed_trem1_valueChanged(int value)
{
    trem1->mudarVelocidade(value);
}

void MainWindow::on_speed_trem2_valueChanged(int value)
{
    trem2->mudarVelocidade(value);
}

void MainWindow::on_speed_trem3_valueChanged(int value)
{
    trem3->mudarVelocidade(value);
}

void MainWindow::on_speed_trem4_valueChanged(int value)
{
    trem4->mudarVelocidade(value);
}

void MainWindow::on_speed_trem5_valueChanged(int value)
{
    trem5->mudarVelocidade(value);
}




bool progressTrem1(int x, int y){
    if(x==310 && y==30){
        //Solicita linha 1
    }
    if(x==330 && y==150){
        //Solicita linha 3
    }
    if(x==310 && y==150){
        //Libera linha 1
    }
    if(x==210 && y==150){
        //Libera linha 3
    }
}

bool progressTrem2(int x, int y){
    if(x==530 && y==30){
        //Solicita linha 2
    }
    if(x==530 && y==150){
        //Solicita linha 5
    }
    if(x==430 && y==150){
        //Solicita linha 4
    }
    if(x==330 && y==150){
        //Solicita linha 1
    }

    if(x==510 && y==150){
        //Libera linha 2
    }
    if(x==410 && y==150){
        //Libera linha 5
    }
    if(x==330 && y==130){
        //Libera linha 4
    }
    if(x==350 && y==30){
        //Libera linha 1
    }
}

bool progressTrem3(int x, int y){
    if(x==530 && y==150){
        //Solicita linha 2
    }
    if(x==630 && y==150){
        //Solicita linha 6
    }
    if(x==550 && y==30){
        //Libera linha 2
    }
    if(x==530 && y==130){
        //Libera linha 6
    }
}


bool progressTrem4(int x, int y){
    if(x==230 && y==170){
        //Solicita linha 3
    }
    if(x==330 && y==150){
        //Solicita linha 4
    }
    if(x==430 && y==150){
        //Solicita linha 7
    }


    if(x==350 && y==150){
        //Libera linha 3
    }
    if(x==430 && y==170){
        //Libera linha 4
    }
    if(x==410 && y==270){
        //Libera linha 7
    }
}


bool progressTrem5(int x, int y){
    if(x==430 && y==150){
        //Solicita linha 5
    }
    if(x==530 && y==150){
        //Solicita linha 6
    }
    if(x==430 && y==270){
        //Solicita linha 7
    }


    if(x==550 && y==150){
        //Libera linha 5
    }
    if(x==630 && y==170){
        //Libera linha 6
    }
    if(x==450 && y==150){
        //Libera linha 7
    }
}
