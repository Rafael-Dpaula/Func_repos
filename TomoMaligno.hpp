#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int inputI(string msg, int variavel)
{
    cout << msg;
    cin >> variavel;
    return variavel;
}

float inputF(string msg, float variavel)
{
    cout << msg;
    cin >> variavel;
    return variavel;
}

string inputS(string msg, string variavel)
{
    cout << msg;
    cin >> variavel;
    return variavel;
}

void menu_gen(int opcoes, string vetOpcoes[10], int &entradaRes)
{
    cout << "===== MENU =====" << endl;
    for (int i = 0; i < opcoes; i++)
    {
        cout << i + 1 << " - " << vetOpcoes[i] << endl;
    }
    cout << endl
         << endl
         << "----> ";
    cin >> entradaRes;
}

void matrizQuad_float_gen(int ordem, float matriz[][100])
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
}

void matrizQuad_int_gen(int ordem, int matriz[][100])
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
}

void vetor_int_gen(int idx, int vetor[])
{
    for (int i = 0; i < idx; i++)
    {
        vetor[i] = rand() % 100 + 1;
    }
}

void vetor_float_gen(int idx, float vetor[])
{
    for (int i = 0; i < idx; i++)
    {
        vetor[i] = rand() % 100 + 1;
    }
}

void add_vetor_string(int posAtual, string info, string vetor[])
{
    vetor[posAtual] = info;
}

void ord_vetor_int_C(int idx, int vetor[])
{
    int aux;
    for (int i = 0; i < idx; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void ord_vetor_int_D(int idx, int vetor[])
{
    int aux;
    for (int i = 0; i < idx; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vetor[j] < vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void ord_vetor_float_C(int idx, float vetor[])
{
    float aux;
    for (int i = 0; i < idx; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void ord_vetor_float_D(int idx, float vetor[])
{
    float aux;
    for (int i = 0; i < idx; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vetor[j] < vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void ord_matrizQuad_int_C(int ordem, int matriz[][100])
{
    int aux;
    for (int linha = 0; linha < ordem; linha++)
    {
        for (int coluna = 0; coluna < ordem; coluna++)
        {
            for (int i = 0; i < ordem; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if ((linha * ordem + coluna) < (i * ordem + j))
                    {
                        if (matriz[linha][coluna] > matriz[i][j])
                        {
                            aux = matriz[linha][coluna];
                            matriz[linha][coluna] = matriz[i][j];
                            matriz[i][j] = aux;
                        }
                    }
                }
            }
        }
    }
}

void ord_matrizQuad_int_D(int ordem, int matriz[][100])
{
    int aux;
    for (int linha = 0; linha < ordem; linha++)
    {
        for (int coluna = 0; coluna < ordem; coluna++)
        {
            for (int i = 0; i < ordem; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if ((linha * ordem + coluna) > (i * ordem + j))
                    {
                        if (matriz[linha][coluna] < matriz[i][j])
                        {
                            aux = matriz[linha][coluna];
                            matriz[linha][coluna] = matriz[i][j];
                            matriz[i][j] = aux;
                        }
                    }
                }
            }
        }
    }
}

void ord_matrizQuad_float_C(int ordem, float matriz[][100])
{
    float aux;
    for (int linha = 0; linha < ordem; linha++)
    {
        for (int coluna = 0; coluna < ordem; coluna++)
        {
            for (int i = 0; i < ordem; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if ((linha * ordem + coluna) < (i * ordem + j))
                    {
                        if (matriz[linha][coluna] > matriz[i][j])
                        {
                            aux = matriz[linha][coluna];
                            matriz[linha][coluna] = matriz[i][j];
                            matriz[i][j] = aux;
                        }
                    }
                }
            }
        }
    }
}

void ord_matrizQuad_float_D(int ordem, float matriz[][100])
{
    float aux;
    for (int linha = 0; linha < ordem; linha++)
    {
        for (int coluna = 0; coluna < ordem; coluna++)
        {
            for (int i = 0; i < ordem; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if ((linha * ordem + coluna) > (i * ordem + j))
                    {
                        if (matriz[linha][coluna] < matriz[i][j])
                        {
                            aux = matriz[linha][coluna];
                            matriz[linha][coluna] = matriz[i][j];
                            matriz[i][j] = aux;
                        }
                    }
                }
            }
        }
    }
}

void matriz_gen_int(int linha, int coluna, int matriz[][100])
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
}

void matriz_gen_float(int linha, int coluna, float matriz[][100])
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j] = rand() % 100 + 1;
        }
    }
}

void mostrar_matrizQuad_int(int ordem, int matriz[][100])
{
    for (int i = 0; i < ordem; i++)
    {
        cout << "\tC" << i;
    }
    cout << endl;
    for (int i = 0; i < ordem; i++)
    {
        cout << "L" << i;
        for (int j = 0; j < ordem; j++)
        {
            cout << "\t" << matriz[i][j];
        }
        cout << endl;
    }
}

