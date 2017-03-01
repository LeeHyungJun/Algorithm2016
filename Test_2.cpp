// HW 2 : Binary Search Tree
// Name : 이형준
// Student ID : 20113315
static int count=0;

template <class T>
bool  BinaryST<T>::Insert(T item)  {	

	if(root==NULL)//datatype 
	{
		root = new BSTNode<T>(item);
		//BSTNode<T>* temp=root;	
	}

	else
	{
		BSTNode<T>* temp=root;
		BSTNode<T>* beforeNode=0;	
		// insert는 노드가 NULL일때까지 탐색을한다.
		//beforeNode->data.key 가 그 itme.key 가 된다.
		//temp==null 이 됨.
		while(temp)
		{
			beforeNode=temp;
			if(temp->data.key > item.key)
				temp=temp->lC;
			else if(temp->data.key < item.key)
				temp=temp->rC;		
			else
			{
				temp->data.val=item.val;
				return false;
			}			
		}
		//temp가 NULL이면 비포노드를 찾아서 비포노드->다음노드 = 생성 해준다
		if(beforeNode->data.key > item.key)
			beforeNode->lC=new BSTNode<T>(item);
		else if(beforeNode->data.key < item.key)
			beforeNode->rC=new BSTNode<T>(item);
		
	}
	return true;
}

template <class T>
T BinaryST<T>::Get(T item)  {
BSTNode<T>* temp=root;
	while(temp)
	{
		if(temp->data.key > item.key)
			temp=temp->lC;
		else if(temp->data.key < item.key)
			temp=temp->rC;		
		else if(temp->data.key == item.key)
			return temp->data;		
	}
	return T(-1);
} 


template <class T>
bool  BinaryST<T>::Delete(T item)  {
//degree 1 degree 0 degree 2/.....

	if(root == NULL)
	 	return false;
	BSTNode<Item>* currentNode = root;
	BSTNode<Item>* beforeNode;
		//while문을 빠져나오면 currenNode는 그 제거해야할 당사자 노드이다.
		//beforeNode는 currentNode의 이전 노드
		while(currentNode->data.key != item.key)
		{
			beforeNode = currentNode;
			if(currentNode->data.key > item.key)
			{
				//currentNode를 찾으면서 내려오다가 lC 나 rC 로 갔는데 없은면 
				//제거할 당사자가 존재하지 않는거임. 리턴 false
				if(currentNode->lC == NULL) 
					return false;
				currentNode = currentNode->lC;
			}
			else
			{
				if(currentNode->rC == NULL) 
					return false;
				currentNode = currentNode->rC;
			}
		}
		/
		//디그리 0일떄 . " 제거해야 할 노드->link = null "
		if(currentNode->rC == NULL && currentNode->lC == NULL)
		{
			if(beforeNode->rC == currentNode)
				beforeNode->rC = NULL;
			else if(beforeNode->lC == currentNode)
				beforeNode->lC = NULL;
			else	
				root = NULL;	
		}
		//디그리 1이고 왼쪽일떄
		else if(currentNode->rC == NULL)
		{
			if(beforeNode->rC == currentNode)
				beforeNode->rC = currentNode->lC;
			else if(beforeNode->lC == currentNode)
				beforeNode->lC = currentNode->lC;
			else
				root = currentNode->lC;
		}
		//디그리 1이고 오른쪽일때	
		else if(currentNode->lC == NULL)
		{
			if(beforeNode->rC == currentNode)
				beforeNode->rC = currentNode->rC;
			else if(beforeNode->lC == currentNode)
				beforeNode->lC = currentNode->rC;
			else
				root = currentNode->rC;
		}
		//디그리 2일때
		else
		{
			BSTNode<Item>* temp = currentNode->rC;
			//insert할떄 노드 찾는거랑 똑같.
			while(temp->lC != NULL)
			{
				temp = temp->lC;
			}
			
			//제거해야될 노드의 sub노드 중 가장 큰 노드가 제거해야될 노드의 key,value를 대체하고
			//그 가장 큰노드를 딜리트(디그리가 1일떄)로 제거.
			currentNode->data.val = temp->data.val;
			currentNode->data.key = temp->data.key;

			Delete(temp->data);
			//currentNode->data.key = temp->data.key;
		}
	return true;
}

template <class T>
void  BinaryST<T>::PreOrder(BSTNode<T> *ptr)  {
	if (ptr != NULL)
  	{
      	cout << ptr->data.key<<"("<<ptr->data.val<<")"<<" ";
  		PreOrder(ptr->lC);   
    	PreOrder(ptr->rC);
   	}
}

template <class T>
void  BinaryST<T>::InOrder(BSTNode<T> *ptr)  {
	if (ptr != NULL)
  	{
  		InOrder(ptr->lC);
		cout << ptr->data.key<<"("<<ptr->data.val<<")"<<" ";   
    	InOrder(ptr->rC);
   	}
}

template <class T>
void  BinaryST<T>::PostOrder(BSTNode<T> *ptr)  {
	if (ptr != NULL)
  	{
  		PostOrder(ptr->lC);   
    	PostOrder(ptr->rC);
		cout << ptr->data.key<<"("<<ptr->data.val<<")"<<" ";
   	}

}

template <class T>
int  BinaryST<T>::Count(BSTNode<T> *ptr)  {
	if (ptr == NULL)	
		return 0;
	return Count(ptr->lC)+Count(ptr->rC)+1;
}

template <class T>
int  BinaryST<T>::Height(BSTNode<T> *ptr)  {
	if(ptr==NULL) return 0;
if(Height(ptr->lC) > Height(ptr->rC))
	return 1+Height(ptr->lC);
else
	return 1+Height(ptr->rC);
}


