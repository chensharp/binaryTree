#include <iostream>

using namespace std;


typedef struct node{
    node *leftchild;
    node *rightchild;
    char data;


}Bitreenode,*Bitree;

void createBitree(Bitree &T){
    char c;
    cin>>c;
    if('#'==c){
        T=NULL;
    }else{
        T = new Bitreenode;
        T->data = c;
        createBitree(T->leftchild);
        createBitree(T->rightchild);
    }
}

int getmax(int a,int b){ return a < b  ? b : a ;  }


int depth(Bitree T){
    if(T == NULL)
        return 0;
    int leftdepth = depth(T->leftchild);
    int righdepth = depth(T->rightchild);

    return 1+ getmax(leftdepth , righdepth);
}

void printLevelNode(Bitree T,int level){
    if(T== NULL || level < 1)
        return;
    if(level == 1){
        cout<<T->data<<" ";
        return;
    }
    printLevelNode(T->leftchild,level-1);
    printLevelNode(T->rightchild,level-1);


}

void levelTraverse(Bitree T){
    if(T == NULL)
        return ;
    int depths = depth(T);
    for(int i=0;i<= depths;i++){
        //print
        printLevelNode(T,i);
        cout<<endl;
    }


}




int main()
{
    //cout << "Hello world!" << endl;
    Bitree T;
    createBitree(T);


    levelTraverse(T);



    return 0;
}
