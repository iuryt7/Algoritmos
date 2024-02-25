#include <iostream>
#include <list>
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

void printCurrentLevel(Node* root, int level);
int height(Node* node);
Node* newNode(int data);
 
void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
 
int height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
         
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
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
		printLevelOrder(root);
		cout << endl;
		destroyTree(root);
	}

	cout << endl << endl;

	return 0;
}
