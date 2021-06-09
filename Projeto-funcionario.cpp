/* À partir da estrutura "Funcionario" descrita abaixo:

Funcionario
  - prontuario: int
  - nome: string
  - salario: double
Elabore um programa que permita administrar uma lista de funcionários e, através de um menu, ofereça as seguintes opções:

   0. Sair
   1. Incluir
   2. Excluir
   3. Pesquisar
   4. Listar
OBSERVAÇÕES:

a) Não poderão ser cadastrados funcionários com mesmo prontuário;

b) A pesquisa de funcionário deverá utilizar o atributo "Prontuário" como critério e, quando encontrado, deverão ser exibidos os demais atributos;

c) A listagem dos funcionários deverá apresentar todos os seus atributos e, ao final, informar o total dos salários. */

#include <iostream>
using namespace std;

struct Lista
{
	int prontuario;
	double salario;
	string nome;
	struct Lista *prox;

};

Lista* init()
{
	return NULL;


}
int isEmpty(Lista* lista)
{
	return(lista == NULL);


}
Lista* insert(Lista* lista, int i, double x, string nome)
{
	Lista* novo = new Lista();
	novo->prontuario = i;
	novo->prox = lista;
	novo->salario = x;
	novo->prox = lista;
	novo->nome = nome;
	novo->prox = lista;
	return novo;

}

void print (Lista* lista)
{
	Lista *aux;
	aux = lista;
	while(aux != NULL)
	{
		cout << "Prontuario: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Salario: " << aux->salario << endl;
		cout << "======================="	<<  endl;
		aux = aux->prox;
	}
	

}

Lista* find (Lista* lista, int i, double x, string nome)
{
	Lista* aux1;
	aux1 = lista;
	Lista* aux2;
	aux2 = lista;
	Lista* aux3;
	aux3 = lista;
	while(aux1 != NULL && aux1->prontuario != i)
	{
		aux1 = aux1->prox;
		aux2 = aux2->prox;
		aux3 = aux3->prox;

	}
	return aux1;
	return aux2;
	return aux3;

}

Lista* remove(Lista* lista, int i)
{
	Lista* aux1;
	Lista *ant = NULL;
	aux1 = lista;








	while(aux1 != NULL && aux1->prontuario != i)
	{
		aux1 = aux1->prox;


	}
	ant->prox = aux1->prox;

	if(aux1 == NULL)
	{
		return lista;
	}
	if(ant == NULL)
	{
		aux1 = aux1->prox;


	}
	else
	{
		ant->prox = aux1->prox;

	}
	return lista;


}




int main(int argc, char** argv)
{
	Lista *minhaLista;
	minhaLista = init();



	int prontuario, salario, op;
	string nome = " ";
	
	do
	{   cout << endl;
		cout << "Cadastro de Funcionario" << endl;
		cout << "Painel de administracao" << endl;
		cout << "0. Sair" << endl;
		cout << "1. Incluir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;
		cout << "Informe sua opcao: " << endl;
		cin >> op;
		system("CLS");
		
		
		if (op == 1)
		{
		

			cout << "Digite o prontuario do novo funcionario" << endl;
			cin >> prontuario;
            cout << "Digite o salario do novo funcionario" << endl;
			cin >> salario;
			cout << "Digite o nome do novo funcionario" << endl;
			cin >> nome;
		    minhaLista = insert(minhaLista, prontuario, salario, nome);
			system("CLS");
			

		}
		if (op == 2)
		{       
		        cout << "Digite o prontuario que deseja excluir: ";
				cin >> prontuario;
				Lista *procurado = find(minhaLista, prontuario, salario, nome);
				if(procurado != NULL)
				{				
				 minhaLista = remove(minhaLista,prontuario);
				}
				else
				{
					cout << "Nao encontrado! " << endl;
				}
			cout << "Prontuario excluido com sucesso! ";
		}
		
		
		
		if (op == 3)
		{
			
				cout << "digite o prontuario: ";
				cin >> prontuario;
				Lista *procurado = find(minhaLista, prontuario, salario, nome);
				if(procurado != NULL)
				{
					cout << "***Dado encontrado: " <<  endl;
					cout << "Prontuario: " << procurado -> prontuario <<  endl;
					cout << "Nome " << procurado -> nome <<  endl;
					cout << "Salario " << procurado -> salario <<  endl;
					cout << "======================="	<<  endl;
				}
				else
				{
					cout << "Prontuario nao foi encontrado! " << endl;
				}
				
			
		}
		
		
		if (op == 4)
		{
                
                Lista *procurado = find(minhaLista, prontuario, salario, nome);
                if(procurado != NULL)
				{
				cout << "**Dados encontrados: " <<  endl;
				print(minhaLista);
				}
				else
				{
					cout << "Lista nao encontrada! " << endl;
				}
		
		}
	}
	while (op != 0);

	return 0;



}