#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

// exemplo de inclusão de repositório de funçoes
// #include "caminho relativo/absoluto do repositório"

int inputI(string msg, int &variavel)
{
    cout << msg;
    cin >> variavel;
    return variavel;
}

float inputF(string msg, float &variavel)
{
    cout << msg;
    cin >> variavel;
    return variavel;
}

string inputS(string msg, string &variavel)
{
    cout << msg;
    cin >> variavel;
    return variavel;
}

void menu_gen(int opcoes, string vetOpcoes[10], int &entradaRes)
{
    if (opcoes > 10)
    {
        cout << "ERROR: risco de overflow de function.";
        return;
    }
    cout << "===== MENU =====" << endl;
    for (int i = 0; i < opcoes; i++)
    {
        cout << i << " - " << vetOpcoes[i] << endl;
    }
    cout << endl
         << endl
         << "----> ";
    cin >> entradaRes;
}

void matriz_gen_int(int linha, int coluna, int matriz[][100], int maior, int menor)
{
    int mid = maior - menor;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            bool unico = false;
            while (!unico)
            {
                matriz[i][j] = rand() % mid + menor;
                unico = true;
                for (int p = 0; p < i; p++)
                {
                    for (int q = 0; q < coluna; q++)
                    {
                        if (matriz[p][q] == matriz[i][j])
                        {
                            unico = false;
                            break;
                        }
                    }
                    if (!unico)
                        break;
                }
                if (unico)
                {
                    for (int k = 0; k < j; k++)
                    {
                        if (matriz[i][k] == matriz[i][j])
                        {
                            unico = false;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void matriz_gen_float(int linha, int coluna, float matriz[][100], int menor, int maior)
{
    int mid = maior - menor;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            bool unico = false;
            while (!unico)
            {
                matriz[i][j] = menor + (rand() % (mid * 100)) / 100.0;
                unico = true;
                for (int p = 0; p < i; p++)
                {
                    for (int q = 0; q < coluna; q++)
                    {
                        if (matriz[p][q] == matriz[i][j])
                        {
                            unico = false;
                            break;
                        }
                    }
                    if (!unico)
                        break;
                }
                if (unico)
                {
                    for (int k = 0; k < j; k++)
                    {
                        if (matriz[i][k] == matriz[i][j])
                        {
                            unico = false;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void vetor_int_gen(int idx, int vetor[], int menor, int maior)
{
    int mid = maior - menor;
    for (int i = 0; i < idx; i++)
    {
        bool unico = false;
        while (!unico)
        {
            vetor[i] = rand() % mid + menor;
            unico = true;
            for (int j = 0; j < i; j++)
            {
                if (vetor[j] == vetor[i])
                {
                    unico = false;
                    break;
                }
            }
        }
    }
}

void vetor_float_gen(int idx, float vetor[], int menor, int maior)
{
    int mid = maior - menor;
    for (int i = 0; i < idx; i++)
    {
        bool unico = false;
        while (!unico)
        {
            vetor[i] = menor + (rand() % (mid * 100)) / 100.0;
            unico = true;
            for (int j = 0; j < i; j++)
            {
                if (vetor[j] == vetor[i])
                {
                    unico = false;
                    break;
                }
            }
        }
    }
}

void add_vetor_string(int posAtual, string info, string vetor[])
{
    vetor[posAtual] = info;
}

void ordena_vetor_int(int vetor[], char ordem, int idx)
{
    int aux;
    if (tolower(ordem) == 'd')
    {
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

    if (tolower(ordem) == 'c')
    {
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
}

void ordena_vetor_float(float vetor[], char ordem, int idx)
{
    float aux;
    if (tolower(ordem) == 'd')
    {
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

    if (tolower(ordem) == 'c')
    {
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
}

void ord_matriz_float(float matriz[][100], int linha, int coluna, char ordenacao)
{
    int total = linha * coluna;
    if (tolower(ordenacao) == 'd')
    {
        for (int k = 0; k < total - 1; k++)
        {
            for (int l = 0; l < total - 1 - k; l++)
            {
                int linha1 = l / coluna;
                int col1 = l % coluna;
                int linha2 = (l + 1) / coluna;
                int col2 = (l + 1) % coluna;
                if (matriz[linha1][col1] < matriz[linha2][col2])
                {
                    float aux = matriz[linha1][col1];
                    matriz[linha1][col1] = matriz[linha2][col2];
                    matriz[linha2][col2] = aux;
                }
            }
        }
    }

    if (tolower(ordenacao) == 'c')
    {
        for (int k = 0; k < total - 1; k++)
        {
            for (int l = 0; l < total - 1 - k; l++)
            {
                int linha1 = l / coluna;
                int col1 = l % coluna;
                int linha2 = (l + 1) / coluna;
                int col2 = (l + 1) % coluna;
                if (matriz[linha1][col1] > matriz[linha2][col2])
                {
                    float aux = matriz[linha1][col1];
                    matriz[linha1][col1] = matriz[linha2][col2];
                    matriz[linha2][col2] = aux;
                }
            }
        }
    }
}

void ord_matriz_int(int matriz[][100], int linha, int coluna, char ordenacao)
{
    int total = linha * coluna;
    if (tolower(ordenacao) == 'd')
    {
        for (int k = 0; k < total - 1; k++)
        {
            for (int l = 0; l < total - 1 - k; l++)
            {
                int linha1 = l / coluna;
                int col1 = l % coluna;
                int linha2 = (l + 1) / coluna;
                int col2 = (l + 1) % coluna;
                if (matriz[linha1][col1] < matriz[linha2][col2])
                {
                    int aux = matriz[linha1][col1];
                    matriz[linha1][col1] = matriz[linha2][col2];
                    matriz[linha2][col2] = aux;
                }
            }
        }
    }

    if (tolower(ordenacao) == 'c')
    {
        for (int k = 0; k < total - 1; k++)
        {
            for (int l = 0; l < total - 1 - k; l++)
            {
                int linha1 = l / coluna;
                int col1 = l % coluna;
                int linha2 = (l + 1) / coluna;
                int col2 = (l + 1) % coluna;
                if (matriz[linha1][col1] > matriz[linha2][col2])
                {
                    float aux = matriz[linha1][col1];
                    matriz[linha1][col1] = matriz[linha2][col2];
                    matriz[linha2][col2] = aux;
                }
            }
        }
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

void leitura_cin_limitada(string arq, string vetor[], int limite) // leitura pelo "Cin", documento com certa quantidade especifica de info em cada linha
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

void leitura_linha(string arq, string vetor[])
{
    ifstream leitura;
    int idx = -1;
    leitura.open(arq);
    if (leitura.good())
    {
        string aux;
        while (!leitura.eof())
        {
            idx++;
            getline(leitura, aux);
            vetor[idx] = aux;
        }
        leitura.close();
    }
    else
    {
        cout << "ERRO: erro de acesso no doc:" << arq << endl;
    }
}

void leitura_limitada_carac(string arq, string vetor[], char limitador) // leitura separado por caracteres, como virgula, ponto e virgula, etc...
{
    ifstream leitura;
    leitura.open(arq);
    if (leitura.good())
    {
        char txt[256];
        int idx = 0;
        while (!leitura.eof())
        {
            leitura.getline(txt, 256, limitador);
            vetor[idx] = string(txt);
            idx++;
        }
        leitura.close();
    }
    else
    {
        cout << "ERRO: erro de acesso no doc:" << arq << endl;
    }
}

void reescrita_vetor(string arq, string vetor[], int idx) // separado com espaço, pega pelo "Cin" da leitura.
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

void escrita_vetor(string arq, string vetor[], int idx) // inserindo no final separado com espaço, pega pelo "Cin" da leitura.
{
    ofstream escrita;
    escrita.open(arq, ios::app);
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
        if (vetor[i] != 0)
        {
            soma += (1 / vetor[i]);
        }
    }
    return (idx / soma);
}

float mediaHarmonica_vetor_int(int idx, int vetor[])
{
    float soma = 0;
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] != 0)
        {
            soma += (1 / vetor[i]);
        }
    }
    return (idx / soma);
}

void error(string aviso)
{
    cout << "ERROR: " << aviso << "." << endl;
}

void alert(string aviso)
{
    cout << "ALERT: " << aviso << "." << endl;
}

bool isPalindromo(string txt)
{
    int idx = 0;
    string contrario;
    for (int i = 0; txt[i] != '\0'; i++)
    {
        idx++;
    }
    for (int i = idx - 1; i >= 0; i--)
    {
        contrario += txt[i];
    }

    return txt == contrario;
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

int intersec_int_vetor(int vetor1[], int vetor2[], int intersec[], int idx1, int idx2)
{
    int idxI = 0;
    for (int i = 0; i < idx1; i++)
    {
        for (int j = 0; j < idx2; j++)
        {
            if (vetor1[i] == vetor2[j])
            {
                intersec[idxI] = vetor1[i];
                idxI++;
                break;
            }
        }
    }
    return idxI;
}

int intersec_float_vetor(float vetor1[], float vetor2[], int idx1, int idx2, float intersec[])
{
    int idxI = 0;
    for (int i = 0; i < idx1; i++)
    {
        for (int j = 0; j < idx2; j++)
        {
            if (vetor1[i] == vetor2[j])
            {
                intersec[idxI] = vetor1[i];
                idxI++;
                break;
            }
        }
    }
    return idxI;
}

float precisao(float num, int casas)
{
    cout << fixed;
    cout.precision(casas);
    return num;
}

void convert_string_int_vetor(string vetorS[], int vetor[], int idx)
{
    char str[256];
    for (int i = 0; i < idx; i++)
    {
        strcpy(str, vetorS[i].c_str());
        vetor[i] = atoi(str);
    }
}

void convert_string_float_vetor(string vetorS[], float vetor[], int idx)
{
    char str[256];
    for (int i = 0; i < idx; i++)
    {
        strcpy(str, vetorS[i].c_str());
        vetor[i] = atof(str);
    }
}

void convert_string_char_vetor(string vetorS[], char vetor[][256], int idx)
{
    for (int i = 0; i < idx; i++)
    {
        if (!vetorS[i].empty())
        {
            strcpy(vetor[i], vetorS[i].c_str());
        }
        else
        {
            vetor[i][0] = '\0';
        }
    }
}

void leitura_limitada_carac_matriz_float(string arq, float matriz[][100], char limitador, int linha, int coluna)
{
    ifstream leitura;
    leitura.open(arq);
    if (leitura.good())
    {
        char txt[256];
        int idx = -1;
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                leitura.getline(txt, 256, limitador);
                matriz[i][j] = atof(txt);
            }
        }
        leitura.close();
    }
    else
    {
        cout << "ERRO: erro de acesso no doc:" << arq << endl;
    }
}

void leitura_limitada_carac_matriz_int(string arq, int matriz[][100], char limitador, int linha, int coluna)
{
    ifstream leitura;
    leitura.open(arq);
    if (leitura.good())
    {
        char txt[256];
        int idx = -1;
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                leitura.getline(txt, 256, limitador);
                matriz[i][j] = atoi(txt);
            }
        }
        leitura.close();
    }
    else
    {
        cout << "ERRO: erro de acesso no doc:" << arq << endl;
    }
}

void mostrar_matriz_transposta_int(int linha, int coluna, int matriz[][100])
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
            cout << "\t" << matriz[j][i];
        }
        cout << endl;
    }
}

void mostrar_diagPrin_int(int ordem, int matriz[][100])
{

    bool primeira = true;
    cout << "ELEMENTOS DIAGONAL PRINCIPAL = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i == j)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ABAIXO DA DIAGONAL PRINCIPAL = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i > j)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ACIMA DA DIAGONAL PRINCIPAL = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i < j)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;
}

void mostrar_diagSec_int(int ordem, int matriz[][100])
{
    bool primeira = true;
    cout << "ELEMENTOS DIAGONAL SECUNDÁRIA = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i + j == ordem - 1)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ABAIXO DA DIAGONAL SECUNDÁRIA = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i + j > ordem - 1)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ACIMA DA DIAGONAL SECUNDÁRIA = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i + j < ordem - 1)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;
}

void mostrar_matriz_transposta_float(int linha, int coluna, float matriz[][100])
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
            cout << "\t" << matriz[j][i];
        }
        cout << endl;
    }
}

void mostrar_diagPrin_float(int ordem, float matriz[][100])
{

    bool primeira = true;
    cout << "ELEMENTOS DIAGONAL PRINCIPAL = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i == j)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ABAIXO DA DIAGONAL PRINCIPAL = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i > j)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ACIMA DA DIAGONAL PRINCIPAL = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i < j)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;
}

void mostrar_diagSec_float(int ordem, float matriz[][100])
{
    bool primeira = true;
    cout << "ELEMENTOS DIAGONAL SECUNDÁRIA = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i + j == ordem - 1)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ABAIXO DA DIAGONAL SECUNDÁRIA = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i + j > ordem - 1)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;

    primeira = true;
    cout << "ELEMENTOS ACIMA DA DIAGONAL SECUNDÁRIA = {";
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (i + j < ordem - 1)
            {
                if (!primeira)
                {
                    cout << ", ";
                }
                cout << matriz[i][j];
                primeira = false;
            }
        }
    }
    cout << "};" << endl;
}

void trocarPos_vetor_int(int vetor[], int pos1, int pos2)
{
    int aux;
    aux = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = aux;
}

void trocarPos_vetor_float(float vetor[], int pos1, int pos2)
{
    float aux;
    aux = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = aux;
}

void trocarPos_vetor_string(string vetor[], int pos1, int pos2)
{
    string aux;
    aux = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = aux;
}

void trocarPos_matriz_int(int matriz[][100], int linhaPos1, int colunaPos1, int linhaPos2, int colunaPos2)
{
    int aux;
    aux = matriz[linhaPos1][colunaPos1];
    matriz[linhaPos1][colunaPos1] = matriz[linhaPos2][colunaPos2];
    matriz[linhaPos2][colunaPos2] = aux;
}

void trocarPos_matriz_float(float matriz[][100], int linhaPos1, int colunaPos1, int linhaPos2, int colunaPos2)
{
    float aux;
    aux = matriz[linhaPos1][colunaPos1];
    matriz[linhaPos1][colunaPos1] = matriz[linhaPos2][colunaPos2];
    matriz[linhaPos2][colunaPos2] = aux;
}

int maior_vetor_int(int vetor[], int idx)
{
    float maior = vetor[0];
    int idxM = 0;
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
            idxM = i;
        }
    }
    return idxM;
}

