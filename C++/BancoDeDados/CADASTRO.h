#ifndef CADASTRO_H_INCLUDED
#define CADASTRO_H_INCLUDED

#include "USUARIO.h"

class OpcoesMenu
{

public:

    //Vetor onde guardarei todos os parâmetros de todos os objetos
    static vector<Usuario> lista;

    //Método que captura os parametros e cria o objeto
    void Formulario_De_Inscricao()
    {

        Usuario NovoUsuario;

        string email;
        string senha;

        string nome;
        string sexo;
        string data_de_nasc;
        int idade;

        ofstream ofs("Banco_De_Dados.txt", fstream::app);

        cout<<"================================="<<endl;
        cout<<"       PÁGINA DE CADASTRO        "<<endl;
        cout<<"================================="<<endl;

        cout<<"Digite seu email: ";
        cin>>email;
        NovoUsuario.Set_Email(email);
        cin.clear();

        cout<<"Digite sua senha: ";
        cin>>senha;
        NovoUsuario.Set_Senha(senha);
        cin.clear();

        cout<<"\nDigite seu nome: ";
        cin>>nome;
        NovoUsuario.Set_Nome(nome);
        cin.clear();

        cout<<"Digite seu sexo: ";
        cin>>sexo;
        NovoUsuario.Set_Sexo(sexo);
        cin.clear();

        cout<<"Digite sua data de nascimento: ";
        cin>>data_de_nasc;

        NovoUsuario.Set_Data(data_de_nasc);
        cin.clear();

        NovoUsuario.Set_Idade(data_de_nasc);

        cout<<" "<<endl;
        cout<<"- Cadastro concluido com sucesso -"<<endl;

        //Grava esse objeto dentro de um arquivo
        ofs * NovoUsuario;

        ofs.close();

    }

    //Método que todos os parâmetros do objeto em forma de texto
    void Lista_Usuarios()
    {


        for(Usuario infos : lista)
        {

            cout<<infos<<endl;

        }

    }

    //Método que, a partir do fornecimento de um email e uma senha, exibe os dados
    void Iniciar_Sessao()
    {

        Usuario UsuarioGravado;

        string email;
        string senha;

        ifstream ifs("Banco_De_Dados.txt");

        //Quando for possível ler o arquivo
        if(ifs.good())
        {
            //Até o arquivo chegar no final
            while(!ifs.eof())
            {
                //Tira todo o conteúdo do arquivo e bota nesse objeto
                ifs >> UsuarioGravado;

                //Adiciona todo o conteúdo do arquivo no vetor
                lista.push_back(UsuarioGravado);
            }
        }

        cout<<"================================="<<endl;
        cout<<"         PÁGINA DE LOGIN         "<<endl;
        cout<<"================================="<<endl;

        cout<<"Digite seu email: ";
        cin>>email;
        cin.clear();

        cout<<"Digite sua senha: ";
        cin>>senha;
        cin.clear();

        //Captura os elementos de vetor e analisa eles, procurando um email e uma senha compatíveis
        auto user_iterator = find_if(
                                       OpcoesMenu::lista.begin(),
                                       OpcoesMenu::lista.end(),
                                       [=](Usuario user){ return (user.Get_Email() == email
                                                                            &&
                                                                  user.Get_Senha() == senha);
                                                     }
                                     );


        //caso seja achado, até o fim da lista, exibe todos os parâmetros em forma de texto
        if(user_iterator != OpcoesMenu::lista.end())
        {
            cout<<*user_iterator<<endl;
        }
        else
        {
            cout<<" "<<endl;
            cout<<"Usuario nao encontrado"<<endl;
            cout<<" "<<endl;
        }

    ifs.close();

    }

    //Função que fecha o programa
    void Encerrar_Sessao()
    {

        cout<<""<<endl;
        cout<<"- Sessão finalizada -"<<endl;

    }

};

vector<Usuario> OpcoesMenu::lista;

#endif // CADASTRO_H_INCLUDED
