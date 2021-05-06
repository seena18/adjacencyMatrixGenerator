#include <iostream>
#include <vector>
using namespace std;


struct node{
  vector<node*> pointers;
  int data;
  node(int n){
    data=n;
  }
  void add(node* n){
    pointers.push_back(n);
  }
};

int** matrix(vector<node> n){
    int** arr = 0;
      arr = new int*[7];
  for(int i=0;i<7;i++){
    arr[i]=new int[7]; 
    for(int j=0;j<7;j++){
      arr[i][j]=0;
    }
  }
  for(int i=0;i<7;i++){
    for(int j=0;j<n[i].pointers.size();j++){
      int y = (n[i].pointers[j])->data-1;
      arr[i][y]=1;
      
        
      }
  }
  cout<<"   1 2 3 4 5 6 7"<<endl;
  cout<<"   -------------"<<endl;
  for(int i=0;i<7;i++){
    cout<<i+1<<" |";
    for(int j=0;j<7;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
 return arr;
}
void findNewVertexOfIndegreeZero(int** arr, int size){
  for(int j =0;j<size;j++){
    for(int i=0;i<size;i++){
      if(arr[i][j]!=0){
        break;
      }
      if(i==6&&arr[i][j]==0){
        cout<<"Vertex v"<<j+1<<" is of indegree 0"<<endl;

      }
    }
  }
}

int main() {
  node v1(1);
  node v2(2);
  node v3(3);
  node v4(4); 
  node v5(5);
  node v6(6);
  node v7(7);
  v1.add(&v2);
  v1.add(&v3);
  v1.add(&v4);
  v2.add(&v4);
  v2.add(&v5);
  v3.add(&v6);
  v4.add(&v3);
  v4.add(&v6);
  v4.add(&v7);
  v5.add(&v4);
  v5.add(&v7);
  v7.add(&v6);
  
   vector<node> n={
    v1,v2,v3,v4,v5,v6,v7
    };
    cout<<"Adjacency Matrix: "<<endl;
  int** arr=matrix(n);
  int size=n.size();
  findNewVertexOfIndegreeZero(arr,size);
}

