#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    setWindowTitle("PACMAN");//cambiar el nombre de la ventana
    ui->resultado->setText("0");
    scene->setSceneRect(0,0,400,400);
    scene->setBackgroundBrush(Qt::black);
    bolita=new cuerpo();
    scene->addItem(bolita);
    bolita->setPos(180,180);
    //pared(int w,int h,int px,int py);
    //----------------Alrededor del mapa-------------------
    paredes.append(new pared(5,125,0,0));
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,0,-125));
    scene->addItem(paredes.back());
    paredes.append(new pared(5,50,-80,-125));
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,0,-170));
    scene->addItem(paredes.back());

    paredes.append(new pared(5,140,0,-260));//lateral izq inf
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,0,-210));
    scene->addItem(paredes.back());
    paredes.append(new pared(5,50,-80,-210));
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,0,-255));
    scene->addItem(paredes.back());

    paredes.append(new pared(40,5,-360,-325));
    scene->addItem(paredes.back());



    paredes.append(new pared(400,5,0,0));//superior
    scene->addItem(paredes.back());

    paredes.append(new pared(5,125,-395,0));//lat der sup
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,-315,-125));
    scene->addItem(paredes.back());
    paredes.append(new pared(5,50,-315,-125));
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,-315,-170));
    scene->addItem(paredes.back());

    paredes.append(new pared(5,140,-395,-260));//lat der inf
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,-315,-210));
    scene->addItem(paredes.back());
    paredes.append(new pared(5,50,-315,-210));
    scene->addItem(paredes.back());
    paredes.append(new pared(85,5,-315,-255));
    scene->addItem(paredes.back());

    paredes.append(new pared(40,5,0,-325));
    scene->addItem(paredes.back());


    paredes.append(new pared(400,5,0,-395));//inferior
    scene->addItem(paredes.back());
    paredes.append(new pared(10,60,-195,0));//perpendicular sup
    scene->addItem(paredes.back());

    //la mitad del mapa
    paredes.append(new pared(30,5,-150,-165));
    scene->addItem(paredes.back());
    paredes.append(new pared(30,5,-210,-165));
    scene->addItem(paredes.back());

    paredes.append(new pared(5,30,-150,-165));
    scene->addItem(paredes.back());

    paredes.append(new pared(90,5,-150,-195));
    scene->addItem(paredes.back());

    paredes.append(new pared(5,30,-235,-165));
    scene->addItem(paredes.back());

    //-----------------internos superior----------------------
    paredes.append(new pared(50,30,-35,-30));//sup izq 1
    scene->addItem(paredes.back());
    paredes.append(new pared(50,30,-115,-30));//sup izq 2
    scene->addItem(paredes.back());

    paredes.append(new pared(50,30,-235,-30));//sup der 1
    scene->addItem(paredes.back());
    paredes.append(new pared(50,30,-315,-30));//sup der 2
    scene->addItem(paredes.back());

    paredes.append(new pared(50,15,-35,-85));//inf izq 1
    scene->addItem(paredes.back());

    paredes.append(new pared(10,90,-115,-85));//inf izq 1 T
    scene->addItem(paredes.back());
    paredes.append(new pared(50,10,-115,-125));//inf izq 2 T
    scene->addItem(paredes.back());

    paredes.append(new pared(80,10,-160,-85));//inf med 1 T
    scene->addItem(paredes.back());
    paredes.append(new pared(10,50,-195,-85));//inf med 2 T
    scene->addItem(paredes.back());

    paredes.append(new pared(10,90,-275,-85));//inf der 1 T
    scene->addItem(paredes.back());
    paredes.append(new pared(50,10,-235,-125));//inf der 2 T
    scene->addItem(paredes.back());

    paredes.append(new pared(50,15,-315,-85));//inf der 2
    scene->addItem(paredes.back());
    //---------------------internos inferiores ----------------------------
    paredes.append(new pared(130,10,-35,-355));//inf izq 1
    scene->addItem(paredes.back());
    paredes.append(new pared(10,40,-115,-325));//inf izq 1
    scene->addItem(paredes.back());

    paredes.append(new pared(130,10,-235,-355));//inf der 2
    scene->addItem(paredes.back());
    paredes.append(new pared(10,40,-275,-325));//inf der 2
    scene->addItem(paredes.back());

    paredes.append(new pared(80,10,-160,-315));//inf med 1 T
    scene->addItem(paredes.back());
    paredes.append(new pared(10,50,-195,-315));//inf med 2 T
    scene->addItem(paredes.back());

    paredes.append(new pared(10,40,-115,-210));//sup izq 1
    scene->addItem(paredes.back());
    paredes.append(new pared(50,10,-115,-280));//sup izq 1
    scene->addItem(paredes.back());

    paredes.append(new pared(80,10,-160,-230));//sup med 1 T
    scene->addItem(paredes.back());
    paredes.append(new pared(10,50,-195,-230));//sup med 2 T
    scene->addItem(paredes.back());

    paredes.append(new pared(10,40,-275,-210));//sup der 1
    scene->addItem(paredes.back());
    paredes.append(new pared(50,10,-235,-280));//sup der 1
    scene->addItem(paredes.back());
    //extremos inferiores
    paredes.append(new pared(50,10,-35,-285));//ext izq 1
    scene->addItem(paredes.back());
    paredes.append(new pared(10,40,-75,-285));//ext izq 1
    scene->addItem(paredes.back());

    paredes.append(new pared(50,10,-315,-285));//ext der 1
    scene->addItem(paredes.back());
    paredes.append(new pared(10,40,-315,-285));//ext der 1
    scene->addItem(paredes.back());
    //---------MONEDAS-------------------------
    for(int i=20;i<=380;i+=10){
        if(i<185 | i>210){
       coins.append(new moneda(6,-i,-15));
       scene->addItem(coins.back());
        }
       }

    //-------lineas 2 y 3-------------------
    for(int i=20;i<=380;i+=10){
        if(i<30 | (i>90 & i<110) | (i>170 & i<185) | (i>210 & i<225) | (i>290 & i<305) | i>370 ){
       coins.append(new moneda(3,-i,-35));
       scene->addItem(coins.back());
        }
     }

   for(int i=20;i<=380;i+=10){
        if(i<30 | (i>90 & i<110) | (i>170 & i<185) | (i>210 & i<225) | (i>290 & i<305) | i>370){
       coins.append(new moneda(3,-i,-55));
       scene->addItem(coins.back());
        }
     }
    //---------linea 4-----------
    for(int i=20;i<=380;i+=10){
       coins.append(new moneda(3,-i,-70));
       scene->addItem(coins.back());
      }
    //----------------- linea 5------
    for(int i=20;i<=380;i+=10){
        if(i<30 | (i>90 & i<110) |(i>130 & i<145) | (i>245 & i<260)| (i>290 & i<310) | i>370){
       coins.append(new moneda(3,-i,-90));
       scene->addItem(coins.back());
        }
     }
    //----------linea 6------
    for(int i=20;i<=380;i+=10){
        if((i>15 & i<110) |(i>130 & i<190) | (i>215 & i<260)| i>290){
       coins.append(new moneda(3,-i,-110));
       scene->addItem(coins.back());
        }
     }
    //-------linea 7---------
    for(int i=20;i<=380;i+=10){
        if((i>90 & i<110) |(i>162 & i<180) | (i>215 & i<230)| (i>290 & i<310)){
       coins.append(new moneda(3,-i,-130));
       scene->addItem(coins.back());
        }
     }
    //---------------linea 8-------------
    for(int i=20;i<=380;i+=10){
        if((i>90 & i<110) |(i>130 & i<265) | (i>290 & i<310)){
       coins.append(new moneda(3,-i,-150));
       scene->addItem(coins.back());
        }
     }
    //-----------------linea 9--------------------
    for(int i=20;i<=380;i+=10){
        if((i>0 & i<140) |(i>245 & i<400)){
       coins.append(new moneda(3,-i,-190));
       scene->addItem(coins.back());
        }
     }
    //----------linea 10---------------
    for(int i=20;i<=380;i+=10){
        if((i>90 & i<110) |(i>130 & i<265) | (i>290 & i<310)){
       coins.append(new moneda(3,-i,-210));
       scene->addItem(coins.back());
        }
     }
    //-------------------linea 11----------------
    for(int i=20;i<=380;i+=10){
        if((i>90 & i<110) |(i>130 & i<145)|(i>240 & i<255) | (i>290 & i<310)){
       coins.append(new moneda(3,-i,-230));
       scene->addItem(coins.back());
        }
     }
    //---------------- linea 12------------------

    for(int i=20;i<=380;i+=10){
        if((i>90 & i<110) |(i>130 & i<185) |(i>215 & i<265) | (i>290 & i<310)){
       coins.append(new moneda(3,-i,-250));
       scene->addItem(coins.back());
        }
     }
    //--------------linea 13----------------
    for(int i=20;i<=380;i+=10){
        if((i>15 & i<185) |(i>215 &  i<385)){
       coins.append(new moneda(3,-i,-265));
       scene->addItem(coins.back());
        }
     }
    //----------------- linea 14------
    for(int i=20;i<=380;i+=10){
        if(i<30 | (i>90 & i<110) |(i>165 & i<225) | (i>290 & i<310) | i>370){
       coins.append(new moneda(3,-i,-285));
       scene->addItem(coins.back());
        }
     }
    //----------------- linea 15------
    for(int i=20;i<=380;i+=10){
        if((i>0 & i<65) | (i>90 & i<310) | i> 335){
       coins.append(new moneda(3,-i,-300));
       scene->addItem(coins.back());
        }
     }
    //----------------- linea 16------
    for(int i=20;i<=380;i+=10){
        if((i>50 & i<65) | (i>90 & i<110) |(i>130 & i<150) |(i>245 & i<260)| (i>290 & i<310) | (i>330 & i<345)){
       coins.append(new moneda(3,-i,-320));
       scene->addItem(coins.back());
        }
     }
    //----------------- linea 17------
    for(int i=20;i<=380;i+=10){
        if((i>0 & i<110) |(i>130 & i<185) |(i>220 & i<270)| (i>290 & i<385)){
       coins.append(new moneda(3,-i,-340));
       scene->addItem(coins.back());
        }
     }
    //----------------- linea 18------
    for(int i=20;i<=380;i+=10){
        if((i>0 & i<30) | (i>170 & i<185) |(i>210 & i<225) |(i>370 & i<385)){
       coins.append(new moneda(3,-i,-360));
       scene->addItem(coins.back());
        }
     }
    //----------------- linea 19------
    for(int i=20;i<=380;i+=10){
        if((i>0 & i<385)){
       coins.append(new moneda(3,-i,-380));
       scene->addItem(coins.back());
        }
     }


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    QList<moneda*>::iterator itm;
    if(evento->key()==Qt::Key_W)
    {
        bolita->MoveUp();
        if(EvaluarColision())
        {
            bolita->MoveDown();
        }
        if(EvaluarColisionMoneda(itm))
        {
          scene->removeItem(*itm);
          coins.erase(itm);
          puntos+=1;
          ui->resultado->setText(QString::number(puntos,10));

        }

    }
    else if(evento->key()==Qt::Key_S)
    {
        bolita->MoveDown();
        if(EvaluarColision())
        {
            bolita->MoveUp();
        }
        if(EvaluarColisionMoneda(itm))
        {
          scene->removeItem(*itm);
          coins.erase(itm);
          puntos+=1;
          ui->resultado->setText(QString::number(puntos,10));

        }

    }
    else if(evento->key()==Qt::Key_A)
    {
        bolita->MoveLeft();
        if(EvaluarColision())
        {
            bolita->MoveRight();
        }
        if(EvaluarColisionMoneda(itm))
        {
          scene->removeItem(*itm);
          coins.erase(itm);
          puntos+=1;
          ui->resultado->setText(QString::number(puntos,10));

        }
        if(EvaluarPosicion()==1){
            bolita->setPosx(400);
            bolita->setPosy((bolita->getPosy()));
        }

    }
    else if(evento->key()==Qt::Key_D)
    {
        bolita->MoveRight();
        if(EvaluarColision())
        {
            bolita->MoveLeft();
        }
        if(EvaluarColisionMoneda(itm))
        {
          scene->removeItem(*itm);
          coins.erase(itm);
          puntos+=1;
          ui->resultado->setText(QString::number(puntos,10));
        }
        if(EvaluarPosicion()==2){
            bolita->setPosx(0);
            bolita->setPosy((bolita->getPosy()));
        }

    }
}
bool MainWindow::EvaluarColision()
{
    QList<pared*>::iterator it;

    for(it=paredes.begin();it!=paredes.end();it++){
       if( bolita->collidesWithItem(*it))
           return true;
    }
    return false;
}
bool MainWindow::EvaluarColisionMoneda(QList<moneda*>::iterator &itm)
{
     for(itm=coins.begin();itm!=coins.end();itm++){
       if( bolita->collidesWithItem(*itm))
          return true;
     }
     return false;
}

int MainWindow::EvaluarPosicion()
{
    int flag=0;
    if(bolita->getPosx()<0){
       return flag=1;
    }
    else if (bolita->getPosx()>400){
        return flag=2;
    }
    else {flag=0;}
    return flag;
}


