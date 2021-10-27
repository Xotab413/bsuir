#include "Functions.h"

void menu(tree** root) {
	char buffer;

	do {
		system("CLS");
		if (!*root) {
			printf(" Because of empty tree you can choose one of these options \n 1 - Input\n 2 - Exit\n");
			rewind(stdin);
			buffer = getchar();

			switch (buffer)
			{
			case '1':
				treeInput(root);
				break;
			case '2':
				return;
			default:
				break;
			}
		}
		else {
			printf(" Choose one of these options \n 1 - Additional input\n 2 - Output with stack \n 3 - Output");
			printf("\n 4 - Deleting\n 5 - Exit \n");
			rewind(stdin);
			buffer = getchar();

			switch (buffer)
			{
			case '1':
				treeInput(root);
				break;
			case '2':
				printWithStack(*root);
				break;
			case '3':
                printBasic(*root);
				break;
			case '4': 
				*root = deleting(*root);
				break;
			case '5':
				treeDestroy(*root);
				break;
			case '6':
				return;

			default: break;

			}
		}
		printf("Do you want to do anything else?(Y/N)");
		rewind(stdin);
		buffer = getchar();
		if (buffer != 'y' && buffer != 'Y') return;
	} while (1);
}

void treeInput(tree** root) {
    tree* current = NULL, * previous = NULL;

	do {
			current = (tree*)calloc(1, sizeof(tree));
			if (!current) {
				printf(" Can't add one more word, try later");
				return;
			}
			current->leftBranch = current->rightBranch = NULL;
		printf(" Enter your word with length less than %d symbols", MAX_WORD_SIZE);
		rewind(stdin);
		getsByMe(current->englishWord, MAX_WORD_SIZE);
		printf(" Enter your word with length less than %d symbols", MAX_WORD_SIZE);
		rewind(stdin);
		getsByMe(current->russianWord, MAX_WORD_SIZE);
		if (!(*root)) {
			*root = current;
			continue;
		}
		previous = *root;
		while (previous) {
			if (strcmpIgnoreCase(previous->englishWord, current->englishWord) == 0) {
				break;	
			}
			else if (strcmpIgnoreCase(previous->englishWord, current->englishWord) > 0) {
				if (previous->leftBranch) previous = previous->leftBranch;
				else {
					previous->leftBranch = current;
					previous = NULL;
				}
			} else {
				if (previous->rightBranch) previous = previous->rightBranch;
				else {
					previous->rightBranch = current;
					previous = NULL;
				}
			}

		}
		printf("\n\n\n\n    Enter   0  \n\n");

	} while (getchar() == '0');
}

int strcmpIgnoreCase(const char* string1, const char* string2) {
	while (*string2 && *string1 && (*string1 == *string2 || *string1 == *string2 - 32 || *string1 == *string2 + 32)) { ++string1; ++string2; }
	return (*string1 > *string2 ? 1 : (*string1 < *string2 ? -1 : 0));
}

void printBasic(tree* dr)
{
	if (dr)
	{
		if (dr->leftBranch) printBasic(dr->leftBranch);
		printf("%15s - %15s\n", dr->englishWord, dr->russianWord);
		if (dr->rightBranch) printBasic(dr->rightBranch);

	}
}

tree* deleting(tree* root) {

	tree* current = root, *previous = root;
	char substring[MAX_WORD_SIZE];
	int buffer;

	printf("\n\n Enter word to search ");
	rewind(stdin);
	getsByMe(substring, MAX_WORD_SIZE);

	while (current) {
		buffer = strcmpIgnoreCase(current->englishWord, substring);
		if (!buffer) {
			printf(" Are you sure you want to delete this element? If yes enter 0\n\n");
			printf(" %15s - %15s ", current->englishWord, current->russianWord);
			if (getchar() == '0') {
				// IF user wants to delete root
				if (current == root) {
					root = current->rightBranch;
					previous = root;
					while (previous->leftBranch) previous = previous->leftBranch;
					previous->leftBranch = current->leftBranch;
					free(current);
					return root;
				}
				// If user wants to delete leaf 
				else if (!current->rightBranch && !current->leftBranch) {
					previous->rightBranch = NULL;
					previous->leftBranch = NULL;
					free(current);
					return root;
				}
				else if (current->rightBranch && current->leftBranch) {
					previous->leftBranch = current->rightBranch;
					previous = previous->rightBranch;
					while (previous->leftBranch) previous = previous->leftBranch;
					previous->leftBranch = current->leftBranch;
				}
				else if (current->leftBranch) {
					previous->rightBranch = current->leftBranch;
				}
				else previous->leftBranch = current->rightBranch;
				free(current);
				return root;
			}
			else return root;
			
		}
		else if (buffer > 0) {
			previous = current; 
			current = current->leftBranch;
		}
		else {
			previous = current;
			current = current->rightBranch;
		}
	}
	printf(" There is no word - %s\n", substring);
}

void treeDestroy(tree* root)  {
	if (root) {
		treeDestroy(root->leftBranch);
		treeDestroy(root->rightBranch);
		free(root);
	}
}

void getsByMe(char string[MAX_WORD_SIZE], int size) {
	char buf;
	int i = 0;
	while ((buf = getchar()) != '\n' && i < MAX_WORD_SIZE - 1) {
		string[i] = buf;
		i++;
	}
	string[i] = '\0';
	rewind(stdin);
}

void printWithStack(tree* root)
{
	typedef struct stack {
		tree* node;             
		struct stack* previous;
	}stack;
   stack *stackKeeper;
   stack * previousElement = NULL;
	if (!root) { 
		printf(" Tree is empty\n"); 
		return; 
	}
	int isLeft = 1;            
										
	stackKeeper = (stack*)calloc(1, sizeof(stack)); 
	stackKeeper->node = root;
                                                
	printf("%s - %s\n", root->englishWord, root->russianWord);
	while (stackKeeper || root->rightBranch)  
	{
		do  
		{
			if (isLeft && root->leftBranch) root = root->leftBranch;
			else if (root->rightBranch) root = root->rightBranch;
			isLeft = 1;
			if (root->leftBranch && root->rightBranch)
			{
				previousElement = stackKeeper;
				stackKeeper = (stack*)calloc(1, sizeof(stack));
				stackKeeper->node = root;
				stackKeeper->previous = previousElement; 
			}
			printf("%s - %s\n", root->englishWord, root->russianWord);
		} while (root->leftBranch || root->rightBranch);
		if (stackKeeper)
		{
			root = stackKeeper->node;
			previousElement = stackKeeper->previous;
			free(stackKeeper); 
		}
 		stackKeeper = previousElement;
		if (root->leftBranch && root->rightBranch) isLeft = 0;
		else break;
	}
}