int maior_vetor_float(float vetor[], int idx)
{
    float maior = vetor[0];
    int idxM = 0;
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
            idxM = i;
        }
    }
    return idxM;
}

int menor_vetor_int(int vetor[], int idx)
{
    float menor = vetor[0];
    int idxM = 0;
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
            idxM = i;
        }
    }
    return idxM;
}

int menor_vetor_float(float vetor[], int idx)
{
    float menor = vetor[0];
    int idxM = 0;
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
            idxM = i;
        }
    }
    return idxM;
}

int maior_matriz_int(int matriz[][100], int linha, int coluna)
{
    int maior = matriz[0][0];
    int idxL = 0, idxC = 0;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                idxL = i;
                idxC = j;
            }
        }
    }
    return maior;
}

float maior_matriz_float(float matriz[][100], int linha, int coluna)
{
    float maior = matriz[0][0];
    int idxL = 0, idxC = 0;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                idxL = i;
                idxC = j;
            }
        }
    }
    return maior;
}

int menor_matriz_int(int matriz[][100], int linha, int coluna)
{
    int menor = matriz[0][0];
    int idxL = 0, idxC = 0;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                idxL = i;
                idxC = j;
            }
        }
    }
    return menor;
}

float menor_matriz_float(float matriz[][100], int linha, int coluna)
{
    float menor = matriz[0][0];
    int idxL = 0, idxC = 0;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                idxL = i;
                idxC = j;
            }
        }
    }
    return menor;
}

int buscar_vetor_int(int vetor[], int idx, int busca)
{
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] == busca)
        {
            return i;
        }
    }
    cout << "ALERT: não encontrado." << endl;
    return -1;
}

int buscar_vetor_float(float vetor[], int idx, float busca)
{
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] == busca)
        {
            return i;
        }
    }
    cout << "ALERT: não encontrado." << endl;
    return -1;
}

int buscar_vetor_string(string vetor[], int idx, string busca)
{
    for (int i = 0; i < idx; i++)
    {
        if (vetor[i] == busca)
        {
            return i;
        }
    }
    cout << "ALERT: não encontrado." << endl;
    return -1;
}