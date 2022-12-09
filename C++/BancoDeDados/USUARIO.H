#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <clocale>
#include <ctime>

using namespace std;

class Usuario
{

private:

    string email;
    string senha;

    string nome;
    string sexo;
    string data_de_nasc;
    int idade;

public:

    //Metodos para instanciar um objet e construi-lo
    string& Set_Email(string& email){this->email = email;}
    string& Set_Senha(string& senha){this->senha = senha;}
    string& Set_Nome(string& nome){this->nome = nome;}
    string& Set_Sexo(string& sexo){this->sexo = sexo;}
    string& Set_Data(string& data_de_nasc){this->data_de_nasc = data_de_nasc;}

    int Set_Idade(string& data_de_nasc)
    {

        time_t now = time(0);
        tm *ltm = localtime(&now);

        string dia = "DD", mes = "MM", ano = "AAAA";

        int dia_ = 0, mes_ = 0, ano_ = 0;

        int idade = 0;

                dia.at(0) = data_de_nasc.at(0);
                dia.at(1) = data_de_nasc.at(1);

                mes.at(0) = data_de_nasc.at(3);
                mes.at(1) = data_de_nasc.at(4);

                ano.at(0) = data_de_nasc.at(6);
                ano.at(1) = data_de_nasc.at(7);
                ano.at(2) = data_de_nasc.at(8);
                ano.at(3) = data_de_nasc.at(9);


        dia_ = stoi(dia);
        mes_ = stoi(mes);
        ano_ = stoi(ano);


        idade = ( 1900 + ltm->tm_year ) - ano_;

        if ( mes_ >= (1 + ltm->tm_mon) && ano_ >= (ltm->tm_mday) )
        {
            idade = idade;
        }

        this->idade = idade;
    }


    //Metodos para retornar os parametros do objeto
    string& Get_Email(){return email;}
    string& Get_Senha(){return senha;}
    string& Get_Nome(){return nome;}
    string& Get_Sexo(){return sexo;}
    string& Get_Data(){return data_de_nasc;}
    int Get_Idade(){return idade;}


    //Sobrecarga de operador que joga os dados do objeto pra dentro do arquivo
    friend ostream& operator*(ostream& saida, const Usuario& user)
    {

        saida<<user.email<<endl;
        saida<<user.senha<<endl;
        saida<<user.nome<<endl;
        saida<<user.sexo<<endl;
        saida<<user.data_de_nasc<<endl;
        saida<<user.idade<<endl;

        return saida;

    }

    //Sobrecarga de operador que tira os dados do objeto do arquivo
    friend istream& operator>>(istream& entrada, Usuario& user)
    {

        entrada>>user.email;
        entrada>>user.senha;
        entrada>>user.nome;
        entrada>>user.sexo;
        entrada>>user.data_de_nasc;
        entrada>>user.idade;

        return entrada;

    }

    //Sobrecarga de operador que exibe os dados da lista na função exibir lista
    friend ostream& operator<<(ostream& saida, const Usuario& user)
    {

        system("cls");

        cout<<" "<<endl;
        saida<<"-----------------------------"<<endl;
        saida<<"    Informacoes do usuário    "<<endl;
        saida<<"-----------------------------"<<endl;
        saida<<" "<<endl;
        saida<<"Nome: "<<user.nome<<endl;
        saida<<"Sexo: "<<user.sexo<<endl;
        saida<<"Data de Nascimento: "<<user.data_de_nasc<<endl;
        saida<<"Idade: "<<user.idade;

        return saida;

    }


};

#endif // USUARIO_H_INCLUDED
