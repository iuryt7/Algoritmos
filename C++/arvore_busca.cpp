#include <iostream>
#include <clocale> //Biblioteca para mudar o idioma que o compilador entende
using namespace std;

// Definindo a estrutura do nó da árvore
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Função para criar um novo nó na árvore
Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Função para inserir um novo nó na árvore
Node* insert(Node* root, int data)
{
	// Caso a raiz seja nula, criamos um novo nó com o dado fornecido
	if (root == NULL)
	{
		root = newNode(data);
		return root;
	}

	// Se o dado fornecido for menor que o dado da raiz, inserimos na subárvore esquerda
	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}

	// Se o dado fornecido for maior que o dado da raiz, inserimos na subárvore direita
	else if (data > root->data)
	{
		root->right = insert(root->right, data);
	}

	return root;
}

// Função para imprimir a árvore em ordem
void emOrdem(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	emOrdem(root->left);
	cout << root->data << " ";
	emOrdem(root->right);
}
void preOrdem(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preOrdem(root->left);
	preOrdem(root->right);
}
void postOrdem(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrdem(root->left);
	postOrdem(root->right);
	cout << root->data << " ";
}
void destroyTree(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	destroyTree(root->left);
	destroyTree(root->right);
	delete root;
}

int main()
{
	//Adicionando a lingua portuguesa para podermos escrever "Árvore"
	setlocale(LC_ALL, "pt_BR.UTF-8");

	int x, y, nmr;
	int caso = 0;
	cin >> x;

	for(int i = 0; i < x; i++)
	{
		cin >> y;
		Node* root = NULL;
		for(int j = 0; j < y; j++)
		{
			cin >> nmr;
			root = insert(root, nmr);
		}
		cout << "Case " << i + 1 << ":" << endl;
		cout << "Pre: ";
		preOrdem(root);
		cout << endl;
		cout << "In.: ";
		emOrdem(root);
		cout << endl;
		cout << "Post: ";
		postOrdem(root);
		cout << endl;
		destroyTree(root);
		caso++;
	}

	cout << endl << endl;

	return 0;
}
