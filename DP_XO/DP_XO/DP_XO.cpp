#include "DP_XO.h"
#include "GameWindow.h"

DP_XO::DP_XO(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);

    connect(ui->joinGame_button, SIGNAL(clicked()), this, SLOT(joinButtonClicked()));
    
}

void DP_XO::joinButtonClicked() {
    GameWindow *gameWindow = new GameWindow(ui->lineEdit->text());
    gameWindow->show();
    hide();
   
    
}

DP_XO::~DP_XO()
{
   
}
