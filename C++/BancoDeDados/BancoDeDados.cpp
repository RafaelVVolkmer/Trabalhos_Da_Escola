#include "CADASTRO.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");

    char opcao, continuar;
    OpcoesMenu opcoes;

        do
        {

            cout<<"=========================================="<<endl;
            cout<<"         BANCO DE DADOS DOS CRIAS         "<<endl;
            cout<<"             - agora em c++ -             "<<endl;
            cout<<"=========================================="<<endl;
            cout<<"           O que deseja fazer?            "<<endl;
            cout<<"------------------------------------------"<<endl;
            cout<<" "<<endl;
            cout<<"1 - Realizar cadastro"<<endl;
            cout<<"2 - Inciar sessao"<<endl;
            cout<<"3 - encerrar sessao"<<endl;
            cout<<" "<<endl;
            cout<<"------------------------------------------"<<endl;
            cout<<" "<<endl;
            cout<<"Opcao escolhida: ";

            cin>>opcao;

                if(opcao == '1')
                {

                    system("cls");

                opcoes.Formulario_De_Inscricao();

                }

                if(opcao == '2')
                {

                    system("cls");

                    opcoes.Iniciar_Sessao();

                }

                if(opcao == '3')
                {

                    system("cls");

                    opcoes.Encerrar_Sessao();

                        return 0;

                }

            cin.clear();

            cout<<" "<<endl;
            cout<<"Deseja continuar? (S ou N)"<<endl;

            cin>>continuar;

            continuar = toupper(continuar);

            system("cls");

        }while(continuar == 'S');

    system("cls");

    opcoes.Encerrar_Sessao();

        return 0;
}
