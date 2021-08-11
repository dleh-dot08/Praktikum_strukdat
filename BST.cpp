#include <iostream>
#include <cstdlib>
using namespace std;

class BST{
	private:
	struct node{
		node* left;
		node* right;
		int data;
	}*root;
	public:
	BST(){
	root = NULL;
	}

	bool isEmpty() const { return root==NULL; }
	void print_inorder();
	void inorder(node*);
	void print_preorder();
	void preorder(node*);
	void print_postorder();
	void postorder(node*);
	void add(int);
	void del(int);
	void display(node* , int);
	void print_display();
	void search(int);
	void print_Search();
	
};

void BST::add(int d){
	node* t = new node;
	node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	if(isEmpty()) root = t;
	else{
		node* cur;
		cur = root;
		while(cur){
			parent = cur;
			if(t->data > cur->data) cur = cur->right;
			else cur = cur->left;
		}
		if(t->data < parent->data)
		parent->left = t;
		else
		parent->right = t;
	}
}

void BST::del(int d){
	//Lokasi element 
	bool found = false;
	if(isEmpty()){
		cout<<" TREE IS EMPTY "<<endl;
		return;
	}
	node* cur;
	node* parent;
	cur = root;
	while(cur != NULL){
		if(cur->data == d){
			found = true;
			break;
		}
		else{
			parent = cur;
			if(d>cur->data) cur = cur->right;
			else cur = cur->left;
		}
	}
	if(!found){
		cout<<" DATA NOT FOUND! "<<endl;
		return;
	}
	// Node jika dengan single child
	if((cur->left == NULL && cur->right != NULL)|| (cur->left != NULL&& cur->right == NULL)){
		if(cur->left == NULL && cur->right != NULL){
			if(parent->left == cur){
				parent->left = cur->right;
				delete cur;
			}
			else{
				parent->right = cur->right;
				delete cur;
			}
		}
		else{
			if(parent->left == cur){
				parent->left = cur->left;
				delete cur;
			}
			else{
				parent->right = cur->left;
				delete cur;
			}
		}
		return;
	}
	// node jika tidak mempunyai child node
	if( cur->left == NULL && cur->right == NULL){
		if(parent->left == cur ) parent->left = NULL;
		else parent->right = NULL;
		delete cur;
		return;
	}
	//Node dengan 2 child node
	// ganti node dengan nilai terkecil di subtree bagain kanan
	if (cur->left != NULL && cur->right != NULL){
		node* temp;
		temp = cur->right;
		if((temp->left == NULL) && (temp->right == NULL)){
			cur = temp;
			delete temp;
			cur->right = NULL;
		}
		else{
			if((cur->right)->left != NULL){
				node* lcur;
				node* lcurrp;
				lcurrp = cur->right;
				lcur = (cur->right)->left;
				while(lcur->left != NULL){
					lcurrp = lcur;
					lcur = lcur->left;
				}
				cur->data = lcur->data;
				delete lcur;
				lcurrp->left = NULL;
			}
			else{
				node* tmp2;
				tmp2 = cur->right;
				cur->data = tmp2->data;
				cur->right = tmp2->right;
				delete tmp2;
			}
		}
		return;
	}

}

void BST::inorder(node* p){
	if(p != NULL){
		if(p->left) inorder(p->left);
		cout<<" "<<p->data<<" ";
		if(p->right) inorder(p->right);
	}
	else return;
}

void BST::print_inorder(){
	inorder(root);
}

void BST::preorder(node* p){
	if(p != NULL){
		cout<<" "<<p->data<<" ";
		if(p->left) preorder(p->left);
		if(p->right) preorder(p->right);
	}
	else return;
}

void BST::print_preorder()
{
preorder(root);
}

void BST::postorder(node* p){
	if(p != NULL){
		if(p->left) postorder(p->left);
		if(p->right) postorder(p->right);
		cout<<" "<<p->data<<" ";
	}
	else return;
}

void BST::print_postorder()
{
postorder(root);
}

void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
}

void BST::print_display()
{
display(root, 1);
}

int main(){
	BST b;
	int ch,tmp,tmp1;
	while(1){
		cout<<endl<<endl;
		cout<<" --------------------------------------- "<<endl;
		cout<<" ==== BINARY SEARCH TREE OPERATIONS ==== "<<endl;
		cout<<" --------------------------------------- "<<endl;
		cout<<" |[1]. Insertion/add"<<endl;
		cout<<" |[2]. In-Order Traversal"<<endl;
		cout<<" |[3]. Pre-Order Traversal"<<endl;
		cout<<" |[4]. Post-Order Traversal"<<endl;
		cout<<" |[5]. Removal"<<endl;
		cout<<" |[6]. display"<<endl;
		cout<<" |[7]. Exit"<<endl;
		cout<<" --------------------------------------- "<<endl;
		cout<<" Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1 : 
				cout<<" Enter Number to be inserted : ";
				cin>>tmp;
				b.add(tmp);
				break;
			case 2 : 
				cout<<endl;
				cout<<" -----In-Order Traversal-----"<<endl;
				cout<<" ----------------------------"<<endl;
				b.print_inorder();
				break;
			case 3 : 
				cout<<endl;
				cout<<" -----Pre-Order Traversal-----"<<endl;
				cout<<" -----------------------------"<<endl;
				b.print_preorder();
				break;
			case 4 : 
				cout<<endl;
				cout<<" -----Post-Order Traversal-----"<<endl;
				cout<<" ------------------------------"<<endl;
				b.print_postorder();
				break;
			case 5 : 
				cout<<" Enter data to be deleted : ";
				cin>>tmp1;
				b.del(tmp1);
				break;
			case 6 :
				cout<<" ----- Display tree -----"<<endl;
				cout<<" ------------------------"<<endl;
				b.print_display();
				break;
			case 7:
			return 0;
		}
	}
}
