#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Priority_Q;

fstream obj;

struct BST_att
{
	char ch;
	int prioirty;

	BST_att* right;
	BST_att* left;

	BST_att()
	{
		right = NULL;
		left = NULL;
	}
};

class BST
{
	BST_att* root;
 public:

	 BST() 
	 {
		 root = NULL;
	 }

	 friend class Priority_Q;

	void Insert(char c, int val)
	{
		root = new BST_att;
		root->ch = c;
		root->prioirty = val;
	}

	void Insert(char c, int val, BST_att* l, BST_att* r)  // Function Overloading
	{
		root = new BST_att;
		root->ch = c;
		root->prioirty = val;
		root->left = l;
		root->right = r;
	}

	void PreOrder(BST_att* r)
	{
		if (r != NULL)
		{
			cout << r->ch << ":" << r->prioirty << "  ";
			PreOrder(r->left);
			PreOrder(r->right);
		}
	}

	BST_att* SearchParentNode(char c)
	{
		BST_att* temp = root;
		while (temp)
		{
			if (temp->right == NULL)
			{
				if (c == temp->left->ch)
				{
					return temp;
				}
			}
			else if (temp->left == NULL)
			{
				if (c == temp->right->ch)
				{
					return temp;
				}
			}
			if (c > temp->ch)
				temp = temp->right;
			else
				temp = temp->left;
		}
		return temp;
	}

};

struct Node
{
	int pr;
	BST obj;
	Node* next;
};

class Priority_Q
{
 private:

	Node* front;
 public:

	 friend void BST_Convert(Priority_Q& q);

	 Priority_Q()
	 {
		 front = NULL;
	 }

	 void Traverse()                                                       //Show BST
	 {
		 Node* temp;
		 temp = front;
		 if (front == NULL)
			 cout << "Queue is empty." << endl;
		 else
		 {
			 cout << "Queue of BST is int the form of : " << endl;
			 cout << "Charachter & Priority of Queue of BST is : " << endl;
			 while (temp != NULL)
			 {
				 temp->obj.PreOrder(temp->obj.root);
				 cout << endl;
				 temp = temp->next;
			 }
		 }
		 cout << endl << endl;
	 }

	 void DeQueue()                                                               // To delete node from prioirty queue
	 {
		 Node* temp;
		 if (front == NULL)
			 cout << "Queue is Empty" << endl;
		 else
		 {
			 temp = front;
			 front = front->next;
			 free(temp);
		 }
	 }

	 void EnQueue(char c, int priority)       //To place node in priority queue
	 {
		 Node* temp, * temp2;
		 temp = new Node;

		 temp->obj.Insert(c, priority);
		 temp->pr = priority;
		 if (front == NULL || priority < front->pr)
		 {
			 temp->next = front;
			 front = temp;
		 }
		 else
		 {
			 temp2 = front;
			 while (temp2->next != NULL && temp2->next->pr <= priority)
				 temp2 = temp2->next;
			 temp->next = temp2->next;
			 temp2->next = temp;
		 }
	 }

	 void EnQueue(char c, int priority, BST_att* l, BST_att* r)              // fuction overloading to place compressed node into queue 
	 {                                                                       //to minimize space and compress tree into one node
		 Node* temp, * temp2;
		 temp = new Node;

		 temp->obj.Insert(c, priority, l, r);
		 temp->pr = priority;
		 if (front == NULL || priority < front->pr)
		 {
			 temp->next = front;
			 front = temp;
		 }
		 else
		 {
			 temp2 = front;
			 while (temp2->next != NULL && temp2->next->pr <= priority)
				 temp2 = temp2->next;
			 temp->next = temp2->next;
			 temp2->next = temp;
		 }
	 }

	 BST_att* Get_Front()
	 {
		 return front->obj.root;
	 }

};

