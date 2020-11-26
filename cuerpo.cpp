#include "cuerpo.h"

QRectF cuerpo::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::yellow);
    //painter->drawEllipse(boundingRect());
    //QImage img("C:/Users/edisson/Documents/tallerColisiones/pacman.png");
    //painter->drawImage(boundingRect(),img);//ubico la imagen deseada en la delimitacion
    painter->drawPixmap(-r,-r,*pixmap,columnas,filas,2*r,2*r);
}

int cuerpo::getPosx() const
{
    return posx;
}



int cuerpo::getPosy() const
{
    return posy;
}

void cuerpo::setPosx(int value)
{
    posx = value;
}

void cuerpo::setPosy(int value)
{
    posy = value;
}

cuerpo::cuerpo(int ra, int px, int py)
{
    r=ra;posx=px;posy=py;
    setPos(posx,posy);
}

cuerpo::cuerpo(QObject *parent)
{
    timer =new QTimer();
    filas = 0;
    columnas= 0;

    pixmap =new QPixmap(":/imagenes/pacman2.png");
    posx=180;posy=180;r=9;

    timer->start(100);
    connect(timer,&QTimer::timeout,this,&cuerpo::Actualizacion);

}

void cuerpo::MoveUp()
{
    posy-=2*velocidad;
    filas=21;
    setPos(posx,posy);

}

void cuerpo::MoveDown()
{
    posy+=2*velocidad;
    filas=62;
    setPos(posx,posy);
}

void cuerpo::MoveRight()
{
    posx+=2*velocidad;
    filas=0;
    setPos(posx,posy);
}

void cuerpo::MoveLeft()
{
    posx-=2*velocidad;
    filas=42;
    setPos(posx,posy);
}



void cuerpo::Actualizacion()
{
    columnas+=20;
    if(columnas>=40){
        columnas=0;
    }
    this->update(-r,-r,2*r,2*r);
}




