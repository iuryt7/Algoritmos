#include <iostream> // básico do básico
#include <cmath> // operacoes matematicas
#include <algorithm> // sort
#include <list> // para a pilha
#include <cstdlib> // para limpar o terminal
#include <windows.h> // para usar o sleep

// tirar o vetor de pontos do item e usar só na main

using namespace std;

// predefinição dos niveis para usar int ao invés de string
string nivel[3] = {"Fraco", "Moderado", "Excelente"};

struct ponto {
	float x;
	float y;
};
typedef ponto vetor;

struct reta {
	ponto A;
	ponto B;
};
typedef reta segmento;

// struct que define o item
struct Item {
	int id;
	int nivel;
	string nome;
	string propriedadeMagica;
	string cor;
};

// Definição da estrutura de um nó da árvore
struct Node {
	Item item;
	Node * left;
	Node * right;
};

vetor cria_vetor(ponto A, ponto B) {
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B) {
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B) {
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

float area_triangulo(ponto A, ponto B, ponto C) {
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

/*
Posicao de C em relacao ao segmento AB
1 -> esquerda
-1 -> direita
0 -> colinear
*/
int sentido(ponto A, ponto B, ponto C) {
	vetor AB;
	vetor AC;
	float vet;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	vet = vetorial(AB, AC);
	if(vet > 0)
		return 1;
	else if(vet < 0)
		return -1;
	else
		return 0;
}

/*
Verifica se o ponto P esta dentro do triangulo ABC
1 -> dentro
-1 -> fora
0 -> na linha
*/
int dentro_triangulo(ponto A, ponto B, ponto C, ponto P) {
	int s1, s2, s3;
	s1 = sentido(A, B, P);
	s2 = sentido(B, C, P);
	s3 = sentido(C, A, P);
	if(s1 == s2 && s2 == s3)
		return 1;
	else if(s1 * s3 == -1 || s1 * s2 == -1 || s2 * s3 == -1)
		return -1;
	else
		return 0;
}

// Os pontos devem estar ordenados pelo angulo
// O poligono deve ser convexo
// Retorna a area do poligono
float area_poligono(ponto v[], int n) {
	float area = 0;
	for(int i = 0; i < n - 2; i++) {
		area = area + area_triangulo(v[0], v[i + 1], v[i + 2]);
	}
	return area;
}


// Verifica se um ponto pertence a um segmento
bool ponto_segmento(segmento S, ponto P) {
	if(sentido(S.A, S.B, P) != 0)
		return false;
	else if(P.x > S.A.x && P.x < S.B.x)
		return true;
	else if(P.x < S.A.x && P.x > S.B.x)
		return true;
	else if(P.y < S.A.y && P.y > S.B.y)
		return true;
	else if(P.y > S.A.y && P.y < S.B.y)
		return true;
	else
		return false;
}

// funcao para comparar dois pontos durante a ordenacao
bool cmp(ponto a, ponto b) {
	// atan2((a.y - 0),(a.x - 0)) -> arco tangente[(a.y - 0)/(a.x - 0)]
	float angA = atan2(a.y, a.x);
	float angB = atan2(b.y, b.x);
	if(angA == angB) { // se os angulos forem iguais, desempata pelo mais longe
		float distA = sqrt(pow(a.x, 2) + pow(a.y, 2)); // raiz[(a.x - 0)^2 + (a.y - 0)^2]
		float distB = sqrt(pow(b.x, 2) + pow(b.y, 2)); // raiz[(b.x - 0)^2 + (b.y - 0)^2]
		return distA > distB; // primeiro o de maior distancia
	} else
		return angA < angB; // primeiro o de menor angulo
}

// funcao para ordenar os pontos de acordo com o angulo formado com a horizontal
void ordena_pelo_angulo(ponto p[], int n) {
	ponto pivot; // será o ponto mais abaixo
	int pos_pivot;
	// encontro o ponto mais abaixo para ser o pivot
	pivot = p[0];
	pos_pivot = 0;
	for(int i = 1; i < n; i++) {
		if(p[i].y < pivot.y) {
			pivot = p[i];
			pos_pivot = i;
		} else if(p[i].y == pivot.y && p[i].x < pivot.x) {
			pivot = p[i];
			pos_pivot = i;
		}
	}

	// coloca o pivot na posicao 0 do vetor
	p[pos_pivot] = p[0];
	p[0] = pivot;

	// desloca o pivot para (0,0), e os demais pontos em relacao ao pivot
	for(int i = 0; i < n; i++) {
		p[i].x -= pivot.x;
		p[i].y -= pivot.y;
	}

	// ordenacao
	sort(p + 1, p + n, cmp);

	// desloca os pontos de volta a posicao original
	for(int i = 0; i < n; i++) {
		p[i].x += pivot.x;
		p[i].y += pivot.y;
	}
}

// penultimo da pilha
ponto next_to_top(list <ponto> pilha) {
	pilha.pop_back();
	return pilha.back();
}

// Encontra o fecho convexo de um conjunto de pontos
// retorna uma lista com os pontos que compoem o fecho convexo
list <ponto> Graham_scan(ponto p[], int n) {
	list <ponto> pilha;

	ordena_pelo_angulo(p, n);

	pilha.push_back(p[0]);
	pilha.push_back(p[1]);
	pilha.push_back(p[2]);
	int i = 3;
	while(i < n) {
		// curva a esquerda, adiciona
		if(sentido(next_to_top(pilha), pilha.back(), p[i]) == 1) {
			pilha.push_back(p[i]);
			i++;
		}
		// curva a direita (ou mesma linha), remove
		else
			pilha.pop_back();
	}
	return pilha;
}

// Função para criar um novo nó na árvore
Node * newNode(Item item) {
	Node * node = new Node();
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Função para inserir um novo nó na árvore
// teste: 1-nome 2-propriedade mágica
Node * insert(Node * node, Item item, int teste) {
	// Caso a raiz seja nula, criamos um novo nó com o dado fornecido
	if (node == NULL) {
		node = newNode(item);
		return node;
	}

	if(teste == 1) {
		// Se o dado fornecido for menor que o dado da raiz, inserimos na subárvore esquerda
		if (item.nome < node->item.nome) {
			node->left = insert(node->left, item, teste);
		}

		// Se o dado fornecido for maior que o dado da raiz, inserimos na subárvore direita
		else if (item.nome >= node->item.nome) {
			node->right = insert(node->right, item, teste);
		}
	}

	if(teste == 2) {
		// Se o dado fornecido for menor que o dado da raiz, inserimos na subárvore esquerda
		if (item.propriedadeMagica < node->item.propriedadeMagica) {
			node->left = insert(node->left, item, teste);
		}

		// Se o dado fornecido for maior que o dado da raiz, inserimos na subárvore direita
		else if (item.propriedadeMagica >= node->item.propriedadeMagica) {
			node->right = insert(node->right, item, teste);
		}
	}

	return node;
}

// Função para realizar a pesquisa na árvore binária
Node * search(Node * node, string key) {
	// Caso base: a árvore está vazia ou a chave é igual à chave do nó atual
	if(node == NULL || node->item.nome == key)
		return node;

	// Se a chave é maior que a chave do nó atual, a pesquisa continua na subárvore direita
	if(node->item.nome < key)
		return search(node->right, key);

	// Se a chave é menor que a chave do nó atual, a pesquisa continua na subárvore esquerda
	return search(node->left, key);
}

// acha o nó mais a esquerda
Node * findMin(Node * node) {
	while(node->left != NULL) {
		node = node->left;
	}
	return node;
}

// Função para remover nós da árvore binária
Node * remove(Node * node, string key) {
	if(node == NULL) {
		return node;
	} else if(key < node->item.nome) {
		node->left = remove(node->left, key);
	} else if(key > node->item.nome) {
		node->right = remove(node->right, key);
	} else {
		// Caso 1: Nó folha (sem filhos)
		if(node->left == NULL && node->right == NULL) {
			delete node;
			node = NULL;
		}
		// Caso 2: Nó com apenas um filho
		else if(node->left == NULL) {
			Node * temp = node;
			node = node->right;
			delete temp;
		} else if(node->right == NULL) {
			Node * temp = node;
			node = node->left;
			delete temp;
		}
		// Caso 3: Nó com dois filhos
		else {
			Node * temp = findMin(node->right);
			node->item = temp->item;
			node->right = remove(node->right, temp->item.nome);
		}
	}
	return node;
}

// remove todos os itens com a mesma cor
Node * removeColor(Node * node, string key) {
	if(node == NULL) {
		return node;
	} else {
		node->left = removeColor(node->left, key);
		node->right = removeColor(node->right, key);

		if(node->item.cor == key) {
			// Caso 1: Nó folha (sem filhos)
			if(node->left == NULL && node->right == NULL) {
				delete node;
				node = NULL;
			}
			// Caso 2: Nó com apenas um filho
			else if(node->left == NULL) {
				Node * temp = node;
				node = node->right;
				delete temp;
			} else if(node->right == NULL) {
				Node * temp = node;
				node = node->left;
				delete temp;
			}
			// Caso 3: Nó com dois filhos
			else {
				Node * temp = findMin(node->right);
				node->item = temp->item;
				node->right = remove(node->right, temp->item.nome);
			}
		}
	}
	return node;
}

// Função para destruir a árvore binária
void destroyTree(Node * node) {
	if(node == NULL) {
		return;
	}

	destroyTree(node->left);
	destroyTree(node->right);
	delete node;
}

// Função para mostrar valores em ordem
void emOrdem(Node * node) {
	if(node == NULL) {
		return;
	}
	emOrdem(node->left);
	cout << "-------------------------------------" << endl;
	cout << "Nome: " << node->item.nome << endl;
	cout << "Nivel: " << nivel[node->item.nivel] << endl;
	cout << "Cor: " << node->item.cor << endl;
	cout << "Propriedade magica: " << node->item.propriedadeMagica << endl;
	cout << "Id: " << node->item.id << endl;
	emOrdem(node->right);
}

// para soltar todos os itens por ordem alfabética de propriedade mágica
void emOrdemPropriedadeMagica(Node * node) {
	if(node == NULL) {
		return;
	}
	emOrdemPropriedadeMagica(node->left);
	cout << "-------------------------------------" << endl;
	cout << "Propriedade magica: " << node->item.propriedadeMagica << endl;
	cout << "Nome: " << node->item.nome << endl;
	cout << "Nivel: " << nivel[node->item.nivel] << endl;
	cout << "Cor: " << node->item.cor << endl;
	cout << "Id: " << node->item.id << endl;
	emOrdemPropriedadeMagica(node->right);
}

// conta quantos itens tem a mesma propriedade mágica
int qntPropriedadeMagica(Node * node, string key) {
	int aux = 0;
	if(node == NULL)
		return 0;
	else {
		if(node->item.propriedadeMagica == key)
			aux++;
		aux += qntPropriedadeMagica(node->left, key);
		aux += qntPropriedadeMagica(node->right, key);
	}
	return aux;
}

int preOrdemTeste(Node * node, string key, bool & achou) {
	int aux = 1;
	if(node == NULL || achou == true) {
		return 0;
	}
	if(node->item.cor == key) {
		achou = true;
	}
	aux += preOrdemTeste(node->left, key, achou);
	aux += preOrdemTeste(node->right, key, achou);
	return aux;
}

//main
int emOrdemTeste(Node * node, string key, bool & achou) {
	int aux = 0;
	if(node == NULL || achou == true) {
		return 0;
	}
	if(achou == false)
		aux += emOrdemTeste(node->left, key, achou);
	if(achou == false)
		aux++;
	if(node->item.cor == key)
		achou = true;
	if(achou == false)
		aux += emOrdemTeste(node->right, key, achou);
	return aux;
}

int posOrdemTeste(Node * node, string key, bool & achou) {
	int aux = 0;
	if(node == NULL || achou == true) {
		return 0;
	}
	if(achou == false)
		aux += posOrdemTeste(node->left, key, achou);
	if(achou == false)
		aux += posOrdemTeste(node->right, key, achou);
	if(achou == false)
		aux++;
	if(node->item.cor == key)
		achou = true;
	return aux;
}

void testePercurso(Node * node, string key) {
	bool achouPre = false, achouEm = false, achouPos = false;
	int pre = preOrdemTeste(node, key, achouPre);
	int em = emOrdemTeste(node, key, achouEm);
	int pos = posOrdemTeste(node, key, achouPos);

	/*
	cout << "pre: " << pre << endl;
	cout << "em: " << em << endl;
	cout << "pos: " << pos << endl;
	*/

	if(achouPre == false)
		cout << "Nao existe nenhum item dessa cor." << endl;
	else if(pre == em && em == pos)
		cout << "Todos os percursos encontram o item ao mesmo tempo." << endl;
	else if(pre == em)
		cout << "Os percursos \"pre ordem\" e \"em ordem\" encontram o item ao mesmo tempo." << endl;
	else if(pre == pos)
		cout << "Os percursos \"pre ordem\" e \"pos ordem\" encontram o item ao mesmo tempo." << endl;
	else if(em == pos)
		cout << "Os percursos \"em ordem\" e \"pos ordem\" encontram o item ao mesmo tempo." << endl;
	else if(pre < em && pre < pos)
		cout << "O percurso \"pre ordem\" encontra o item primeiro." << endl;
	else if(em < pre && em < pos)
		cout << "O percurso \"em ordem\" encontra o item primeiro." << endl;
	else if(pos < pre && pos < em)
		cout << "O percurso \"pos ordem\" encontra o item primeiro." << endl;
}

void introIncrivel() {
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << "Bem-vindo ao sistema de Bolsa Infinita!" << endl;
		Sleep(15);
		system("cls");
	}
	for(int i = 20; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << "Bem-vindo ao sistema de Bolsa Infinita!" << endl;
		Sleep(15);
		system("cls");
	}
}

int main() {
	Node * node = NULL; // nó principal - raiz
	Node * propriedadesMagicas = NULL; // nó para pesquisa por propriedade mágica em ordem alfabética
	Node * result = NULL; // nó resultado para buscas
	
	list <ponto> fechoConvexo; // para pegar os pontos externos de um polígono
	ponto v[10]; // pontos


	int contadorId = 0; // serve para ser um contador para inserção de ids
	int flag; // opções do menu
	int n, n2; // quantidade de repetições em for
	int auxInt; // auxiliar para entradas de int
	string auxStr; // auxiliar para entradas de string
	Item item; // item para inserção nos nós

	// a melhor intro que você irá ver hoje (e para o resto de sua vida)
	//introIncrivel();

	// opções
	do {
		// menu do usuário
		cout << "Bem-vindo ao sistema de Bolsa Infinita!" << endl <<
		"1> Inserir item" << endl <<
		"2> Pesquisar item" << endl <<
		"3> Remover item" << endl <<
		"4> Remover todos os itens da mesma cor" << endl <<
		"5> Mostrar todos os itens" << endl <<
		"6> Mostrar quantidade de itens com a mesma propriedade magica" << endl <<
		"7> Descobrir por qual percurso um item de uma cor especifica eh encontrado primeiro" << endl <<
		"8> Destruir bolsa" << endl <<
		"9> Terminar programa" << endl << endl;

		cin >> flag;

		switch(flag) {
			// inserir
		case 1:
			cout << "Quantos itens deseja inserir?" << endl;

			cin >> n;
			while(n < 0) {
				cout << "Opcao invalida tente novamente: " << flush;
				cin >> n;
			}

			for(int i = 0; i < n; i++) {
				contadorId++;
				item.id = contadorId;
				cout << "------------ Item " << i + 1 << " ------------" << endl;
				cout << "Nome: " << flush;
				cin.ignore();
				getline(cin, item.nome);
				cout << "Nivel (1 - Fraco | 2 - Moderado | 3 - Forte): " << flush;
				cin >> item.nivel;
				while(item.nivel < 1 || item.nivel > 3) {
					cout << "Opcao invalida tente novamente: " << flush;
					cin >> item.nivel;
				}
				item.nivel -= 1;
				cout << "Cor: " << flush;
				cin.ignore();
				getline(cin, item.cor);
				cout << "Propriedade magica: " << flush;
				getline(cin, item.propriedadeMagica);

				cout << "----------------------------------------------" << endl;
				cout << "Deseja inserir o tamanho do item como pontos de um poligono? (nao>1 - sim>2)" << endl;
				cin >> auxInt;
				while(auxInt < 1 || auxInt > 2) {
					cout << "Opcao invalida tente novamente: " << flush;
					cin >> auxInt;
				}

				if(auxInt == 2) {
					int contador = 0;
					cout << "Quantos pontos o poligono do item tem?" << endl;
					cin >> n2;
					for (int i = 0; i < n2; i++) {
						cout << "Ponto " << i+1 << ": " << flush;
						cin >> v[i].x >> v[i].y;
					}
					fechoConvexo = Graham_scan(v, n);

					while(!fechoConvexo.empty()) {
						v[contador] = fechoConvexo.back();
						fechoConvexo.pop_back();
						contador++;
					}

					if(area_poligono(v, n2) <= 1256.64) {
						node = insert(node, item, 1);
						propriedadesMagicas = insert(propriedadesMagicas, item, 2);
						cout << endl << "Item \"" << item.nome << "\" inserido com sucesso! Id = " << item.id << endl;
					} else {
						cout << "O item eh muito grande e nao pode passar pela boca da mochila" << endl;
					}
				} else {
					node = insert(node, item, 1);
					propriedadesMagicas = insert(propriedadesMagicas, item, 2);
					cout << endl << "Item \"" << item.nome << "\" inserido com sucesso! Id = " << item.id << endl;
				}
			}
			break;

			// pesquisar
		case 2:
			if(node == NULL) {
				cout << "Nao existe nenhum item na bolsa." << endl;
			} else {
				cout << "Qual Item voce quer procurar na bolsa?" << endl;
				cin.ignore();
				getline(cin, auxStr);

				result = search(node, auxStr);

				if(result != NULL) {
					cout << "Item \"" << auxStr << "\" encontrado!" << endl;
					cout << "mostrar informacoes do item? (1>nao | 2>sim)" << endl;
					cin >> auxInt;
					while(auxInt < 1 || auxInt > 2) {
						cout << "Opcao invalida tente novamente: " << flush;
						cin >> auxInt;
					}
					if(auxInt == 2) {
						cout << "-------------------------------------" << endl;
						cout << "Nome: " << result->item.nome << endl;
						cout << "Nivel: " << nivel[result->item.nivel] << endl;
						cout << "Cor: " << result->item.cor << endl;
						cout << "Propriedade magica: " << result->item.propriedadeMagica << endl;
						cout << "Id: " << result->item.id << endl;
					}
				} else
					cout << "Item \"" << auxStr << "\" nao encontrado!" << endl;
			}
			break;

			// remover
		case 3:
			if(node == NULL)
				cout << "Nao existe nenhum item na bolsa." << endl;
			else {
				cout << "Qual item quer remover da bolsa?" << endl;
				cin.ignore();
				getline(cin, auxStr);

				// faz uma pesquisa antes para conferir se o valor existe na árvore
				result = search(node, auxStr);

				if(result != NULL) {
					node = remove(node, auxStr);
					cout << "Item \"" << auxStr << "\" removido da bolsa." << endl;
				} else
					cout << "Item \"" << auxStr << "\" nao encontrado para remocao." << endl;
			}
			break;

			// remove todos os itens de mesma cor
		case 4:
			if(node != NULL) {
				cout << "Itens de qual cor remover?" << endl;
				cout << "Cor: " << flush;
				cin.ignore();
				getline(cin, auxStr);

				node = removeColor(node, auxStr);
				propriedadesMagicas = removeColor(propriedadesMagicas, auxStr);

				cout << "Todos os itens da cor \"" << auxStr << "\" foram removidos com sucesso." << endl;
			} else
				cout << "Bolsa vazia." << endl;
			break;

			// mostra os elementos
		case 5:
			if(node == NULL)
				cout << "Bolsa vazia." << endl;
			else {
				cout << "Deseja mostrar os itens por oredem alfabetica de nome" <<
				"ou propriedade magica? (1>nome | 2>propriedade magica)" << endl;
				cin >> auxInt;
				while(auxInt < 1 || auxInt > 2) {
					cout << "Opcao invalida tente novamente: " << flush;
					cin >> auxInt;
				}
				if(auxInt == 1)
					emOrdem(node);
				else
					emOrdemPropriedadeMagica(propriedadesMagicas);
				cout << endl;
			}
			break;

			// motra a quantidade de itens com uma mesma propriedade mágica
		case 6:
			if(node != NULL) {
				cout << "Mostrar quantidade de itens com qual propriedade magica?" << endl;
				cin.ignore();
				getline(cin, auxStr);
				cout << qntPropriedadeMagica(node, auxStr) << " itens com a propriedade magica \"" << auxStr << "\"." << endl;
			} else
				cout << "Bolsa vazia." << endl;
			break;

			// descobre em qual percurso (ordem, preordem ou posordem) o item é encontrado primeiro
		case 7:
			if(node != NULL) {
				cout << "Qual cor procurar?" << endl;
				cin.ignore();
				getline(cin, auxStr);
				testePercurso(node, auxStr);
			} else {
				cout << "Bolsa vazia." << endl;
			}
			break;

			// deleta a árvore
		case 8:
			if(node == NULL)
				cout << "Bolsa vazia." << endl;
			else {
				cout << "Tem certeza que deseja remover todos os itens da bolsa ? (1>nao | 2>sim)" << endl;
				cin >> auxInt;
				while(auxInt < 1 || auxInt > 2) {
					cout << "Opcao invalida tente novamente : " << flush;
					cin >> auxInt;
				}

				if(auxInt == 2) {
					destroyTree(node);
					node = NULL;
					destroyTree(propriedadesMagicas);
					propriedadesMagicas = NULL;
					cout << "Todos os itens removidos com sucesso." << endl;
				} else
					cout << "Operacao cancelada." << endl;
			}
			break;

			// apenas finaliza o programa
		case 9:
			break;

			// pede uma nova opção se a entrada não for um número válido
		default:
			cout << "Escolha uma opcao valida." << endl;
		}

		if(flag != 9) {
			cout << endl;
			system("pause");
		}
		system("cls");

	} while(flag != 9);

	cout << endl << "Fim do programa." << endl << endl;

	system("pause");

	return 0;
}

/*
Seu código deve ser capaz de:
1 pronto • Inserir itens colocando seu nome, sua propriedade mágica e sua identificação
(será a quantidade de itens já inseridos, por exemplo, o primeiro item terá
identificação 1, o segundo terá identificação 2), sua cor e imprimir todas essas
informações por ordem crescente do nome.
2 pronto • Verificar se um item existe pelo seu nome, se sim, imprimir “Item encontrado!”,
se não “Item não encontrado!”.
3 pronto • Ordenar e imprimir de forma alfabética das propriedades mágicas.
4 pronto • Retornar a quantidade de itens que possuem as mesmas propriedades
mágicas.
5 pronto • Remover todos os elementos de uma determinada cor.
6 pronto • Descobrir por qual percurso (emOrdem, pósOrdem e préOrdem) encontra
primeiro o item da cor procurada.
*/
