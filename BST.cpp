//BST
#include <iostream>
using namespace std;

template<class Type>
class BST;

template<class Type>
class BSTNode{
	friend class BST<Type>;
	public:
		BSTNode(Type d=Type(),BSTNode<Type>* left=nullptr,BSTNode<Type>* right=nullptr)
		:data(d),leftChild(left),rightChild(right){
			
		}
		~BSTNode(){}
	private:
		Type data;
		BSTNode<Type> *leftChild;
		BSTNode<Type> *rightChild;
};
template<class Type>
class BST{
	public:
		BST():root(nullptr){}
		~BST(){
			makeEmpty(root);
			root=nullptr;
		}
	public:
		bool insert(const Type &x){//����ӿ�
			return insert(root,x);
		}
		bool remove(const Type &x){
			return remove(root,x);
		}
		BST(Type arr[],int n):root(nullptr){
			for(int i=0;i<n;i++){
				insert(arr[i]);
			}
		}
		void show(){
			return show(root);
		}
		void showPair(){
			return showPair(root);
		}
		void makeEmpty(){//�ÿ� �ͷ�������ڴ�ռ�
			makeEmpty(root);
		}
		Type Min() const{
			BSTNode<Type>* t=root;
			while(t->leftChild!=nullptr){
				t=t->leftChild;
			}
			return t->data;
		}
		Type Max() const{
			BSTNode<Type>* t=root;
			while(t->rightChild!=nullptr){
				t=t->rightChild;
			}
			return t->data;
		}
		//s�����ɹ����ؽڵ��ַ
		BSTNode<Type>* find(const Type &x){
			return find(root,x);
		}
	protected:
		bool insert(BSTNode<Type> *&t,const Type &x){//ʵ�ʲ��뺯�� ��ı����νṹ��������
			if(t==nullptr){//Ҷ��
				t=new BSTNode<Type> (x);
				return true;
			}
			else if(x<t->data){//��߲���
				insert(t->leftChild,x);
			}
			else if(x>t->data){
				insert(t->rightChild,x);
			}
		}
		
		bool remove(BSTNode<Type>* &t,const Type &x){//ɾ���ؼ���
		//1��Ҷ�ӽڵ�
		//2����������/������
		//3������������������
		/*
			BSTNode<Type>* p=t->leftChild;
			if(t!=nullptr){
				if(x<t->data)
					remove(t->leftChild,x);
				else if(x>t->data)
					remove(t->rightChild,x);
				else{//ɾ���ýڵ�
					if(t->leftChild==nullptr && t->rightChild==nullptr){//1\Ҷ��
						delete t;
						t=nullptr;
					}
					else if(t->leftChild!=nullptr && t->rightChild==nullptr){
						p=t;
						t=p->leftChild;;
						delete p;
					}
					else if(t->leftChild==nullptr && t->rightChild!=nullptr){
						p=t;
						t=p->rightChild;
						delete p;
					}
					else if(t->leftChild!=nullptr && t->rightChild!=nullptr){
						//��ǰ������������Ҷ��
						p=t->leftChild;
						while(p->rightChild!=nullptr){
							p=p->rightChild;
						}
						t->data=p->data;
						remove(t->leftChild,p->data);
					}
				}
			}
			*/
			BSTNode<Type>* p;
			if(t!=nullptr){
				if(x<t->data) remove(t->leftChild,x);
				else if(x>t->data) remove(t->rightChild,x);
				else if(t->leftChild!=nullptr && t->rightChild!=nullptr){
					p=t->leftChild;
					int tmp;
					while(p->rightChild!=nullptr){
						p=p->rightChild;
					}
					tmp=p->data; 
					remove(t,tmp);
					t->data=tmp;
				}
				else{
					p=t;
					if(t->leftChild!=nullptr)
						t=t->leftChild;
					else
						t=t->rightChild;
					delete p;
				}
			}
			return true;
			
		}
		
		void show(BSTNode<Type> *t){
			if(t!=nullptr){//�������
				show(t->leftChild);
				cout<<t->data<<" ";
				show(t->rightChild);
			}
		}
		void showPair(BSTNode<Type> *t){
			if(t!=nullptr){
				showPair(t->leftChild);
				cout<<(t->data).first<<":"<<(t->data).second<<" ";
				showPair(t->rightChild);
			}
		}
		void makeEmpty(BSTNode<Type>* &t){//Ҫ�ı� ������
			if(t!=nullptr){
				makeEmpty(t->leftChild);
				makeEmpty(t->rightChild);
				delete t;
				t=nullptr;
			}
		}
		BSTNode<Type>* find(BSTNode<Type> *t,const Type &x){
			if(t!=nullptr) return nullptr;
			if(t->data==x) return t;
			if(x<t->data) return find(t->leftChild,x);
			else return find(t->rightChild,x);
		}
	private:
		BSTNode<Type>* root;//�����ڵ�
};
int main(){
	   //key    //value ��ֵ��
	pair<int,string> v1={1,"abc"};
	pair<int,string> v2={4,"xyz"};
	pair<int,string> v3={2,"hjk"};
	BST<pair<int,string>> bst;
	bst.insert(v1);
	bst.insert(v2);
	bst.insert(v3);
	bst.showPair();
	return 0;
}
/*
int main(){
	//int arr[]={5,53,78,65,17,87,9,81,45,23};
	int arr[]={5,3,4,6,2,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	BST<int> bst(arr,n);
	bst.show();
	cout<<endl;
	cout<<"Min()="<<bst.Min()<<endl;
	cout<<"Max()="<<bst.Max()<<endl;
	int key=3;
	BSTNode<int> *p=bst.find(key);
	bst.remove(key);
	bst.show();
	return 0;
}
/*
int main(){
	int arr[]={53,78,65,17,87,9,81,45,23};
	int n=sizeof(arr)/sizeof(arr[0]);
	BST<int> bst;
	for(int i=0;i<n;i++){
		bst.insert(arr[i]);
	}
	bst.show();
	cout<<endl;
	return 0;
}
*/