void Frequency(char c, string s, Priority_Q& obj)
{
	if (s.size() == 0)
	{
		return;
	}
	else
	{
		string temp = "";
		int count = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == c)
			{
				count++;
			}
			else
			{
				temp += s[i];
			}
		}
		obj.EnQueue(c, count);
		Frequency(temp[0], temp, obj);
	}
}

void BST_Convert(Priority_Q & q)
{
	while (q.front->next)
	{
		BST_att* left = q.Get_Front();
		q.DeQueue();
		BST_att* right = q.Get_Front();
		q.DeQueue();
		q.EnQueue('$', (left->prioirty + right->prioirty), left, right);

	}
}

void Bits_Conversion(BST_att* r, string s)
{
	if (r == NULL)
	{
		return;
	}
	else
	{
		if (r->left == NULL && r->right == NULL)
		{
			ofstream obj2;
			string p;
			string data = "";
			obj.open("MyFile.txt", ios::in);
			obj2.open("temp.txt", ios::out);
			while (getline(obj, p))
				data += p;
			int count = 0;
			while (count != data.size())
			{
				obj >> data[count];
				if (data[count] == r->ch)
				{
					obj2 << s;
				}
				else
					obj2 << data[count];
				count++;
			}
			obj.close();
			obj2.close();
			remove("MyFile.txt");
			rename("temp.txt", "MyFile.txt");
		}
		Bits_Conversion(r->left, s + "0");
		Bits_Conversion(r->right, s + "1");
	}
}

int Binary_To_Int(string bin)
{
	int sum = 0;
	for (int i = 0; i < bin.size(); i++)
	{
		if (bin[i] == '1')
		{
			sum += pow(2, ((bin.size() - 1) - i));
		}
	}
	return sum;
}

void Compress()
{
	ofstream obj2;
	string p;
	string data = "";
	obj.open("MyFile.txt", ios::in);
	obj2.open("temp.txt", ios::out);
	while (getline(obj, p))
	{
		data += p;
	}
		
	int count = 0;
	int i = 1;
	p = "";

jump:
	if (count != data.size())
	{
		while (count < (8 * i) && count != data.size())
		{
			p += data[count];
			count++;
		}
		char Code = (char)Binary_To_Int(p);
		obj2 << Code;
		i++;
		p = "";
		goto jump;
	}

	obj.close();
	obj2.close();
	remove("MyFile.txt");
	rename("temp.txt", "MyFile.txt");
}

string Int_To_Binary(int n)
{
	string a;
	string b;
	int i;
	for (i = 0; n > 0; i++)
	{
		a += to_string(n % 2);
		n = n / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		b += a[i];
	}
	cout << b << endl;
	return b;
}

string Char_To_Binary(string k)
{
	string sum = "";
	for (int i = 0; i < k.size(); i++)
	{
		sum += Int_To_Binary((int)k[i]);
	}
	return sum;
}

void De_Compress(BST_att* r)
{
	BST_att* temp = r;
	string s = "";
	ofstream obj2;
	obj.open("MyFile.txt", ios::in);
	obj2.open("temp.txt");
	string p;
	string data;
	string k = "";
	while (getline(obj, p))
		k += p;
	data = Char_To_Binary(k);
	int count = 0;
	while (count < data.size())
	{
		if (r->left == NULL && r->right == NULL)
		{
			obj2 << temp->ch;
			temp = r;
		}
		else
		{
			if (data[count] == '0')
			{
				temp = temp->left;
				s += "0";
			}
			else
			{
				temp = temp->right;
				s += "1";
			}
			count++;
		}
	}

	obj.close();
	obj2.close();
	remove("MyFile.txt");
	rename("temp.txt", "MyFile.txt");
}

int main()
{
	fstream A;
	string s = "";
	string p;
	A.open("MyFile.txt", ios::in);
	while (getline(A, p))
	{
		s += p;
	}	
	Priority_Q obj;
	Frequency(s[0], s, obj);
	BST_Convert(obj);
	obj.Traverse();
	A.close();
	Bits_Conversion(obj.Get_Front(), "");
	Compress();

}