void mostrar_matrizQuad_float(int ordem, float matriz[][100])
{
    for (int i = 0; i < ordem; i++)
    {
        cout << "\tC" << i;
    }
    cout << endl;
    for (int i = 0; i < ordem; i++)
    {
        cout << "L" << i;
        for (int j = 0; j < ordem; j++)
        {
            cout << "\t" << matriz[i][j];
        }
        cout << endl;
    }
}

void mostrar_matriz_int(int linha, int coluna, int matriz[][100])
{
    for (int i = 0; i < coluna; i++)
    {
        cout << "\tC" << i;
    }
    cout << endl;
    for (int i = 0; i < linha; i++)
    {
        cout << "L" << i;
        for (int j = 0; j < coluna; j++)
        {
            cout << "\t" << matriz[i][j];
        }
        cout << endl;
    }
}

void mostrar_matriz_float(int linha, int coluna, float matriz[][100])
{
    for (int i = 0; i < coluna; i++)
    {
        cout << "\tC" << i;
    }
    cout << endl;
    for (int i = 0; i < linha; i++)
    {
        cout << "L" << i;
        for (int j = 0; j < coluna; j++)
        {
            cout << "\t" << matriz[i][j];
        }
        cout << endl;
    }
}

void mostrar_vetor_int(int idx, int vetor[])
{
    cout << "VET[" << idx << "]: {";
    for (int i = 0; i < idx; i++)
    {
        cout << vetor[i];
        if (i != (idx - 1))
        {
            cout << ", ";
        }
    }
    cout << "};" << endl;
}

void mostrar_vetor_float(int idx, float vetor[])
{
    cout << "VET[" << idx << "]: {";
    for (int i = 0; i < idx; i++)
    {
        cout << vetor[i];
        if (i != (idx - 1))
        {
            cout << ", ";
        }
    }
    cout << "};" << endl;
}

void leitura_cin(string arq, string vetor[])
{
    ifstream leitura;
    leitura.open(arq);
    string txt;
    int idx = -1;
    if (leitura.good())
    {
        while (!leitura.eof())
        {
            idx++;
            leitura >> txt;
            vetor[idx] = txt;
        }
        leitura.close();
    }
    else
    {
        cout << "ERRO: erro de acesso no doc:" << arq << endl;
    }
}

void leitura_cin_limitada(string arq, string vetor[], int limite)
{
    ifstream leitura;
    leitura.open(arq);
    string txt;
    string aux;
    int idx = -1;
    if (leitura.good())
    {
        while (!leitura.eof())
        {
            idx++;
            leitura >> txt;
            vetor[idx] = txt;
            if (idx % limite == 0)
            {
                getline(leitura, aux);
            }
        }
        leitura.close();
    }
    else
    {
        cout << "ERRO: erro de acesso no doc:" << arq << endl;
    }
}

void reescrita_vetorial(string arq, string vetor[], int idx) // separado com espaço, pega pelo "Cin" da leitura.
{
    ofstream escrita;
    escrita.open(arq, ios::out | ios::trunc);
    if (escrita.good())
    {
        for (int i = 0; i < idx; i++)
        {
            if (!vetor[i].empty())
            {
                escrita << vetor[i] << " ";
            }
        }
        escrita.close();
    }
    else
    {
        cout << "ERRO: erro de acesso no doc:" << arq << endl;
    }
}

float media_vetor_float(int idx, float vetor[])
{
    float soma = 0;
    for (int i = 0; i < idx; i++)
    {
        soma += vetor[i];
    }
    return (soma / idx);
}

float media_vetor_int(int idx, int vetor[])
{
    float soma = 0;
    for (int i = 0; i < idx; i++)
    {
        soma += vetor[i];
    }
    return (soma / idx);
}

float mediaHarmonica_vetor_float(int idx, float vetor[])
{
    float soma = 0;
    for (int i = 0; i < idx; i++)
    {
        soma += (1 / vetor[i]);
    }
    return (idx / soma);
}

float mediaHarmonica_vetor_int(int idx, int vetor[])
{
    float soma = 0;
    for (int i = 0; i < idx; i++)
    {
        soma += (1 / vetor[i]);
    }
    return (idx / soma);
}

void alert(string aviso)
{
    for (int i = 0; aviso[i] != '\0'; i++)
    {
        aviso[i] = tolower(aviso[i]);
    }
    cout << "ERROR: " << aviso << "." << endl;
}

bool isPalindromo(string txt)
{
    int idx = 0;
    for (int i = 0; txt[i] != '\0'; i++)
    {
        idx++;
    }
    string contrario, txtC;
    for (int i = 0; i < idx; i++)
    {
        txtC += txt[i];
    }
    for (int i = idx - 1; i >= 0; i--)
    {
        contrario += txt[i];
    }

    return txtC == contrario;
}

bool isPar(int num)
{
    return (num % 2 == 0);
}

int tamanho_string(string txt)
{
    int idx = 0;
    for (int i = 0; txt[i] != '\0'; i++)
    {
        idx++;
    }
    return idx;
}
