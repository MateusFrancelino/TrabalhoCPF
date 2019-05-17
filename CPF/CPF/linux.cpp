/**
	Estrutura inicial para o jogo SOKOBAN feito por Thiago Felski Pereira
	Jogo feito pelos acadêmicos Matheus Evandro Rech, Mateus da Silva Francelino e Henrique Leonardo Beerends Junior.
	Data inicial: 04/04/2019
	Última atualização: 05/05/2019 05:34:45 PM
**/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <random>
#include <ctime>

#define L 30
#define C 60

using namespace std;

int main()
{
	///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
	//FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
	//INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
	short int CX = 0, CY = 0;
	COORD coord;
	coord.X = CX;
	coord.Y = CY;
	//FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


//Posição inicial do personagem no console
	int x=3, y= 3, movimentos=0,xc,yc,continuar=1, xo, yo;
	//Variável para tecla precionada
	char tecla;
	//Coordenadas para impressão na tela
	int i, j;
	//variavel para saber se o objetivo foi completo
	bool localidade = true;
	while (continuar == 1) {
        if(localidade == true){
            default_random_engine generator(time(0));
            uniform_int_distribution<int> aleatorioobjetivox(1,28);//gera numero aleatorio da localidade do objetivo
            uniform_int_distribution<int> aleatorioobjetivoy(1,58);
            uniform_int_distribution<int> aleatoriocaixax(2,27);//gera numero aleatorio da localidade da caixa
            uniform_int_distribution<int> aleatoriocaixay(2,57);
            xc = aleatoriocaixax(generator);
            yc = aleatoriocaixay(generator);
            xo = aleatorioobjetivox(generator);
            yo = aleatorioobjetivoy(generator);
            localidade = false;
            movimentos = 0;
        }
		///Imprime o jogo: mapa e personagem.
		i = 0;
		cout << "Movimentos: " << movimentos<< "|  Para parar o jogo aperte 'p'                                       "<<"\n";//imprime o numero de movimentos
		 cout<< "X: "<<x<<" Y: "<<y<< " XC: "<< xc << " YC: "<< yc << "\n";
		while (i < L) {
			j = 0;
			while (j < C) {
				if (i == x && j == y) {
					cout<<(char)(248);//imprime o boneco
				}
				else if (i == xc && j == yc){
                    cout<<(char) (219);//imprime a caixa
				}
				else if (i == 0 || i == L - 1 || j == 0 || j == C - 1) {
					if(i>0 && i<29){
                        cout << (char)(186);//imprime as linhas superiores e inferios da borda
                    }
                    else if(i == 0 && j == 59){
                        cout << (char)(187);//imprime o canto superior direito
                    }
                    else if(i == 0 && j == 0){
                        cout << (char)(201);//imprime o canto superior esquerdo
                    }
                    else if(i == 29 && j == 59){
                        cout << (char)(188);//imprime o canto inferior direito
                    }
                    else if(i == 29 && j == 0){
                        cout << (char)(200);//imprime o canto inferior esquerdo
                    }
                    else{
                        cout << (char)(205);//imprime os paredes laterais
                    }
				}
				else if(i == xo && j == yo){
                    cout << (char) (176);
				}
				else {
					cout << " ";//imprime os espaços em branco
				}
				j++;//proxima coluna
			}
			cout << "\n";
			i++;//proxima linha
		}
		///executa os movimentos
		if (_kbhit()) {
			tecla = getch();
			switch (tecla)
			{
			case 'w': ///cima
				if(x-1 > 0 && x-1 <= 28){//bloqueia o movimento pra fora do mapa
                    x--;//movimenta o boneco
                    movimentos++;//soma o movimento
                    if(x == xc && y == yc && x > 1 && x < 28 && y>0 && y <= 58){//verifica se o movimento da caixa é dentro do mapa
                        xc--;//movimenta a caixa
                    }
                    if(x == xc && y == yc){//se a posição do boneco for a mesma da caixa ele volta a posição
                        x++;
                        movimentos--;
                    }
				}
                break;
			case 's': ///baixo
				if(x+1 > 0 && x+1 <= 28){//bloqueia o movimento pra fora do mapa
                    x++;//movimenta a caixa
                    movimentos++;//soma o movimento
                    if(x == xc && y == yc && x > 0 && x < 28 && y > 0 && y <= 58){//verifica se o movimento da caixa é dentro do mapa
                        xc++;//movimenta a caixa
                    }
                    if(x == xc && y == yc){//se a posição do boneco for a mesma da caixa ele volta a posição
                        x--;
                        movimentos--;
                    }
				}
				break;
			case 'a': ///esquerda
				if(y-1 > 0 && y-1 <= 58){//bloqueia o movimento pra fora do mapa
                    y--;//movimenta o boneco
                    movimentos++;//soma o movimento
                    if(x == xc && y == yc && x > 0 && x <= 28 && y > 1 && y <= 58){//verifica se o movimento da caixa é dentro do mapa
                        yc--;//movimenta a caixa
                    }
                    if(x == xc && y == yc){//se a posição do boneco for a mesma da caixa ele volta a posição
                        y++;
                        movimentos--;
                    }
				}
				break;
			case 'd': ///direita
				if(y+1 > 0 && y+1 <= 58){//bloqueia o movimento pra fora do mapa
                    y++;//movimenta o boneco
                    movimentos++;//soma o movimento
                    if(x == xc && y == yc && x > 0 && x <= 28 && y > 0 && y < 58){//verifica se o movimento da caixa é dentro do mapa
                        yc++;//movimento a ciaxa
                    }
                    if(x == xc && y == yc){//se a posição do boneco for a mesma da caixa ele volta a posição
                        y--;
                        movimentos--;
                    }
				}
				break;
            case 'p':///parar o jogo
                continuar = 0;
                break;
			}
		}

		/*
			Recoloca o mapa no inicio da tela,
			isso faz com que o jogo seja escrito sempre no mesmo lugar.
			se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
		*/
		if(xo == xc && yo == yc){
            localidade = true;
		}
		if(continuar == 1){
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
		else{//tela de fim de jogo
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            i=0;
            while(i<L-1){
                j=0;
                while(j<C){
                    if (i == 0 || i == L - 1 || j == 0 || j == C - 1) {
                        if(i>0 && i<29){
                            cout << (char)(186);//imprime as linhas superiores e inferios da borda
                        }
                        else if(i == 0 && j == 59){
                            cout << (char)(187);//imprime o canto superior direito
                        }
                        else if(i == 0 && j == 0){
                            cout << (char)(201);//imprime o canto superior esquerdo
                        }
                        else if(i == 29 && j == 59){
                            cout << (char)(188);//imprime o canto inferior direito
                        }
                        else if(i == 29 && j == 0){
                            cout << (char)(200);//imprime o canto inferior esquerdo
                        }
                        else{
                            cout << (char)(205);//imprime os paredes laterais
                        }
                    }
                    else if(i == 3 && j == 16){
                        cout << "Obrigado por jogar o sokoban";
                        j=43;
                    }
                    else if(i == 5 && j == 12){
                    cout<< "              a0000b.";
                    j=32;
                    }
                    else if (i == 6 && j == 12){
                        cout << "             d000000b.";
                        j=33;
                    }
                    else if (i == 7 && j == 12){
                        cout << "             0P'YP'Y00";
                        j=33;
                    }
                    else if (i == 8 && j == 12){
                        cout << "             0|o||o|00";
                        j=33;
                    }
                    else if(i == 9 && j == 12){
                        cout << "             0'    .00";
                        j=33;
                    }
                    else if ( i == 10 && j == 12){
                        cout << "             0`._.' Y0.";
                        j=34;
                    }
                    else if (i == 11 && j == 12){
                        cout << "            d/      `0b.";
                        j=35;
                    }
                    else if (i == 12 && j == 12){
                        cout << "           dP   .    Y0b.";
                        j=36;
                    }
                    else if (i == 13 && j == 12){
                    cout << "          d0:'  '  `::00b";
                    j=36;
                    }
                    else if (i == 14 && j== 12){
                        cout << "         d0'         'Y00b";
                        j=37;
                    }
                    else if ( i == 15 && j == 12){
                        cout << "        :0P    '      :000";
                        j=37;
                    }
                    else if ( i == 16 && j == 12){
                        cout << "         0a.   :     _a00P";
                        j=37;
                    }
                    else if (i == 17 && j == 12){
                        cout << "       ._/'Yaa_:   .| 00P|";
                        j=37;
                    }
                    else if (i == 18 && j == 12){
                        cout << "       \    YP'    `| 0P  `.";
                        j=38;
                    }
                    else if (i == 19 && j == 12){
                        cout << "       /     \.___.d|    .'";
                        j=37;
                    }
                    else if (i == 20 && j == 12){
                        cout << "       `--..__)0000P`._.'";
                        j=36;
                    }

                    else if(i == 22 && j == 22){
                        cout << "Inatale o Linux";
                        j=36;
                    }
                    else if(i == 23 && j == 22){
                        cout << "Desenvolvedores:";
                        j=37;
                    }
                    else if(i == 24 && j == 20){
                        cout << "Matheus Evandro Rech";
                        j=39;
                    }
                    else if(i == 25 && j == 17){
                        cout << "Mateus da Silva Francelino";
                        j=42;
                    }
                    else if(i == 26 && j == 14){
                        cout << "Henrique Leonardo Beerends Junior";
                        j=46;
                    }
                    else{
                        cout << " ";
                    }
                    j++;
                }
                i++;
                cout << "\n";
            }
        }
    }
    cout << "\n";
    system("pause > NULL");
    return 0;
}
